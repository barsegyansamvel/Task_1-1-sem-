#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
@brief считывает значение,
введенное с клавиатуры с проверкой ввода
@return считанное значение
*/
double get_value();

/**
@brief проверяет, что шаг положительный
@param step значение проверяемой переменной
*/
void check_step(const double step);

/**
@brief проверяет, принадлежит ли значение аргумента функции её области определения
@param x - аргумент функции
@return true, если аргумент принадлежит ООФ, иначе false
*/
bool proverka(const double x);

/**
@brief рассчитывает значение функции y по заданной формуле
@param x значение аргумента
@return значение функции
*/
double get_y(const double x);

/**
@brief Точка входа в программу
@return возвращает 0, если программа выполнена корректно
*/
int main(void)
{
    printf("Vvedite nachalnoe znachenie: ");
    double start = get_value();

    printf("Vvedite konechnoe znachenie: ");
    double end = get_value();

    printf("Vvedite shag: ");
    double step = get_value();
    check_step(step);

    for (double x = start; x < end + DBL_EPSILON; x = x + step)
    {
        if (proverka(x))
        {
            printf("x = %lf, y = %lf\n", x, get_y(x));
        }
        else
        {
            printf("x = %lf, ne prinadlezhit OOF\n", x);
        }
    }

    return 0;
}

double get_value()
{
    double value = 0.0;
    if (scanf("%lf", &value) != 1)
    {
        printf("Error\n");
        exit(EXIT_FAILURE);
    }
    return value;
}

void check_step(const double step)
{
    if (step <= 0.0)
    {
        printf("Oshibka, shag dolzhen byt polozhitelnym\n");
        exit(EXIT_FAILURE);
    }
}

bool proverka(const double x)
{
/* функция y = 0.29*x**3 + x - 1.2502 определена для всех x,
поэтому область определения - вся числовая прямая.
возвращаем true всегда.
(создал для проверки, которая написана в условии)*/
    return true;
}

double get_y(const double x)
{
    return 0.29 * pow(x, 3.0) + x - 1.2502;
}