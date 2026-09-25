#include <stdio.h>
#include <stdlib.h>

/*
@brief Запрашивает у пользователя стороны кирпича (x, y, z)
@param x Указатель на переменную для первой стороны
@param y Указатель на переменную для второй стороны
@param z Указатель на переменную для третьей стороны
*/
void vvod_kirpich(double* x, double* y, double* z);

/*
@brief Запрашивает у пользователя стороны отверстия (r, s)
@param r Указатель на переменную для первой стороны
@param s Указатель на переменную для второй стороны
*/
void vvod_otverstie(double* r, double* s);

/*
@brief Проверяет, помещается ли грань со сторонами a и b в отверстие r x s
@param a Первая сторона грани
@param b Вторая сторона грани
@param r Первая сторона отверстия
@param s Вторая сторона отверстия
@return 1, если помещается, 0 - если нет
*/
int proverka(const double a, const double b, const double r, const double s);

/*
@brief Точка входа в программу
@return 0 в случае успеха, -1 в случае ошибки ввода
*/
int main(void)
{
    double x=0, y=0, z=0;
    double r=0, s=0;

    input_kirpich(&x, &y, &z);
    input_otverstie(&r, &s);

    if (proverka(x, y, r, s) || proverka(x, z, r, s) || proverka(y, z, r, s))
    {
        printf("\nKirpich PROYDET skvoz' otverstie.\n");
    }
    else
    {
        printf("\nKirpich NE proydet skvoz' otverstie.\n");
    }
    return 0;
}

void vvod_kirpich(double* x, double* y, double* z)
{
    printf("Vvedite storony kirpicha (x y z): ");
    if (scanf("%lf %lf %lf", x, y, z) != 3)
    {
        printf("Oshibka vvoda!\n");
        exit(EXIT_FAILURE);
    }
}

void vvod_otverstie(double* r, double* s)
{
    printf("Vvedite storony otverstiya (r s): ");
    if (scanf("%lf %lf", r, s) != 2)
    {
        printf("Oshibka vvoda!\n");
        exit(EXIT_FAILURE);
    }
}

int fits(double a, double b, double r, double s)
{
    if ((a <= r && b <= s) || (a <= s && b <= r))
    {
        return 1;
    }
    return 0;
}
