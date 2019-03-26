#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f1(double);
double f2(double, double);

int main()
{

    double a = -3, b = 3, h = 0.2;

    printf("*************** Part 1 ***************\n");

    printf("x:\t");
    for (double x = a; x <= b; x += h) {
        char c = x + h < b ? '\t' : '\n';
        printf("%.3f%c", x, c);
    }

    printf("y:\t");
    for (double x = a; x <= b; x += h) {
        char c = x + h < b ? '\t' : '\n';
        printf("%.3f%c", f1(x), c);
    }

    printf("**************************************\n");

    printf("*************** Part 2 ***************\n");

    double a1=2, b1 = 4, h1 = 0.2;
    double c1=-3, d1 = 3, h2 = 0.15;
    printf("y\\x\t");
    for (double x = a1; x <= b1; x += h1) {
        char c = x + h1 < b1 ? '\t' : '\n';
        printf("%.3f%c", x, c);
    }

    for (double y = c1; y <= d1; y += h2) {
        printf("%.3f\t", y);
        for (double x = a1; x <= b1; x += h1) {
            char c = x + h1 < b1 ? '\t' : '\n';
            printf("%.3f%c", f2(x, y), c);
        }
    }

    printf("**************************************\n");
    return 0;
}

double f1(double x) {
    double e = 2.718282;
    if (x <= -2.0) {
        return pow(e, 2*x )-1;
    } else {
        if (x > -2.0 && x <= 2.0) {
            return x-pow(e,pow(-x,2) );
        } else {
            return (x + abs(3-x))/sqrt(x+1);
        }
    }
}

double f2(double x, double y) {
    return x*y-((y+1)/sqrt(x));
}
