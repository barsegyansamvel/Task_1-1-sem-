#include <stdio.h>

/*
@brief Вычисляет силу тяжести
@param m Масса тела (кг)
@return Сила тяжести (Н)
*/
double get_sila_tyazh(const double m);

/*
@brief Вычисляет вес тела
@param m Масса тела (кг)
@return Вес тела (Н)
*/
double get_ves(const double m);

/*
@brief Точка входа в программу
@return 0 в случае успеха
*/
int main(void)
{
    double m=0;
    printf("Vvedite massu meshka (kg): ");
    scanf("%lf", &m);

    printf("\nRezultaty\n");
    printf("Sila tyazhesti: %lf N\n", get_sila_tyazh(m));
    printf("Ves meshka: %lf N\n", get_ves(m));

    return 0;
}

const double g = 9.8;

double get_sila_tyazh(const double m)
{
    return m * g;
}

double get_ves(const double m)
{
    return m * g;
}
