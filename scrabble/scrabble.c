#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if(score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }


}

int compute_score(string word)
{
    int score = 0;

    for (int i = 0, len = strlen(word); i < len ; i++)
    {
        if (isupper(word[i]))

        // to make a reference to the corresponding char points, we access
        // it by subctracting A (or 65 in USCII). This way if the char is
        // A, we will reference to the location 0 (65 - A = 0), if B, we
        // will have 1 (66 - A), and so on. This way we et the reference we
        // need. The same loic is appplied for the 'ele if', but instead of 'A'
        // we subtract by 'a' (97 in USCII).
        {
            score += POINTS[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {
            score += POINTS[word[i] - 'a'];
        }
    }

    return score;

}




//  PSEUDO CODE
//
//  get both strings
//  calculate points for each word
//      . separate the strins into chars
//      . see how many points each char makes
//          >
//
//  compare the 2 values
//  print the winner
