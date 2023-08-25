// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <strings.h> 
#include <string.h>
#include <stdlib.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = LENGTH * 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int index = hash(word);
    node *trav = table[index];
    while(trav != NULL)
    {
        if(strcasecmp(trav->word, word) == 0)
        {
            return true;
        }
        trav = trav->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return (strlen(word) - 1) * (toupper(word[0]) - 'A');
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");

    if (file == NULL)
    {
        printf("Could not open %s.\n", dictionary);
        return false;
    }

    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) == 1)
    {

        node *n = malloc(sizeof(node));
        strcpy(n->word, word);
        n->next = NULL;

        int index = hash(word);

        node *tmp =  table[index];
        n->next = tmp;
        table[index] = n;
    }

    fclose(file);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    int count = 0;

    for(int i = 0; i < N; i++)
    {
        node *trav = table[i];
        while(trav != NULL)
        {
            count++;
            trav = trav->next;
        }
    }

    return count;

}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for(int i = 0; i < N; i++)
    {
        node *trav = table[i];
        while(trav != NULL)
        {
            node *tmp = trav;
            trav = trav->next;
            free(tmp);
        }
    }

    return true;
}
