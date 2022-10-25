#include <stdio.h>
#include <string.h>
// #include <math.h>

void convert(long long, int, int);
long long to_dec(long long, int);
void from_dec(long long, int, char[]);
long long pow(long long, int);
void print_reversed(char[]);
int is_correct(long long, int);

int main(void)
{
    long long x;
    int s, t;
    scanf("%lld %d %d", &x, &s, &t);

    convert(x, s, t);

    return 0;
}

void convert(long long x, int s, int t)
{
    if ((2 > s || 10 < s) || (2 > t || 10 < t) || !is_correct(x, s))
    {
        puts("cannot convert!");
        return;
    }
    long long dec = to_dec(x, s);
    char result[64];
    from_dec(dec, t, result);

    print_reversed(result);
}

int is_correct(long long x, int s)
{
    while (x)
    {
        int d = x % 10;
        if (d >= s)
            return 0;
        x /= 10;
    }
    return 1;
}

void print_reversed(char str[])
{
    int size = strlen(str);
    for (int i = size - 1; i >= 0; i--)
    {
        putchar(str[i]);
    }
}

void from_dec(long long x, int from, char res[])
{
    // printf("%lld from decimal to %d:\n", x, from);
    int count = 0;
    while (x)
    {
        int rem = x % from;
        x /= from;
        char crem[2];
        sprintf(crem, "%d", rem);
        res[count] = crem[0];
        // printf("%lld (x = %lld, rem = %d, pow = %lld)\n", res, x, rem, pow(10, count));
        count++;
    }
    res[count] = '\0';
    // printf(" = %lld", res);
}

long long to_dec(long long x, int to)
{
    long long dec = 0;
    int count = 0;
    while (x)
    {
        int d = x % 10;
        x /= 10;
        dec += d * pow(to, count);
        count++;
    }
    return dec;
}

long long pow(long long x, int exp)
{
    // printf("%lld ** %d", x, exp);
    long long res = 1;
    while (exp--)
    {
        res *= x;
    }
    // printf("= %lld\n", res);
    return res;
}