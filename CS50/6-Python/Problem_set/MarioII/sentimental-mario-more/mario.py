while True:
    try:
        height = int(input("Height: "))
    except ValueError:
        continue

    if height >= 1 and height <= 8:
        break

for i in range(1,height+1):
    print(" "*(height-i) + "#"*i +"  "+ "#"*i)