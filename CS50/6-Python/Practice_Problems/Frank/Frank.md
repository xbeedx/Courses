# Frank, Ian and Glen’s Letters

[FIGlet](https://en.wikipedia.org/wiki/FIGlet), named after [Frank, Ian, and Glen’s letters](http://www.figlet.org/faq.html), is a program from the early 1990s for making large letters out of ordinary text, a form of [ASCII art](https://en.wikipedia.org/wiki/ASCII_art):
```
 _ _ _          _   _     _
| (_) | _____  | |_| |__ (_)___
| | | |/ / _ \ | __| '_ \| / __|
| | |   <  __/ | |_| | | | \__ \
|_|_|_|\_\___|  \__|_| |_|_|___/
```
Among the fonts supported by FIGlet are those at [figlet.org/examples.html](http://www.figlet.org/examples.html).

FIGlet has since been ported to Python as a module called [pyfiglet](https://pypi.org/project/pyfiglet/0.7/).

In a file called figlet.py, implement a program that:

- Expects zero or two command-line arguments:
    - Zero if the user would like to output text in a random font.
    - Two if the user would like to output text in a specific font, in which case the first of the two should be -f or --font, and the second of the two should be the name of the font.
- Prompts the user for a str of text.
- Outputs that text in the desired font.

If the user provides two command-line arguments and the first is not -f or --font or the second is not the name of a font, the program should exit via sys.exit with an error message.

## How to Test

Here’s how to test your code manually:

Run your program with python figlet.py test. Your program should exit via sys.exit and print an error message:
```
Invalid usage
```
Run your program with python figlet.py -a slant. Your program should exit via sys.exit and print an error message:
```
Invalid usage
```
Run your program with python figlet.py -f invalid_font. Your program should exit via sys.exit and print an error message:
```
Invalid usage
```
Run your program with python figlet.py -f slant. Type CS50. Your program should print the following:
```
   ___________ __________ 
  / ____/ ___// ____/ __ \
 / /    \__ \/___ \/ / / /
/ /___ ___/ /___/ / /_/ / 
\____//____/_____/\____/  
```
Run your program with python figlet.py -f rectangles. Type Hello, world. Your program should print the following:
```
 _____     _ _                        _   _ 
|  |  |___| | |___      _ _ _ ___ ___| |_| |
|     | -_| | | . |_   | | | | . |  _| | . |
|__|__|___|_|_|___| |  |_____|___|_| |_|___|
                  |_|                       
```
Run your program with python figlet.py -f alphabet. Type Moo. Your program should print the following:
```
M   M         
MM MM         
M M M ooo ooo 
M   M o o o o 
M   M ooo ooo                     
```

## [Result](https://submit.cs50.io/check50/d81057e67e9f1b1bfe3b380a35afce65ccdd2de4)