#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>

unsigned char gmul(unsigned char b, unsigned char a)
{
    unsigned char p = 0;
    unsigned char counter;
    unsigned char hi_bit_set;
    for (counter = 0; counter < 8; counter++)
    {
        if ((b & 1) == 1)
            p ^= a;
        hi_bit_set = (a & 0x80);
        a <<= 1;
        if (hi_bit_set == 0x80)
            a ^= 0x1b;
        b >>= 1;
    }
    return p;
}

int main()
{
    uint8_t input[4][4];
    printf("Enter 16 values");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int in;
            scanf("%x", &in);
            input[i][j] = (uint8_t)in;
        }
    }
    printf("Original Matrix\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%x ", input[i][j]);
        }
        printf("\n");
    }
    uint8_t arr[8];
    for (int i = 1; i < 4; i++)
    {
        for (int j = i; j < i + 4; j++)
        {
            arr[j - i] = input[i][j & 3];
        }
        for (int j = 0; j < 4; j++)
        {
            input[i][j] = arr[j];
        }
    }
    printf("Shifted Matrix First\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%x ", input[i][j]);
        }
        printf("\n");
    }
    for (int k = 0; k < 3; k++)
    {
        for (int i = 1; i < 4; i++)
        {
            for (int j = i; j < i + 4; j++)
            {
                arr[j - i] = input[i][j & 3];
            }
            for (int j = 0; j < 4; j++)
            {
                input[i][j] = arr[j];
            }
        }
    }
    printf("Shifted Matrix to original\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%x ", input[i][j]);
        }
        printf("\n");
    }

    // uint8_t arr_2[8];
    // for (int i = 1; i < 4; i++)
    // {
    //     for (int j = i; j < i + 4; j++)
    //     {
    //         printf("%d\n", j & 3);
    //         printf("%d\n", j - i);
    //         arr_2[j - i] = input[i][j & 3];
    //     }
    //     for (int j = 0; j < 4; j++)
    //     {
    //         input[i][j] = arr_2[j];
    //     }
    // }
    // printf("Shifted Matrix\n");
    // for (int i = 0; i < 4; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         printf("%x ", input[i][j]);
    //     }
    //     printf("\n");
    // }

    // uint8_t pre[4][4] = {{2, 3, 1, 1}, {1, 2, 3, 1}, {1, 1, 2, 3}, {3, 1, 1, 2}};
    // printf("Predifined Matrix\n");
    // for (int i = 0; i < 4; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         printf("%x ", pre[i][j]);
    //     }
    //     printf("\n");
    // }
    // uint8_t result[4][4];
    // for (int i = 0; i < 4; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         result[i][j] = 0;
    //         for (int k = 0; k < 4; k++)
    //         {
    //             int res = (uint8_t)(gmul((unsigned char)(pre[i][k]), (unsigned char)(input[k][j])));
    //             result[i][j] = result[i][j] ^ res;
    //         }
    //     }
    // }
    // printf("Shifited Matrix\n");
    // for (int i = 0; i < 4; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         printf("%x ", result[i][j]);
    //     }
    //     printf("\n");
    // }
    // uint8_t pre_2[4][4] = {{14, 11, 13, 9}, {9, 14, 11, 13}, {13, 9, 14, 11}, {11, 13, 9, 14}};
    // printf("Predifined Matrix\n");
    // for (int i = 0; i < 4; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         printf("%x ", pre[i][j]);
    //     }
    //     printf("\n");
    // }
    // uint8_t result_2[4][4];
    // for (int i = 0; i < 4; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         result_2[i][j] = 0;
    //         for (int k = 0; k < 4; k++)
    //         {
    //             int res = (uint8_t)(gmul((unsigned char)(pre_2[i][k]), (unsigned char)(result[k][j])));
    //             result_2[i][j] = result_2[i][j] ^ res;
    //         }
    //     }
    // }
    // printf("ReShifited Matrix\n");
    // for (int i = 0; i < 4; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         printf("%x ", result_2[i][j]);
    //     }
    //     printf("\n");
    // }
    return 0;
}