# Max


## Learning Goals
- Pass an array into a function
- Create a helper function that finds a maximum value

## Background

There are many situations where you’ll find it helpful to have a function that finds the maximum (and minimum) value in an array. Since there is no built-in max function in C, you’ll create one in this practice problem. You can then use it in upcoming problem sets where it may be helpful!

## Implementation Details

The main function initializes the array, asks the user to enter values, and then passes the array and the number of items to the max function. Complete the max function by iterating through every element in the array, and return the maximum value.

## Thought Question

What types of programs can you think of that might benefit from a max helper function?

## How to Test Your Code

Your program should behave per the examples below.
```
max/ $ ./max
Number of elements: 3
Element 0: 2
Element 1: 10
Element 2: -1
The max value is 10.
```
```
max/ $ ./max
Number of elements: 4
Element 0: -100
Element 1: -200
Element 2: -3
Element 3: -5000
The max value is -3.
```