#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
@enum Для выбора операций.
*/
enum {
    operation_one = 1,
    operation_two = 2,
    operation_three = 3 };

/**
@enum Для выбора метода заполнения массива.
*/
enum {
    arrscanf = 1,
    arrauto = 2 };

/**
@brief Считывает значение введённое с клавиатуры с проверкой ввода.
@return Считанное значение.
*/
int get_value();

/**
@brief Проверяет массив на ошибку выделения памяти.
@param ptr Массив, который проверяем.
*/
void check_array(int *ptr);

/**
@brief Находит произведение элементов с чётным значением
@param ptr Массив
@param length Длина массива
@return Возвращает произведение
*/
long long product_even(int *ptr, const size_t length);

/**
@brief Выводит массив на экран
@param ptr Массив
@param length Длина массива
*/
void print_arr(int *ptr, const size_t length);

/**
@brief Заменяет элементы с нечётными номерами на квадраты их номеров
@param ptr Массив
@param length Длина массива
*/
void replace_odd_indexes(int *ptr, const size_t length);

/**
@brief Проверяет, есть ли положительные элементы, делящиеся на k с остатком 2
@param ptr Массив
@param length Длина массива
@return 1, если есть; 0, если нет
*/
int check_divisible(int *ptr, const size_t length);

/**
@brief Заполняет массив введёнными элементами.
@param ptr Массив, который заполняет.
@param length Длина массива.
*/
void scanf_arr(int *ptr, const size_t length);

/**
@brief Заполняет массив случайными элементами из заданного промежутка.
@param ptr Массив, который заполняет.
@param length Длина массива.
*/
void auto_arr(int *ptr, const size_t length);

/**
@brief Точка входа в программу.
@return Возвращает 0, если программа выполнена корректно.
*/
int main(void) {
  setlocale(LC_ALL, "ru_RU.UTF-8");

  printf("Введите количество элементов массива: \n");
  size_t length = (size_t)get_value();

  int *ptr = malloc(sizeof(int) * length);
  check_array(ptr);

  printf("Выберите операцию: \n %d - Заполнить массив вручную. \n %d - "
         "Заполнить массив автоматически. \n",
         arrscanf, arrauto);
  int choise_one = get_value();
  switch (choise_one) {
  case arrscanf:
    scanf_arr(ptr, length);
    break;

  case arrauto:
    auto_arr(ptr, length);
    break;

  default:
    fprintf(stderr, "Неверный выбор. \n");
    free(ptr);
    exit(1);
  }
  print_arr(ptr, length);

  printf("Выберите действие: \n "
         "%d - Найти произведение элементов с чётным значением. \n"
         "%d - Заменить элементы с нечётными номерами на квадраты их номеров. \n"
         "%d - Проверить, есть ли положительные элементы, делящиеся на k с остатком 2. \n",
         operation_one, operation_two, operation_three);
  int choise_two = get_value();
  switch (choise_two) {
  case operation_one:
    printf("Произведение: %lld \n", product_even(ptr, length));
    break;

  case operation_two:
    replace_odd_indexes(ptr, length);
    print_arr(ptr, length);
    break;

  case operation_three:
    if (check_divisible(ptr, length)) {
      printf("Да, такие элементы есть. \n");
    } else {
      printf("Нет, таких элементов нет. \n");
    }
    break;

  default:
    fprintf(stderr, "Неверный выбор.\n");
    free(ptr);
    exit(1);
  }

  free(ptr);
  return 0;
}

int get_value() {
  int value = 0;
  if (!(scanf("%d", &value) == 1)) {
    fprintf(stderr, "Error\n");
    exit(1);
  }
  return value;
}

void check_array(int *ptr) {
  if (ptr == NULL) {
    fprintf(stderr, "Ошибка выделения памяти. \n");
    free(ptr);
    exit(1);
  }
}

long long product_even(int *ptr, const size_t length) {
  check_array(ptr);
  long long product = 1;
  int found = 0;
  for (size_t i = 0; i < length; i++) {
    if (ptr[i] % 2 == 0) {
      product *= ptr[i];
      found = 1;
    }
  }
  if (!found) {
    return 0;
  }
  return product;
}

void print_arr(int *ptr, const size_t length) {
  check_array(ptr);
  printf("Массив:\n");
  for (size_t i = 0; i < length; i++) {
    printf(" %d", ptr[i]);
  }
  printf("\n");
}

void replace_odd_indexes(int *ptr, const size_t length) {
  check_array(ptr);
  for (size_t i = 1; i < length; i += 2) {
    ptr[i] = (int)(i * i);
  }
}

int check_divisible(int *ptr, const size_t length) {
  check_array(ptr);
  printf("Введите число k: \n");
  int k = get_value();
  if (k == 0) {
    fprintf(stderr, "Число k не должно быть нулём.\n");
    free(ptr);
    exit(1);
  }
  for (size_t i = 0; i < length; i++) {
    if (ptr[i] > 0 && ptr[i] % k == 2) {
      return 1;
    }
  }
  return 0;
}

void scanf_arr(int *ptr, const size_t length) {
  check_array(ptr);
  printf("Введите последовательно элементы массива: \n");
  for (size_t i = 0; i < length; i++) {
    ptr[i] = get_value();
  }
}

void auto_arr(int *ptr, const size_t length) {
  check_array(ptr);
  printf("Введите минимальную границу массива: \n");
  int min = get_value();
  printf("Введите максимальную границу массива: \n");
  int max = get_value();

  if (min > max) {
    fprintf(stderr, "Минимальная граница больше максимальной. \n");
    free(ptr);
    exit(1);
  }

  srand(time(NULL));
  for (size_t i = 0; i < length; i++) {
    ptr[i] = rand() % (max - min + 1) + min;
  }
}