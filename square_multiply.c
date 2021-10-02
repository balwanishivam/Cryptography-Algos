#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1025

int sqrm(int x, int g)
{

    int c[10000], i = 0;
    while (x > 0)
    {
        c[i] = x % 2;
        i += 1;
        x /= 2;
    }

    int z = 1;
    for (int j = i - 1; j > -1; j -= 1)
    {
        z = (z * z) % N;
        if (c[j] == 1)
            z = (z * g) % N;
    }

    return z;
}
int main()
{
    int a, b;
    printf("Enter for Alice: ");
    scanf("%d", &a);
    printf("\nEnter for Bob: ");
    scanf("%d", &b);

    int ka = sqrm(a, 2);
    int kb = sqrm(b, 2);

    printf("Value of g_a and g_b are: %d %d", ka, kb);
    ka = (sqrm(b, ka)) % N;
    kb = (sqrm(a, kb)) % N;

    printf("\nFinal keys are: %d %d", ka, kb);
    return 0;
}