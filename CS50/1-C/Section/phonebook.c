#include <stdio.h>

int main(void){
    char username[20];
    char address[20];
    char phonenumber[20];
    int age;

    printf("username: ");
    scanf(" %[^\n]", username);

    printf("phone number: ");
    scanf(" %[^\n]", phonenumber);

    printf("age: ");
    scanf("%i", &age);

    printf("address: ");
    scanf(" %[^\n]", address);

    printf("username: %s\nphone number: %s\nage: %i\naddress: %s\n",username,phonenumber,age,address);
}