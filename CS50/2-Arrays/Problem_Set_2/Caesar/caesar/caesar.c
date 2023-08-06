#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

string cypher(string plaintext, int key);
char rotate(char a, int step);
bool only_digits(string text);

int main(int argc, string argv[]) 
{
    //check arguments
   if(argc != 2 || !only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    string plaintext = get_string("plaintext: ");
    string cyphertext = cypher(plaintext, atoi(argv[1]));
    printf("ciphertext: %s\n",cyphertext);

}

bool only_digits(string text)
{
    for(int i = 0; i<strlen(text);i++)
    {
        if ( !isdigit(text[i]) )
        {
            return false;
        }
    }
    return true;
}

string cypher(string plaintext, int key)
{
    for(int i = 0; i<strlen(plaintext);i++)
    {
        plaintext[i] = rotate(plaintext[i],key%26);
    }
    return plaintext;
}

char rotate(char a, int step)
{
    if( !isalpha(a) )
    {
        return a;
    }

    if( (islower(a) && a+step > 'z') || (isupper(a) && a+step > 'Z') )
    {
        if(isupper(a))
        {
            a = 'A' + (step - ('Z' - a) - 1);
        } else {
            a = 'a' + (step - ('z' - a) - 1);
        }
    } else {
        a += step;
    }

    return a;
}