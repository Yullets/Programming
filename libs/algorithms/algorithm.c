//
// Created by Fr on 14.12.2021.
//
#include <stdio.h>
#include "algorithm.h"


int min2(long long a, long long b) {
    return a < b ? a : b;
}

int max2(int a, int b) {
    return a > b ? a : b;
}

void swap(void *a, void *b, size_t size) {
    for (size_t i = 0; i < size; i++) {
        char *pa = a + i;
        char *pb = b + i;

        char t = *pa;
        *pa = *pb;
        *pb = t;
    }
}
