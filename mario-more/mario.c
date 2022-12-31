#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int width;
//this "do while" loop gets a prompt for the width of "#" printed in the base of the
//mountain and repeats itself until it gets one number between 1 and 8
    do
    {
        width = get_int("Width:");
    }
    while (width > 8 || width < 1);

    //Here i and j are responsible for the columns and rows,
    //like positions on a numerical table. There is a mathematical
    //relation between the positions and the characters as the
    //nested "if" statement shows.


    //this iteration is responsible for the number of rows
    for (int i = 0; i < width; i++)
    {
        //this iteration makes the rows
        for (int j = 0; j < width + i + 3; j++)
        {
            if (j == width || j == width + 1 ||  i + j < width - 1)
                printf(" ");
            else
                printf("#");
        }
        printf("\n");
    }
}