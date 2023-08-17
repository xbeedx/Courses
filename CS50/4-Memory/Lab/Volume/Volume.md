# [Lab 4: Volume](https://cs50.harvard.edu/x/2023/labs/4/volume/)

Write a program to modify the volume of an audio file.
```
$ ./volume INPUT.wav OUTPUT.wav 2.0
```
Where INPUT.wav is the name of an original audio file and OUTPUT.wav is the name of an audio file with a volume that has been scaled by the given factor (e.g., 2.0).


## WAV Files

[WAV files](https://docs.fileformat.com/audio/wav/) are a common file format for representing audio. WAV files store audio as a sequence of “samples”: numbers that represent the value of some audio signal at a particular point in time. WAV files begin with a 44-byte “header” that contains information about the file itself, including the size of the file, the number of samples per second, and the size of each sample. After the header, the WAV file contains a sequence of samples, each a single 2-byte (16-bit) integer representing the audio signal at a particular point in time.

Scaling each sample value by a given factor has the effect of changing the volume of the audio. Multiplying each sample value by 2.0, for example, will have the effect of doubling the volume of the origin audio. Multiplying each sample by 0.5, meanwhile, will have the effect of cutting the volume in half.


## Types

So far, we’ve seen a number of different types in C, including int, bool, char, double, float, and long. Inside a header file called stdint.h are the declarations of a number of other types that allow us to very precisely define the size (in bits) and sign (signed or unsigned) of an integer. Two types in particular will be useful to us in this lab.

- uint8_t is a type that stores an 8-bit unsigned (i.e., not negative) integer. We can treat each byte of a WAV file’s header as a uint8_t value.
- int16_t is a type that stores a 16-bit signed (i.e., positive or negative) integer. We can treat each sample of audio in a WAV file as an int16_t value.


## Implementation Details

Complete the implementation of volume.c, such that it changes the volume of a sound file by a given factor.

- The program accepts three command-line arguments: input represents the name of the original audio file, output represents the name of the new audio file that should be generated, and factor is the amount by which the volume of the original audio file should be scaled.
    - For example, if factor is 2.0, then your program should double the volume of the audio file in input and save the newly generated audio file in output.
- Your program should first read the header from the input file and write the header to the output file. Recall that this header is always exactly 44 bytes long.
    - Note that volume.c already defines a variable for you called HEADER_SIZE, equal to the number of bytes in the header.
- Your program should then read the rest of the data from the WAV file, one 16-bit (2-byte) sample at a time. Your program should multiply each sample by the factor and write the new sample to the output file.
    - You may assume that the WAV file will use 16-bit signed values as samples. In practice, WAV files can have varying numbers of bits per sample, but we’ll assume 16-bit samples for this lab.
- Your program, if it uses malloc, must not leak any memory.


## Hints

- You’ll likely want to create an array of bytes to store the data from the WAV file header that you’ll read from the input file. Using the uint8_t type to represent a byte, you can create an array of n bytes for your header with syntax like
```c
uint8_t header[n];
```
replacing n with the number of bytes. You can then use header as an argument to fread or fwrite to read into or write from the header.

- You’ll likely want to create a “buffer” in which to store audio samples that you read from the WAV file. Using the int16_t type to store an audio sample, you can create a buffer variable with syntax like
```c
int16_t buffer;
```
You can then use &buffer as an argument to fread or fwrite to read into or write from the buffer. (Recall that the & operator is used to get the address of the variable.)

- You may find the documentation for [fread](https://man.cs50.io/3/fread) and [fwrite](https://man.cs50.io/3/fwrite) helpful here.
    - In particular, note that both functions accept the following arguments:
        - ptr: a pointer to the location in memory to store data (when reading from a file) or from which to write data (when writing data to a file)
        - size: the number of bytes in an item of data
        - nmemb: the number of items of data (each of size bytes) to read or write
        - stream: the file pointer to be read from or written to
    - Per its documentation, fread will return the number of items of data successfully read. You may find this useful to check for when you’ve reached the end of the file!


## [Result](https://submit.cs50.io/check50/a41e3f2e03f8017b2ba330f2d6952cb06ec88f7a)
