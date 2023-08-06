# [Hours](https://cs50.harvard.edu/x/2023/problems/2/hours/)

## Learning Goals
- Practice using arrays
- Using an array as a parameter to a function
- Adding values in a loop
- Integer division and type casting

## Background
Suppose you’re taking CS50 (if you’re reading this you probably are!) and spending time every week on each problem set. You may be wondering how many hours you’ve spent learning computer science, on average or in total! In this program, you’ll complete a function that calculates, based on a user’s input, a total number of hours or an average number of hours across a given number of days.

## Code
```c
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

float calc_hours(int hours[], int weeks, char output);

int main(void)
{
    int weeks = get_int("Number of weeks taking CS50: ");
    int hours[weeks];

    for (int i = 0; i < weeks; i++)
    {
        hours[i] = get_int("Week %i HW Hours: ", i);
    }

    char output;
    do
    {
        output = toupper(get_char("Enter T for total hours, A for average hours per week: "));
    }
    while (output != 'T' && output != 'A');

    printf("%.1f hours\n", calc_hours(hours, weeks, output));
}

// TODO: complete the calc_hours function
float calc_hours(int hours[], int weeks, char output)
{

}
```

## Implementation Details
The main function prompts the user for the number of weeks a user has been taking CS50, then creates an array with as many elements. Notice that, after retrieving some data, the program prompts the user to type in either “T” or “A”—”T” should (but doesn’t yet!) print the total number of hours the user entered, while “A” should (but doesn’t yet!) print the average hours the user entered. Notice that the do while loop uses toupper to capitalize the letter that’s input before it is saved in the variable output. Then, the printf function calls calc_hours. Note the syntax involved when passing an array to a function.

To complete calc_hours, first total up the hours saved in the array into a new variable. Then, depending on the value of output, return either this sum, or the average number of hours.

## Thought Question
What is the advantage of using a function to calculate hours?

## How to Test Your Code
Your program should behave per the examples below.
```
hours/ $ ./hours
Number of weeks taking CS50: 3
Week 0 HW Hours: 3
Week 1 HW Hours: 7
Week 2 HW Hours: 10
Enter T for total hours, A for average hours per week: A
6.7 hours
```
```
hours/ $ ./hours
Number of weeks taking CS50: 2
Week 0 HW Hours: 2
Week 1 HW Hours: 8
Enter T for total hours, A for average hours per week: T
10.0 hours
```

