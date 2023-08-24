# Shorts

Table of contents
<br>\=================
- [Data Structures](#data-structures)
- [Structures](#structures)
- [Singly-Linked Lists](#singly-linked-lists)
- [Doubly-Linked Lists](#doubly-linked-lists)
- [Hash Tables](#hash-tables)
- [Tries](#tries)
- [Queues](#queues)
- [Stacks](#stacks)


# Data Structures

[Video](https://youtu.be/3uGchQbk7g8)

## Arrays
- Insertion is bad- lots of shifting to fit an element in the middle
- Deletion is bad- lots of shifting after removing an element
- Lookup is great - random access, constant time
- Relatively easy to sort
- Relatively small size-wise
- Stuck with a fixed size, no flexibility

##  Linked lists
- Insertion is easy - just tack onto the front
- Deletion is easy - once you find the element
- Lookup is bad - have to rely on linear search
- Relatively difficult to sort - unless you're willing to compromise on
- super-fast insertion and instead sort as you construct
- Relatively small size-wise (not as small as arrays)

## Hash tables
- Insertion is a two-step process - hash, then add
- Deletion is easy - once you find the element
- Lookup is on average better than with linked lists because you have
- the benefit of a real-world constant factor
- Not an ideal data structure if sorting is the goal - just use an array
- Can run the gamut of size

##  Tries
- Insertion is complex - a lot of dynamic memory allocation, but gets easier as you go
- Deletion is easy - just free a node
- Lookup is fast-not quite as fast as an array, but almost
- Already sorted - sorts as you build in almost all situations
- Rapidly becomes huge, even with very little data present, not great if space is at a premium


# Structures

[Video](https://youtu.be/E4lb2gkyXr8)

- Structures provide a way to unify several variables of different types into a single, new variable type which can be assigned its own type name.

- We use structures (structs) to group together elements of a variety of data types that have a logical connection.

- Think of a structure like a “super-variable".

```c
struct car
{
    int year;
    char model [10];
    char plate[7];
    int odometer;
    double engine_size;
};
```

- Once we have defined a structure, which we typically do in separate .h files or atop our programs outside of any functions, we have effectively created a new type.

- That means we can create variables of that type using the familiar syntax.

- We can also access the various fields (also known as members) of the structure using the dot operator (.)

```c
// variable declaration
struct car mycar;
// field accessing
mycar.year = 2011;
strcpy(mycar.plate, "CS50");
mycar.odometer = 50505;
```

- Structures, like variables of all other data types, do not need to be created on the stack. We can dynamically allocate structures at run time if our program requires it.

- In order to access the fields of our structures in that situation, we first need to dereference the pointer to the structure, and then we can access its fields.

```c
// variable declaration
struct car *mycar = malloc(sizeof(struct car));
// field accessing
(*mycar).year = 2011;
strcpy((*mycar).plate, "CS50");
(*mycar).odometer = 50505;
```

- This is a little annoying. And so as you might expect, there's a shorter way!

- The arrow operator (->) makes this process easier. It's an operator that does two things back-to-back:
    - First, it dereferences the pointer on the left side of the operator.
    - Second, it accesses the field on the right side of the operator.

```c
// field accessing
mycar->year = 2011;
strcpy(mycar->plate, “CS50”);
mycar->odometer = 50505;
```


# Singly-Linked Lists

[Video](https://youtu.be/zQI3FyWm144)

- Arrays are great for element lookup, but unless we want to insert at the very end of the array, inserting elements is quite costly.

- Arrays also suffer from a great inflexibility.

- Through clever use of pointers, dynamic memory allocation, and structs, we can put the pieces together to develop a new kind of data structure that gives us the ability to grow and shrink a collection of like values to fit our needs.

- We call this combination of elements, when used in this way, a linked list.

- A linked list node is a special kind of struct with two members:
    - Data of some data type (int, char, float...)
    - A pointer to another node of the same type

- In this way, a set of nodes together can be thought of as forming a chain of elements that we can follow from beginning to end.

```c
typedef struct sllist
{
    VALUE val;
    struct sllist* next;
}
sllnode;
```

In order to work with linked lists effectively, there are a number of operations that we need to understand:
1. Create a linked list when it doesn't already exist.
2. Search through a linked list to find an element.
3. Insert a new node into the linked list.
4. Delete a single element from a linked list.
5. Delete an entire linked list.

- Create a linked list.
```c
sllnode* create (VALUE val);
```

Steps involved:

    a. Dynamically allocate space for a new sllnode.
    b. Check to make sure we didn't run out of memory.
    c. Initialize the node's val field.
    d. Initialize the node's next field.
    e. Return a pointer to the newly created sllnode.

- Search through a linked list to find an element.
```c
bool find(sllnode* head, VALUE val);
```

Steps involved:

    a. Create a traversal pointer pointing to the list's head.
    b. If the current node's val field is what we're looking for, report success.
    c. If not, set the traversal pointer to the next pointer in the list and go back to step b.
    d. If you've reached the end of the list, report failure.

- Insert a new node into the linked list.
```c
sllnode* insert (sllnode* head, VALUE val);
```

Steps involved:

    a. Dynamically allocate space for a new sllnode.
    b. Check to make sure we didn't run out of memory.
    c. Populate and insert the node at the beginning of the linked list.
    d. Return a pointer to the new head of the linked list.

- Delete an entire linked list.
```c
void destroy (sllnode* head);
```

Steps involved:

    a. If you've reached a null pointer, stop.
    b. Delete the rest of the list.
    C. Free the current node.

- In order to work with linked lists effectively, there are a number of operations that we need to understand:
1. Create a linked list when it doesn't already exist.
2. Search through a linked list to find an element.
3. Insert a new node into the linked list.
4. Delete a single element from a linked list.
5. Delete an entire linked list.


# Doubly-Linked Lists

[Video](https://youtu.be/FHMPswJDCvU)

- Singly-linked lists really extend our ability to collect and organize data, but they suffer from a crucial limitation.
    - We can only ever move in one direction through the list.

- Consider the implication that would have for trying to delete a node.

- A doubly-linked list, by contrast, allows us to move forward and backward through the list, all by simply adding one extra pointer to our struct definition.

```c
typedef struct dllist
{
    VALUE val;
    struct dllist* prev;
    struct dllist* next;
}
dllnode;
```

- Insert a new node into the linked list.
```c
dllnode* insert (dllnode* head, VALUE val);
```

Steps involved:
    a. Dynamically allocate space for a new dl1node.
    b. Check to make sure we didn't run out of memory.
    c. Populate and insert the node at the beginning of the linked list.
    d. Fix the prev pointer of the old head of the linked list.
    e. Return a pointer to the new head of the linked list.

- Delete a node from a linked list.
```c
void delete(dllnode* target);
```

Steps involved:
    a. Fix the pointers of the surrounding nodes to "skip over" target.
    b. Free target.

- Linked lists, of both the singly- and doubly-linked varieties, support extremely efficient insertion and deletion of elements.
    - In fact, these operations can be done in constant time.

- What's the downside? Remember how we had to find an element? We've lost the ability to randomly-access list elements.
    - Accessing a desired element may now take linear time.


# Hash Tables

[Video](https://youtu.be/nvzVHwrrub0)

- Hash tables combine the random access ability of an array with the dynamism of a linked list.

- This means (assuming we define our hash table well):
    - Insertion can start to tend toward 0(1)
    - Deletion can start to tend toward 0(1)
    - Lookup can start to tend toward 0(1)

- We're gaining the advantages of both types of data structure, while mitigating the disadvantages.

- To get this performance upgrade, we create a new structure whereby when we insert data into the structure, the data itself gives us a clue about where we will find the data, should we need to later look it up.

- The trade off is that hash tables are not great at ordering or sorting data, but if we don't care about that, then we're good to go!

- A hash table amounts to a combination of two things with which we're quite familiar.

    - First, a hash function, which returns an nonnegative integer value called a hash code.
    - Second, an array capable of storing data of the type we wish to place into the data structure.

- The idea is that we run our data through the hash function, and then store the data in the element of the array represented by the returned hash code.

- How to define a hash function? Really no limit to the number of possible hash functions.

- A good hash function should:
    - Use only the data being hashed
    - Use all of the data being hashed
    - Be deterministic
    - Uniformly distribute data
    - Generate very different hash codes for very similar data

```c
unsigned int hash(char* str)
{
    int sum = 0;
    for (int j = 0; str[j] != '\0'; j++)
    {
        sum += str[j];
    }
    return sum % HASH_MAX;
}
```

- A collision occurs when two pieces of data, when run through the hash function, yield the same hash code.

- Presumably we want to store both pieces of data in the hash table, so we shouldn't simply overwrite the data that happened to be placed in there first.

- We need to find a way to get both elements into the hash table while trying to preserve quick insertion and lookup.

### Resolving collisions: Linear probing

- In this method, if we have a collision, we try to place the data in the next consecutive element in the array (wrapping around to the beginning if necessary) until we find a vacancy.

- That way, if we don't find what we're looking for in the first location, at least hopefully the element is somewhere nearby.

- Linear probing is subject to a problem called clustering. Once there's a miss, two adjacent cells will contain data, making it more likely in the future that the cluster will grow.

- Even if we switch to another probing technique, we're still limited. We can only store as much data as we have locations in our array.

### Resolving collisions: Chaining

- Let's start to pull it all together.

- What if instead of each element of the array holding just one piece of data, it held multiple pieces of data?

- If each element of the array is a pointer to the head of a linked list, then multiple pieces of data can yield the same hash code and we'll be able to store it all!

- We've eliminated clustering.

- We know from experience with linked lists that insertion (and creation, if necessary) into a linked list is an O(1) operation.

- For lookup, we only need to search through what is hopefully a small list, since we're distributing what would otherwise be one huge list across n lists.


# Tries

[Video](https://youtu.be/MC-iQHFdEDI)

- We have seen a few data structures that handle the mapping of key-value pairs.
    - Arrays: The key is the element index, the value is the data at that location.
    - Hash tables: The key is the hash code of the data, the value is a linked list of data hashing to that hash code.

- What about a slightly different kind of data structure where the key is guaranteed to be unique, and the value could be as simple as a Boolean that tells you whether the data exists in the structure?

- Tries combine structures and pointers together to store data in an interesting way.

- The data to be searched for in the trie is now a roadmap.
    - If you can follow the map from beginning to end, the data exists in the trie.
    -  If you can't, it doesn't.

- Unlike with a hash table, there are no collisions, and no two pieces of data (unless they are identical) have the same path.

- Let's map key-value pairs where the keys are four-digit years (YYYY) and the values are names of universities founded during those years.

- In a trie, the paths from a central root node to a leaf node (where the school names would be), would be labeled with digits of the year.

- Each node on the path from root to leaf could have 10 pointers emanating from it, one for each digit.

- To insert an element into the trie, simply build the correct path from the root to the leaf.

```c
typedef struct _trie
{
    char university [20];
    struct _trie* paths [10];
}
trie;
```

- To search for an element in the trie, use successive digits to navigate from the root, and if you can make it to the end without hitting a dead end (a NULL pointer), you've found it.


# Queues

[Video](https://youtu.be/3TmUv1uS92s)

- A queue is a special type of structure that can be used to maintain data in an organized way.

- This data structure is commonly implemented in one of two ways: as an array or as a linked list.

- In either case, the important rule is that when data is added to the queue, it is tacked onto the end, and so if an element needs to be removed, the element at the front is the only element that can legally be removed.
    - First in, first out (FIFO)

- There are only two operations that may legally be performed on a queue.
    - Enqueue: Add a new element to the end of the queue.
    - Dequeue: Remove the oldest element from the front of the queue.

## Array-based implementation
```c
typedef struct _queue
{
    VALUE array [CAPACITY];
    int front;
    int size;
}
queue;
```

### Enqueue: Add a new element to the end of the queue.
- In the general case, enqueue () needs to:
    - Accept a pointer to the queue.
    - Accept data of type VALUE to be added to the queue.
    - Add that data to the queue at the end of the queue.
    - Change the size of the queue.

### Dequeue: Remove the most recent element from the front of the queue.
- In the general case, dequeue () needs to:
    - Accept a pointer to the queue.
    - Change the location of the front of the queue.
    - Decrease the size of the queue.
    - Return the value that was removed from the queue.

## Linked list-based implementation
```c
typedef struct _queue
{
    VALUE val;
    struct _queue *prev;
    struct _queue *next;
}
queue;
```

- Just make sure to always maintain pointers to the head and tail of the linked list! (probably global)

### To enqueue:
    - Dynamically allocate a new node;
    - Set its next pointer to NULL, set its prev pointer to the tail;
    - Set the tail's next pointer to the new node;
    - Move the tail pointer to the newly-created node.

### To dequeue:
    - Traverse the linked list to its second element (if it exists);
    - Free the head of the list;
    - Move the head pointer to the (former) second element;
    - Make that node's prev pointer point to NULL.


# Stacks

[Video](https://youtu.be/hVsNqhEthOk)

- A stack is a special type of structure that can be used to maintain data in an organized way.

- This data structure is commonly implemented in one of two ways: as an array or as a linked list.

- In either case, the important rule is that when data is added to the stack, it sits "on top," and so if an element needs to be removed, the most recently added element is the only element that can legally be removed.
    -  Last in, first out (LIFO)

- There are only two operations that may legally be performed on a stack.
    - Push: Add a new element to the top of the stack.
    - Pop: Remove the most recently-added element from the top of the stack.

## Array-based implementation
```c
typedef struct _stack
{
    VALUE array [CAPACITY];
    int top;
}
stack;
```

### Push: Add a new element to the top of the stack.
- In the general case, push() needs to:
    - Accept a pointer to the stack.
    - Accept data of type VALUE to be added to the stack.
    - Add that data to the stack at the top of the stack.
    - Change the location of the top of the stack.

### Pop: Remove the most recent element from the top of the stack.
- In the general case, pop () needs to:
    - Accept a pointer to the stack.
    - Change the location of the top of the stack.
    - Return the value that was removed from the stack.

##  Linked list-based implementation
```c
typedef struct _stack
{
    VALUE val;
    struct stack *next;
}
stack;
```

- Just make sure to always maintain a pointer to the head of the linked list!

### To push;
- dynamically allocate a new node, set its next pointer to point to the current head of the list, then move the head pointer to the newly-created node.

### To pop;
- traverse the linked list to its second element (if it exists), free the head of the list, then move the head pointer to the (former) second element.