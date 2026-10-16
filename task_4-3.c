#include <locale.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
@enum Для выбора операций.
*/
enum {
  operation_one = 1,
  operation_two = 2 };

/**
@enum Для выбора метода заполнения массива.
*/
enum {
  arr_scanf = 1,
  arr_auto = 2 };

/**
@brief Считывает целое число с проверкой ввода.
@return Считанное значение.
*/
int get_value(void);

/**
@brief Проверяет указатель на NULL.
@param ptr Указатель на массив или его строку.
*/
void check_array(const void *ptr);

/**
@brief Выделяет память под двумерный массив.
@param rows Количество строк.
@param columns Количество столбцов.
@return Указатель на созданный массив.
*/
int **create_arr(const size_t rows, const size_t columns);

/**
@brief Освобождает память двумерного массива.
@param ptr Массив.
@param rows Количество строк.
*/
void free_arr(int **ptr, const size_t rows);

/**
@brief Выводит двумерный массив на экран.
@param ptr Массив.
@param rows Количество строк.
@param columns Количество столбцов.
*/
void print_arr(int *const *ptr, const size_t rows, const size_t columns);

/**
@brief Заменяет нулем первый минимальный по модулю элемент каждого столбца.
@param ptr Массив.
@param rows Количество строк.
@param columns Количество столбцов.
*/
void replace_min(int **ptr, const size_t rows, const size_t columns);

/**
@brief Удаляет столбцы, в которых первый элемент больше последнего.
@param ptr Массив.
@param rows Количество строк.
@param columns Исходное количество столбцов.
@return Количество оставшихся столбцов.
*/
size_t delete_columns(int **ptr, const size_t rows, const size_t columns);

/**
@brief Заполняет массив введенными элементами по строкам.
@param ptr Массив.
@param rows Количество строк.
@param columns Количество столбцов.
*/
void scanf_arr(int **ptr, const size_t rows, const size_t columns);

/**
@brief Заполняет массив случайными числами из заданного промежутка.
@param ptr Массив.
@param rows Количество строк.
@param columns Количество столбцов.
*/
void auto_arr(int **ptr, const size_t rows, const size_t columns);

/**
@brief Точка входа в программу.
@return Возвращает 0, если программа выполнена корректно.
*/
int main(void) {
  setlocale(LC_ALL, "ru_RU.UTF-8");

  printf("Введите количество строк: \n");
  int input_rows = get_value();
  printf("Введите количество столбцов: \n");
  int input_columns = get_value();
  if (input_rows <= 0 || input_columns <= 0) {
    fprintf(stderr, "Количество строк и столбцов должно быть положительным.\n");
    return 1;
  }

  size_t rows = (size_t)input_rows;
  size_t columns = (size_t)input_columns;
  int **ptr = create_arr(rows, columns);

  printf("Выберите операцию: \n %d - Заполнить массив вручную. \n %d - "
         "Заполнить массив автоматически. \n",
         arr_scanf, arr_auto);
  int choise_one = get_value();
  switch (choise_one) {
  case arr_scanf:
    scanf_arr(ptr, rows, columns);
    break;

  case arr_auto:
    auto_arr(ptr, rows, columns);
    break;

  default:
    fprintf(stderr, "Неверный выбор.\n");
    free_arr(ptr, rows);
    return 1;
  }
  print_arr(ptr, rows, columns);

  printf("Выберите действие: \n "
         "%d - Заменить минимальный по модулю элемент каждого столбца нулем. \n"
         "%d - Удалить столбцы, в которых первый элемент больше последнего. \n",
         operation_one, operation_two);
  int choise_two = get_value();
  switch (choise_two) {
  case operation_one:
    replace_min(ptr, rows, columns);
    break;

  case operation_two:
    columns = delete_columns(ptr, rows, columns);
    break;

  default:
    fprintf(stderr, "Неверный выбор.\n");
    free_arr(ptr, rows);
    return 1;
  }
  print_arr(ptr, rows, columns);

  free_arr(ptr, rows);
  return 0;
}

