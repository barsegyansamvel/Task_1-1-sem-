#include <stdio.h>
#include <math.h>

/* 
@brief Вычисляет значение A по формуле
@param x Значение константы x
@param y Значение константы y
@return Вычисленное значение A
*/
double get_a(const double x, const double y);

/* 
@brief Вычисляет значение B по формуле
@param z Значение константы z
@return Вычисленное значение B
*/
double get_b(const double z);

/*
@brief Точка входа в программу
@return 0 в случае успеха
*/
int main(void)
{
    const double x = 1.426;
    const double y = -1.22;
    const double z = 3.5;

    const double a = get_a(x, y);
    const double b = get_b(z);

    printf("Ishodnie dannie:\n");
    printf("X: %lf\n", x);
    printf("Y: %lf\n", y);
    printf("Z: %lf\n\n", z);
    printf("Rezultat vichisleniy:\n");
    printf("A: %lf\n", a);
    printf("B: %lf\n", b);

    return 0;
}

double get_a(const double x, const double y)
{
    return (2.0 * cos(x - (3,14 / 6.0))) / (0.5 + pow(sin(y), 2.0));
}

double get_b(const double z)
{
    return (1.0 + pow(z, 2.0)) / (3.0 + pow(z, 2.0) / 5.0);
}