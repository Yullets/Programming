//
// Created by Fr on 14.02.2022.
//

#ifndef COURSE_TASKS_H
#define COURSE_TASKS_H

//меняет местами строки, где находятся максимальный и
//минимальный элементы.
void changeRowsWithMinAndMaxEl (matrix m);

//возвращает максимальное значение элементов строки.
int getMax(const int *a, int n);

//сортирует матрицу по неубыванию максимальных значений в строках.
void sortRowsByMaxElement(matrix m);

//возвращает минимальное значение элементов строки.
int getMin(const int *a, int n);

//сортирует матрицу по неубыванию минимальных значений в столбцах.
void sortColsByMinElement(matrix m);

//перемножает матрицы.
matrix mulMatrices(matrix m1, matrix m2);

//возводит в квадрат симметричную матрицу.
void getSquareOfMatrixIfSymmetric(matrix *m);

#endif //COURSE_TASKS_H
