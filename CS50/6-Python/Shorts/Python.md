# [Python](https://youtu.be/mgBpcQRDtl0)

## Python Syntax

- Python is an example of a very commonly-used modern programming language.
    - C was first released in 1972, Python in 1991.

- Python is an excellent and versatile language choice for making complex C operations much simpler.
    - String manipulation
    - Networking

- Fortunately, Python is heavily inspired by C (its primary interpreter, Cpython, is actually written in C) and so the syntax should be a shallow learning curve.

- To start writing Python, open up a file with the .py file extension.

- Unlike a C program, which typically has to be compiled before you can run it, a Python program can be run without explicitly compiling it first.

### Variables 

- Python variables have two big differences from C.
    - No type specifier
    - Declared by initialization only 
    - Python statements needn't end with semicolons!

### Conditionals

- All of the old favorites from C are still available for you to use, but they look a little bit different now.
```py
if y < 43 or z == 15:
    # code block 1
else:
     # code block 2
```

- In python, "else if" becomes "elif"

Therefore, the ternary operator; 

```c
    boolean letters_only = isalpha(var)? True : False;
```

becomes

```py
    letters_only = True if var.isalpha() else False
```

### Loop

- Two varieties: while and for 
```py
counter = 0
while counter w 100
    print(counter)
    counter += 1
```

```py
for x in range(0,100,2)
    print(x)
```

### Arrays

- Here's where things really start to get a lot better than C.

- Python arrays (more appropriately known as lists) are not fixed in size; they can grow or shrink as needed, and you can always tack extra elements onto your array and splice things in and out easily.

### Lists

-  Declaring a list is pretty straightforward.
```py
nums = []
nums = list()
nums = [1,2,3,4]
nums [x for x in range (500)]
```

- Tracking on to an existing list can be done in a few ways:
```py
nums = [1,2,3,4]
nums.append(5)
#or
nums.insert(4,5)
#or
nums[len(nums:)] = [5]
```

### Tuples

- Python also has a data type that is not quite like anything comparable to C, a tuple

- Tuples are ordered, immutable sets of data; they are great for associating collections of data, sort of like a struct in C, but where those values are unlikely to change. 

- Here is an exemple of tuples:
```py
presidents = [
    ("George Washington", 1789),
    ("John Adams", 1797),
    ("Thomas Jefferson", 1881),
    ("James Madison", 1809)
    ]
```

- This list is iterable as well: 
```py
for prez, year in presidents:
    print("In {1}, {0} took office". format (prez, year))
```

### Dictionaries

- Python also has built in support for dictionaries, allowing you to specify list indices with words or phrases (keys), instead of integers, which you were restricted to in C.
```py
pizzas = {
    "cheese":9;
    "pepperoni": 10,
    "vegetable": 11,
    "buffalo chicken": 12
}
```
```py
pizzas ["cheese"] = 8
```
```py
if pizza ["vegetables"] < 12:
    # do something
```

- Python also has built in support for dictionaries, allowing you to specify list indices with words or phrases (keys), instead of integers, which you were restricted to in C.

- But this creates a somewhat new problem... how do we iterate through a dictionary? We don't have indexes ranging from [0, n-1] anymore.

### Loops (redux)

- The for loop in Python is extremely flexible!
```py
for pie in pizzas:
    # use pie in here as a stand-in for "i"
```
```py
for pie, price in pizzas.items():
    print("A whole {} pizza costs ${}".format(pie, price))
```


### Printing and variable interpolation

- format gives one way to interpolate variables into our printed
statements in a very printf-like way, but there are others.
```py
print("A whole {} pizza costs ${}".format(pie, price))
```
```py
print("A whole " + pie + pizza costs $" + str(price))
```


### Functions

- Python has support for functions as well. Like variables, we don't need to specify the return type of the function (because it doesn't matter), nor the data types of any parameters (ditto).

- All functions are introduced with the def keyword.
    - Also, no need for main; the interpreter reads from top to bottom!
    - If you wish to define main nonetheless (and you might want to!), you must at the very end of your code have:
```py
if __name__ == "___main___":
    main()
```

```py
def square(x):
    result = 0
    for i in range(0, x):
        result += X
        return result
print (square (5))
```

### Objects

- Python is an object-oriented programming language.

- An object is sort of analogous to a C structure.

- C structures contain a number of fields, which we might also call properties.
    - But the properties themselves can not ever stand on their own.

- Objects, meanwhile, have properties but also methods, or functions that are inherent to the object, and mean nothing outside of it. You define the methods inside the object also.
    - Thus, properties and methods don't ever stand on their own.

- You define a type of object using the class keyword in Python.
- Classes require an initialization function, also more-generally known as a constructor, which sets the starting values of the properties of the object.
- In defining each method of an object, self should be its first parameter, which stipulates on what object the method is called.

```py
class Student():
    def __init__(self, name, id):
        self.name = name
        self.id = id
    
    def changeID(self, id):
        self.id = id

    def print (self):
        print("{} - {}".format(self.name, self.id))


jane = Student ("Jane", 10)
jane.print()
# Jane - 10
jane.changeID (11)
jane.print()
# Jane - 11
```

### Style

- If you haven't noticed, good style is crucial in Python.
- Tabs and indentation actually matter in this language, and things will not work the way you intend for them to if you disregard styling!
- Good news? No more curly braces to delineate blocks!
    - Now they just are used to declare dictionaries.

### Including files

- Just like C programs can consist of multiple files to form a single program, so can Python programs tie files together.
```py
import csv
csv.method()
```

<br>

- Python programs can be prewritten in .py files, but you can also write and test short Python snippets using the Python interpreter from the command line.
- All that is required is that the Python interpreter is installed on the system you wish to run your Python programs on.
- To run your Python program through the Python interpreter at the command-line, simply type
```
python <file>
```
- and your program will run through the interpreter, which will execute everything inside of the file, top to bottom.
- You can also make your programs look a lot more like C programs when they execute by adding a shebang to the top of your Python files, which automatically finds and executes the interpreter for you.
```
#!/usr/bin/env python3
```
- If you do this, you need to change the permissions on your file as well using the Linux command chmod as follows:
```
chmod a+x <file>
```