#include <stdio.h>

int get_size(void);
void print_grid(int n);

int main(void)
{
    //Get size of grid
    int n = get_size();

    //Print grid of bricks
    print_grid(n);
}

int get_size(void){
    int n;
    do{
        printf("Size: ");
        scanf("%d", &n);
    } while(n<0);
    return n;
}

void print_grid(int n){
    for(int i=0; i<n;i++){
        for(int j = 0; j<n;j++){
            printf("#");
        }
        printf("\n");
    }
}