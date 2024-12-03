#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// 단어 게임

int score_points(string s);

int main(void)
{
    string p1 = get_string("Player 1: ");
    string p2 = get_string("Player 2: ");

    int p1_sc = score_points(p1);
    int p2_sc = score_points(p2);

    if (p1_sc > p2_sc)
    {
        printf("Player 1 wins!\n");
    }
    else if (p1_sc < p2_sc)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int score_points(string s)
{
    int score = 0;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        char c = toupper(s[i]);
        switch (c)
        {
            case 'A':
            case 'E':
            case 'I':
            case 'L':
            case 'N':
            case 'O':
            case 'R':
            case 'S':
            case 'T':
            case 'U':
                score += 1;
                break;
            case 'D':
            case 'G':
                score += 2;
                break;
            case 'B':
            case 'C':
            case 'M':
            case 'P':
                score += 3;
                break;
            case 'F':
            case 'H':
            case 'V':
            case 'W':
            case 'Y':
                score += 4;
                break;
            case 'K':
                score += 5;
                break;
            case 'J':
            case 'X':
                score += 8;
                break;
            case 'Q':
            case 'Z':
                score += 10;
                break;
        }
    }
    return score;
}
