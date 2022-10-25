#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Point
{
    double x;
    double y;
};

double distance(struct Point, struct Point);
double area(struct Point, struct Point, struct Point);

int main()
{
    struct Point a = {2.5, 6};
    struct Point b = {1, 2.2};
    struct Point c = {10, 6};
    double dist = distance(a, b);
    double ar = area(a, b, c);
    printf("%lf %lf", dist, ar);
    return 0;
}

double distance(struct Point p1, struct Point p2)
{
    double d = pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2);
    return (sqrt(d));
}

double area(struct Point a, struct Point b, struct Point c)
{
    return (0.5 * fabs(a.x * b.y - b.x * a.y + b.x * c.y - c.x * b.y + c.x * a.y - a.x * c.y));
}