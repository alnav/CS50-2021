#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
int calculateScore(int letters, int words, int sentences);

int main(void)
{

    // Readability
    // Formula: index = 0.0588 * L - 0.296 * S - 15.8

    // Get user input
    string text = get_string("Text: ");

    // Initialise variables
    int letters = 0;
    int words = 1;
    int sentences = 0;

    // Loop to count letters, words and sentences
    for (int i = 0; i < strlen(text); i++)
    {
        if isalpha(text[i])
        {
            letters++;
        }
        else if (text[i] == ' ')
        {
            words++;
        }
        else if (text[i] == '.' | text[i] == '?' | text[i] == '!')
        {
            sentences++;
        }
    }

    // Calculate score
    int score = calculateScore(letters, words, sentences);

    // Print score
    printf("Letters %i\n", letters);
    printf("Words %i\n", words);
    printf("Sentences %i\n", sentences);

    if (score < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (score > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", score);
    }

}

int calculateScore(int letters, int words, int sentences)
{
    // Calculate L (letters per 100 words) and S (sentences per 100 words)
    float L = (float) letters * 100 / words;
    float S = (float) sentences * 100 / words;

    // Coleman-Liau index
    int score = round(0.0588 * L - 0.296 * S - 15.8);

    return score;
}