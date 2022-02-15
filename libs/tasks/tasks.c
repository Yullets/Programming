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
#include "../algorithms/array/array.h"

void changeRowsWithMinAndMaxEl(matrix m) {
    position minPos = getMinValuePos(m);
    position maxPos = getMaxValuePos(m);
    swapRows(m, minPos.rowIndex, maxPos.rowIndex);
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


int getMin(const int *a, int n) {
    int minElement = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < minElement)
            minElement = a[i];
    }
    return minElement;
}

void sortColsByMinElement(matrix m) {
    insertionSortColsMatrixByColCriteria(m, getMin);
}


matrix mulMatrices(matrix m1, matrix m2) {
    matrix m3 = getMemMatrix(m1.nRows, m2.nCols);

    for (int i = 0; i < m1.nRows; i++) {
        for (int j = 0; j < m2.nCols; j++) {
            m3.values[i][j] = 0;
            for (int k = 0; k < m1.nCols; k++) {
                m3.values[i][j] += m1.values[i][k] * m2.values[k][j];
            }
        }
    }

    return m3;
}

void getSquareOfMatrixIfSymmetric(matrix *m) {
    if (!isSymmetricMatrix(*m))
        return;

    matrix square = mulMatrices(*m, *m);

    freeMemMatrix(m);
    *m = square;
}

long long getSum(const int *a, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];

    return sum;
}

bool isUnique(const long long *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] == a[j])
                return false;
        }
    }

    return true;
}

void transposeIfMatrixHasNotEqualSumOfRows(matrix m) {
    int *a = (int *) malloc(sizeof(int) * m.nRows);

    for (int i = 0; i < m.nRows; i++)
        a[i] = getSum(m.values[i], m.nCols);

    if (isUnique(a, m.nRows))
        transposeSquareMatrix(m);
}

bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    matrix mul = mulMatrices(m1, m2);

    bool res = isEMatrix(mul);
    freeMemMatrix(&mul);

    return res;
}

long long findSumOfMaxesOfPseudoDiagonal(matrix m) {
    int sum = 0;
    for (int i = 1; i < m.nRows; i++) {
        int rowIndex = i;
        int colIndex = 0;
        int maxValue1 = m.values[rowIndex][colIndex];
        while (rowIndex < m.nRows && colIndex < m.nCols) {
            if (m.values[rowIndex][colIndex] > maxValue1)
                maxValue1 = m.values[rowIndex][colIndex];
            rowIndex++;
            colIndex++;
        }
        sum += maxValue1;
    }

    for (int i = 1; i < m.nCols; i++) {
        int rowIndex = 0;
        int colIndex = i;
        int maxValue2 = m.values[rowIndex][colIndex];
        while (colIndex < m.nCols && rowIndex < m.nRows) {
            if (m.values[rowIndex][colIndex] > maxValue2)
                maxValue2 = m.values[rowIndex][colIndex];
            rowIndex++;
            colIndex++;
        }
        sum += maxValue2;
    }

    return sum;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int getMinInArea(matrix m) {
    position posMax = getMaxValuePos(m);

    int rowI = posMax.rowIndex;

    int leftColI = posMax.colIndex;
    int rightColI = posMax.colIndex;

    int minValue = m.values[posMax.rowIndex][posMax.colIndex];
    while (rowI >= 0) {
        for (int i = leftColI; i < rightColI; i++)
            minValue = min(m.values[rowI][i], minValue);

        if (leftColI > 0)
            leftColI--;

        if (rightColI + 1 < m.nCols)
            rightColI++;
        rowI--;
    }

    return minValue;
}