#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);
void message_to_binary(string message, int array[][BITS_IN_BYTE]);
void print_binary_array(int array[][BITS_IN_BYTE], int length);

int main(void)
{
    //Get the message from the user
    string message = get_string("Message: ");

    //Convert the message to binary and store each bit in an array
    int message_bits[strlen(message)][BITS_IN_BYTE];
    message_to_binary(message, message_bits);

    //print the bits
    print_binary_array(message_bits, strlen(message));
    
}

void message_to_binary(string message, int array[][BITS_IN_BYTE])
{
    for(int i = 0; i< strlen(message);i++)
    {
        int binary_char = message[i];

        for(int j = 0; j < BITS_IN_BYTE; j++)
        {
            array[i][BITS_IN_BYTE-1-j] = binary_char%2;
            binary_char = binary_char/2;
        }
    }
}

void print_binary_array(int array[][BITS_IN_BYTE], int length)
{
    for(int i = 0; i< length;i++)
    {
        for(int j = 0; j < BITS_IN_BYTE; j++)
        {
            print_bulb(array[i][j]);
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
