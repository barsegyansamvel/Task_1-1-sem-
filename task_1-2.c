#include <stdio.h>
#include <math.h>

/*
@brief Вычисляет площадь одной грани куба
@param a Длина ребра куба
@return Площадь грани
*/
double get_plosh_gran(const double a);

/*
@brief Вычисляет площадь полной поверхности куба
@param a Длина ребра куба
@return Площадь полной поверхности
*/
double get_plosh_poln_pov(const double a);

/*
@brief Вычисляет объем куба
@param a Длина ребра куба
@return Объем куба
*/
double get_obyem(const double a);

/*
@brief Точка входа в программу
@return 0 в случае успеха
*/
int main(void)
{
    double a=0;
    printf("Vvedite dlinu rebra kuba (a): ");
    scanf("%lf", &a);

    printf("\nRezultaty:\n");
    printf("Ploshchad' grani: %.3lf\n", get_plosh_gran(a));
    printf("Ploshchad' polnoy poverkhnosti: %.3lf\n", get_plosh_poln_pov(a));
    printf("Ob'em: %.3lf\n", get_obyem(a));

    return 0;
}

double get_plosh_gran(const double a)
{
    return pow(a, 2.0);
}

double get_plosh_poln_pov(const double a)
{
    return 6.0 * pow(a, 2.0);
}

double get_obyem(const double a)
{
    return pow(a, 3.0);
}
