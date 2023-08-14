#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

const int KEY_LENGTH = 26;

bool valid_argugments(int argc, string argv[]);
string substitute(string plaintext, string key);

int main(int argc, string argv[]) 
{   
    if (!valid_argugments(argc, argv))
    {
        return 1;
    }

    string plaintext = get_string("plaintext:  ");
    printf("ciphertext: %s\n",substitute(plaintext, argv[1]));

    return 0;
}

//Check if arguments are valid
bool valid_argugments(int argc, string argv[])
{
    //one and only one key submitted 
    if(argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return false;
    }

    //key must contain 26 characters
    if(strlen(argv[1]) != KEY_LENGTH)
    {
        printf("Key must contain 26 characters.\n");
        return false;
    }

    //key must only contain alphabetic characters
    for(int i = 0; i < KEY_LENGTH; i++)
    {
        if(!isalpha(argv[1][i]))
        {
            printf("Key must only contain alphabetic characters.\n");
            return false;
        }
    }

    return true;
}

string substitute(string plaintext, string key)
{
    int chars_key[KEY_LENGTH];

    //fill array with the key
    for(int i = 0; i < KEY_LENGTH; i++)
    {
        chars_key[i] = key[i];
    }

    //subsitute characters in plaintext using the array
    for(int i = 0; i < strlen(plaintext); i++)
    {
        if (isalpha(plaintext[i]))
        {
            if(islower(plaintext[i]))
            {
                plaintext[i] = tolower(chars_key[plaintext[i] - 97]);
            } else 
            {
                plaintext[i] = toupper(chars_key[plaintext[i] - 65]);
            }
        } 
    }

    return plaintext;
}
