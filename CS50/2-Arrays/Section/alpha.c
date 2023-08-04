#include <stdio.h>
#include <cs50.h>

void toLowerCase(string word);
int isAlphabetical(string word);

int main(void)
{
    string word =  get_string("Word: ");
    toLowerCase(word);

    return isAlphabetical(word);
}

int isAlphabetical(string word)
{
    int i=1; 
    while(word[i] != '\0')
    {
        //Check if not alphabetical
        if(word[i] < word[i-1]){
            printf("No\n");
            return 0;
        }
        i++;
    }
    printf("Yes\n");
    return 0;
}

void toLowerCase(string word)
{
    int i=0; 
    while(word[i] != '\0')
    {
        if(word[i] < 97 )
        {
            word[i] += 32; 
        }
        i++;
    }
}