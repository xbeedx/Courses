while True:
    try:
        change = int(float(input("Change owed: "))*100)
    except ValueError:
        continue

    if change > 0:
        break

quarters = int(change/25)
change = change % 25

dimes = int(change/10)
change = change % 10

nickels = int(change/5)
change = change % 5

pennies = int(change)

print(quarters+dimes+nickels+pennies)