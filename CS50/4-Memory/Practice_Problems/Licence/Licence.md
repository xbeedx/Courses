# License


## Learning Goals

- Practice working with files and file pointers
- More work with strings and arrays
- Debugging with debug50
- Use valgrind to check for memory leaks


## Background

Suppose you work for a company that develops AI-enhanced license plate recognition technology. As you develop your technology, you may want to use actual license plate numbers as test data. You have a text file with some plate numbers you want to analyze, so you first try reading from that text file and printing out the license plates, to test your file-reading logic. But when you run your program, only the last number prints 8 times! What went wrong?


## Implementation Details

If you open the plates.txt file, you’ll notice that there are actually 8 different license plate numbers. There are a few errors in the distribution code that are causing this to happen. Let’s start by walking through the code.

We first check for command-line arguments, since argv[1] should be the text file that contains the license plates. We then create a character array of length 7, since the plate numbers are 6 chars long and we need to save space for the NUL terminator. Now we create an array of char *’s (character pointers, otherwise known as strings!) to store the 8 plate numbers. We create a file pointer to our external text file, create a variable to hold the index of each array element, and begin reading the file and saving the plate numbers to the array. Finally, to test that we did this correctly, we print out the values in the array.

However, when we compile and execute this code, something is clearly wrong. You’ll need to make the appropriate corrections!

### Debugging

Take a close look at what values are actually being added to the array. You can experiment with debug50 to find the error in the distribution code.

Is there a better way to copy license plate numbers to the license array?

### Checking for Memory Leaks

Once your program seems to be working properly, run valgrind to make sure there are no memory leaks.
```
valgrind ./license plates.txt
```
You may end up with something like this:
```
==24478== HEAP SUMMARY:
==24478==     in use at exit: 528 bytes in 9 blocks
==24478==   total heap usage: 10 allocs, 1 frees, 4,624 bytes allocated
==24478== 
==24478== 56 bytes in 8 blocks are definitely lost in loss record 1 of 2
==24478==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==24478==    by 0x109207: main (license.c:30)
==24478== 
==24478== 472 bytes in 1 blocks are still reachable in loss record 2 of 2
==24478==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==24478==    by 0x4A086CD: __fopen_internal (iofopen.c:65)
==24478==    by 0x4A086CD: fopen@@GLIBC_2.2.5 (iofopen.c:86)
==24478==    by 0x1091CD: main (license.c:20)
==24478== 
==24478== LEAK SUMMARY:
==24478==    definitely lost: 56 bytes in 8 blocks
==24478==    indirectly lost: 0 bytes in 0 blocks
==24478==      possibly lost: 0 bytes in 0 blocks
==24478==    still reachable: 472 bytes in 1 blocks
==24478==         suppressed: 0 bytes in 0 blocks
==24478== 
==24478== For lists of detected and suppressed errors, rerun with: -s
==24478== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
```
There seem to be two kinds of memory errors here that need to be corrected!


## How to Test Your Code

Your program should behave per the examples below.
```
license/ $ ./license plates.txt
11ZT00
1KAD21
78ZZ01
99ZZ11
72ZZ21
98ZZ31
44ZW41
34ZZ51
```

## [Result](https://submit.cs50.io/check50/14ad6d8e1f075519315be4b79a5fa9be9fee31d2)

```
==28717== HEAP SUMMARY:
==28717==     in use at exit: 0 bytes in 0 blocks
==28717==   total heap usage: 10 allocs, 10 frees, 4,624 bytes allocated
==28717== 
==28717== All heap blocks were freed -- no leaks are possible
==28717== 
==28717== For lists of detected and suppressed errors, rerun with: -s
==28717== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```