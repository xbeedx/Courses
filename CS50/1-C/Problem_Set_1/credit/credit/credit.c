#include <stdio.h>
#include <string.h>

//Functions
long get_long(char* text);
char* checkCard(long number);
int lunh(long number);

int main(void) 
{
   long number = get_long( "Number: ");
   char* card = checkCard(number);
   card = lunh(number) ? card : "INVALID";
   printf("%s",card);
}

// get_long()
long get_long(char* text) {
    long number;
    int input_successful;

    do {
        printf("%s", text);
        input_successful = scanf("%ld", &number) == 1;
        while (getchar() != '\n') {}
    } while (!input_successful);

    return number;
}

// get nb digits in a long
int get_length(long number){
    int length = 0;
    long number_copy = number;
    while(number_copy>0){
        number_copy = number_copy/10;
        length++;
    }
    return length;
}

char* checkCard(long number) {
    char* card;

    int length = get_length(number);

    long number_copy = number, TwoDigts,FirstDigit;
    while (number_copy){
        TwoDigts = FirstDigit;
        FirstDigit = number_copy;
        number_copy /= 10;
    }   

    switch(length)
    {
        case 15:
            card = "AMEX";
            if(TwoDigts != 34 && TwoDigts != 37)
                card = "INVALID";
            break;
        case 16:
            card = "MASTERCARD";
            if(TwoDigts<51 || TwoDigts>55){
                if(FirstDigit==4){
                    card = "VISA";
                    break;
                }
                card = "INVALID";
                break;
            }
            break;
        case 13:
            card = "VISA";
            if(FirstDigit!=4){
                card = "INVALID";
                }
            break;
        default:
            card = "INVALID";
            break;
    }  

    return card;
}

int lunh(long number){
    int length = get_length(number);
    int numbersSTL[length];
    int numbersO[length];

    //Fill tables
    for(int i = 0; i<length;i++){
        numbersSTL[i] = -1;
        numbersO[i] = -1;
    }

    long number_copy = number;
    int i = 0;
    while (number_copy){
        numbersO[i] = number_copy%10;
        numbersSTL[i] = (number_copy%100)/10;
        number_copy /= 100;
        i++;
    }   

    int sum = 0;
    for(i = 0; i<length;i++){
        if(numbersSTL[i] != -1){
            numbersSTL[i] *=  2;
            if(numbersSTL[i]>10){
                sum += (numbersSTL[i] % 10);
                numbersSTL[i] /= 10;
            }
            sum += numbersSTL[i];
        }
    }

    for(i = 0; i<length;i++){
        if(numbersO[i] != -1)
            sum += numbersO[i];
    }

    if(sum%10 == 0){
        return 1;
    }

    return 0;
}