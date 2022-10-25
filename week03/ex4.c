#include <stdio.h>
#include <stdlib.h>

void *aggregate(void *base, size_t size, int n, void *initial_value, void *(*opr)(const void *, const void *));

void *addInt(const void *a, const void *b)
{
    int *x = malloc(sizeof(int *));
    *x = (*(int *)a) + (*(int *)b);
    return x;
}

void *addDouble(const void *a, const void *b)
{
    double *x = malloc(sizeof(double *));
    *x = (*(double *)a) + (*(double *)b);
    return x;
}

void *mulInt(const void *a, const void *b)
{
    int *x = malloc(sizeof(int *));
    *x = (*(int *)a) * (*(int *)b);
    return x;
}

void *mulDouble(const void *a, const void *b)
{
    double *x = malloc(sizeof(double *));
    *x = (*(double *)a) * (*(double *)b);
    return x;
}

void *meanInt(const void *a, const void *b)
{
    return addInt(a, b);
}

void *meanDouble(const void *a, const void *b)
{
    return addDouble(a, b);
}

void *aggregate(void *base, size_t size, int n, void *initial_value, void *(*opr)(const void *, const void *))
{

    void *output;

    if (size == sizeof(int))
    { // base is a pointer to an integer
        int *result = malloc(size);
        *result = *((int *)initial_value);
        for (int i = 0; i < n; i++)
        {
            result = (int *)(opr(((int *)base + i), result));
        }
        if (opr == meanInt)
        {
            *result = (*result) / n;
        }
        output = (void *)result;
    }
    else
    { // base is a pointer to a double
        double *result = malloc(size);
        *result = *((double *)initial_value);
        for (int i = 0; i < n; i++)
        {
            result = (double *)(opr(((double *)base + i), result));
        }
        if (opr == meanDouble)
        {
            *result = (*result) / n;
        }
        output = (void *)result;
    }

    return output;
}

int main()
{

    int *ints = malloc(sizeof(int) * 5);
    double *doubles = malloc(sizeof(double) * 5);

    for (int i = 0; i < 5; i++)
    {
        ints[i] = i + 1;
        doubles[i] = ((double)(i + 1)) * 1.1;
    }

    int zi = 0;
    int *zero_int = &zi;
    int oi = 1;
    int *one_int = &oi;
    double zd = 0;
    double *zero_double = &zd;
    double od = 1;
    double *one_double = &od;

    // Addition

    int *result1a = aggregate(ints, sizeof(int), 5, zero_int, addInt);

    printf("%d\n", *result1a);

    double *result2a = aggregate(doubles, sizeof(double), 5, zero_double, addDouble);

    printf("%f\n", *result2a);

    // Multiplication

    int *result1m = aggregate(ints, sizeof(int), 5, one_int, mulInt);

    printf("%d\n", *result1m);

    double *result2m = aggregate(doubles, sizeof(double), 5, one_double, mulDouble);

    printf("%f\n", *result2m);

    // Mean

    int *result1mean = aggregate(ints, sizeof(int), 5, zero_int, meanInt);

    printf("%d\n", *result1mean);

    double *result2mean = aggregate(doubles, sizeof(double), 5, zero_double, meanDouble);

    printf("%f\n", *result2mean);

    // free the pointers
    free(result1a);
    free(result1m);
    free(result1mean);
    free(result2a);
    free(result2m);
    free(result2mean);
    free(doubles);
    free(ints);

    return EXIT_SUCCESS;
}