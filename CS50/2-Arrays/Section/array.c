#include <stdio.h>
#include <cs50.h>

void printArray(int array[], int size);
void setArray(int array[], int size);

int main(void)
{   
    int lenght;
    do{
        lenght = get_int("Length:");
    } while(lenght < 1);

    int twice[lenght];
    
    setArray(twice,lenght);
    printArray(twice,lenght);
}

void setArray(int array[], int size)
{
    array[0] = 1;
    for(int i=1; i<size;i++)
    {
        array[i] = 2*array[i-1];
    }
}


void printArray(int array[], int size)
{
    for(int i=0; i<size;i++)
    {
        printf("%i\n",array[i]);
    }
}