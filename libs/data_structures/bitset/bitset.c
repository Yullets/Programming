//
// Created by Fr on 14.12.2021.
//

#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <stdbool.h>

typedef struct bitset {
    uint32_t values;
    uint32_t maxValue;
} bitset;

bitset bitset_create(unsigned maxValue) {
    assert(maxValue < 32);
    return (bitset) {0, maxValue};
}

bool bitset_in(bitset set, unsigned value) {
    return set.values >> value & 1;
}

bool bitset_isEqual(bitset set1, bitset set2) {
    assert(set1.maxValue == set2.maxValue);
    int totalShifts = set1.maxValue - set1.values;
    int usedSet1 = (set1.values << totalShifts) >> totalShifts;
    int usedSet2 = (set2.values << totalShifts) >> totalShifts;
    return usedSet1 == usedSet2;
}


bool bitset_isSubset(bitset subset, bitset set) {
    assert(subset.maxValue == set.maxValue);
    return subset.values == set.values & subset.values;
}

void bitset_insert(bitset *set, unsigned int value) {
    set->values |= (1 << value);
}

void bitset_deleteElement(bitset *set, unsigned int value) {
    set->values = set->values & ~(1 << value);
}

bitset bitset_union(bitset set1, bitset set2) {
    assert(set1.maxValue == set2.maxValue);
    return (bitset) {set1.values | set2.values, set1.maxValue};
}

bitset bitset_intersection(bitset set1, bitset set2) {
    assert(set1.maxValue == set2.maxValue);
    return (bitset) {set1.values & set2.values, set1.maxValue};
}

bitset bitset_difference(bitset set1, bitset set2) {
    assert(set1.maxValue == set2.maxValue);
    return (bitset) {set1.values & ~set2.values, set1.maxValue};
}

bitset bitset_symmetricDifference(bitset set1, bitset set2) {
    assert(set1.maxValue == set2.maxValue);
    return (bitset) {set1.values ^ set2.values, set1.maxValue};
}

bitset bitset_compliment(bitset set) {
    return (bitset) {~set.values, set.maxValue};
}

void bitset_print(bitset set) {
    printf("{");
    bool isEmpty = true;
    for (size_t i = 0; i <= set.maxValue; ++i) {
        if (bitset_in(set, i)) {
            printf("%d, ", i);
            isEmpty = false;
        }
    }
    if (isEmpty)
        printf("}\n");
    else
        printf("\b\b}\n");
}

