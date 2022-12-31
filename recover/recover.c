#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //Check if we receive only 2 inputs
    if (argc != 2)
    {
        printf("Usage: ./recover [name of forensic image].raw\n");
        return 1;
    }

    // Storing the adress of the input file in a variable
    FILE *input_file = fopen(argv[1], "r");


    //If the file can't be open, the adress stored
    //inside *input_file will be of value NULL.
    // If this happens, we will catch an error.
    if (input_file == NULL)
    {
        printf("Unable to read the file.\n");
        return 1;
    }


    //Store blocks of 512 bytes in an array (remember, a char = 1 byte)
    unsigned char buffer[512];

    //A variable to keep track of the number of images. Remeber,
    //initializing it with a value prevents trash data being represented
    int image_count = 0;

    //File pointer for recovered images
    FILE *output_file = NULL;

    //char FileName[8]
    char *filename = malloc(8 * sizeof(char));

    //Reads the input file in blocks of 512 and store them in the buffer variable
    while (fread(buffer, sizeof(char), 512, input_file))
    {
        // Check if the readed bytes correspond to the pattern of JPEGs
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer [2]
            == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //Closing the output files after they're written
            if (image_count > 0)
            {
                fclose(output_file);
            }
            sprintf(filename, "%03i.jpg", image_count);

            output_file = fopen(filename, "w");

            image_count++;
        }

        if (output_file != NULL)
        {
            fwrite(buffer, sizeof(char), 512, output_file);
        }

    }
    free(filename);
    fclose(output_file);
    fclose(input_file);


    return 0;
}


/*
        PSEUDOCODE

Check if the number of cmmd-line args is != 2
    if(true)
        printf a message of error
        return


    store the adress of the file in a variable
        check if it can be open
            if not,
                display error msg, return

            if it can
                check the first bits of the file
                if it has the special combination; keep going;

                if not, skip to next one





*/