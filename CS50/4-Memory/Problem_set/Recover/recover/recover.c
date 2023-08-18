#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BLOCK_SIZE 512

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    FILE *raw_file = fopen(argv[1], "r");
    if (raw_file == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }

    char file_name[8];
    int counter = 0;
    FILE *recovered = NULL;

    BYTE buffer[BLOCK_SIZE];

    while (fread(buffer, 1, BLOCK_SIZE, raw_file) == BLOCK_SIZE)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (recovered != NULL)
            {
                fclose(recovered);
            }

            sprintf(file_name, "%03i.jpg", counter);

            recovered = fopen(file_name, "w");
            if (recovered == NULL)
            {
                printf("Could not create %s.\n", file_name);
                return 1;
            }
            counter++;
        }

        if (recovered != NULL)
        {
            fwrite(&buffer, 1, BLOCK_SIZE, recovered);
        }
    }

    if (recovered != NULL)
    {
        fclose(recovered);
    }

    fclose(raw_file);
    return 0;
}
