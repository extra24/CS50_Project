#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

string rotate(string text, int key);
int is_digit(string key);

int main(int argc, string argv[])
{
    // argc가 1이거나 (명령줄 인자가 들어오지 않은 경우) argv의 값이 숫자가 아닌 경우 return 0으로 프로그램 종료
    if (argc == 1 || argc > 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else if (is_digit(argv[1]) == -1)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
y
    string plaintext = get_string("plaintext: ");
    string ciphertext = rotate(plaintext, atoi(argv[1]));
    printf("ciphertext: %s\n", ciphertext);

}

string rotate(string text, int key)
{
    // key 만큼 값만큼 string의 문자 회전
    int len = strlen(text);
    for (int i = 0; i < len; i++)
    {
        char charNum = text[i];
        char num = 0;
        if (charNum >= 'A' && charNum <= 'Z')
        {
            charNum -= 'A';
            num = (charNum + key) % 26;
            num += 'A';
        }
        else if (charNum >= 'a' && charNum <= 'z')
        {
            charNum -= 'a';
            num = (charNum + key) % 26;
            num += 'a';
        }
        else
        {
            num = text[i];
        }
        text[i] = num;
    }
    return text;
}

int is_digit (string key)
{
    int keyNum = atoi(key);
    for (int i = 0; i < strlen(key); i++)
    {
        int keycheck = isdigit(key[i]);
        if (keycheck == 0)
        {
            return -1;
        }
    }
    return keyNum;
}
