#include <stdio.h>
#include <stdlib.h>


char* get_string(char* text);


int main(void)
{
    char* name = get_string("What's your name? ");
    printf("hello, %s\n",name);
}

char* get_string(char* text) 
{
    printf("%s", text);

    char* s = (char*)malloc(100 * sizeof(char));
    scanf(" %[^\n]", s);

    return s;
}