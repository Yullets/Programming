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
        fprintf ( stderr , " bad alloc ");
        exit (1) ;
    }

    return vec;
}

void reserve(vector *v, size_t newCapacity) {
    v->data = (int *) realloc(v->capacity, newCapacity * sizeof(int));
    v->capacity = newCapacity;
    if (v->data == NULL) {
        fprintf ( stderr , " bad alloc ");
        exit (1) ;
    }

    if (newCapacity == 0)
        v->data = NULL;
    else if (newCapacity < v->size)
        v->size = newCapacity;
}

void clear(vector *v){
    v->size = 0;
}

void shrinkToFit(vector *v){
    reserve(v, v->size);
}

void deleteVector(vector *v) {
    free(v->data);
}
