#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*
@brief Запрашивает у пользователя число и проверяет ввод
@return Введенное число типа double
*/
double get_chislo();

/*
@brief Точка входа в программу
@return 0 в случае успеха, -1 в случае ошибки ввода
*/
int main(void)
{
    const double a = 2;

    printf("Vvedite znachenie x: ");
    const double x = get_chislo();


    double y=0;

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

double get_chislo()
{
    double chislo = 0.0;
    if (scanf("%lf", &chislo) != 1) {
        printf("Oshibka vvoda chisla!\n");
        exit(EXIT_FAILURE);
    }
    return chislo;
}
