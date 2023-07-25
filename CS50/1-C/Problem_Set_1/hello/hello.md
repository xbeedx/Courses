# [Hello](https://cs50.harvard.edu/x/2023/psets/1/hello/)

## Getting Started

Start by clicking inside your terminal window, then execute cd by itself. You should find that its “prompt” resembles the below.

```
$
```
Click inside of that terminal window and then type

```
mkdir hello
```

followed by Enter in order to make a directory called hello in your codespace. Take care not to overlook the space between mkdir and hello or any other character for that matter!

Here on out, to execute (i.e., run) a command means to type it into a terminal window and then hit Enter. Commands are “case-sensitive,” so be sure not to type in uppercase when you mean lowercase or vice versa.

Now execute
```
cd hello
```
to move yourself into (i.e., open) that directory. Your prompt should now resemble the below.
```
hello/ $
```
If not, retrace your steps and see if you can determine where you went wrong!

Shall we have you write your first program? Execute
```
code hello.c
```
to create a new file called **hello.c**, which should open automatically in your codespace’s text editor. As soon as you save the file with command-S (on macOS) or control-S (on Windows), it should also appear in your codespace’s explorer.

Proceed to write your first program by typing precisely these lines into **hello.c**:
```c
#include <stdio.h>

int main(void)
{
    printf("hello, world\n");
}
```
<sub>Notice how VS Code adds “syntax highlighting” (i.e., color) as you type, though VS Code’s choice of colors might differ from this problem set’s. Those colors aren’t actually saved inside of the file itself; they’re just added by VS Code to make certain syntax stand out. Had you not saved the file as hello.c from the start, VS Code wouldn’t know (per the filename’s extension) that you’re writing C code, in which case those colors would be absent.<sub>

## Listing Files

Next, in your terminal window, immediately to the right of the prompt (hello/ $), execute

```
ls
```

You should see just **hello.c**! That’s because you’ve just listed the files in your **hello** folder. In particular, you executed a command called **ls**, which is shorthand for “list.” (It’s such a frequently used command that its authors called it just **ls** to save keystrokes.) Make sense?

## Compiling Programs

Now, before we can execute the hello.c program, recall that we must compile it with a compiler, translating it from source code into machine code (i.e., zeroes and ones). Execute the command below to do just that:
```
make hello
```
And then execute this one again:
```
ls
```
This time, you should see not only hello.c but hello listed as well? You’ve now translated the source code in hello.c into machine code in hello.

Now execute the program itself by executing the below.
```
./hello
```
Hello, world, indeed!

## Getting User Input

Suffice it to say, no matter how you compile or execute this program, it only ever prints hello, world. Let’s personalize it a bit, just as we did in class.

Modify this program in such a way that it first prompts the user for their name and then prints hello, **so-and-so**, where **so-and-so** is their actual name.

As before, be sure to compile your program with:
```
make hello
```
And be sure to execute your program, testing it a few times with different inputs, with:
```
./hello
```