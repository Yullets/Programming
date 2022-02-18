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

//возвращает матрицу, которая является результатом
//перемножения матриц m1 и m2.
matrix mulMatrices(matrix m1, matrix m2);

//возводит в квадрат симметричную матрицу.
void getSquareOfMatrixIfSymmetric(matrix *m);

//возвращает значение 'истина', если массив состоит изуникальных элементов,
//иначе - 'ложь'.
bool isUnique(const long long *a, int n);

//возвращает сумму элементов массива.
long long getSum(const int *a, int n);

//транспонирует матрицу, если среди сумм элементов строки нет равных.
void transposeIfMatrixHasNotEqualSumOfRows(matrix m);

//возвращает значение 'истина', если матрицы взаимно обратные,
//иначе - 'ложь'.
bool isMutuallyInverseMatrices(matrix m1, matrix m2);

//возвращае сумму максимальных элементов, находящихся на псевдодиагонали.
long long findSumOfMaxesOfPseudoDiagonal(matrix m);

//возвращает минимальное значение из a и b.
int min(int a, int b);

//возвращает минимальное значение из выделенной территории.
int getMinInArea(matrix m);

//возвращает расстояния между координатами.
float getDistance(int *a, int n);

//сортирует массив по критерию.
void insertionSortRowsMatrixByRowCriteriaF(matrix m,
                                           float(*criteria)(int *, int));

//сортирует массив по расстоянию между координатами.
void sortByDistances(matrix m);

int cmp_long_long(const void *pa, const void *pb);

//возвращает кол-во уникальных элементов.
int countNUnique(long long *a, int n);

//возвращает кол-во уникальных классов матриц.
int countEqClassesByRowsSum(matrix m);

#endif //COURSE_TASKS_H
