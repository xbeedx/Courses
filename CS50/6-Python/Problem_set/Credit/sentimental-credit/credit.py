import re

def main():
    number = input("Number: ")

    result = checkCard(number)
    result = result if lunh(number) else "INVALID"

    print(result)

def checkCard(number):
    length = len(number)
    FirstDigit = int(number[0])
    TwoDigts = int(number[0:2])

    if length == 15:
        if number.startswith("34") or number.startswith("37"):
            return "AMEX"
        
    if length == 16:
        if TwoDigts<51 or TwoDigts>55:
            if FirstDigit == 4:
                return "VISA"
            else:
                return "INVALID"
        else: 
            return "MASTERCARD"
    
    if length == 13:
        if FirstDigit!=4: 
            return "INVALID"
        return "VISA"

    return "INVALID"
    
def lunh(number):
    numbersSTL=[]
    numbers0 = []

    i = len(number)-1
    while i >= 0:
        numbers0.append(int(number[i]))

        double = int(number[i-1])*2
        if i == 0:
            break
        if double >= 10:
            numbersSTL.append(double%10)
            numbersSTL.append(int(double/10))
        else:
            numbersSTL.append(double)

        i-=2

    total = sum(numbersSTL) + sum(numbers0)

    return True if total % 10 == 0 else False
    

main()