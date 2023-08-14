// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{   
    bool has_lower_case = false;
    bool has_upper_case = false;
    bool has_number = false;
    bool has_symbol = false;


    int i = 0;
    while(password[i] != '\0')
    {
        if(password[i] >= 'A' && password[i] <= 'Z' ){
            has_upper_case = true;
        } else if(password[i] >= 'a' && password[i] <= 'z' ){
            has_lower_case = true;
        } else if(password[i] >= '0' && password[i] <= '9' ){
            has_number = true;
        } else if (ispunct(password[i])){
            has_symbol = true;
        }

        i++;
    }

    return has_lower_case && has_upper_case && has_number && has_symbol;
}