//
// Created by Fr on 20.12.2021.
//

#include <stdint.h>
#include <assert.h>
#include <memory.h>
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <stdlib.h>
#include "../../algorithms/array/array.h"
#include "../../algorithms/algorithm.h"

typedef struct ordered_array_set {
    int *data; // элементы множества
    size_t size; // количество элементов в множестве
    size_t capacity; // максимальное количество элементов в множестве
} ordered_array_set;

ordered_array_set ordered_array_set_create(size_t capacity) {
    return (ordered_array_set) {
            malloc(sizeof(int) * capacity),
            0,
            capacity
    };
}

size_t ordered_array_set_in(ordered_array_set *set, int value) {
    return binarySearch_(set->data, set->size, value);
}

void ordered_array_set_isAbleAppend(ordered_array_set *set) {
    assert(set->size < set->capacity);
}

void ordered_array_set_insert(ordered_array_set *set, int value) {
    ordered_array_set_isAbleAppend(set);
    if (ordered_array_set_in(set, value) == set->size) {
        int positionInsert = binarySearchLessOrEqual_(set->data, set->size,
                                                      value);
        if (positionInsert == -1)
            insert_(set->data, &set->size, 0, value);
        else
            insert_(set->data, &set->size, positionInsert + 1, value);
    }
}


ordered_array_set ordered_array_set_create_from_array(const int *a, const
size_t size) {
    ordered_array_set set = ordered_array_set_create(size);
    for (size_t i = 0; i < size; i++)
        ordered_array_set_insert(&set, a[i]);

    return set;
}

ordered_array_set ordered_array_set_intersection(ordered_array_set set1, ordered_array_set set2) {
    ordered_array_set set = ordered_array_set_create(min2(set1.size, set2.size));
    for (size_t i = 0; i < set1.size; i++) {
        if (ordered_array_set_in(&set2, set1.data[i]) != set2.size)
            ordered_array_set_insert(&set, set1.data[i]);
    }

    return set;
}

bool ordered_array_set_isEqual(ordered_array_set set1, ordered_array_set set2) {
    if (set1.size != set2.size)
        return false;

    return memcmp(set1.data, set2.data, sizeof(int) * set1.size) == 0;
}

bool ordered_array_set_isSubset(ordered_array_set subset, ordered_array_set set) {
    return ordered_array_set_isEqual(ordered_array_set_intersection(subset, set), subset);
}

void ordered_array_set_deleteElement(ordered_array_set *set, int value) {
    size_t posOfElementToDelete = binarySearch_(set->data, set->size, value);
    assert(posOfElementToDelete < set->size);
    deleteByPosSaveOrder_(set->data, &set->size, posOfElementToDelete);
}

ordered_array_set ordered_array_set_union(ordered_array_set set1, ordered_array_set set2) {
    ordered_array_set set = ordered_array_set_create(set1.size + set2.size);
    for (size_t i = 0; i < set1.size; i++)
        append_(set.data, &set.size, set1.data[i]);
    for (size_t i = 0; i < set2.size; i++) {
        if (linearSearch_(set.data, set.size, set2.data[i]) == set.size)
            ordered_array_set_insert(&set, set2.data[i]);
    }

    return set;
}

ordered_array_set ordered_array_set_difference(ordered_array_set set1, ordered_array_set set2) {
    ordered_array_set set = ordered_array_set_create(set1.size + set2.size);
    for (size_t i = 0; i < set1.size; i++)
        if (ordered_array_set_in(&set2, set1.data[i]) == set2.size)
            ordered_array_set_insert(&set, set1.data[i]);

    return set;
}

ordered_array_set ordered_array_set_symmetricDifference(ordered_array_set set1, ordered_array_set set2) {
    ordered_array_set difference1 = ordered_array_set_difference(set1, set2);
    ordered_array_set difference2 = ordered_array_set_difference(set1, set2);
    ordered_array_set set3 = ordered_array_set_union(difference1, difference2);

    return set3;
}

ordered_array_set ordered_array_set_complement(
        ordered_array_set set, ordered_array_set universumSet) {
    assert(ordered_array_set_isEqual(ordered_array_set_intersection(set, universumSet), set));

    return ordered_array_set_difference(universumSet, set);
}

void ordered_array_set_print(ordered_array_set set) {
    printf("{");
    bool isEmpty = true;
    for (size_t i = 0; i < set.size; i++) {
        printf("%d, ", set.data[i]);
        isEmpty = false;
    }
    if (isEmpty)
        printf("}");
    else
        printf("\b\b}");
}

void ordered_array_set_delete(ordered_array_set set) {
    free(set.data);
}


//ordered_array_set ordered_array_set_intersection(ordered_array_set set1,
//                                                 ordered_array_set set2) {
//    size_t capacity = set1.size + set2.size;
//    ordered_array_set set3 = ordered_array_set_create(capacity);
//    size_t i = 0;
//    size_t j = 0;
//    while (i < set1.size && j < set2.size) {
//        if (set1.data[i] > set2.data[j]) {
//            j++;
//        } else if (set1.data[i] < set2.data[j]) {
//            i++;
//        } else {
//            append_(set3.data, &set3.size, set1.data[i++]);
//            j++;
//        }
//    }
//    return (ordered_array_set) set3;
//}


//ordered_array_set ordered_array_set_difference(ordered_array_set set1,
//                                               ordered_array_set set2) {
//    size_t i = 0;
//    size_t j = 0;
//    int capacity = set1.size + set2.size;
//    ordered_array_set set3 = ordered_array_set_create(capacity);
//    while (i < set1.size && j < set2.size) {
//        if (set1.data[i] < set2.data[j]) {
//            append_(set3.data, &set3.size, set1.data[i++]);
//        } else if (set1.data[i] == set2.data[j]) {
//            i++;
//        } else {
//            j++;
//        }
//    }
//    for (size_t k = i; k < set1.size; k++) {
//        append_(set3.data, &set3.size, set1.data[k]);
//    }
//    return (ordered_array_set) set3;
//}
