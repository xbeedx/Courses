# [Lab 4: Smiley](https://cs50.harvard.edu/x/2023/labs/4/smiley/)


## Background

![smiley_spec_image](https://cs50.harvard.edu/x/2023/labs/4/smiley/smiley_spec_image.png)

You’ve seen in lecture a bit about how images are stored on a computer. In this lab, you’ll practice working with a BMP file, actually the smiley face pictured here, and change all the black pixels to a color of your choosing.

However, the smiley face you’ll be working with is not just made of of 0’s and 1’s, or black and white pixels, but consists of 24 bits per pixel. It uses eight bits to represent red values, eight bits for green and eight bits for blue. Since each color uses eight bits or one byte, we can use a number in the range of 0 to 255 to represent its color value. In hexadecimal, this is represented by 0x00 to 0xff. By mixing together these red, green and blue values, we can create millions of possible colors.

If you look at bmp.h, one of the the helper files in the distribution code, you’ll see how each RGB triple is represented by a struct like:
```c
typedef struct
{
    BYTE rgbtBlue;
    BYTE rgbtGreen;
    BYTE rgbtRed;
}
RGBTRIPLE;
```

where BYTE is defined as an 8-bit integer.

You’ll notice several files provided in the distribution code to handle the reading and writing of an image file, as well as handling the image’s metadata or “headers”. You’ll be completing the function colorize in helpers.c, which already has as input parameters, the image’s height, width, and a two-dimensional array of RGBTRIPLE’s which create the image itself.


## Implementation Details

Open up helpers.c and notice that the colorize function is incomplete. Note that the image’s height, width and a two-dimensional array of pixels is set up as the input parameters for this function. You are to implement this function to change all the black pixels in the image to a color of your choosing.

You can compile your code by simply typing make at the $ prompt.

You then execute the program by typing:
```
./colorize smiley.bmp outfile.bmp
```
where outfile.bmp is the name of the new bmp you are creating.


## Thought Question

How do you think you represent a black pixel when using a 24-bit color BMP file?
Is this the same or different when mixing paints to repesent various colors?


## [Result](https://submit.cs50.io/check50/b2431730573562d28c06ded2b2151ef20076f739)
![smiley](./smiley/outfile.bmp)