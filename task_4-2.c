#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 1000

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
  arr_scanf = 1,
  arr_auto = 2 };

/**
@brief Считывает значение введённое с клавиатуры с проверкой ввода.
@return Считанное значение.
*/
int get_value();

/**
@brief Выводит массив на экран
@param arr Массив
@param length Длина массива
*/
void print_arr(int arr[], const size_t length);

/**
@brief Заменяет предпоследний элемент на максимальный по модулю
@param arr Массив
@param length Длина массива
*/
void replace_pre_last(int arr[], const size_t length);

/**
@brief Вставляет элемент K до и после всех элементов, заканчивающихся на K
@param arr Исходный массив
@param length Длина массива
@return Длина массива после вставки
*/
size_t insert_k(int arr[], const size_t length);

/**
@brief Формирует массив A из массива D по правилу
@param arr_d Исходный массив
@param length Длина массива
*/
void form_array_a(int arr_d[], const size_t length);

/**
@brief Заполняет массив введёнными элементами.
@param arr Массив, который заполняет.
@param length Длина массива.
*/
void scanf_arr(int arr[], const size_t length);

/**
@brief Заполняет массив случайными элементами из заданного промежутка.
@param arr Массив, который заполняет.
@param length Длина массива.
*/
void auto_arr(int arr[], const size_t length);

/**
@brief Точка входа в программу.
@return Возвращает 0, если программа выполнена корректно.
*/
int main(void) {
  setlocale(LC_ALL, "ru_RU.UTF-8");

  printf("Введите количество элементов массива: \n");
  int input_length = get_value();
  if (input_length < 1 || input_length > MAX_LENGTH) {
    fprintf(stderr, "Количество элементов должно быть от 1 до %d.\n", MAX_LENGTH);
    return 1;
  }
  size_t length = (size_t)input_length;
  int arr[MAX_LENGTH];

  printf("Выберите операцию: \n %d - Заполнить массив вручную. \n %d - "
         "Заполнить массив автоматически. \n",
         arr_scanf, arr_auto);
  int choise_one = get_value();
  switch (choise_one) {
  case arr_scanf:
    scanf_arr(arr, length);
    break;

  case arr_auto:
    auto_arr(arr, length);
    break;

  default:
    fprintf(stderr, "Неверный выбор. \n");
    exit(1);
  }
  print_arr(arr, length);

  printf("Выберите действие: \n "
         "%d - Заменить предпоследний элемент на максимальный по модулю. \n"
         "%d - Вставить K до и после элементов, заканчивающихся на K. \n"
         "%d - Сформировать массив A из D по правилу. \n",
         operation_one, operation_two, operation_three);
  int choise_two = get_value();
  switch (choise_two) {
  case operation_one:
    replace_pre_last(arr, length);
    print_arr(arr, length);
    break;

  case operation_two:
    length = insert_k(arr, length);
    print_arr(arr, length);
    break;

  case operation_three:
    form_array_a(arr, length);
    break;

  default:
    fprintf(stderr, "Неверный выбор.\n");
    exit(1);
  }

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

void print_arr(int arr[], const size_t length) {
  printf("Массив:\n");
  for (size_t i = 0; i < length; i++) {
    printf(" %d", arr[i]);
  }
  printf("\n");
}

void replace_pre_last(int arr[], const size_t length) {
  if (length < 2) {
    fprintf(stderr, "Массив слишком мал.\n");
    return;
  }
  int max_abs = abs(arr[0]);
  for (size_t i = 1; i < length; i++) {
    if (abs(arr[i]) > max_abs) {
      max_abs = abs(arr[i]);
    }
  }
  arr[length - 2] = max_abs;
}

size_t insert_k(int arr[], const size_t length) {
  printf("Введите число K: \n");
  int k = get_value();

  size_t count = 0;
  for (size_t i = 0; i < length; i++) {
    if (abs(arr[i]) % 10 == abs(k) % 10) {
      count += 2;
    }
  }

  if (count == 0) {
    printf("Нет элементов, заканчивающихся на %d.\n", k);
    return length;
  }

  size_t new_length = length + count;
  if (new_length > MAX_LENGTH) {
    fprintf(stderr, "Недостаточно места: максимум %d элементов.\n", MAX_LENGTH);
    return length;
  }
  int result[MAX_LENGTH];

  size_t j = 0;
  for (size_t i = 0; i < length; i++) {
    if (abs(arr[i]) % 10 == abs(k) % 10) {
      result[j++] = k;
      result[j++] = arr[i];
      result[j++] = k;
    } else {
      result[j++] = arr[i];
    }
  }

  for (size_t i = 0; i < new_length; i++) {
    arr[i] = result[i];
  }
  return new_length;
}

void form_array_a(int arr_d[], const size_t length) {
  int arr_a[MAX_LENGTH];

  for (size_t i = 0; i < length; i++) {
    if (i % 2 == 0) {
      arr_a[i] = (int)(i * arr_d[i] * arr_d[i]);
    } else {
      if (i + 1 != 0) {
        arr_a[i] = (int)(arr_d[i] / (i + 1));
      } else {
        arr_a[i] = 0;
      }
    }
  }

  printf("Массив A:\n");
  for (size_t i = 0; i < length; i++) {
    printf(" %d", arr_a[i]);
  }
  printf("\n");

}

void scanf_arr(int arr[], const size_t length) {
  printf("Введите последовательно элементы массива: \n");
  for (size_t i = 0; i < length; i++) {
    arr[i] = get_value();
  }
}

void auto_arr(int arr[], const size_t length) {
  printf("Введите минимальную границу массива: \n");
  int min = get_value();
  printf("Введите максимальную границу массива: \n");
  int max = get_value();

  if (min > max) {
    fprintf(stderr, "Минимальная граница больше максимальной. \n");
    exit(1);
  }

  srand(time(NULL));
  for (size_t i = 0; i < length; i++) {
    arr[i] = rand() % (max - min + 1) + min;
  }
}
