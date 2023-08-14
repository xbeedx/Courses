# [Half](https://cs50.harvard.edu/x/2023/problems/1/half/)

# Learning Goals
- Work with different data types
- Practice type casting
- Use math operations
- Create a function with input parameters and return value

## Background
Suppose you are eating out at a restaurant with a friend and want to split the bill evenly. You may want to anticipate the amount you’ll owe before the bill arrives with tax added. In this problem, you’ll complete a function to calculate the amount each of you owes based on the bill amount, the tax, and the tip.

## Code 

You are to complete the function, *half*, which calculates exactly half of the bill after tax and tip are added, and returns that value.

```c
// Calculate your half of a restaurant bill
// Data types, operations, type casting, return value

#include <cs50.h>
#include <stdio.h>

float half(float bill, float tax, int tip);

int main(void)
{
    float bill_amount = get_float("Bill before tax and tip: ");
    float tax_percent = get_float("Sale Tax Percent: ");
    int tip_percent = get_int("Tip percent: ");

    printf("You will owe $%.2f each!\n", half(bill_amount, tax_percent, tip_percent));
}

// TODO: Complete the function
float half(float bill, float tax, int tip)
{
    return 0.0;
}
```

## Implementation Details

Your function should use the input parameters, bill, tax, and tip, to calculate the final amount. However, since these values are percentages, you’ll have to do some work to convert these to more appropriate formats to use for your calculation.

The tax should be added to the bill amount before calculating the tip. Finally, you will return exactly half of the full amount, including the bill amount, the tax and the tip.

# How to Test Your Code

Your program should behave per the examples below.
```c
half/ $ ./half
Bill before tax and tip: 12.50
Sale Tax Percent: 8.875
Tip percent: 20
You will owe $8.17 each!
```
```c
half/ $ ./half
Bill before tax and tip: 23.50
Sale Tax Percent: 7  
Tip percent: 15
You will owe $14.46 each!
```
```c
half/ $ ./half
Bill before tax and tip: 100
Sale Tax Percent: 6.25
Tip percent: 18
You will owe $62.69 each!
```