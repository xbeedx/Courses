# Shorts

Table of contents
<br>\=================
- [Data Types](#data-types)
- [Variables](#variables)
- [Operators](#operators)
- [Boolean expressions](#boolean-expressions)
- [Conditional](#conditional)
- [Loops](#loops)
- [Command Line](#command-line)

# Data Types
[Video](https://youtu.be/Fc9htmvVZ9U)

> int
>> The int data type is used for variables that will store integers. <br><br>
>> Integers always take up 4 bytes of memory (32 bits). This mean the range of values they can stores is necessarily limitied to 32 bits worth of information. 
>> ## Integer Range : 
>> -2^31 ---------------- 0 ---------------- 2^31 - 1 

> unsigned int
>> Unsigned is a qualifier that can be appplied to certain types (including int), which effectively doubles the positive range of variables of that type, at the cost of disallowing any negative values.
>> ## Unsigned Integer Range : 
>> 0 ---------------- 2^31 ---------------- 2^32 - 1 

> float
>> The float data type is used for variables that will store floating-point values, also known as real numbers.<br><br>
>> Floating point values always take up 4 byte of memeory (32 bits).<br><br>
>> It's a little complicated to describe the range of float, but suffice it to say with 32 bits of precision, some of which might be used for an integer part, we are limited on how precise we can be, 

> double
>> The double data type is used for variables that will store floating-point values, also known as real numbers.<br><br>
>> The difference is that doulbes are double precision. They always take up 8 bytes of memory (64 bits)<br><br>
>> With an addition 32 bits of precision relative to a float, doubles allow us to specify much more precise real numbers. 

> void
>> Is a type but not a data type.<br><br>
>> Functions can have a void return type, which just mean they don't return a value. <br><br>
>> The parameter list of a function can also be void. It simply means the function takes no parameter. <br><br>
>> For now, think of void as more as a placeholder for "nothing" . It's more complex than that.

# Variables

## Creating a variable
To bring a variable into existence, you need simply specify the data type of the variable and give it a name 
```c
int number;
char letter;
```
If you wish to create multiple variables of the same type, you specify the type name once, and then list as many of that type as you want.
```c
int height, width;
float sqrt2, sqrt3, pi;
```

## Using a variable 
After a variable is declared, it's no longer necessary to specify that variable's type. 
```c
int number;     //declaration
number = 17;    //assignement
char letter;    //declaration
letter = 'H';   //assignement
```
If you are simultaneously declaring and setting the value of a variable (sometimes called initializing), you can consolidate this to one step. 
```c
int number = 17;    //initialization
char letter = 'H';  //initialization
```


# Operators 
[Video](https://youtu.be/f1xZf4iJDWE)

In C we can add (+), substract (-), multiply (*) and divide (/) numbers, as expected. 
```c
int x = y + 1;
x = x * 5;
```
<br>

We also have the modulus operator (%), which gives us the remainder when the number on the left of the operator is divided by the number on the right. 
```c
int m = 13 % 4; // m is now 1 
```
<br>

C is also provides a shorthand way to apply an arithmetic operator to a single variable. 
```c
x = x * 5;
x *= 5;
```
This trick works with all five basic arithmetic operators. C proives a further shorthand for incrementing or decrementing a variable by 1. 
```c
x++;
x--;
```
<br>

# Boolean expressions 

Boolean expressions are used in C for comparing values. 

All boolean expressions in C evaluate one of two possible values - true or false 

We can use the result of evaluating a boolean expression in other programming constructs such as deciding which branch ina conditional to take, or determining wheter a loop should continue to run. 

Sometimes when working with boolean expressions we will use variables of type bool, but we don't have to. 


In C, every nonzero value is equivalent to true, and zero is false. 

Two main type s of Boolean expressions: logical operators and relational operators. 

##  Logical operators

Logical AND (&&) is true if and only if both operands are true, otherwise false. 

|   x   |   y   |   (x && y)   |
|-------|-------|--------------|
| true  | true  |     true     |
| true  | false |     false    |
| false | true  |     false    |
| false | false |     false    |

Logical OR (||) is true if and only if at least one operands is true, otherwise false. 

|   x   |   y   |   (x \|\| y)   |
|-------|-------|--------------|
| true  | true  |     true     |
| true  | false |     true     |
| false | true  |     true     |
| false | false |     false    |

Logical NOT (!) inverts the value of its operand. 

|   x   |   !x   |
|-------|--------|
| true  | false  |
| false | true   |


##  Relational operators

The behave as you would expect them to, and appear syntactically similar to how you may recall them from elementary arithmetic.
- Less than (x < y)
- Less than or equal to (x <= y)
- Greater than (x>y)
- Greater than or equal to (x >= y)

C can also test two variables for equality nd inequality 
- Equality (x == y)
- Inequality (x != y)

# Conditional 
[Video](https://youtu.be/1wsaV5nVC7g)

Conditional expressions allow your programs to make decisions and take different forks in the road, depending on the values of variables, or based on what the user inputs. 

C provides a few different ways to implement conditional expressions (also known as branches) in your programs.

```c
if (boolean-expression){

}
```

If the boolean-expression evaluates to  true, then all the lines of code between the curly braces will execute in order from top to bottom. 

If the boolean-expression evaluate to  false, those lines of code will not execute. 
```c
if (boolean-expression){

} else {

}
```

If the boolean-expression evaluates to  true,  all the lines of code between the first set of curly braces will execute in order from top to bottom. 

If the boolean-expression evaluate to  false, all the lines of code between the second set of curly braces will execute in order from top to bottom. 
```c
if (boolean-expr1){
    //first branch
} else if (boolean-expr2){
    //second branch
} else if (boolean-expr3){
    //third branch
} else {
    //fourth branch
} 
```
in C it's possible to create an if-else if-else chain

Each branch is mutually exclusive

```c
if (boolean-expr1){
    //first branch
} 
if (boolean-expr2){
    //second branch
}
if (boolean-expr3){
    //third branch
} else {
    //fourth branch
} 
```
It's also possible to create a chain of non-mutually exclusive branches. 

```c
int x; 
switch(){
    case 1:
        printf("One!\n");
        break;
    case 2:
        printf("Two!\n");
        break;
    case 3:
        printf("Three!\n");
        break;
    default:
        printf("Sorry!\n");
        break;
}
```

Switch() statement is a conditional tatement that permits enumeration of discrete cases, instead of relying on boolean expressions. 

It's important to break; between each cases, or you will "fall through" each case (unless that is desire behavior).

## ?:

```c
int x;
if (expr) {
    x = 5
} else {
    x = 6;
}
```
```c
int x = (expr) ? 5 : 6;
```

These two snippets of code act identically

The ternary operator (?:) is mostly a cute trick, but is useful for writting trivially short conditional branches. 

# Loops
[Video](https://youtu.be/WgX8e_O7eG8)

Loops allow our programs to eexcute lines of code repeatedly, saving you from having to copy and paste or otherwise repeat lines of code. 

```c
while(true){

}
``` 

This is what we call an infinite loop. These lines of code between the curly braces will execute repeatedly from top to bottom, until and unless we break out of it or otherwhise kill our program. 

```c
while(boolean-expr){

}
``` 

If the boolean-expr evaluates to true all the lines of code between the curly braces will execute repeatedly, in order from top to bottom, until boolean-expr evaluates to false.

```c
do{

}while(boolean-expr)
``` 

The loop will execute all the lines of code between the curly braces once, and the, if boolean-expr evaluates to true, will go back and repeat that process until boolean-expr evaluates to false. 


```c
for(start; expr; increment){

}
``` 

Syntactically unatractive, but for loops are used to repeat the body of a loop a specified number of times, in this example 10. 

The process undertaken in a for loop is : 
- The statement(s) in start are executed
- The expr is checked 
    - If it evaluates to true, the body of the loops executes. 
    - If it evaluates to false, the body of the loop does not execute. 
- The statement(s) in increment are executed, and then the expr is checked again, etc...

> while <br>
> Use when you want a loop to repeat an unknown number of times, and possibly not at all.

> do-while <br>
> Use when you want a loop to repeat an unknown number of times, but at least once.

> for <br>
> Use when you want a loop to repeat a discrete number of times, though you may not know the number at the moment the program is compiled. 

# Command Line

[Video](https://youtu.be/BnJ013X02b8)

The following commands are working for any UNIX-based system 

> ls <br><br>
> Short for "list", this command will give you a readout of all the files and folders in your current directory

> cd \<directory> <br><br>
> Short for "change directory", this command changes your current directory to \<directory>, which you specify, in your workspace or on your operating system. <br><br>
> The shorthand name for the current directory is . <br><br>
> The shorthand name for the parent directory of the current directory is .. <br><br>
> If ever curious about the name of the current directory, though the terminal prompt will often tell you, you wan type pwd (present working directory)

> mkdir \<directory> <br><br>
> Short for "make directory", this command will create a new subdirectory called \<directory> located in the current directory

> cp \<source> \<destination> <br><br>
> Short for "copy", this command will allow you to create a duplicate of the file you specify as \<source>, which it will save in  \<destination>. <br><br>
> If you wish to copy entire directories, you'll need to modify the command slightly: <br><br>
> cp -r \<source directory> \<destination directory> <br>
> The "-r" stands for recursive, and tells cp to dive down into the directory and copy everything inside of it (including any subdirectories it might contain).

> rm \<file> <br><br>
> Short for "remove", this command will delete \<file> after it asks you to confirm (y/n) you want to delete it. <br><br>
> You can skip the confirmation by typing:<br>
> rm -f\<file> <br>
> But use at your own peril! There's no undo. <br><br>
> To delete the entire directories you need to use the -r flag. <br>
> rm -r \<directory> <br><br>
> You can also combine the -r and -f flags into -rf.