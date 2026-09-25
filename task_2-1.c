#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*
@brief Получает значение числа от пользователя
@return Полученное число типа double, -1 в случае ошибки ввода
*/
double get_chislo();

/*
@brief Получает значение выбранного пользователем действия
@return Полученное число (номер операции) типа int, -1 в случае ошибки ввода
*/
int get_deistvie();

/*
@brief Перечисление действий с переменными
@details AREA - Вычисление площади
         PERIMETER - Вычисление периметра
*/
enum ActionType
{
    PLOSHAD = 1,
    PERIMETR = 2
};

/*
@brief Точка входа в программу
@return 0 в случае успеха, -1 в случае ошибки ввода
*/
int main(void)
{
    printf("Введите первый катет (a): ");
    const double a = get_chislo();

    printf("Введите второй катет (b): ");
    const double b = get_chislo();
    
    const int deistvie = get_deistvie();

    switch (deistvie)
    {
        case PLOSHAD:
            printf("Ploshad treygolnika ravna: %lf\n", 0.5 * a * b);
            break;

        case PERIMETR:
            printf("Perimetr treygolnika raven: %lf\n", a + b + sqrt(pow(a, 2) + pow(b, 2)));
            break;

        default:
            printf("Oshibka: neverno vibrano deistvie\n");
            return -1;
    }

    return 0;
}

double get_chislo()
{
    double chislo;
    if (scanf("%lf", &chislo) != 1) {
        printf("Ошибка ввода числа!\n");
        exit(EXIT_FAILURE);
    }
    return chislo;
}

int get_deistvie()
{
    int deistvie;
    printf("\nVyberite deystvie:\n");
    printf("1 - Вычислить площадь\n");
    printf("2 - Увеличить периметр");
    printf("Vash vybor: ");
    
    if (scanf("%d", &deistvie) != 1) {
        printf("Oshibka vvoda deiystviya\n");
        exit(EXIT_FAILURE);
    }
    return deistvie;
}
