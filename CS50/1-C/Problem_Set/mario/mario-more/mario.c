#include <stdio.h>

int get_int(char* text);

int main(void) 
{
    int height;
    do{
        height = get_int("Height: ");
    }while(height<1 || height>8);

    for(int i=1; i<=height;i++){
        for(int j =0;j<height-i;j++)
            printf(" ");

        for(int k=0;k<i;k++)
            printf("#");

        printf("  ");

        for(int k=0;k<i;k++)
            printf("#");

        printf("\n");
    }
       
}

int get_int(char* text) {
    int number;
    int input_successful;

    do {
        printf("%s", text);
        input_successful = scanf("%d", &number) == 1;
        while (getchar() != '\n') {}
    } while (!input_successful);

    return number;
}