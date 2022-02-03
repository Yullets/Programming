//
// Created by Fr on 02.02.2022.
//

#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <stdlib.h>
#include "vector.h"

vector createVector(size_t n) {
    vector vec = {NULL, 0, n};

    if (n == 0)
        return vec;

    vec.data = (int *) malloc((sizeof(int) * n));
    if (vec.data == NULL) {
        fprintf(stderr, " bad alloc ");
        exit(1);
    }

    return vec;
}

void reserve(vector *v, size_t newCapacity) {
    v->data = (int *) realloc(v->data, newCapacity * sizeof(int));
    v->capacity = newCapacity;
    if (newCapacity < v->size)
        v->size = newCapacity;

    if (newCapacity == 0)
        return;

    if (v->data == NULL) {
        fprintf(stderr, " bad alloc ");
        exit(1);
    }
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    reserve(v, v->size);
}

void deleteVector(vector *v) {
    free(v->data);
}

bool isEmpty(vector *v) {
    return (v->size == 0);
}

bool isFull(vector *v) {
    return (v->size == v->capacity);
}

int getVectorValue(vector *v, size_t i) {
    return v->data[i];
}

void pushBack(vector *v, int x) {
    if (isEmpty(v) && isFull(v))
        reserve(v, 1);
    else if (isFull(v))
        reserve(v, 2 * v->capacity);

    v->data[v->size] = x;
    v->size++;
}

void popBack(vector *v) {
    if (isEmpty(v)) {
        fprintf(stderr, " vector is empty ");
        exit(1);
    } else
        v->size--;
}

int* atVector(vector *v, size_t index){
    if(index >= v->size)
        fprintf(stderr, "IndexError: a[%zu] is not exists", index);

    return (int*) &v->data + index;
}

int* back(vector *v) {
    return atVector(v, v->size - 1);
}

int* front(vector *v){
    return atVector(v, 0);
}