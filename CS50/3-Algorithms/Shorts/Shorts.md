# Shorts

Table of contents
<br>\=================
- [Search](#search)
  - [Linear Search](#linear-search)
  - [Binary Search](#binary-search)
- [Sort](#sort)
    - [Bubble Sort](#bubble-sort)
    - [Selection Sort](#selection-sort)
    - [Merge Sort](#merge-sort)
- [Recursion](#recursion)

# Search

## Linear Search
[Video](https://www.youtube.com/watch?v=TwsgCHYmbbA&feature=youtu.be)

In linear seach, the idea of the algorithm is to iterate across the arrya from left to right, searching for a specified element 

*In pseudocode:*
> - Repeat, starting at the first element :
>    - If the first element is equal to the element we are looking for(the target), stop
>    - Else, move to the next element

Worst-case scenario: We have to look through the entire array of n elements, either because the target element is the last element of the array or doesn't exist in the array at all. => O(n)

Best-case scenario: The target element is the first element of the array, and so we can stop looking immediately after we start. => Ω(1)


## Binary Search
[Video](https://youtu.be/T98PIp4omUA)

In binary search the idea of the algorithm is to divide and conquer, reducing the search area by half each time, trying to find a target number. 
> In order to leverage this power however, our array must first be sorted, else we can't make assumptions about the array's content. 

*In pseudocode:*
> - Repeat until the (sub)array is of size 0
>    - Calculate the middle point of the current (sub)array
>    - If the target is at the middle, stop
>    - Otherwise, if the target is less than what's at the middle, repeat, changing the end point to be just to the left of the middle
>    - Otherwise, if the target is greater than what's at the middle, repeat, changing the start point to be just to the right of the middle

Worst-case scenario: we have to divide a list of n elements in half repeatedly to find the target element, either because the target element will be found at the end of the last division or doesn't exist in the array at all. => O(log n)

Best-case scenario: The target element is at the midpoint of the fulla rray, and so we can stop looking immediately after we start. => Ω(1)


# Sort

## Bubble Sort
[Video](https://youtu.be/RT-hUXUWQ2I)

In bubble sort, the idea of the algorithm is to move higher valued elements generally generally towards the right and lower value elements generally towards the left. 

*In pseudocode:*
> - Set swap counter to a non zero value
> - Repeat until the swap counter is 0:
>    - Reset swap counter to 0
>    - Look at each adjacent pair
>       - If two adjacent elements are not in order, swap them and add one to the swap counter

Worst-case scenario: The array is in reverse order; we have to "bubble" each of the n elements all the way across the array; and since we can only fully bubble one element into position per pass, we must do this n times. => O(n^2)

Best-case scenario: The array is already perfectly sorted, and we make no swaps on the first pass. => Ω(n) 

## Selection Sort
[Video](https://youtu.be/3hH8kTHFw2A)

In selection sort, the idea of the algorithm is to find the smallest unsorted element and add it to the end of the sorted list.

*In pseudocode:*
> - Repeat until no unsorted elements remain:
>    - Search the unsorted part of the data to find the smallest value
>    - Swap the smallest found value with the first element of the unsorted part

Worst-case scenario: We have to iterate over each of the n the elements of the array (to find the smallest unsorted element) and we must repeat thos process n times, since only one element get sorted on each pass. => O(n^2)

Best-case scenario: Exactly the same! There's no way to guarantee the array is sorted until we go through this process for all elements. => Ω(n^2)

## Merge Sort
[Video](https://youtu.be/Ns7tGNbtvV4)

In merge sort, the idea of the algorithm is to sort smaller arrays and then combine those arrays together (merge them) in sorted order.

Merge sort leverages something called *recursion*.

*In pseudocode:*
> - Sort the left half of the array (assuming n>1)
> - Sort the right half of the array (assuming n>1)
> - Merge the two halves together

Worst-case scenario: We have to split n elements up and then recombine them, effectively doubling the sorted subarrays as we build them up. (combining sorted 1-element arrays into 2-element arrays, combininb 2-element arrays into 4-element arrays...) => O(n log n)

Best-case scenario: The array is already perfectly sorted. But we still have to split and recombine it back together with this algorithm. => Ω(n log n)


# Recursion 
[Video](https://youtu.be/mz6tAJMVmfM)

We might describe an implementation of an algorithm as being particularly "elegent" if it solves a problem in a way that is both interesting and easy to visualize.

The technique of **recursion** is a very common way to implement such an "elegent" solution. 

The definition of a recursive function is one that, as a part of its execution, invokes itself. 

### Factorial

The factorial function (n!) is definied over all positive integers. 

n! equals all of the positive integers less than or equal to n, multiplied together.

Thinking of term of programming , we'll define the mathematical function n! as fact(n).
```
fact(n) = n * fact(n-1)
```

This forms the basis for a recursive definition of the factorial function. 

Every recursive function has two cases that could pply, given any input.
- The base case, which when triggered will terminate the recursive process. 
- The recursive case, which is where the recursion will always occur. 

```c
int fact(int n)
{
    if(n == 1)
    {
        return 1;
    }

    return n * fact(n-1);
}
```

In general, but not always, recursive functions replace loops in non-recursive functions. 

It's also possible to have more than one base or recursive case, If the program might recurse or terminate in different ways, depending on the input being passed in.  

**Multiple base cases:** The Fibonacci number sequence is defined as follows:
- The first element is 0.
- The second element is 1.
- The nth element is the sum of the (n-1)th and (n-2)th elements. 

**Multiple recursive cases:** The Collatz conjecture.

### Collatz conjecture

The Collatz conjectureis applies to positive integers and speculates that it is always possible to get "back to 1" if you follow these steps:
- If n is 1, stop.
- Otherwise, if n is even, repeat the process on n/2.
- Otherwise, if n is odd, repeat the process on 3n+1.
