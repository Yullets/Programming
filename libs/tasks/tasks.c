//
// Created by Fr on 14.02.2022.
//

#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <assert.h>
#include "../algorithms/algorithm.h"
#include "../data_structures/matrix/matrix.h"

void changeRowsWithMinAndMaxEl (matrix m) {
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