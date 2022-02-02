//
// Created by Fr on 02.02.2022.
//

#ifndef COURSE_VECTOR_H
#define COURSE_VECTOR_H

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct vector {
    int *data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
} vector;

//возвращает структуру-дескриптор вектор из n значений.
vector createVector(size_t n);

//изменяет количество памяти, выделенное под хранение элементов вектора.
void reserve(vector *v, size_t newCapacity);

//удаляет элементы из контейнера, но не освобождает выделенную память.
void clear(vector *v);

//освобождает память, выделенную под неиспользуемые элементы.
void shrinkToFit(vector *v);

//освобождает память, выделенную вектору.
void deleteVector(vector *v);

//возвращает значение 'истина', если вектор пустой, иначе - ложь.
bool isEmpty(vector *v);

//возвращает значение 'истина', если вектор полный, иначе - ложь.
bool isFull(vector *v);

//возвращает i-ый элемент вектора v.
int getVectorValue(vector *v, size_t i);

//добавляет элемент x в конец вектора v. Если вектор заполнен, увеличьте количество выделенной ему памяти в
//2 раза, используя reserve.
void pushBack(vector *v, int x);

//удаляет последний элемент из вектора.
void popBack(vector *v);

#endif //COURSE_VECTOR_H
