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

void test_atVector_requestToLastElement(){
    vector v = createVector(3);
    pushBack(&v, 3);
    pushBack(&v, 7);
    pushBack(&v, 10);
    int *a = atVector(&v, 2);
    assert(*a == 10);
}

void test_back_oneElementInVector(){
    vector v = createVector(1);
    pushBack(&v, 3);
    int *a = back(&v);
    assert(*a == 3);
}

void test_front_oneElementInVector(){
    vector v = createVector(1);
    pushBack(&v, 10);
    int *a = front(&v);
    assert(*a == 10);
}

void test() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector1();
    test_pushBack_fullVector2();
    test_popBack_notEmptyVector();
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
    test_back_oneElementInVector();
    test_front_oneElementInVector();
}

int main() {
    test();
    return 0;
}
