//
// Created by Fr on 15.02.2022.
//

#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <assert.h>
#include "../algorithms/algorithm.h"
#include "../data_structures/matrix/matrix.h"
#include "tasks.h"
#include "tests.h"

void test_changeRowsWithMinAndMaxEl1() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 0,
                    3, 6, 9,
                    7, 8, 5,
            },
            3, 3);

    changeRowsWithMinAndMaxEl(m);

    matrix expectedM = createMatrixFromArray(
            (int[]) {
                    3, 6, 9,
                    1, 2, 0,
                    7, 8, 5,
            },
            3, 3);

    assert(twoMatricesEqual(m, expectedM));

    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
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

    matrix expectedM = createMatrixFromArray(
            (int[]) {
                    3, 2, 1,
                    6, 5, 4,
                    9, 8, 7,
            },
            3, 3);

    assert(twoMatricesEqual(m, expectedM));

    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
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

    matrix expectedM = createMatrixFromArray(
            (int[]) {
                    3, 2, 3,
                    7, 1, 2,
                    1, 8, 1,
            },
            3, 3);

    assert(twoMatricesEqual(m, expectedM));

    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
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

    matrix expectedM = createMatrixFromArray(
            (int[]) {
                    2, 4, 1,
                    1, 7, 7,
                    0, 2, 9,
            },
            3, 3);

    assert(twoMatricesEqual(m, expectedM));

    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
}

void test_sortColsByMinElement() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    3, 5, 2, 4, 3, 3,
                    2, 5, 1, 8, 2, 7,
                    6, 1, 4, 4, 8, 3,
            },
            3, 6);
    sortColsByMinElement(m);

    matrix expectedM = createMatrixFromArray(
            (int[]) {
                    5, 2, 3, 3, 3, 4,
                    5, 1, 2, 2, 7, 8,
                    1, 4, 6, 8, 3, 4,
            },
            3, 6);

    assert(twoMatricesEqual(m, expectedM));

    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
}

void test_getSquareOfMatrixIfSymmetric1() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    3, 5, 2,
                    2, 5, 1,
                    6, 1, 4,
            },
            3, 3);

    getSquareOfMatrixIfSymmetric(&m);

    matrix expectedM = createMatrixFromArray(
            (int[]) {
                    3, 5, 2,
                    2, 5, 1,
                    6, 1, 4,
            },
            3, 3);
    assert(twoMatricesEqual(m, expectedM));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
}

void test_getSquareOfMatrixIfSymmetric2() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 6,
                    2, 1, 1,
                    6, 1, 1,
            },
            3, 3);

    getSquareOfMatrixIfSymmetric(&m);

    matrix expectedM = createMatrixFromArray(
            (int[]) {
                    41, 10, 14,
                    10, 6, 14,
                    14, 14, 38,
            },
            3, 3);
    assert(twoMatricesEqual(m, expectedM));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
}

void tests() {
    test_changeRowsWithMinAndMaxEl1();
    test_changeRowsWithMinAndMaxEl2();
    test_sortRowsByMaxElement1();
    test_sortRowsByMaxElement2();
    test_sortColsByMinElement();
    test_getSquareOfMatrixIfSymmetric1();
    test_getSquareOfMatrixIfSymmetric2();
}