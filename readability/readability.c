#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

//This program calculates the index of complexity of texts and
//prints it out for the user.
//
//It does that using the number of letters per 100 words (l) and
// sentences per 100 words (s) to calculate the index using the
//Coleman Liau phormula.

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
float per_hundred(float words, float value);
int coleman_liau_index(float l, float s);

int main(void)
{
    // Get the user text input
    string text = get_string("Text: ");

    // Declaring variables needed
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Calculate the values of l and s to use in the
    // Coleman Liau phormula
    double l = per_hundred(words, letters);
    double s = per_hundred(words, sentences);

    int index = coleman_liau_index(l, s);


    // Prints the input text results
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }


}

// Count the number of letters in the input
int count_letters(string text)
{
    int letters = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }

    return letters;
}

// Count the number of words in the input.
// It starts at 1, because it use spaces
// to count the number of words.

int count_words(string text)
{
    int words = 1;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isspace(text[i]))
        {
            words++;
        }
    }

    return words;
}

// Count the number of sentences in the input
int count_sentences(string text)
{
    int sentences = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == 46 && text[i + 1] == 46)
        {
            break;
        }
        else if (text[i] == 33)
        {
            sentences++;
        }
        else if (text[i] == 46)
        {
            sentences++;
        }
        else if (text[i] == 63)
        {
            sentences++;
        }
    }

    return sentences;
}

// Function to calculate the per hundred values
float per_hundred(float words, float value)
{
    float result;
    result = (100 * value) / words;

    return result;
}

// The Coleman Liau phormula
int coleman_liau_index(float l, float s)
{
    float calculus = 0.0588 * l - 0.296 * s - 15.8;

    int index = round(calculus);

    return index;
}

