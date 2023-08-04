#include <stdio.h>
#include <cs50.h>

bool valid_triangle(int a, int b, int c);
int get_length(void);

int main(void)
{
    int a = get_length();
    int b = get_length();
    int c = get_length();

    if(valid_triangle(a,b,c))
    {
        printf("true\n");
        return 0;
    }
    printf("false\n");
}

int get_length(void)
{   
    int x;

    do
    {
        x = get_int("Length: ");
    } while(x <= 0);

    return x;
}

bool valid_triangle(int a, int b, int c)
{
    if((a+b>c) && (a+c>b) && (c+b>a))
    {
        return true;
    }
    return false;
}