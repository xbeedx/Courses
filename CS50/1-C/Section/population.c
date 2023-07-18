#include <stdio.h>

int main(void){

    int start, newBorns, deaths;
    int years = 0;
    int end;

    do{
        printf("How many llamas do we have ? ");
        scanf("%i", &start);
    }while(start<9);

    do{
        printf("How many llamas do we want ? ");
        scanf("%i", &end);
    }while(end<start);


    printf("\n================\nStart size: %i\nEnd size: %i\n",start,end);

    while(start<end){
        newBorns = start/3;
        deaths = start/4;
        start += newBorns;
        start -= deaths;
        years++;
    }

    printf("It took %i years to reach a population of %i\n", years, end);
}