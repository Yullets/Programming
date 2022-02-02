#include <stdio.h>
#include "libs/data_structures/unordered_array_set/unordered_array_set.h"
#include "libs/data_structures/ordered_array_set/ordered_array_set.h"

//на неупорядоченном массиве

void utestCreate1() {
    unordered_array_set set = unordered_array_set_create(5);
    assert(set.data != NULL);
    assert(set.size == 0);
    assert(set.capacity == 5);
    unordered_array_set_delete(set);

    printf("Test 1 passed\n");
}

void utestCreate2() {
    unordered_array_set set = unordered_array_set_create(0);
    assert(set.data == NULL);
    assert(set.size == 0);
    assert(set.capacity == 0);
    unordered_array_set_delete(set);

    printf("Test 2 passed\n");
}

void unordered_array_set_test() {
    utestCreate1();
    utestCreate2();
}

void utestCreateFromArray1() {
    int a[4] = {1, 3, 5, 7};
    unordered_array_set set = unordered_array_set_create_from_array(a, 4);
    assert(set.size == 4);

    for (size_t i = 0; i < 4; i++)
        assert(a[i] == set.data[i]);

    printf("Test 1 passed\n");
}

void utestCreateFromArray2() {
    int a[7] = {1, 2, 13, 4, 9, 3, 7};
    unordered_array_set set = unordered_array_set_create_from_array(a, 7);
    assert(set.size == 7);

    for (size_t i = 0; i < 7; i++)
        assert(a[i] == set.data[i]);

    printf("Test 2 passed\n");
}

void unordered_array_set_from_array_test() {
    utestCreateFromArray1();
    utestCreateFromArray2();
}

void utestSetIn1() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2}, 2);
    int value = 1;
    long long resSet = unordered_array_set_in(&set1, value);
    int index = 0;
    assert (resSet == index);

    printf("Test 1 passed\n");
}

void utestSetIn2() {
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {1, 9, 7, 2}, 4);
    int value = 7;
    long long resSet = unordered_array_set_in(&set2, value);
    int index = 2;
    assert (resSet == index);

    printf("Test 2 passed\n");
}

void unordered_array_set_in_test() {
    utestSetIn1();
    utestSetIn2();
}

void utestisEqual1() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);

    bool resSet = unordered_array_set_isEqual(set1, set2);
    bool expectedRes = true;
    assert (resSet == expectedRes);

    printf("Test 1 passed\n");
}

void utestisEqual2() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 4, 66, 15}, 4);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {1, 4, 66, 15}, 4);

    bool resSet = unordered_array_set_isEqual(set1, set2);
    bool expectedRes = true;
    assert (resSet == expectedRes);

    printf("Test 2 passed\n");
}

void unordered_array_set_isEqual_test() {
    utestisEqual1();
    utestisEqual2();
}

void utestIsAbleAppend1() {
    unordered_array_set_create(0);

    printf("Test 1 passed\n");
}

void utestIsAbleAppend2() {
    unordered_array_set_create(1);

    printf("Test 2 passed\n");
}

void unordered_array_set_isAbleAppend_test() {
    utestIsAbleAppend1();
    utestIsAbleAppend2();
}

void utestInsert1() {
    unordered_array_set set1 = unordered_array_set_create(3);
    unordered_array_set_insert(&set1, 8);
    unordered_array_set_insert(&set1, 4);
    unordered_array_set_insert(&set1, 7);

    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {8, 4, 7}, 3);
    assert(unordered_array_set_isEqual(set1, expectedSet));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(expectedSet);

    printf("Test 1 passed\n");
}

void utestInsert2() {
    unordered_array_set set1 = unordered_array_set_create(5);
    unordered_array_set_insert(&set1, 2);
    unordered_array_set_insert(&set1, 3);
    unordered_array_set_insert(&set1, 4);
    unordered_array_set_insert(&set1, 9);
    unordered_array_set_insert(&set1, 1);

    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {2, 3, 4, 9, 1}, 5);
    assert(unordered_array_set_isEqual(set1, expectedSet));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(expectedSet);

}

void unordered_array_set_insert_test() {
    utestInsert1();
    utestInsert2();
}

void utestUnion1() {
    unordered_array_set set1 =
            unordered_array_set_create_from_array((int[]) {1, 2}, 2);
    unordered_array_set set2 =
            unordered_array_set_create_from_array((int[]) {2, 3}, 2);
    unordered_array_set resSet =
            unordered_array_set_union(set1, set2);
    unordered_array_set expectedSet =
            unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    assert(unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);

    printf("Test 1 passed\n");
}

