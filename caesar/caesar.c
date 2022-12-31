#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

bool only_digits(string s);
char rotate(char og_char, int key);

int main(int argc, string argv[])
{
    //Check for the correct amount of arguments, 2
    if (argc == 2)
    {
        if (only_digits(argv[1]) == false)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        else
            //Get the text that will be "rotated"
        {
            int key = atoi(argv[1]);
            string plain_text = get_string("plaintext: ");

            //use the function rotate for each letter of the inputed text
            for (int i = 0, len = strlen(plain_text); i < len; i++)
            {
                plain_text[i] = rotate(plain_text[i], key);
            }

            //print the resulting coded text
            printf("ciphertext: %s\n", plain_text);
            return 0;
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

//Function to check if the key uses only digits;
//To do so, it keeps couting how many non digits
//are used. If it is 0, it returns true, else,
//he returns false.
bool only_digits(string s)
{
    int non_digits = 0;
    string key = s;

    for (int i = 0, len = strlen(key); i < len; i++)
    {
        if (isdigit(key[i]))
        {
        }
        else
        {
            non_digits = non_digits + 1;
        }
    }

    if (non_digits > 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

//Function to rotate only alphabetic characters according to
//the provided key, maintaining it's upper or lower case.
//
//It does so by using it's original char USCII code, subtracts
//the corresponding "A" or "a" values and uses the arithmetic
//phormula given by the CS50 team.
//
//We them add it's corresponding value (A if uppercase
//or a if lower) to get the new char.

char rotate(char og_char, int key)
{
    char new_char;
    if (isalpha(og_char))
    {
        if (isupper(og_char))
        {
            {
                new_char = (og_char - 65 + key) % 26;
                new_char = new_char + 65;
                return new_char;
            }
        }
        else
        {
            new_char = (og_char - 97 + key) % 26;
            new_char = new_char + 97;
            return new_char;
        }
    }
    else
    {
        return og_char;
    }
}