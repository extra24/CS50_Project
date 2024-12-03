#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// 독해력 측정

int coleman_liau(string text);

int main(void)
{
    string text = get_string("Text: ");
    int grade = coleman_liau(text);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

int coleman_liau(string text)
{
    // L은 100 단어(words)당 평균 글자(letters) 수
    // S는 100 단어(words)당 평균 문장(sentence) 수
    // int index = 0.0588 * L - 0.296 * S - 15.8;

    int letter_cnt = 0;
    int word_cnt = 1;
    int sentence_cnt = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        char c = toupper(text[i]);
        if (c == ' ')
        {
            word_cnt++;
        }
        else if (c == '!' || c == '?' || c == '.')
        {
            sentence_cnt++;
        }
        else if (c >= 'A' && c <= 'Z')
        {
            letter_cnt++;
        }
    }

    float L = ((float) letter_cnt / (float) word_cnt) * 100;
    float S = ((float) sentence_cnt / (float) word_cnt) * 100;
    int index = (int) round(0.0588 * L - 0.296 * S - 15.8);

    return index;
}