void utestUnion2() {
    unordered_array_set set1 =
            unordered_array_set_create_from_array((int[]) {4, 6, 7}, 3);
    unordered_array_set set2 =
            unordered_array_set_create_from_array((int[]) {8, 7, 5}, 3);
    unordered_array_set resSet =
            unordered_array_set_union(set1, set2);
    unordered_array_set expectedSet =
            unordered_array_set_create_from_array((int[]) {4, 6, 7, 8, 5}, 5);
    assert(unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);

    printf("Test 2 passed\n");
}


void unordered_array_set_union_test() {
    utestUnion1();
    utestUnion2();
}

void utestIntersection1() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 6, 10}, 6);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {1, 4, 5, 6}, 4);
    unordered_array_set resSet = unordered_array_set_intersection(set1, set2);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {1, 4, 6}, 3);

    assert (unordered_array_set_isEqual(resSet, expectedSet));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);

    printf("Test 1 passed\n");
}

void utestIntersection2() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {4, 6, 7, 2, -3, 0, 44}, 7);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {5, 1, 2}, 3);
    unordered_array_set resSet = unordered_array_set_intersection(set1, set2);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {2}, 1);
    assert (unordered_array_set_isEqual(resSet, expectedSet));

    printf("Test 2 passed\n");
}

void unordered_array_set_intersection_test() {
    utestIntersection1();
    utestIntersection2();
}

void utestDifference1() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {0, 3, 5, 6}, 4);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {5, 1, 2}, 3);
    unordered_array_set resSet = unordered_array_set_difference(set1, set2);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {0, 3, 6}, 3);
    assert (unordered_array_set_isEqual(resSet, expectedSet));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);

    printf("Test 1 passed\n");
}

void utestDifference2() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {63, 3, 4, 5}, 4);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {0, 3, 4}, 3);
    unordered_array_set resSet = unordered_array_set_difference(set1, set2);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {63, 5}, 2);
    assert (unordered_array_set_isEqual(resSet, expectedSet));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);

    printf("Test 2 passed\n");
}

void unordered_array_set_difference_test() {
    utestDifference1();
    utestDifference2();
}

void utestSymmetricDifference1() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {5, 6, 7, 1, 2}, 5);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {-4, 5, 7, 9, 3}, 5);
    unordered_array_set resSet = unordered_array_set_symmetricDifference(set1, set2);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {1, -4, 6, 2, 9, 3}, 6);
    assert (unordered_array_set_isEqual(resSet, expectedSet));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);

    printf("Test 1 passed\n");
}

void utestSymmetricDifference2() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 6, 10}, 6);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {1, 4, 5, 6}, 4);
    unordered_array_set resSet = unordered_array_set_symmetricDifference(set1, set2);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {2, 3, 5, 10}, 4);
    assert (unordered_array_set_isEqual(resSet, expectedSet));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);

    printf("Test 2 passed\n");
}

void unordered_array_set_symmetricDifference_test() {
    utestSymmetricDifference1();
    utestSymmetricDifference2();
}

void utestComplement1() {
    unordered_array_set universumSet =
            unordered_array_set_create_from_array((int[]) {1, 2, 3, 5, 6}, 5);
    unordered_array_set set1 =
            unordered_array_set_create_from_array((int[]) {}, 0);
    unordered_array_set resSet =
            unordered_array_set_complement(set1, universumSet);
    unordered_array_set expectedSet =
            unordered_array_set_create_from_array((int[]) {1, 2, 3, 5, 6}, 5);
    assert(unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(universumSet);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);

    printf("Test 1 passed\n");
}

void utestComplement2() {
    unordered_array_set universumSet =
            unordered_array_set_create_from_array((int[]) {1, 2, 3, 5, 6}, 5);
    unordered_array_set set1 =
            unordered_array_set_create_from_array((int[]) {1, 2, 3, 5, 6}, 5);
    unordered_array_set resSet =
            unordered_array_set_complement(set1, universumSet);
    unordered_array_set expectedSet =
            unordered_array_set_create_from_array((int[]) {}, 0);
    assert(unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(universumSet);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);

    printf("Test 2 passed\n");
}

void unordered_array_set_complement_test() {
    utestComplement1();
    utestComplement2();
}

