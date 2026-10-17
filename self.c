// Захарова Вероника Сергеевна Пи1-1
#include <stdio.h>

#define MAX_SIZE 100
#define MIN_VALUE (-1000)
#define MAX_VALUE 1000

int main(void) {
    int rows, cols;
    int a[MAX_SIZE][MAX_SIZE];

    /* Ввод размеров матрицы */
    if (scanf("%d %d", &rows, &cols) != 2) {
        printf("Ошибка: неверный ввод размеров матрицы.\n");
        return 1;
    }

    /* Проверка размеров */
    if (rows < 1 || rows > MAX_SIZE ||
        cols < 1 || cols > MAX_SIZE) {
        printf("Ошибка: недопустимые размеры матрицы.\n");
        return 1;
    }

    /* Ввод элементов матрицы */
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (scanf("%d", &a[i][j]) != 1) {
                printf("Ошибка: неверный ввод элемента матрицы.\n");
                return 1;
            }

            if (a[i][j] < MIN_VALUE ||
                a[i][j] > MAX_VALUE) {
                printf("Ошибка: элемент вне диапазона [-1000, 1000].\n");
                return 1;
            }
        }
    }

    /* Вывод матрицы */
    printf("Матрица:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    /* Вычисление сумм столбцов */
    printf("Суммы столбцов: ");

    for (int col = 0; col < cols; col++) {
        int sum = 0;  /* Обнуляем сумму нового столбца */

        for (int row = 0; row < rows; row++) {
            sum += a[row][col];
        }

        printf("%d", sum);

        if (col < cols - 1) {
            printf(", ");
        }
    }
    printf("\n");

    /* Сумма первой строки — начальный минимум */
    int minSum = 0;

    for (int j = 0; j < cols; j++) {
        minSum += a[0][j];
    }

    int minIndex = 0;

    /* Проверяем остальные строки */
    for (int i = 1; i < rows; i++) {
        int rowSum = 0;

        for (int j = 0; j < cols; j++) {
            rowSum += a[i][j];
        }

        /* Только строго меньшее значение */
        if (rowSum < minSum) {
            minSum = rowSum;
            minIndex = i;
        }
    }

    printf("Индекс первой строки с минимальной суммой: %d\n",
           minIndex);
    printf("Минимальная сумма строки: %d\n", minSum);

    return 0;
}
