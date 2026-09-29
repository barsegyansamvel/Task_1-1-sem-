#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/**
@brief считывает целое значение с клавиатуры с проверкой ввода
@return возвращает считанное значение
*/
int get_chislo();

/**
@brief проверяет, что число положительное
@param value - проверяемое значение
*/
void check_positive(const double value);

/**
@brief считывает вещественное значение с клавиатуры с проверкой ввода
@return возвращает считанное значение
*/
double get_double();

/**
@brief рассчитывает сумму n членов последовательности
@param n - заданное число членов
@return рассчитанное значение
*/
double get_sum_n(const int n);

/**
@brief рассчитывает сумму членов последовательности с точностью e
@param e - заданная точность
@return рассчитанное значение
*/
double get_sum_e(const double e);

/**
@brief рассчитывает коэффициент рекуррентного выражения
@param i текущий индекс
@return рассчитанное значение коэффициента
*/
double get_recurent(const int i);

/**
@brief Точка входа в программу
@return 0, если программа выполнена корректно, иначе 1
*/
int main(void) {
  printf("Vvedite n: \n");
  int n = get_chislo();
  check_positive((double)n);
  printf("Summa %d chlenov posledovatelnosti ravna %lf\n", n, get_sum_n(n));

  printf("Vvedite e: \n");
  double e = get_double();
  check_positive(e);
  printf("Summa posledovatelnosti s tochnostyu %lf ravna %lf\n", e, get_sum_e(e));

  return 0;
}

int get_chislo() {
  int chislo = 0;
  if (!(scanf("%d", &chislo) == 1)) {
    fprintf(stderr, "Error\n");
    exit(1);
  }
  return chislo;
}

void check_positive(const double value) {
  if (!(value > 0)) {
    fprintf(stderr, "Error\n");
    exit(1);
  }
}

double get_double() {
  double chislo = 0;
  if (!(scanf("%lf", &chislo) == 1)) {
    fprintf(stderr, "Error\n");
    exit(1);
  }
  return chislo;
}

double get_sum_n(const int n) {
  double current = 1;
  double result = current;
  for (int i = 1; i < n; i++) {
    current *= get_recurent(i);
    result += current;
  }
  return result;
}

double get_sum_e(const double e) {
    double current = 1;
    double result = 0;
    for (int i = 0; fabs(current) >= e; i++) {
        result += current;
        current *= get_recurent(i + 1);
    }
    return result;
}

double get_recurent(const int i) {
  return -1.0 / (i * (i + 1.0));
}