//
// Created by Fr on 14.02.2022.
//

#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <assert.h>
#include "../algorithms/algorithm.h"
#include "../data_structures/matrix/matrix.h"
#include "tasks.h"

void changeRowsWithMinAndMaxEl(matrix m) {
    position minPos = getMinValuePos(m);
    position maxPos = getMaxValuePos(m);
    swapRows(m, minPos.rowIndex, maxPos.rowIndex);
}

void test_changeRowsWithMinAndMaxEl1() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 0,
                    3, 6, 9,
                    7, 8, 5,
            },
            3, 3);

    changeRowsWithMinAndMaxEl(m);

    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 6, 9,
                    1, 2, 0,
                    7, 8, 5,
            },
            3, 3);

    assert(twoMatricesEqual(m, m1));

    freeMemMatrix(&m);
    freeMemMatrix(&m1);
}

void test_changeRowsWithMinAndMaxEl2() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    9, 8, 7,
                    6, 5, 4,
                    3, 2, 1,
            },
            3, 3);

    changeRowsWithMinAndMaxEl(m);

    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 2, 1,
                    6, 5, 4,
                    9, 8, 7,
            },
            3, 3);

    assert(twoMatricesEqual(m, m1));

    freeMemMatrix(&m);
    freeMemMatrix(&m1);
}

int getMax(const int *a, int n) {
    int maxElement = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > maxElement)
            maxElement = a[i];
    }
    return maxElement;
}

void sortRowsByMaxElement(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getMax);
}

void test_sortRowsByMaxElement1() {
    matrix m = createMatrixFromArray(
            (int[]) {
                7, 1, 2,
                1, 8, 1,
                3, 2, 3,
            },
            3, 3);
    sortRowsByMaxElement(m);

    matrix m1 = createMatrixFromArray(
            (int[]) {
                3, 2, 3,
                7, 1, 2,
                1, 8, 1,
            },
            3, 3);

    assert(twoMatricesEqual(m, m1));

    freeMemMatrix(&m);
    freeMemMatrix(&m1);
}

void test_sortRowsByMaxElement2() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    2, 4, 1,
                    1, 7, 7,
                    0, 2, 9,
            },
            3, 3);
    sortRowsByMaxElement(m);

    matrix m1 = createMatrixFromArray(
            (int[]) {
                    2, 4, 1,
                    1, 7, 7,
                    0, 2, 9,
            },
            3, 3);

    assert(twoMatricesEqual(m, m1));

    freeMemMatrix(&m);
    freeMemMatrix(&m1);
}


void tests() {
    test_changeRowsWithMinAndMaxEl1();
    test_changeRowsWithMinAndMaxEl2();
    test_changeRowsWithMinAndMaxEl1();
    test_changeRowsWithMinAndMaxEl2();
}