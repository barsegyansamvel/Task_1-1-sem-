#include <locale.h>
#include <math.h>
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
  arr_scanf = 1,
  arr_auto = 2 };

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
@brief Выводит массив на экран
@param ptr Массив
@param length Длина массива
*/
void print_arr(int *ptr, const size_t length);

/**
@brief Заменяет предпоследний элемент на максимальный по модулю
@param ptr Массив
@param length Длина массива
*/
void replace_pre_last(int *ptr, const size_t length);

/**
@brief Вставляет элемент K до и после всех элементов, заканчивающихся на K
@param ptr Указатель на массив
@param length Указатель на длину массива (меняется!)
*/
void insert_k(int **ptr, size_t *length);

/**
@brief Формирует массив A из массива D по правилу
@param ptr_d Исходный массив
@param length Длина массива
*/
void form_array_a(int *ptr_d, const size_t length);

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
         arr_scanf, arr_auto);
  int choise_one = get_value();
  switch (choise_one) {
  case arr_scanf:
    scanf_arr(ptr, length);
    break;

  case arr_auto:
    auto_arr(ptr, length);
    break;

  default:
    fprintf(stderr, "Неверный выбор. \n");
    free(ptr);
    exit(1);
  }
  print_arr(ptr, length);

  printf("Выберите действие: \n "
         "%d - Заменить предпоследний элемент на максимальный по модулю. \n"
         "%d - Вставить K до и после элементов, заканчивающихся на K. \n"
         "%d - Сформировать массив A из D по правилу. \n",
         operation_one, operation_two, operation_three);
  int choise_two = get_value();
  switch (choise_two) {
  case operation_one:
    replace_pre_last(ptr, length);
    print_arr(ptr, length);
    break;

  case operation_two:
    insert_k(&ptr, &length);
    print_arr(ptr, length);
    break;

  case operation_three:
    form_array_a(ptr, length);
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

void print_arr(int *ptr, const size_t length) {
  check_array(ptr);
  printf("Массив:\n");
  for (size_t i = 0; i < length; i++) {
    printf(" %d", ptr[i]);
  }
  printf("\n");
}

void replace_pre_last(int *ptr, const size_t length) {
  check_array(ptr);
  if (length < 2) {
    fprintf(stderr, "Массив слишком мал.\n");
    return;
  }
  int max_abs = abs(ptr[0]);
  for (size_t i = 1; i < length; i++) {
    if (abs(ptr[i]) > max_abs) {
      max_abs = abs(ptr[i]);
    }
  }
  ptr[length - 2] = max_abs;
}

void insert_k(int **ptr, size_t *length) {
  check_array(*ptr);
  printf("Введите число K: \n");
  int k = get_value();

  size_t count = 0;
  for (size_t i = 0; i < *length; i++) {
    if (abs((*ptr)[i]) % 10 == abs(k) % 10) {
      count += 2;
    }
  }

  if (count == 0) {
    printf("Нет элементов, заканчивающихся на %d.\n", k);
    return;
  }

  size_t new_length = *length + count;
  int *new_ptr = malloc(sizeof(int) * new_length);
  check_array(new_ptr);

  size_t j = 0;
  for (size_t i = 0; i < *length; i++) {
    if (abs((*ptr)[i]) % 10 == abs(k) % 10) {
      new_ptr[j++] = k;
      new_ptr[j++] = (*ptr)[i];
      new_ptr[j++] = k;
    } else {
      new_ptr[j++] = (*ptr)[i];
    }
  }

  free(*ptr);
  *ptr = new_ptr;
  *length = new_length;
}

void form_array_a(int *ptr_d, const size_t length) {
  check_array(ptr_d);
  int *ptr_a = malloc(sizeof(int) * length);
  check_array(ptr_a);

  for (size_t i = 0; i < length; i++) {
    if (i % 2 == 0) {
      ptr_a[i] = (int)(i * ptr_d[i] * ptr_d[i]);
    } else {
      if (i + 1 != 0) {
        ptr_a[i] = (int)(ptr_d[i] / (i + 1));
      } else {
        ptr_a[i] = 0;
      }
    }
  }

  printf("Массив A:\n");
  for (size_t i = 0; i < length; i++) {
    printf(" %d", ptr_a[i]);
  }
  printf("\n");

  free(ptr_a);
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