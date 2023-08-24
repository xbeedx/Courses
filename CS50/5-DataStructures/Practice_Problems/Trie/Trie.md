# Trie

## Background

Imagine you just rescued a dog and you’re deciding on a name. You found a file online with a list of about 150 of the most popular dog names! You are curious as to whether or not the names you are considering are on this list. Since trie’s are great for data lookups, we’ve given you some (almost!) complete code in trie.c. There is one function, check, which is not yet implemented. Your job is to complete this function.


## Implementation Details

Notice that the trie itself is implemented through the creative use of several structs called node. Each node in a trie has an array of (potential) children, with size 26—one potential child for each letter of the alphabet! Adding words to this trie, notice that—for every letter in a word—we create a new node child whose parent is either the root node (for the first letter) or the previous letter (if not the first letter). On the very last letter, we set the is_word attribute of the child node to true. Now, checking if a word is in our trie is as easy as following each letter of that word through our trie. If we get to the final letter and see that is_word is true, well, that name is in our trie!


## Thought Question

When might you want to use a trie as a data structure? When might you not?


## How to Test Your Code
Your program should behave per the examples below.
```
trie/ $ ./trie dog_names.txt
Check word: Molly
Found!
```
```
trie/ $ ./trie dog_names.txt
Check word: Lucy
Found!
```
```
trie/ $ ./trie dog_names.txt
Check word: Prudence
Not Found.
```
