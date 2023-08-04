# Shorts

Table of contents
<br>\=================

# Functions
[Video](https://youtu.be/n1glFqt3g38)

> C and nearly all languages developed since allow us to rite functions, sometimes also known as procedures, methods or subroutines.

### What is a function ? 
> -  black box with a set of 0+ inputs and 1 output 
> ![function](./images/function)

### Why call it a black box ? 
> - If we aren't writing the functions ourselves, we don't need to know the underlying implementation.
> - That's part of the contract of using functions. The behavior is typically predictable based on that name. That's why most functions have clear, obvious(ish) names, and are well-documented. 

### Why use functions ? 
> - Organization
>   - Functions help break up a complicated problem into more managable subparts.
> - Simplification
>   - Smaller components tends to be easier to design, implement and debug.
> - Reusability 
>   - Functions can be recycled; you only need to write them once, but cna use them as often as you need!

### Function Declaration 
> The first step to declare a function is to declare it. This gives the compiler a heads-up that a user-writter function appears in the code. <br><br>
> Function declaration should always go atop the code, before writing main().<br><br>
> There is a stand form that every function declaration follows:<br><br>
>  return-type name(argument-list);
> - The return-type is what kind of variable the function will output. 
> - The name is what you want to call your function 
> - The argument-list is the comma-separated set of inputs to your function, each of which has a type and a name. 

> The second step to creating a functio is to define it. This allopws for predictable behavior when the function is called with inputs. 

### Function Calls
> To call a function, simply pass it appropriate arguments nd assign its return value to something of the correct type. 

### Function Miscellany 
> Functions can sometimes take no inputs. In that case, we declare the function as having a void argument list. <br><br>
> Functions sometimes do not have an output.  In that case, we declare the function as having a void return type. <br><br>

# Variable and Scope
[Video](https://youtu.be/GiFbdVGjF9I) 

> - Scope is a characteristic of a a variable that defines from which functions that variable may be accessed. <br><br>
>   - Local variables can only be accessed from the functions in which they are created. <br><br>
>   - Global variables can be accessed by any function in the program.

### why does this distinction matter ?
> For the most part, local variables in C are passed by value in function calls. <br><br>
> When  a function is passe by value, the callee receives a copy of the passed variable, not the variable itself. <br><br>
> That means that the variable in the caller is unchanged unless overwritten. 

# Debugging (“Step through”)
[Video](https://youtu.be/---HbbANxDQ)

# Duplicate of 'Debugging (“Step into”)'
[Video](https://youtu.be/tk3cl8hyfqM)

# Arrays
[Video](https://youtu.be/K1yC1xshF40)

> Arrays are fundamental data structure. <br><br>
> We use arrays to hold values of the same type at contiguous memory locations. <br><br>
> An array is  block of contiguous space in memory ...<br>
> which has been partitioned into small, identically-sized blocks of space called elements ...<br>
> each of which can store a certain amount of data ...<br>
> all of the same data type ... <br>
> and which can be accessed directly by an index.

> In C, the elements of an array are indexed strating from 0. 
> - If an array consists of n elements, the first element is located at index 0. And the last at index n-1. 
> - C is very lenient. It will not prevent you from going "out of bounds" of your array. 

### Arrays Declaration 
```c
type name[size];
```
> - The type is what kind of variable each element of the array will be.
> - The name is what you want to call your array. 
> - The size is how many elements you would like your array to contain. 

> When declaring and initializing an array simultaneously ,there is a special syntax that may be used to fill up the array with its starting values :
> bool truthtable[3] = {false, true, true};

### Arrays Dimensions
> Arrays can consist of more than a single dimension. You can have as many size specifiers as you wish. <br><br>
```c
bool battleship[10][10];
```
> You can choose to think of this as either a 10x10 grid of cells 
> - In memory though, It's really just a 100-element one-dimensional array
> - Multi-dimensional arrays are great abstractions to help visualize game boards or other complex representations. 

> While we can treat individual elements of arrays as variables, we can't treat entire arrays themselves as variables. <br><br>
> We cannot, for instance, asign one array to another using the assignement operator. That is not legal in C. <br>
> Instead, we must use a loop to copy over the elements one at a time. 

> Most variables in C are passed by value in function calls. <br><br>
> Arrays do not follow this rule. Rather, they are passed by reference. The callee receives the actual array, not a copy of it. 

# Command Line Arguments
[Video](https://youtu.be/AI6Ccfno6Pk)

> If we want the user to provide data to our program before the program strats running, we need a new form. 

> To collect so called command-line arguements from the user, declare main as:
```c
int main(int argc, string argv[])
```
> These two special arguments enabele you to know what data the user provided at the command line and how much data they provided. 

> argc (argument count)
> > This integer-type variable will store the number of command-line arguments the user typed when the program was executed. 

|      Command       |    argc    |
|--------------------|------------|
| ./greedy           |      1     |
| ./greedy 1024 cs50 |      3     |

> argv (argument vector)
> > This array of strings stores, one string per element, the actual text the used typed at the command-line when the program was executed. <br><br>
> > The first element of argv is always found at argv[0]. The last element of argv is always found at argv[argc-1].