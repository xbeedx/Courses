#include <stdio.h>

int main(void){
    long x;
    printf("x: ");
    scanf("%ld", &x);
    
    long y;
    printf("y: ");
    scanf("%ld", &y);

    double z = (double) x / (double) y;
    printf("%.20f\n",z);
}