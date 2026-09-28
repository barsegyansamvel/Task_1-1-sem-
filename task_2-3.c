#include <stdio.h>
#include <stdlib.h>

/**
@brief Запрашивает у пользователя число с проверкой ввода
@return Введенное число типа double
*/
double vvod_chisla();

/**
@brief Проверяет, помещается ли грань со сторонами a и b в отверстие r x s
@param a Первая сторона грани
@param b Вторая сторона грани
@param r Первая сторона отверстия
@param s Вторая сторона отверстия
@return 1, если помещается, 0 - если нет
*/
int proverka(const double a, const double b, const double r, const double s);

/**
@brief Точка входа в программу
@return 0 в случае успеха
*/
int main(void)
{
    double x = vvod_chisla();
    double y = vvod_chisla();
    double z = vvod_chisla();

    double r = vvod_chisla();
    double s = vvod_chisla();

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

double vvod_chisla()
{
    double value = 0;
    printf("Vvedite chislo: ");
    if (scanf("%lf", &value) != 1)
    {
        printf("Oshibka vvoda chisla!\n");
        exit(EXIT_FAILURE);
    }
    return value;
}

int proverka(const double a, const double b, const double r, const double s)
{
    if ((a <= r && b <= s) || (a <= s && b <= r))
    {
        return 1;
    }
    return 0;
}
