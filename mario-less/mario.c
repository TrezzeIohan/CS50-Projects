#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int width, i, j;

    do {
        width = get_int("Between 1 and 8, type the desired width:");
    }

    while (width < 1 || width > 8);

    for (i = 0; i < width; i++) {


        for (j = 0 ; j < width; j++)
        {

            if (j < width - i - 1) {

                printf(" ");
            }
            else {
                printf("#");
            }

        }
    printf("\n");

    }



}