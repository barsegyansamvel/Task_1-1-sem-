#include <stdio.h>
#include <stdlib.h>

/*
@brief Проверяет, помещается ли грань со сторонами a и b в отверстие r x s
@param a Первая сторона грани
@param b Вторая сторона грани
@param r Первая сторона отверстия
@param s Вторая сторона отверстия
@return 1, если помещается, 0 - если нет
*/
int proverka(double a, double b, double r, double s);

/*
@brief Точка входа в программу
@return 0 в случае успеха, -1 в случае ошибки ввода
*/
int main(void)
{
    double x, y, z;
    double r, s;

    printf("Vvedite storony kirpicha (x y z): ");
    if (scanf("%lf %lf %lf", &x, &y, &z) != 3) {
        printf("Oshibka vvoda!\n");
        return -1;
    }

    printf("Vvedite storony otverstiya (r s): ");
    if (scanf("%lf %lf", &r, &s) != 2) {
        printf("Oshibka vvoda!\n");
        return -1;
    }

    int result = 0;

    if (proverka(x, y, r, s))
    {
        result = 1;
    }
    else if (proverka(x, z, r, s))
    {
        result = 1;
    }
    else if (proverka(y, z, r, s))
    {
        result = 1;
    }


    if (result == 1)
    {
        printf("Kirpich PROYDET skvoz' otverstie.\n");
    }
    else
    {
        printf("Kirpich NE proydet skvoz' otverstie.\n");
    }

    return 0;
}

int proverka(double a, double b, double r, double s)
{
    if (a <= r)
    {
        if (b <= s)
        {
            return 1;
        }
    }

    if (a <= s)
    {
        if (b <= r)
        {
            return 1;
        }
    }

    return 0;
}