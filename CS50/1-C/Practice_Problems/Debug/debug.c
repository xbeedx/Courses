// Become familiar wih C syntax
// Learn to debug buggy code

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* get_string(char* text);

int main(void)
{
    // Ask for your name and where live
    char name[20];
    char location[50];

    strcpy(name, get_string("What is your name? "));
    strcpy(location, get_string("Where do you live? "));

    // Say hello
    printf("Hello, %s, from %s!", name, location);

    return 0;
}

char* get_string(char* text) {
    printf("%s", text);
    char* s = (char*)malloc(100 * sizeof(char));
    scanf(" %[^\n]", s);
    return s;
}