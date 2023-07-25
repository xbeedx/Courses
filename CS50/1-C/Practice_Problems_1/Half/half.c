// Calculate your half of a restaurant bill
// Data types, operations, type casting, return value

#include <stdio.h>

float half(float bill, float tax, int tip);
float get_float(char* text);
int get_int(char* text);


int main(void)
{
    float bill_amount = get_float("Bill before tax and tip: ");
    float tax_percent = get_float("Sale Tax Percent: ");
    int tip_percent = get_int("Tip percent: ");

    printf("You will owe $%.2f each!\n", half(bill_amount, tax_percent, tip_percent));
}

// TODO: Complete the function
float half(float bill, float tax, int tip)
{
    bill += bill * (tax / 100);
    bill += bill * ((float)tip / 100); 

    return bill / 2;
}

float get_float(char* text) {
    printf("%s", text);
    float number;
    scanf("%f", &number);
    return number;
}

int get_int(char* text) {
    printf("%s", text);
    int number;
    scanf("%i", &number);
    return number;
}