void utestDeleteElement1() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[])
                                                                             {3, 4, 5, 7, 10}, 5);
    unordered_array_set_deleteElement(&set1, 7);
    unordered_array_set expectedSet =
            unordered_array_set_create_from_array((int[]) {3, 4, 5, 10}, 4);
    assert(unordered_array_set_isEqual(set1, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(expectedSet);
}

void utestDeleteElement2() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[])
                                                                             {5, -3, 3}, 3);
    unordered_array_set_deleteElement(&set1, -3);
    unordered_array_set expectedSet =
            unordered_array_set_create_from_array((int[]) {5, 3}, 2);
    assert (unordered_array_set_isEqual(set1, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(expectedSet);
}

void unordered_array_set_deleteElement_test() {
    utestDeleteElement1();
    utestDeleteElement2();

}

void test_unordered() {
    unordered_array_set_test();
    unordered_array_set_from_array_test();
    unordered_array_set_in_test();
    unordered_array_set_isEqual_test();
    unordered_array_set_isAbleAppend_test();
    unordered_array_set_insert_test();
    unordered_array_set_union_test();
    unordered_array_set_intersection_test();
    unordered_array_set_difference_test();
    unordered_array_set_symmetricDifference_test();
    unordered_array_set_complement_test();
    unordered_array_set_deleteElement_test();
}

//на упорядоченном массиве

void otestSetIn1() {
    ordered_array_set set1 =
            ordered_array_set_create_from_array((int[]) {3, 4, 5, 7, 10}, 5);
    int resIndex = ordered_array_set_in(&set1, 10);
    int expectedIndex = 4;
    assert(resIndex == expectedIndex);

    printf("Test 1 passed\n");
    ordered_array_set_delete(set1);
}

void otestSetIn2() {
    ordered_array_set set1 =
            ordered_array_set_create_from_array((int[]) {3, 4, 5, 7, 10}, 5);
    int resIndex = ordered_array_set_in(&set1, 10);
    int expectedIndex = 4;
    assert(resIndex == expectedIndex);

    printf("Test 2 passed\n");
    ordered_array_set_delete(set1);
}

void ordered_array_set_in_test() {
    otestSetIn1();
    otestSetIn2();
}


void otestisEqual1() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);

    bool resSet = ordered_array_set_isEqual(set1, set2);
    bool expectedRes = true;
    assert (resSet == expectedRes);

    printf("Test 1 passed\n");
}

void otestisEqual2() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1, 4, 66, 15}, 4);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {1, 4, 66, 15}, 4);

    bool resSet = ordered_array_set_isEqual(set1, set2);
    bool expectedRes = true;
    assert (resSet == expectedRes);

    printf("Test 2 passed\n");
}

void ordered_array_set_isEqual_test() {
    otestisEqual1();
    otestisEqual2();
}

void otestIsSubset1() {
    ordered_array_set subset = ordered_array_set_create_from_array((int[])
                                                                           {0}, 0);
    ordered_array_set set = ordered_array_set_create_from_array((int[]) {0,
                                                                         3, 4}, 3);
    assert (ordered_array_set_isSubset(subset, set));
    ordered_array_set_delete(subset);
    ordered_array_set_delete(set);
}

void otestIsSubset2() {
    ordered_array_set subset = ordered_array_set_create_from_array((int[])
                                                                           {}, 0);
    ordered_array_set set = ordered_array_set_create_from_array((int[]) {},
                                                                0);
    assert (ordered_array_set_isSubset(subset, set));
    ordered_array_set_delete(subset);
    ordered_array_set_delete(set);
}

void ordered_array_set_isSubset_test() {
    otestIsSubset1();
    otestIsSubset2();
}

void otestInsert1() {
    ordered_array_set set1 = ordered_array_set_create(10);
    ordered_array_set_insert(&set1, 5);
    ordered_array_set_insert(&set1, 5);
    ordered_array_set_insert(&set1, 10);
    ordered_array_set_insert(&set1, 4);
    ordered_array_set_insert(&set1, 3);
    ordered_array_set expectedSet =
            ordered_array_set_create_from_array((int[]) {3, 4, 5, 10}, 4);
    assert(ordered_array_set_isEqual(set1, expectedSet));
    ordered_array_set_delete(set1);
    ordered_array_set_delete(expectedSet);

    printf("Test 1 passed\n");
}

void otestInsert2() {
    ordered_array_set set1 = ordered_array_set_create(5);
    ordered_array_set_insert(&set1, 0);
    ordered_array_set_insert(&set1, -16);
    ordered_array_set_insert(&set1, 20);
    ordered_array_set_insert(&set1, 9);
    ordered_array_set expectedSet =
            ordered_array_set_create_from_array((int[]) {-16, 0, 9, 20}, 4);
    assert(ordered_array_set_isEqual(set1, expectedSet));
    ordered_array_set_delete(set1);
    ordered_array_set_delete(expectedSet);
}
void ordered_array_insert_test() {
    otestInsert1();
    otestInsert2();
}

