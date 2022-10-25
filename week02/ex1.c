#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
    int i;
    unsigned int ui;
    long l;
    float f;
    double d;
    i = INT_MAX;
    ui = UINT_MAX;
    l = LONG_MAX;
    f = FLT_MAX;
    d = DBL_MAX;
    printf("int: %i of size %ld\n", i, sizeof(i));
    printf("unsigned int: %u of size %ld\n", ui, sizeof(ui));
    printf("long int: %li of size %ld\n", l, sizeof(l));
    printf("float: %f of size %ld\n", f, sizeof(f));
    printf("double: %lf of size %ld\n", d, sizeof(d));
    return 0;
}