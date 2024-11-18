#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long cardNum = get_long("Number: ");
    int sum = 0;
    int len = 0;       // 카드 숫자 자릿수
    int firstNum = 0;  // 카드의 시작 숫자
    int secondNum = 0; // 카드의 두 번째 숫자

    for (int i = 0; cardNum > 0; i++)
    {
        if (i % 2 > 0)
        {
            int evenNum = 2 * (cardNum % 10);

            if (evenNum >= 10)
            {
                sum += (evenNum - 9);
            }
            else
            {
                sum += evenNum;
            }
        }
        else
        {
            sum += cardNum % 10;
        }

        secondNum = firstNum;
        firstNum = cardNum % 10;
        len++;
        cardNum /= 10;
    }

    if (sum % 10 == 0)
    {
        if (len == 15)
        {
            if (firstNum == 3 && (secondNum == 4 || secondNum == 7))
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (len == 13)
        {
            if (firstNum == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (len == 16)
        {
            // master or visa
            if (firstNum == 4)
            {
                printf("VISA\n");
            }
            else if (firstNum == 5 && (secondNum == 1 || secondNum == 2 || secondNum == 3 ||
                                       secondNum == 4 || secondNum == 5))
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
