//
// Created by Fr on 05.02.2022.
//

#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include "../../algorithms/algorithm.h"
#include "matrix.h"

matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);
    for (int i = 0; i < nRows; i++)
        values[i] = (int *) malloc(sizeof(int) * nCols);
    return (matrix) {values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices,
                              int nRows, int nCols) {
    matrix *ms = (matrix *) malloc(sizeof(matrix) * nMatrices);
    for (int i = 0; i < nMatrices; i++)
        ms[i] = getMemMatrix(nRows, nCols);
    return ms;
}

void freeMemMatrix(matrix *m) {
    for (int i = 0; i < m->nRows; i++)
        free(m->values[i]);
    free(m->values);
}

void freeMemMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        free(ms->values[i]);
    free(ms->values);
}

void inputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            scanf("%d", &m.values[i][j]);
}

void inputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        inputMatrix(ms[i]);
}

void outputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            printf("%d\n", m.values[i][j]);
}

void outputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        outputMatrix(ms[i]);
}

void swapRows(matrix m, int i1, int i2) {
    int *t = m.values[i1];
    m.values[i1] = m.values[i2];
    m.values[i2] = t;
}

void swapColumns(matrix m, int j1, int j2) {
    for (int i = 0; i < m.nRows; i++)
        swap(&m.values[i][j1], &m.values[i][j2], sizeof(int));
}

bool isSquareMatrix(matrix m) {
    return m.nRows == m.nCols;
}

bool twoMatricesEqual(matrix m1, matrix m2) {
    if (m1.nRows != m2.nRows || m1.nCols != m2.nCols)
        return false;

    for (int i = 0; i < m1.nRows; i++) {
        for (int j = 0; j < m1.nCols; j++) {
            if (m1.values[i][j] != m2.values[i][j])
                return false;
        }
    }

    return true;

}

bool isEMatrix(matrix m) {
    if (m.nRows != m.nCols)
        return false;

    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            if (m.values[i][i] != 1 || i != j && m.values[i][j] != 0)
                return false;
        }
    }

    return true;
}

bool isSymmetricMatrix(matrix m) {
    if (m.nRows != m.nCols)
        return false;

    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < i; j++) {
            if (m.values[i][j] != m.values[j][i])
                return false;
        }
    }

    return true;
}

void transposeSquareMatrix(matrix m){
    for(int i = 0; i < m.nRows; i++){
        for(int j = 0; j < m.nCols; j++){
            if(i != j)
                swap(&m.values[i][j], &m.values[j][i], sizeof(int));
        }
    }
}