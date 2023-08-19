#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wav.h"

#define CMD_ARGS 2

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);



int main(int argc, char *argv[])
{
    // Ensure proper usage
    if(argc != 1 + CMD_ARGS)
    {
        fprintf(stderr, "Usage: ./reverse input.wav output.wav\n");
        return 1;
    }

    // Open input file for reading
    char *infile = argv[1];
    FILE *input = fopen(infile,"r");
    if(input == NULL)
    {
        fprintf(stderr,"Could not open %s.\n",infile);
        return 1;
    }

    // Read header
    WAVHEADER wh;
    fread(&wh,sizeof(WAVHEADER),1,input);

    // Use check_format to ensure WAV format
    if(!check_format(wh))
    {
        fprintf(stderr,"Input is not a WAV file.\n");
        return 1;
    }


    // Open output file for writing
    char *outfile = argv[2];
    FILE *output = fopen(outfile,"w");
    if(output == NULL)
    {
        fprintf(stderr,"Could not open %s.\n",outfile);
        return 1;
    }

    // Write header to file
    fwrite(&wh,sizeof(WAVHEADER),1,output);

    // Use get_block_size to calculate size of block
    int BLOCK_SIZE = get_block_size(wh);

    // Write reversed audio to file
    BYTE buffer[BLOCK_SIZE];

    int numBlocks = wh.subchunk2Size / BLOCK_SIZE;

    for (int i = numBlocks - 1; i >= 0; i--)
    {
        fseek(input, sizeof(WAVHEADER) + i * BLOCK_SIZE, SEEK_SET);
        fread(buffer, 1, BLOCK_SIZE, input);
        fwrite(buffer, 1, BLOCK_SIZE, output);
    }
    
    fclose(input);
    fclose(output);
}

int check_format(WAVHEADER header)
{
    char *WAV_Format = "WAVE";

    for(int i = 0; i < 4; i ++)
    {
        if(header.format[i] != WAV_Format[i])
        {
            return 0;
        }
    }
    return 1;
}

int get_block_size(WAVHEADER header)
{
    return header.numChannels * (header.bitsPerSample/8);
}