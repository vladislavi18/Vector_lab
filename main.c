# include <stdio.h>
# include <stdint.h>
#include <assert.h>
# include "libs/data_structures/vector/vector.h"

void inputArray(int *a, size_t size) {
    for (size_t i = 0; i < size; i++) {
        scanf("%d", &a[i]);
    }
}

void outputArray(int *a, size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void test_reserve_emptyVector() {
    vector v = createVector(2);
    reserve(&v, 4);
    assert(v.capacity == 4);
}

void test_reserve_vectorReduction() {
    vector v = createVector(4);
    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 3);
    pushBack(&v, 4);
    reserve(&v, 2);
    assert(v.capacity == 2);
    assert(v.data[0] == 1);
    assert(v.data[1] == 2);
}

void test_reserve_vectorIncreases() {
    vector v = createVector(0);
    pushBack(&v, 1);
    reserve(&v, 2);
    assert(v.capacity == 2);
    assert(v.data[0] == 1);
}

void test_reserve() {
    test_reserve_emptyVector();
    test_reserve_vectorReduction();
    test_reserve_vectorIncreases();
}

void test_clear_oneElementInVector() {
    vector v = createVector(2);
    pushBack(&v, 1);
    pushBack(&v, 2);
    clear(&v);
    assert(v.size == 0);
    assert(v.capacity == 2);
}

void test_shrinkToFit_vectorIsNotFull1() {
    vector v = createVector(2);
    pushBack(&v, 1);
    shrinkToFit(&v);
    assert(v.capacity == 1);
    assert(v.size == 1);
    assert(v.data[0] == 1);
}

void test_shrinkToFit_vectorIsNotFull2() {
    vector v = createVector(5);
    pushBack(&v, 1);
    shrinkToFit(&v);
    assert(v.capacity == 1);
    assert(v.size == 1);
    assert(v.data[0] == 1);
}

void test_shrinkToFit_vectorEmpty() {
    vector v = createVector(0);
    shrinkToFit(&v);
    assert(v.capacity == 0);
    assert(v.size == 0);
}

void test_shrinkToFit_vectorFull() {
    vector v = createVector(1);
    pushBack(&v, 1);
    shrinkToFit(&v);
    assert(v.capacity == 1);
    assert(v.size == 1);
}

void test_shrinkToFit() {
    test_shrinkToFit_vectorIsNotFull1();
    test_shrinkToFit_vectorIsNotFull2();
    test_shrinkToFit_vectorEmpty();
    test_shrinkToFit_vectorFull();
}

void test_deleteVector_vectorIsNotFull() {
    vector v = createVector(2);
    pushBack(&v, 1);
    deleteVector(&v);
    assert(v.data == NULL);
    assert(v.capacity == 0);
    assert(v.size == 0);
}

void test_deleteVector_vectorFull() {
    vector v = createVector(2);
    pushBack(&v, 1);
    pushBack(&v, 2);
    deleteVector(&v);
    assert(v.data == NULL);
    assert(v.capacity == 0);
    assert(v.size == 0);
}

void test_deleteVector_vectorEmpty() {
    vector v = createVector(0);
    deleteVector(&v);
    assert(v.data == NULL);
    assert(v.capacity == 0);
    assert(v.size == 0);
}

void test_deletVector() {
    test_deleteVector_vectorIsNotFull();
    test_deleteVector_vectorFull();
    test_deleteVector_vectorEmpty();
}

void test_isEmpty_vectorEmpty() {
    vector v = createVector(0);
    assert(isEmpty(&v) == 1);
}

void test_isEmpty_vectorNotEmpty() {
    vector v = createVector(1);
    pushBack(&v, 1);
    assert(isEmpty(&v) == 0);
    assert(v.data[0] == 1);
    assert(v.capacity == 1);
    assert(v.size == 1);
}

void test_isEmpty() {
    test_isEmpty_vectorEmpty();
    test_isEmpty_vectorNotEmpty();
}

void test_isFull_vectorFull() {
    vector v = createVector(1);
    pushBack(&v, 1);
    assert(isFull(&v) == 1);
    assert(v.data[0] == 1);
    assert(v.capacity == 1);
    assert(v.size == 1);
}

void test_isFull_vectorEmpty() {
    vector v = createVector(1);
    assert(isFull(&v) == 0);
    assert(v.capacity == 1);
    assert(v.size == 0);
}

void test_isFull() {
    test_isFull_vectorFull();
    test_isFull_vectorEmpty();
}

void test_getVectorValue_returnsIndexOfElement() {
    vector v = createVector(2);
    pushBack(&v, 1);
    pushBack(&v, 2);
    assert(getVectorValue(&v, 0) == 1);
    assert(getVectorValue(&v, 1) == 2);
    assert(v.capacity == 2);
    assert(v.size == 2);
}

void test_pushBack_emptyVector() {
    vector v = createVector(0);
    pushBack(&v, 3);
    assert(v.size == 1);
    assert(v.capacity == 1);
    assert(v.data[0] == 3);
}

void test_pushBack_fullVector1() {
    vector v = createVector(1);
    pushBack(&v, 3);
    pushBack(&v, 5);
    assert(v.size == 2);
    assert(v.capacity == 2);
    assert(v.data[0] == 3);
    assert(v.data[1] == 5);
}

void test_pushBack_fullVector2() {
    vector v = createVector(2);
    pushBack(&v, 3);
    pushBack(&v, 5);
    pushBack(&v, 7);
    assert(v.size == 3);
    assert(v.capacity == 4);
    assert(v.data[0] == 3);
    assert(v.data[1] == 5);
    assert(v.data[2] == 7);
}

void test_pushBack() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector1();
    test_pushBack_fullVector2();
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);
    assert (v.size == 1);
    popBack(&v);
    assert (v.size == 0);
    assert (v.capacity == 1);
}

void test_atVector_notEmptyVector() {
    vector v = createVector(2);
    pushBack(&v, 2);
    pushBack(&v, 4);
    int *a = atVector(&v, 1);
    assert(*a == 4);
}

void test_atVector_requestToLastElement() {
    vector v = createVector(3);
    pushBack(&v, 3);
    pushBack(&v, 7);
    pushBack(&v, 10);
    int *a = atVector(&v, 2);
    assert(*a == 10);
}

void test_atVector() {
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
}

void test_back_oneElementInVector() {
    vector v = createVector(1);
    pushBack(&v, 3);
    int *a = back(&v);
    assert(*a == 3);
}

void test_front_oneElementInVector() {
    vector v = createVector(1);
    pushBack(&v, 10);
    int *a = front(&v);
    assert(*a == 10);
}

void test() {
    test_reserve();
    test_clear_oneElementInVector();
    test_shrinkToFit();
    test_deletVector();
    test_isEmpty();
    test_isFull();
    test_getVectorValue_returnsIndexOfElement();
    test_pushBack();
    test_popBack_notEmptyVector();
    test_atVector();
    test_back_oneElementInVector();
    test_front_oneElementInVector();
}

int main() {
    test();
    return 0;
}
