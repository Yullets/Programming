//
// Created by Fr on 05.02.2022.
//

#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <stdlib.h>
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

void freeMemMatrix(matrix *m){
    for (int i = 0; i < m->nRows; i++)
        free(m->values[i]);
    free(m->values);
}

void freeMemMatrices(matrix *ms, int nMatrices){
    for (int i = 0; i <nMatrices; i++)
        free(ms->values[i]);
    free(ms->values);
}

void inputMatrix(matrix m){
    for(int i = 0; i <m.nRows; i++)
        for(int j = 0; j < m.nCols; j++)
            scanf("%d", &m.values[i][j]);
}

void inputMatrices(matrix *ms, int nMatrices){
    for(int i = 0; i < nMatrices; i++)
        inputMatrix(ms[i]);
}

void outputMatrix(matrix m){
    for (int i = 0; i < m.nRows; i++)
        for(int j = 0; j < m.nCols; j++)
            printf("%d\n", m.values[i][j]);
}

void outputMatrices(matrix *ms, int nMatrices){
    for(int i = 0; i < nMatrices; i++)
        outputMatrix(ms[i]);
}

