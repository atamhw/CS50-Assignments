#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text)
{
    int counter = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            counter++;
        }
    }
    return counter;
}

int count_words(string text)
{
    int counterWords = 1;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            counterWords++;
        }
    }
    return counterWords;
}

int count_sentences(string text)
{
    int counterSentence = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            counterSentence++;
        }
    }
    return counterSentence;
}

int main(void)
{
    string text = get_string("Enter Text ");
    int letter_count = count_letters(text);
    int count_word = count_words(text);
    int sentence_count = count_sentences(text);
    // printf("%i letters\n", letter_count);
    // printf("%i words\n", count_word);
    // printf("%i sentences\n", sentence_count);

    float L = (float) letter_count / count_word * 100;
    float S = (float) sentence_count / count_word * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);

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
