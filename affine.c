//Submitted by Shivam Balwani
//ID:201851122
//Batch:CS
//Code:Affine Cipher
#include <stdio.h>
#include <stdlib.h>

char *decrypt(char *message, int a, int b)
{
    int i;
    char ch;
    //find inverse
    int a_inv = 0;
    int flag = 0;
    for (int i = 0; i < 26; i++)
    {
        flag = (a * i) % 26;
        if (flag == 1)
        {
            a_inv = i;
            break;
        }
    }
    for (i = 0; message[i] != '\0'; ++i)
    {
        ch = message[i];

        if (ch >= 'a' && ch <= 'z')
        {
            ch = (char)(((a_inv * ((ch - 'a' - b + 26)) % 26)) + 'a');
            message[i] = ch;
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
            ch = (char)(((a_inv * ((ch - 'A' - b + 26)) % 26)) + 'A');
            message[i] = ch;
        }
    }
    // printf("%d", a_inv);
    return message;
}

char *encrypt(char *message, int a, int b)
{
    int i;
    char ch;
    for (i = 0; message[i] != '\0'; ++i)
    {
        ch = message[i];

        if (ch >= 'a' && ch <= 'z')
        {
            ch = (char)((((a * (ch - 'a')) + b) % 26) + 'a');
            message[i] = ch;
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
            ch = (char)((((a * (ch - 'A')) + b) % 26) + 'A');
            message[i] = ch;
        }
    }
    return message;
}

int main()
{
    char message[100];
    char *enc_message, *de_message;
    int a = 3;
    int b = 2;
    printf("Enter a message to encrypt: ");
    gets(message);
    // printf("Enter key: ");
    // scanf("%d", &key);
    enc_message = encrypt(message, a, b);
    printf("Encrypted message: %s", enc_message);
    de_message = decrypt(message, a, b);
    printf("\nDecrypted message: %s", de_message);
    return 0;
}