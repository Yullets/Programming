//
// Created by Fr on 14.02.2022.
//

#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>

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
    long long *a = (long long *) malloc(sizeof(long long) * m.nRows);

    for (int i = 0; i < m.nRows; i++)
        a[i] = getSum(m.values[i], m.nCols);


    if (isUnique(a, m.nCols))
        transposeSquareMatrix(m);

    free(a);
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

float getDistance(int *a, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i] * a[i];

    return sqrt(sum);
}

void insertionSortRowsMatrixByRowCriteriaF(matrix m,
                                           float(*criteria)(int *, int)) {
    float *rowsCriteria = (float *) malloc(sizeof(float) * m.nRows);

    for (int i = 0; i < m.nRows; i++)
        rowsCriteria[i] = criteria(m.values[i], m.nCols);

    for (int i = 1; i < m.nRows; i++) {
        int currentIndex = i;
        while (currentIndex > 0 && rowsCriteria[currentIndex] < rowsCriteria[currentIndex - 1]) {
            swapRows(m, currentIndex, currentIndex - 1);
            swap(&rowsCriteria[currentIndex], &rowsCriteria[currentIndex - 1], sizeof(int));
            currentIndex--;
        }
    }

    free(rowsCriteria);
}

void sortByDistances(matrix m) {
    insertionSortRowsMatrixByRowCriteriaF(m, getDistance);
}

int cmp_long_long(const void *pa, const void *pb) {
    long long arg1 = *(const long long *) pa;
    long long arg2 = *(const long long *) pb;
    if (arg1 < arg2)
        return -1;
    if (arg1 > arg2)
        return 1;
    return 0;
}

int countNUnique(long long *a, int n) {
    qsort(a, n, sizeof(long long), cmp_long_long);
    int unique = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1])
            unique++;
    }

    return unique;
}

int countEqClassesByRowsSum(matrix m) {
    long long *a = (long long *) malloc(sizeof(long long) * m.nRows);
    for (int i = 0; i < m.nRows; i++) {
        a[i] = getSum(m.values[i], m.nCols);
    }
    int res = countNUnique(a, m.nRows);
    free(a);

    return res;
}

int getNSpecialElement(matrix m) {
    int *sum = (int *) malloc(sizeof(int) * m.nRows);
    int *col = (int *) malloc(sizeof(int) * m.nRows);

    for (int i = 0; i < m.nCols; i++) {
        for (int j = 0; j < m.nRows; j++)
            col[j] = m.values[j][i];
        sum[i] = getSum(col, m.nRows);
    }

    int count = 0;
    for (int i = 0; i < m.nRows; i++) {
        for(int j = 0; j < m.nCols; j++)
            if (m.values[i][j] > sum[j] - m.values[i][j])
                count++;
    }

    free(sum);
    free(col);
}
