# Recursive atoi

## Background

Imagine that you travel back in time to the 1970’s, when the C programming language was first created. You are hired as a programmer to come up with a way to convert strings to ints. (You may have used a function just like this in Week 2, called atoi). You want to be thorough in your development process and plan to try several approaches before deciding on the most efficient.

In this problem, you will start with a simple implementation of atoi that handles positive ints using loops. You want to rework this into an implementation that uses recursion. Recusive functions can be memory intensive and are not always the best solution, but there are some problems in which using recursion can provide a simpler and more elegant solution.

## Implementation Details

In the recursive version of convert, start with the last char and convert it into an integer value. Then shorten the string, removing the last char, and then recursively call convert using the shortened string as input, where the next char will be processed.

## Thought Question

Why do you need a base case whenever you create a recursive function?

## How to Test Your Code

Your program should behave per the examples below.
```
atoi/ $ ./atoi
Enter a positive integer: 3432
3432
```
```
atoi/ $ ./atoi
Enter a positive integer: 98765
98765
```

## A More Thorough Implementation
The actual version of atoi must handle negative numbers, as well as leading spaces and non-numeric characters. It might look something like this:
```c
#include <stdio.h>
 
// Iterative function to implement `atoi()` function in C
long atoi(const char S[])
{
    long num = 0;
    int i = 0, sign = 1;
 
    // skip white space characters
    while (S[i] == ' ' || S[i] == '\n' || S[i] == '\t') {
        i++;
    }
 
    // note sign of the number
    if (S[i] == '+' || S[i] == '-')
    {
        if (S[i] == '-') {
            sign = -1;
        }
        i++;
    }
 
    // run till the end of the string is reached, or the
    // current character is non-numeric
    while (S[i] && (S[i] >= '0' && S[i] <= '9'))
    {
        num = num * 10 + (S[i] - '0');
        i++;
    }
 
    return sign * num;
}
 
// Implement `atoi()` function in C
int main(void)
{
    char S[] = " -1234567890";
 
    printf("%ld ", atoi(S));
 
    return 0;
}
```

From [techiedelight.com/implement-atoi-function-c-iterative-recursive](https://www.techiedelight.com/implement-atoi-function-c-iterative-recursive/).