#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *x = malloc(3 * sizeof(int));
    if(x==NULL)
    {
        return 1;
    }
    x[0] = 71;
    x[1] = 73;
    x[2] = 33;
    free(x);
    return 0;
}