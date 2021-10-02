//Submitted by Shivam Balwani
//ID:201851122
//Batch:CS
//Code:Fiestel Network
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int function(unsigned int y, unsigned int key)
{
    unsigned int x = y ^ key;
    unsigned int result;
    int b1 = (((int)(x >> 0)) + 1) % 16;
    int b2 = (((int)(x >> 4)) + 1) % 16;
    int b3 = (((int)(x >> 8)) + 1) % 16;
    int b4 = (((int)(x >> 12)) + 1) % 16;
    int b5 = (((int)(x >> 16)) + 1) % 16;
    int b6 = (((int)(x >> 20)) + 1) % 16;
    int b7 = (((int)(x >> 24)) + 1) % 16;
    int b8 = ((int)(x >> 28) + 1) % 16;
    result = ((int)b8 << 28) | ((int)b7 << 24) | ((int)b6 << 20) | ((int)b5 << 16) | ((int)b4 << 12) | ((int)b3 << 8) | ((int)b2 << 4) | ((int)b1);
    // printf("%d %d %d %d %d %d %d %d %d", b1, b2, b3, b4, b5, b6, b7, b8, result);
    return result;
}

int main()
{
    unsigned long long int v;
    unsigned int x, y, l1, key, f1, r1, r0, l0, f0;
    printf("Enter plain text 64 bit:");
    scanf("%llu", &v);
    x = (v >> 32);
    y = (v);
    printf("Enter key:");
    scanf("%ld", &key);
    l1 = y;
    f1 = function(y, key);
    r1 = x ^ f1;
    unsigned long long int encrypt = (unsigned long long int)l1 << 32 | r1;
    printf("--------------------------------Outputs--------------------------------");
    printf("\nEncryption: %llu", encrypt);
    r0 = l1;
    f0 = function(l1, key);
    l0 = r1 ^ f0;
    unsigned long long int decrypt = (unsigned long long int)l0 << 32 | r0;
    printf("\nDecryption: %llu", decrypt);
    return 0;
}