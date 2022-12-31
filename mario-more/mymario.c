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
    while ( width > 8 || width < 0);





       for (int i = 0; i < width; i++)
       {

       }

    printf("\n");
}