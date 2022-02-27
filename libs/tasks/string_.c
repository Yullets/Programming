//
// Created by Yulia on 26.02.2022.
//

#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>

#include "../algorithms/algorithm.h"
#include "../data_structures/matrix/matrix.h"
#include "../algorithms/array/array.h"

size_t strlen_ ( char *begin) {
    char *end = begin;
    while (*end != '\0')
        end++;

    return end - begin;
}
