#include <stdio.h>

int prime(int number);
int get_int(char* text);

int main(void)
{
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    int max;
    do
    {
        max = get_int("Maximum: ");
    } 
    while (min >= max);
    
    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

int prime(int number)
{
    if(number < 2)
        return 0;
    else if(number == 2)
        return 1;
    else if(number % 2 == 0)
        return 0;
    else
    {
        for(int i = 3; i * i <= number; i += 2)
        {
            if(number % i == 0)
                return 0;
        }
    }
    return 1;
}

int get_int(char* text) {
    printf("%s", text);
    int number;
    scanf("%i", &number);
    return number;
}