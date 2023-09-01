def main():
    jar = Jar()
    print("Capacity:")
    print(str(jar.capacity), end="\n\n")

    print("str:")
    print(str(jar), end="\n\n")

    print("Deposit 2 cookies:")
    jar.deposit(2)
    print(str(jar), end="\n\n")

    print("Withdraw a cookie:")
    jar.withdraw(1)
    print(str(jar), end="\n\n")

    print("Add too many cookies:")
    try:
        jar.deposit(12)
        print(str(jar), end="\n\n")
    except ValueError:
        print("too many cookies", end="\n\n")

    print("Remove too many cookies:")
    try:
        jar.withdraw(2)
        print(str(jar), end="\n\n")
    except ValueError:
        print("No cookie in the Jar", end="\n\n")

class Jar:
    def __init__(self, capacity=12):
        if capacity < 0:
            raise ValueError
        self.capacity_cookies = capacity
        self.cookies = 0

    def __str__(self):
        str = ""
        for _ in range(self.cookies):
            str += "🍪"
        return str

    def deposit(self, n):
        if self.cookies + n > self.capacity_cookies:
            raise ValueError
        self.cookies += n

    def withdraw(self, n):
        if self.cookies - n < 0:
            raise ValueError
        self.cookies -= n

    @property
    def capacity(self):
        return self.capacity_cookies

    @property
    def size(self):
        return self.cookies
    
main()