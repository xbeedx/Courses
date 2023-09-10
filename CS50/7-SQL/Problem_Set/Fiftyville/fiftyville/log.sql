-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT * FROM crime_scene_reports WHERE street = 'Humphrey Street' AND year = 2021 AND month = 7 AND day = 28;
--
--295|2021|7|28|Humphrey Street|Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery.
--297|2021|7|28|Humphrey Street|Littering took place at 16:36. No known witnesses.
-- New Info :
--              10:15am at the Humphrey Street bakery. 3 witnesses

-- Checking interviews at 10:15 mentionning the bakery

SELECT *
FROM interviews
WHERE year = 2021 AND month = 7 AND day = 28 AND transcript LIKE '%bakery%';

--161|Ruth|2021|7|28|Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.
--162|Eugene|2021|7|28|I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.
--163|Raymond|2021|7|28|As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket.

-- Cheking cars that left the parking within 10minutes after 10:15
SELECT license_plate
FROM bakery_security_logs
WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute >= 15 AND minute <= 25 AND activity = 'exit';

-- 5P2BI95
-- 94KL13X
-- 6P58WS2
-- 4328GD8
-- G412CB7
-- L93JTIZ
-- 322W7JE
-- 0NTHK55

-- Checking the ATM on Leggett Street's logs

SELECT account_number, amount
FROM atm_transactions
WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw';

-- 28500762|48
-- 28296815|20
-- 76054385|60
-- 49610011|50
-- 16153065|80
-- 25506511|20
-- 81061156|30
-- 26013199|35

-- Checking phone_calls of less than a minute made after 10:15

SELECT caller, receiver
FROM phone_calls
WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60;

--(130) 555-0289|(996) 555-8899
--(499) 555-9472|(892) 555-8872
--(367) 555-5533|(375) 555-8161
--(499) 555-9472|(717) 555-1342
--(286) 555-6063|(676) 555-6554
--(770) 555-1861|(725) 555-3243
--(031) 555-6622|(910) 555-3251
--(826) 555-1652|(066) 555-9701
--(338) 555-6650|(704) 555-2131

-- Cheking if one of the callers withdrawed money in the morning and left the parking after the theft

SELECT name
FROM people
INNER JOIN bank_accounts ON id = person_id
WHERE phone_number IN (
                        SELECT caller
                        FROM phone_calls
                        WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60
                        )
AND account_number IN (
                        SELECT account_number
                        FROM atm_transactions
                        WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw'
                        )
AND license_plate IN (
                        SELECT license_plate
                        FROM bakery_security_logs
                        WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute >= 15 AND minute <= 25 AND activity = 'exit'
                        )
;

-- Bruce
-- Diana

-- Checking if one of those took the earliest flight the day after

SELECT name
FROM people
WHERE passport_number IN (
    SELECT passport_number
    FROM passengers
    WHERE flight_id = (
                        SELECT flights.id
                        FROM flights
                        INNER JOIN airports ON airports.id = flights.origin_airport_id
                        WHERE year = 2021 AND month = 7 AND day = 29 AND city = 'Fiftyville'
                        ORDER BY hour, minute
                        LIMIT 1
                        )
                    )
AND name IN (
            SELECT name
            FROM people
            INNER JOIN bank_accounts ON id = person_id
            WHERE phone_number IN (
                                SELECT caller
                                FROM phone_calls
                                WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60
                                )
            AND account_number IN (
                                SELECT account_number
                                FROM atm_transactions
                                WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw'
                                )
            AND license_plate IN (
                                SELECT license_plate
                                FROM bakery_security_logs
                                WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute >= 15 AND minute <= 25 AND activity = 'exit'
                                )
    )
;

-- Bruce

-- Bruce is the thief

-- Checking who Bruce called

SELECT name
FROM people
WHERE phone_number IN (
                        SELECT receiver
                        FROM phone_calls
                        WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60
                        AND caller = (
                                        SELECT phone_number
                                        FROM people
                                        WHERE name = 'Bruce'
                                    )
                        )
;

-- Robin is the accomplice

-- Cheking for flights with Bruce and Robin in

SELECT city
from airports
INNER JOIN flights ON flights.destination_airport_id = airports.id
INNER JOIN passengers ON passengers.flight_id = flights.id
WHERE passport_number IN (
                            SELECT passport_number
                            FROM people
                            WHERE name = 'Bruce' OR name = 'Robin'
                         )
;

-- New York City