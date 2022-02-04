#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include "libs/data_structures/vector/vector.h"
#include "libs/data_structures/vector/vectorVoid.h"

void test_pushBack_emptyVector() {
    vector v = createVector(0);
    pushBack(&v, 1);

    assert(v.capacity == 1);
}

void test_pushBack_fullVector() {
    vector v = createVector(5);
    pushBack(&v, 1);

    assert(v.capacity == 10);
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);

    assert (v.size == 1);
    popBack(&v);
    assert (v.size == 0);
    assert (v.capacity == 1);
}

void test_atVector_notEmptyVector1() {
    vector v = createVector(4);

    pushBack(&v, 1);
    pushBack(&v, 3);
    pushBack(&v, 6);
    pushBack(&v, 9);

    assert(v.data + 3 == atVector(&v, 3));
}

void test_atVector_notEmptyVector2() {
    vector v = createVector(2);

    pushBack(&v, 9);
    pushBack(&v, 7);

    assert(v.data + 1 == atVector(&v, 1));
}

void test_atVector_requestToLastElement1() {
    vector v = createVector(3);

    pushBack(&v, 3);
    pushBack(&v, 6);
    pushBack(&v, 5);

    assert(v.data + 2 == back(&v));
}

void test_atVector_requestToLastElement2() {
    vector v = createVector(1);

    pushBack(&v, 1);

    assert(v.data == back(&v));
}

void test_back_oneElementInVector() {
    vector v = createVector(1);

    pushBack(&v, 7);

    assert(v.data == back(&v));
}

void test_front_oneElementInVector() {
    vector v = createVector(1);

    pushBack(&v, 2);

    assert(v.data == front(&v));
}

void test() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
    test_atVector_notEmptyVector1();
    test_atVector_notEmptyVector2();
    test_atVector_requestToLastElement1();
    test_atVector_requestToLastElement2();
    test_back_oneElementInVector();
    test_front_oneElementInVector();
}

int main() {
    //vector v = createVector ( SIZE_MAX );
    //test();
    //vectorVoid v;

    size_t n;
    scanf("%zd", &n);

    vectorVoid v = createVectorV(0, sizeof(float));
    for (int i = 0; i < n; i++) {
        float x;
        scanf("%f", &x);

        pushBackV(&v, &x);
    }

    for (int i = 0; i < n; i++) {
        float x;
        getVectorValueV(&v, i, &x);

        printf("%f ", x);
    }

    return 0;
}
