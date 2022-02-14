//
// Created by Fr on 14.02.2022.
//

#ifndef COURSE_TASKS_H
#define COURSE_TASKS_H

//меняет местами строки, где находятся максимальный и
//минимальный элементы.
void changeRowsWithMinAndMaxEl (matrix m);

void test_changeRowsWithMinAndMaxEl1();

void test_changeRowsWithMinAndMaxEl2();

//возвращает максимальное значение элементов строки.
int getMax(const int *a, int n);

//сортирует матрицу по неубыванию максимальных значений в строках.
void sortRowsByMaxElement(matrix m);

void test_sortRowsByMaxElement1();

void test_sortRowsByMaxElement2();

//возвращает минимальное значение элементов строки.
int getMin(const int *a, int n);

//сортирует матрицу по неубыванию минимальных значений в столбцах.
void sortColsByMinElement(matrix m);

void tests();

#endif //COURSE_TASKS_H
