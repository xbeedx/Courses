#include <stdio.h>

int main(void)
{
    FILE *input = fopen("hi.txt","r");
    char buffer[3];
    fread(buffer, 1,3,input);

    printf("%s\n", buffer);
}