void otestDeleteElement1() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {-2,
                                                                          -1, 0, 3, 6, 8}, 6);
    ordered_array_set_deleteElement(&set1, 0);
    ordered_array_set expectedSet =
            ordered_array_set_create_from_array((int[]) {-2, -1, 3, 6, 8}, 5);
    assert (ordered_array_set_isEqual(set1, expectedSet));
    ordered_array_set_delete(set1);
    ordered_array_set_delete(expectedSet);
}
void otestDeleteElement2() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1,
                                                                          6, 3, 88}, 4);
    ordered_array_set_deleteElement(&set1, 1);
    ordered_array_set expectedSet =
            ordered_array_set_create_from_array((int[]) {6, 3, 88}, 3);
    assert (ordered_array_set_isEqual(set1, expectedSet));
    ordered_array_set_delete(set1);
    ordered_array_set_delete(expectedSet);
}
void ordered_array_set_deleteElement_test() {
    otestDeleteElement1();
    otestDeleteElement2();
}

void otestUnion1() {
    ordered_array_set set1 =
            ordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    ordered_array_set set2 =
            ordered_array_set_create_from_array((int[]) {}, 0);
    ordered_array_set resSet =
            ordered_array_set_union(set1, set2);
    ordered_array_set expectedSet =
            ordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    assert(ordered_array_set_isEqual(resSet, expectedSet));
    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}

void otestUnion2() {
    ordered_array_set set1 =
            ordered_array_set_create_from_array((int[]) {2, 3, 4, 6}, 4);
    ordered_array_set set2 =
            ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
    ordered_array_set resSet =
            ordered_array_set_union(set1, set2);
    ordered_array_set expectedSet =
            ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5, 6},
                                                6);
    assert(ordered_array_set_isEqual(resSet, expectedSet));
    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}

void ordered_array_set_union_test() {
    otestUnion1();
    otestUnion2();
}

void otestIntersection1() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {4,
                                                                          6, 7, 2, -3, 0, 44}, 7);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {5,
                                                                          1, 2}, 3);
    ordered_array_set resSet = ordered_array_set_intersection(set1, set2);
    ordered_array_set expectedSet =
            ordered_array_set_create_from_array((int[]) {2}, 1);
    assert (ordered_array_set_isEqual(resSet, expectedSet));
    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}
void otestIntersection2() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {-3,
                                                                          4, 22, 8, 4}, 5);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {5,
                                                                          1, 2}, 3);
    ordered_array_set resSet = ordered_array_set_intersection(set1, set2);
    ordered_array_set expectedSet =
            ordered_array_set_create_from_array((int[]) {}, 0);
    assert (ordered_array_set_isEqual(resSet, expectedSet));
    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}
void ordered_array_set_intersection_test() {
    otestIntersection1();
    otestIntersection2();
}

void otestDifference1() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {-1,
                                                                          0, 8, 9, 33}, 4);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {-1,
                                                                          33, 34}, 3);
    ordered_array_set resSet = ordered_array_set_difference(set1, set2);
    ordered_array_set expectedSet =
            ordered_array_set_create_from_array((int[]) {0, 8, 9}, 3);
    assert (ordered_array_set_isEqual(resSet, expectedSet));
    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}
void otestDifference2() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {-
                                                                                  11, -4, 4, 9, 10}, 5);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {2,
                                                                          6, 67, 99}, 4);
    ordered_array_set resSet = ordered_array_set_difference(set1, set2);
    ordered_array_set expectedSet =
            ordered_array_set_create_from_array((int[]) {-11, -4, 4, 9, 10}, 5);
    assert (ordered_array_set_isEqual(resSet, expectedSet));
    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}
void ordered_array_set_difference_test() {
    otestDifference1();
    otestDifference2();
}


void otestSimmetricDifference1() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1,
                                                                          2, 3, 4, 6, 10}, 6);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {1,
                                                                          2, 3, 4, 6, 10}, 6);
    ordered_array_set resSet = ordered_array_set_symmetricDifference(set1,
                                                                     set2);
    ordered_array_set expectedSet =
            ordered_array_set_create_from_array((int[]) {}, 0);
    assert (ordered_array_set_isEqual(resSet, expectedSet));
    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}
