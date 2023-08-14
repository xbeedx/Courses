#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char* s = (char*)malloc(100 * sizeof(char));
    scanf(" %[^\n]", s);
    printf("s: %s\n",s);
    
}
