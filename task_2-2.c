#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*
@brief Точка входа в программу
@return 0 в случае успеха, -1 в случае ошибки ввода
*/
int main(void)
{
    const double a = 2;
    double x;

    printf("Vvedite znachenie x: ");
    if (scanf("%lf", &x) != 1) {
        printf("Oshibka vvoda!\n");
        return -1;
    }

    double y;

    if (x < 1)
    {
        y = 1;
    }
    else if (x >= 1)
    {
        y = a * pow(x, 2 * log(x));
    }
    else if (x <= 2)
    {
        y = a * pow(x, 2 * log(x));
    }
    else
    {
        y = exp(a * x) * cos(x);
    }

    printf("Rezultat:\n");
    printf("x = %lf\n", x);
    printf("y = %lf\n", y);

    return 0;
}