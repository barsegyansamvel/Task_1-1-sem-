#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/**
@brief Вычисляет значение функции e^x
@param x Аргумент функции
@return Возвращает значение функции
*/
double znach_f_e(const double x);

/**
@brief считывает значение с клавиатуры с проверкой ввода
@return возвращает считанное значение
*/
double get_chislo();

/**
@brief Проверяет корректность введённых значений
@param A Начало интервала
@param B Конец интервала
@param H Шаг
@param epsilon Точность
*/
void check_input(const double A, const double B, const double H, const double epsilon);

/**
@brief Вычисляет сумму ряда с заданной точностью
@param x Аргумент
@param epsilon Точность вычисления
@return Возвращает рассчитанную сумму ряда
*/
double sum_ryada(const double x, const double epsilon);

/**
@brief Вычисляет коэффициент рекуррентного выражения
@param n Номер члена последовательности
@param x Аргумент
@return Возвращает значение коэффициента
*/
double get_n(const int n, const double x);

/**
@brief Точка входа в программу
@return 0, если программа выполнена корректно, иначе 1
*/
int main(void) {
  printf("Vvedite interval: \n");
  const double A = get_chislo();
  const double B = get_chislo();
  printf("Vvedite shag: \n");
  const double H = get_chislo();
  printf("Vvedite tochnost: \n");
  const double EPSILON = get_chislo();

  check_input(A, B, H, EPSILON);

  printf("Interval: [%.2lf, %.2lf], shag: %.2lf, tochnost: %.4lf \n", A, B, H, EPSILON);
  printf("x\t\tf(x)\t\tS(x)\t\t \n");

  const int n = (int)round((B - A) / H);
  for (int k = 0; k <= n; k++) {
    const double x = A + k * H;
    printf("%.2lf\t\t%.4lf\t\t%.4lf\t\t \n", x, znach_f_e(x), sum_ryada(x, EPSILON));
  }

  printf("\n");
  return 0;
}

double znach_f_e(const double x) {
  return exp(x);
}

void check_input(const double A, const double B, const double H, const double epsilon) {
  if (A >= B) {
    fprintf(stderr, "Oshibka: nachalo intervala dolzhno byt menshe konca.\n");
    exit(1);
  }
  if (H <= 0) {
    fprintf(stderr, "Oshibka: shag dolzhen byt polozhitelnym.\n");
    exit(1);
  }
  if (epsilon <= 0) {
    fprintf(stderr, "Oshibka: tochnost dolzhna byt polozhitelnoy.\n");
    exit(1);
  }
}

double sum_ryada(const double x, const double epsilon) {
  double sum = 0.0;
  double current = 1.0;

  for (int i = 0; fabs(znach_f_e(x) - sum) > epsilon; i++) {
    sum += current;
    current *= get_n(i + 1, x);
  }
  return sum;
}

double get_n(const int n, const double x) {
  return x / n;
}

double get_chislo() {
  double chislo = 0;
  if (!(scanf("%lf", &chislo) == 1)) {
    fprintf(stderr, "Error\n");
    exit(1);
  }
  return chislo;
}
