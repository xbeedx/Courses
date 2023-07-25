# [Debug](https://cs50.harvard.edu/x/2023/problems/1/debug/)

## Learning Goals

- Become familiar with C syntax
- Learn what C compiler error messages mean
- Get practice debugging

![Bug](https://cs50.harvard.edu/x/2023/problems/1/debug/first_bug.jpg)

## Background

There are two kinds of errors that can occur when writing a program. The first errors you are likely to encounter are **syntactical** errors. In addition to syntactical errors, there can also be logical errors, which we’ll take a look at soon.

In computer science, syntax is important for a computer to understand what you are telling it to do. Each programming language has its own syntactical rules, which include the combination of both words and punctuation.

This lab starts with distribution code which has several syntactical errors. The idea is for you to try to compile (make) the program, learn to interpret the rather cryptic error messages output by the compiler, and debug the program.

## Code
```c
// Become familiar wih C syntax
// Learn to debug buggy code

#include <cs50.h>

int main(void)
{
    // Ask for your name and where live
    name = get_string("What is your name? ")
    location = get_string("Where do you live? ")

    // Say hello
    print("Hello, %i, from %i!", name, location)
}
```

## How to Test Your Code

Your program should behave per the examples below.
```c
debug/ $ ./debug
What is your name? Carter
Where do you live? Cambridge
Hello, Carter, from Cambridge!
```
```c
debug/ $ ./debug
What is your name? Margaret
Where do you live? New York
Hello, Margaret, from New York!
```

