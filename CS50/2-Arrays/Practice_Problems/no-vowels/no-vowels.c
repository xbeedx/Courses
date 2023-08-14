// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>

string replace(string text);

int main(int argc, string argv[])
{
    //command-line arguments check. 
    if(argc != 2)
    {
        printf("Invalid command-line argument: ./no-vowels word");
        return 1;
    }

    //print the leetspeak
    printf("%s\n",replace(argv[1]));

}

//replace vowels with numbers
string replace(string text)
{
    int i = 0;
    while(text[i] != '\0')
    {
        switch(text[i])
        {
            case 'a':
                text[i] = '6';
                break;
            case 'e':
                text[i] = '3';
                break;
            case 'i':
                text[i] = '1';
                break;
            case 'o':
                text[i] = '0';
                break;
            default:
                break;
        }
        i++;
    }
    return text;
}