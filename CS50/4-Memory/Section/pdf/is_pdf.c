#include <stdio.h>
#include <stdint.h>

int main(int argc, char *argv[])
{

    if(argc != 2)
    {
        printf("Usage: ./is_pdf <filename>\n");
        return 1;
    }

    //Open file
    FILE *input = fopen(argv[1], "r");

    //Check if file exists
    if(input == NULL)
    {
        printf("No such file found\n");
        return 1;
    }

    uint8_t buffer[4];

    //Read file
    fread(buffer, 1, 4, input);

    int pdf_values[4]={37,80,68,70};

    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", buffer[i]);
        if(buffer[i] != pdf_values[i])
        {
            printf("Not a PDF\n");
            fclose(input);
            return 1;
        }
    }

    fclose(input);
    printf("File is a PDF\n");
    return 0;
}