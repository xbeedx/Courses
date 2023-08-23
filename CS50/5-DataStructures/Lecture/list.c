#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
    int number; 
    struct node *next;
} node;

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        printf("Usage: ./list ...\n");
        return 1;
    }

    node *list = NULL;

    for(int i = 1; i < argc; i++)
    {
        int number = atoi(argv[i]);

        node *n = malloc(sizeof(node));
        if(n == NULL)
        {
            return 1;
        }

        n->number=number;
        n->next = NULL;

        n->next = list;
        
        list = n;
    }

    for(node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%i\n", ptr->number);
    }

    node *ptr = list;

    while(ptr != NULL)
    {
        node *next = list->next;
        free(ptr);
        ptr = next;
    }

    
}