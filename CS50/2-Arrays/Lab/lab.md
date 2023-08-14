# [Lab 2: Scrabble](https://cs50.harvard.edu/x/2023/labs/2/)


## Background

In the game of Scrabble, players create words to score points, and the number of points is the sum of the point values of each letter in the word.

<table class="table table-bordered table-striped">
  <thead><tr><th style="" data-field="0"><div class="th-inner "><div style="text-align: left">A</div></div><div class="fht-cell"></div></th><th style="" data-field="1"><div class="th-inner "><div style="text-align: left">B</div></div><div class="fht-cell"></div></th><th style="" data-field="2"><div class="th-inner "><div style="text-align: left">C</div></div><div class="fht-cell"></div></th><th style="" data-field="3"><div class="th-inner "><div style="text-align: left">D</div></div><div class="fht-cell"></div></th><th style="" data-field="4"><div class="th-inner "><div style="text-align: left">E</div></div><div class="fht-cell"></div></th><th style="" data-field="5"><div class="th-inner "><div style="text-align: left">F</div></div><div class="fht-cell"></div></th><th style="" data-field="6"><div class="th-inner "><div style="text-align: left">G</div></div><div class="fht-cell"></div></th><th style="" data-field="7"><div class="th-inner "><div style="text-align: left">H</div></div><div class="fht-cell"></div></th><th style="" data-field="8"><div class="th-inner "><div style="text-align: left">I</div></div><div class="fht-cell"></div></th><th style="" data-field="9"><div class="th-inner "><div style="text-align: left">J</div></div><div class="fht-cell"></div></th><th style="" data-field="10"><div class="th-inner "><div style="text-align: left">K</div></div><div class="fht-cell"></div></th><th style="" data-field="11"><div class="th-inner "><div style="text-align: left">L</div></div><div class="fht-cell"></div></th><th style="" data-field="12"><div class="th-inner "><div style="text-align: left">M</div></div><div class="fht-cell"></div></th><th style="" data-field="13"><div class="th-inner "><div style="text-align: left">N</div></div><div class="fht-cell"></div></th><th style="" data-field="14"><div class="th-inner "><div style="text-align: left">O</div></div><div class="fht-cell"></div></th><th style="" data-field="15"><div class="th-inner "><div style="text-align: left">P</div></div><div class="fht-cell"></div></th><th style="" data-field="16"><div class="th-inner "><div style="text-align: left">Q</div></div><div class="fht-cell"></div></th><th style="" data-field="17"><div class="th-inner "><div style="text-align: left">R</div></div><div class="fht-cell"></div></th><th style="" data-field="18"><div class="th-inner "><div style="text-align: left">S</div></div><div class="fht-cell"></div></th><th style="" data-field="19"><div class="th-inner "><div style="text-align: left">T</div></div><div class="fht-cell"></div></th><th style="" data-field="20"><div class="th-inner "><div style="text-align: left">U</div></div><div class="fht-cell"></div></th><th style="" data-field="21"><div class="th-inner "><div style="text-align: left">V</div></div><div class="fht-cell"></div></th><th style="" data-field="22"><div class="th-inner "><div style="text-align: left">W</div></div><div class="fht-cell"></div></th><th style="" data-field="23"><div class="th-inner "><div style="text-align: left">X</div></div><div class="fht-cell"></div></th><th style="" data-field="24"><div class="th-inner "><div style="text-align: left">Y</div></div><div class="fht-cell"></div></th><th style="" data-field="25"><div class="th-inner "><div style="text-align: left">Z</div></div><div class="fht-cell"></div></th></tr></thead>
  <tbody><tr data-index="0"><td>1</td><td>3</td><td>3</td><td>2</td><td>1</td><td>4</td><td>2</td><td>4</td><td>1</td><td>8</td><td>5</td><td>1</td><td>3</td><td>1</td><td>1</td><td>3</td><td>10</td><td>1</td><td>1</td><td>1</td><td>1</td><td>4</td><td>4</td><td>8</td><td>4</td><td>10</td></tr></tbody>
</table>

For example, if we wanted to score the word Code, we would note that in general Scrabble rules, the C is worth 3 points, the o is worth 1 point, the d is worth 2 points, and the e is worth 1 point. Summing these, we get that Code is worth 3 + 1 + 2 + 1 = 7 points.


## Implementation Details

Complete the implementation of scrabble.c, such that it determines the winner of a short scrabble-like game, where two players each enter their word, and the higher scoring player wins.

- Notice that we’ve stored the point values of each letter of the alphabet in an integer array named POINTS.
    - For example, A or a is worth 1 point (represented by POINTS[0]), B or b is worth 3 points (represented by POINTS[1]), etc.
- Notice that we’ve created a prototype for a helper function called compute_score() that takes a string as input and returns an int. Whenever we would like to assign point values to a particular word, we can call this function. Note that this prototype is required for C to know that compute_score() exists later in the program.
- In main(), the program prompts the two players for their words using the get_string() function. These values are stored inside variables named word1 and word2.
- In compute_score(), your program should compute, using the POINTS array, and return the score for the string argument. Characters that are not letters should be given zero points, and uppercase and lowercase letters should be given the same point values.
    - For example, ! is worth 0 points while A and a are both worth 1 point.
    - Though Scrabble rules normally require that a word be in the dictionary, no need to check for that in this problem!
- In main(), your program should print, depending on the players’ scores, Player 1 wins!, Player 2 wins!, or Tie!.


## How to Test Your Code
Your program should behave per the examples below.

```
$ ./scrabble
Player 1: Question?
Player 2: Question!
Tie!
```
```
$ ./scrabble
Player 1: Oh,
Player 2: hai!
Player 2 wins!
```
```
$ ./scrabble
Player 1: COMPUTER
Player 2: science
Player 1 wins!
```
```
$ ./scrabble
Player 1: Scrabble
Player 2: wiNNeR
Player 1 wins!
```