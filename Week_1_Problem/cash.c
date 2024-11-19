#include <cs50.h>
#include <stdio.h>

// greed algorithm

int main(void)
{
    int cnt = 0;
    int cash;
    int cent25 = 25;
    int cent10 = 10;
    int cent5 = 5;
    int cent1 = 1;

    do
    {
        cash = get_int("Change owed: ");
    }
    while (cash <= 0);

    while (cash > 0)
    {
        if (cash >= cent25)
        {
            cash -= cent25;
            cnt++;
        }
        else if (cash >= cent10)
        {
            cash -= cent10;
            cnt++;
        }
        else if (cash >= cent5)
        {
            cash -= cent5;
            cnt++;
        }
        else
        {
            cash -= cent1;
            cnt++;
        }
    }

    printf("%i\n", cnt);
}