void otestSimmetricDifference2() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {-
                                                                                  12, -11, -1, 0, 4, 3, 7}, 7);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {-
                                                                                  12, -11, -1, 4, 3, 7}, 6);
    ordered_array_set resSet = ordered_array_set_symmetricDifference(set1,
                                                                     set2);
    ordered_array_set expectedSet =
            ordered_array_set_create_from_array((int[]) {0}, 1);
    assert (ordered_array_set_isEqual(resSet, expectedSet));
    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}
void ordered_array_set_symmetricDifference_test() {
    otestSimmetricDifference1();
    otestSimmetricDifference2();
}

void otestCompliment1() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {8,
                                                                          9}, 2);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {-4,
                                                                          -3, 4, 7, 8, 9, 10}, 7);
    ordered_array_set resSet = ordered_array_set_complement(set1, set2);
    assert(resSet.data[0] == -4);
    assert(resSet.data[1] == -3);
    assert(resSet.data[2] == 4);
    assert(resSet.data[3] == 7);
    assert(resSet.data[4] == 10);
    assert(resSet.size == 5);
    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
}
void otestCompliment2() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {2,
                                                                          10, 19}, 3);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {2,
                                                                          10, 19, 39, 69}, 5);
    ordered_array_set resSet = ordered_array_set_complement(set1, set2);
    assert(resSet.data[0] == 39);
    assert(resSet.data[1] == 69);
    assert(resSet.size == 2);
    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
}
void ordered_array_set_complement_test() {
    otestCompliment1();
    otestCompliment2();
}


void test_ordered() {
    ordered_array_set_in_test();
    ordered_array_insert_test();
    ordered_array_set_isEqual_test();
    ordered_array_set_isSubset_test();
    ordered_array_set_deleteElement_test();
    ordered_array_set_union_test();
    ordered_array_set_intersection_test();
    ordered_array_set_difference_test();
    ordered_array_set_symmetricDifference_test();
    ordered_array_set_complement_test();

}

int main() {
    test_unordered();
    test_ordered();

    return 0;
}


//void utestComplement1() {
//    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
//    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {1, 3, 2, 4, 5, 6, 8}, 7);
//    unordered_array_set resSet = unordered_array_set_complement(set1, set2);
//    assert(resSet.data[0] == 6);
//    assert(resSet.data[1] == 8);
//    assert(resSet.size == 2);
//
//    unordered_array_set_delete(set1);
//    unordered_array_set_delete(set2);
//    unordered_array_set_delete(resSet);
//
//    printf("Test 1 passed\n");
//}
//
//void utestComplement2() {
//    int a1[] = {4, 7, 8, 9, 1};
//    unordered_array_set set1 = {a1, 5, 10};
//    int a2[] = {4, 8, 9, 1, 7, -3, -4, 0};
//    unordered_array_set set2 = {a2, 8, 10};
//    unordered_array_set resSet = unordered_array_set_complement(set1, set2);
//
//    assert(resSet.data[0] == -3);
//    assert(resSet.data[1] == -4);
//    assert(resSet.data[2] == 0);
//    assert(resSet.size == 3);
//
//    unordered_array_set_delete(set1);
//    unordered_array_set_delete(set2);
//    unordered_array_set_delete(resSet);
//
//    printf("Test 2 passed\n");
//}
//
//void unordered_array_set_complement_test() {
//    utestComplement1();
//    utestComplement2();
//}

//void utestDeleteElement1() {
//    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {3,
//                                                                          4, 5, 7, 10}, 5);
//    unordered_array_set_deleteElement(&set1, 7);
//    unordered_array_set expectedSet =
//            unordered_array_set_create_from_array((int[]) {3, 4, 5, 10}, 4);
//    assert(unordered_array_set_isEqual(set1, expectedSet));
//    unordered_array_set_delete(set1);
//    unordered_array_set_delete(expectedSet);
//
//    printf("Test 1 passed\n");
//}
//
//void utestDeleteElement2() {
//    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {6,
//                                                                              4, 3, 1, 15, 66}, 6);
//    unordered_array_set_deleteElement(&set2, 66);
//    unordered_array_set expectedSet =
//            unordered_array_set_create_from_array((int[]) {6, 4, 3, 1, 15}, 5);
//    assert(unordered_array_set_isEqual(set2, expectedSet));
//    unordered_array_set_delete(set2);
//    unordered_array_set_delete(expectedSet);
//
//    printf("Test 1 passed\n");
//}
//
//void unordered_array_set_deleteElement_test() {
//    utestDeleteElement1();
//    utestDeleteElement2();
//}