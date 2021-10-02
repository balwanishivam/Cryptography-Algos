//Submitted by Shivam Balwani
//ID:201851122
//Batch:CS
//Code:Playfair Cipher
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void generatekeymatrix(char key[], int ks, char keymatrix[5][5])
{
    int i, j, k, flag = 0, *visited;
    visited = (int *)calloc(26, sizeof(int));
    for (i = 0; i < ks; i++)
    {
        if (key[i] != 'j')
            visited[key[i] - 97] = 2;
    }

    visited['j' - 97] = 1;

    i = 0;
    j = 0;

    for (k = 0; k < ks; k++)
    {
        if (visited[key[k] - 97] == 2)
        {
            visited[key[k] - 97] -= 1;
            keymatrix[i][j] = key[k];
            j++;
            if (j == 5)
            {
                i++;
                j = 0;
            }
        }
    }

    for (k = 0; k < 26; k++)
    {
        if (visited[k] == 0)
        {
            keymatrix[i][j] = (char)(k + 97);
            j++;
            if (j == 5)
            {
                i++;
                j = 0;
            }
        }
    }
    printf("The Key Matrix is:\n");
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("%c  ", keymatrix[i][j]);
        }
        printf("\n");
    }
}
char *encrypt(char *message, char keymap[5][5])
{
    int i, j, r1 = 0, r2 = 0, c1 = 0, c2 = 0, k;
    for (i = 0; i < strlen(message); i++)
    {
        if (i % 2 == 0)
        {
            for (k = 0; k < 5; k++)
            {
                for (j = 0; j < 5; j++)
                {
                    if (keymap[k][j] == message[i])
                    {
                        r1 = k;
                        c1 = j;
                    }
                    if (keymap[k][j] == message[i + 1])
                    {
                        r2 = k;
                        c2 = j;
                    }
                }
            }
            if (r1 == r2)
            {
                if (c2 == 4)
                {
                    message[i] = keymap[r1 % 5][(c1 + 1) % 5];
                    message[i + 1] = keymap[r2 % 5][0];
                }
                else
                {
                    message[i] = keymap[r1 % 5][(c1 + 1) % 5];
                    message[i + 1] = keymap[r2 % 5][(c2 + 1) % 5];
                }
            }
            else if (c1 == c2)
            {
                if (r2 == 4)
                {
                    message[i] = keymap[(r1 + 1) % 5][c1 % 5];
                    message[i + 1] = keymap[0][c2 % 5];
                }
                else
                {
                    message[i] = keymap[(r1 + 1) % 5][c1 % 5];
                    message[i + 1] = keymap[(r2 + 1) % 5][c2 % 5];
                }
            }
            else if (r1 != r2 && c1 != c2)
            {
                message[i] = keymap[r1 % 5][c2 % 5];
                message[i + 1] = keymap[r2 % 5][c1 % 5];
            }
            i++;
        }
        else
        {
            i++;
        }
    }
    return message;
}
char *decrypt(char *encryptmsg, char keymap[5][5])
{
    int i, j, r1 = 0, r2 = 0, c1 = 0, c2 = 0, k;
    for (i = 0; i < strlen(encryptmsg); i++)
    {
        r1 = 0, r2 = 0, c1 = 0, c2 = 0;
        if (i % 2 == 0)
        {
            for (k = 0; k < 5; k++)
            {

                for (j = 0; j < 5; j++)
                {
                    if (keymap[k][j] == encryptmsg[i])
                    {
                        r1 = k;
                        c1 = j;
                    }
                    if (keymap[k][j] == encryptmsg[i + 1])
                    {
                        r2 = k;
                        c2 = j;
                    }
                }
            }
            if (r1 == r2)
            {
                if (c2 == 0)
                {
                    encryptmsg[i] = keymap[r1 % 5][(c1 - 1 + 5) % 5];
                    encryptmsg[i + 1] = keymap[r2 % 5][4];
                }
                else
                {
                    encryptmsg[i] = keymap[r1 % 5][(c1 - 1 + 5) % 5];
                    encryptmsg[i + 1] = keymap[r2 % 5][(c2 - 1 + 5) % 5];
                }
            }
            else if (c1 == c2)
            {
                if (r2 == 0)
                {
                    encryptmsg[i] = keymap[(r1 - 1 + 5) % 5][c1 % 5];
                    encryptmsg[i + 1] = keymap[4][c2 % 5];
                }
                else
                {
                    encryptmsg[i] = keymap[(r1 - 1 + 5) % 5][c1 % 5];
                    encryptmsg[i + 1] = keymap[(r2 - 1 + 5) % 5][c2 % 5];
                }
            }
            else if (r1 != r2 && c1 != c2)
            {
                encryptmsg[i] = keymap[r1 % 5][c2 % 5];
                encryptmsg[i + 1] = keymap[r2 % 5][c1 % 5];
            }
            i++;
        }
        else
        {
            i++;
        }
    }
    return encryptmsg;
}
void prepare(char message[])
{
    int len = 100;
    char *temp = calloc(len, sizeof(char));
    int j = 0;
    for (int i = 0; i < strlen(message); i++)
    {
        if (message[i] == message[i + 1])
        {
            temp[j++] = message[i];
            temp[j] = 'x';
            temp[++j] = message[i + 1];
        }
        else
        {
            temp[j++] = message[i];
        }
    }
    int size = strlen(temp);
    if (size % 2 != 0)
    {
        temp[size++] = 'x';
        temp[size] = '\0';
    }
    printf("\nEdited Message: %s", temp);
    strcpy(message, temp);
}
int main()
{

    char key[30];
    char message[100];
    char keymatrix[5][5];
    char *encryptmsg;
    char *msg;
    int i = 0;
    printf("Enter key: ");
    gets(key);
    int len = strlen(key);
    generatekeymatrix(key, len, keymatrix);
    printf("Enter your plain text:");
    gets(message);
    prepare(message);
    int size = strlen(message);
    encryptmsg = encrypt(message, keymatrix);
    printf("\nCIPHER TEXT: %s", encryptmsg);
    msg = decrypt(encryptmsg, keymatrix);
    printf("\nDECIPHER TEXT: %s", msg);
    return 0;
}
