#include <stdio.h>

long long tribonacci(int);

int main(void)
{
    int x;
    long long res;
    // scanf("%d", &x);
    printf("%lld\n", tribonacci(4));
    printf("%lld\n", tribonacci(36));
    return 0;
}

long long tribonacci(int n)
{
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;
    n -= 2;
    long long x1 = 0, x2 = 1, x3 = 1;
    while (n--)
    {
        long long sum = x1 + x2 + x3;
        x1 = x2;
        x2 = x3;
        x3 = sum;
    }
    return x3;
}