int get_value(void) {
  int value = 0;
  if (!(scanf("%d", &value) == 1)) {
    fprintf(stderr, "Ошибка ввода.\n");
    exit(1);
  }
  return value;
}

void check_array(const void *ptr) {
  if (ptr == NULL) {
    fprintf(stderr, "Ошибка выделения памяти.\n");
    exit(1);
  }
}

int **create_arr(const size_t rows, const size_t columns) {
  if (rows > SIZE_MAX / sizeof(int *) || columns > SIZE_MAX / sizeof(int)) {
    fprintf(stderr, "Слишком большой размер массива.\n");
    exit(1);
  }
  int **ptr = malloc(sizeof(int *) * rows);
  if (ptr == NULL) {
    fprintf(stderr, "Ошибка выделения памяти.\n");
    exit(1);
  }
  for (size_t i = 0; i < rows; i++) {
    ptr[i] = malloc(sizeof(int) * columns);
    if (ptr[i] == NULL) {
      free_arr(ptr, i);
      check_array(NULL);
    }
  }
  return ptr;
}

void free_arr(int **ptr, const size_t rows) {
  check_array(ptr);
  for (size_t i = 0; i < rows; i++) {
    free(ptr[i]);
  }
  free(ptr);
}

void print_arr(int *const *ptr, const size_t rows, const size_t columns) {
  check_array(ptr);
  if (columns == 0) {
    printf("Все столбцы удалены.\n");
    return;
  }
  printf("Массив:\n");
  for (size_t i = 0; i < rows; i++) {
    check_array(ptr[i]);
    for (size_t j = 0; j < columns; j++) {
      printf(" %d", ptr[i][j]);
    }
    printf("\n");
  }
}

void replace_min(int **ptr, const size_t rows, const size_t columns) {
  check_array(ptr);
  for (size_t i = 0; i < rows; i++) {
    check_array(ptr[i]);
  }
  for (size_t j = 0; j < columns; j++) {
    size_t min_index = 0;
    long long min_abs = llabs((long long)ptr[0][j]);
    for (size_t i = 1; i < rows; i++) {
      long long current_abs = llabs((long long)ptr[i][j]);
      if (current_abs < min_abs) {
        min_abs = current_abs;
        min_index = i;
      }
    }
    ptr[min_index][j] = 0;
  }
}

size_t delete_columns(int **ptr, const size_t rows, const size_t columns) {
  check_array(ptr);
  for (size_t i = 0; i < rows; i++) {
    check_array(ptr[i]);
  }
  size_t new_columns = 0;
  for (size_t j = 0; j < columns; j++) {
    if (ptr[0][j] <= ptr[rows - 1][j]) {
      for (size_t i = 0; i < rows; i++) {
        ptr[i][new_columns] = ptr[i][j];
      }
      new_columns++;
    }
  }
  return new_columns;
}

void scanf_arr(int **ptr, const size_t rows, const size_t columns) {
  check_array(ptr);
  printf("Введите элементы массива по строкам:\n");
  for (size_t i = 0; i < rows; i++) {
    check_array(ptr[i]);
    for (size_t j = 0; j < columns; j++) {
      ptr[i][j] = get_value();
    }
  }
}

void auto_arr(int **ptr, const size_t rows, const size_t columns) {
  check_array(ptr);
  printf("Введите минимальную границу массива: \n");
  int min = get_value();
  printf("Введите максимальную границу массива: \n");
  int max = get_value();
  if (min > max) {
    fprintf(stderr, "Минимальная граница больше максимальной.\n");
    free_arr(ptr, rows);
    exit(1);
  }

  srand((unsigned int)time(NULL));
  long long range = (long long)max - min + 1;
  for (size_t i = 0; i < rows; i++) {
    check_array(ptr[i]);
    for (size_t j = 0; j < columns; j++) {
      ptr[i][j] = (int)(rand() % range + min);
    }
  }
}
