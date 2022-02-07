# include <stdint.h>
#include <assert.h>
# include "libs/data_structures/vector/vectorVoid.h"
#include <math.h>
#include <float.h>

#define EPS 10E-7

void test_reserveV_emptyVector() {
    vectorVoid v = createVectorV(2, sizeof(int));
    reserveV(&v, 4);
    assert(v.capacity == 4);
}

void test_reserveV_vectorReduction() {
    vectorVoid v = createVectorV(4, sizeof(int));
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    pushBackV(&v, &a);
    pushBackV(&v, &b);
    pushBackV(&v, &c);
    pushBackV(&v, &d);
    reserveV(&v, 2);
    assert(v.capacity == 2);
    int e;
    getVectorValueV(&v, 0, &e);
    assert(e == 1);
    int f;
    getVectorValueV(&v, 1, &f);
    assert(f == 2);
}

void test_reserveV_vectorIncreases() {
    vectorVoid v = createVectorV(0, sizeof(int));
    int a = 1;
    pushBackV(&v, &a);
    reserveV(&v, 2);
    assert(v.capacity == 2);
    int b = 1;
    getVectorValueV(&v, 0, &b);
    assert(b == 1);
}

void test_reserveV_emptyVectorFloat() {
    vectorVoid v = createVectorV(2, sizeof(float));
    reserveV(&v, 4);
    assert(v.capacity == 4);
}

void test_reserveV_vectorReductionFloat() {
    vectorVoid v = createVectorV(4, sizeof(float));
    float a = 1.5f;
    float b = 2.5f;
    float c = 3.7f;
    float d = 4.2f;
    pushBackV(&v, &a);
    pushBackV(&v, &b);
    pushBackV(&v, &c);
    pushBackV(&v, &d);
    reserveV(&v, 2);
    assert(v.capacity == 2);
    float e;
    getVectorValueV(&v, 0, &e);
    assert(fabs(e - 1.5) < DBL_EPSILON);
    float f;
    getVectorValueV(&v, 1, &f);
    assert(fabs(f - 2.5) < DBL_EPSILON);
}

void test_reserveV_vectorIncreasesFloat() {
    vectorVoid v = createVectorV(0, sizeof(float));
    float a = 1.6f;
    pushBackV(&v, &a);
    reserveV(&v, 2);
    assert(v.capacity == 2);
    getVectorValueV(&v, 0, &a);
    assert(fabs(a - 1.6) < EPS);
}

void test_reserveV() {
    test_reserveV_emptyVector();
    test_reserveV_vectorReduction();
    test_reserveV_vectorIncreases();
    test_reserveV_emptyVectorFloat();
    test_reserveV_vectorReductionFloat();
    test_reserveV_vectorIncreasesFloat();
}

void test_clearV_oneElementInVector() {
    vectorVoid v = createVectorV(2, sizeof(int));
    int a = 1;
    int b = 2;
    pushBackV(&v, &a);
    pushBackV(&v, &b);
    clearV(&v);
    assert(v.size == 0);
    assert(v.capacity == 2);
}

void test_shrinkToFit_vectorIsNotFull1() {
    vectorVoid v = createVectorV(2, sizeof(int));
    int a = 1;
    pushBackV(&v, &a);
    shrinkToFitV(&v);
    assert(v.capacity == 1);
    assert(v.size == 1);
    int b;
    getVectorValueV(&v, 0, &b);
    assert(b == 1);
}

void test_shrinkToFit_vectorIsNotFull2() {
    vectorVoid v = createVectorV(5, sizeof(int));
    int a = 2;
    pushBackV(&v, &a);
    shrinkToFitV(&v);
    assert(v.capacity == 1);
    assert(v.size == 1);
    getVectorValueV(&v, 0, &a);
    assert(a == 2);
}

void test_shrinkToFit_vectorEmpty() {
    vectorVoid v = createVectorV(0, sizeof(int));
    shrinkToFitV(&v);
    assert(v.capacity == 0);
    assert(v.size == 0);
}

void test_shrinkToFit_vectorFull() {
    vectorVoid v = createVectorV(1, sizeof(int));
    int a = 1;
    pushBackV(&v, &a);
    shrinkToFitV(&v);
    assert(v.capacity == 1);
    assert(v.size == 1);
    getVectorValueV(&v, 0, &a);
    assert(a == 1);
}

void test_shrinkToFit_vectorIsNotFull1Float() {
    vectorVoid v = createVectorV(2, sizeof(float));
    float a = 1.5f;
    pushBackV(&v, &a);
    shrinkToFitV(&v);
    assert(v.capacity == 1);
    assert(v.size == 1);
    float b;
    getVectorValueV(&v, 0, &b);
    assert(fabs(b - 1.5) < DBL_EPSILON);
}

void test_shrinkToFit_vectorIsNotFull2Float() {
    vectorVoid v = createVectorV(5, sizeof(float));
    float a = 2.3f;
    pushBackV(&v, &a);
    shrinkToFitV(&v);
    assert(v.capacity == 1);
    assert(v.size == 1);
    getVectorValueV(&v, 0, &a);
    assert(fabs(a - 2.3) < EPS);
}

void test_shrinkToFit_vectorEmptyFloat() {
    vectorVoid v = createVectorV(0, sizeof(float));
    shrinkToFitV(&v);
    assert(v.capacity == 0);
    assert(v.size == 0);
}

void test_shrinkToFit_vectorFullFloat() {
    vectorVoid v = createVectorV(1, sizeof(float));
    float a = 1.7f;
    pushBackV(&v, &a);
    shrinkToFitV(&v);
    assert(v.capacity == 1);
    assert(v.size == 1);
    getVectorValueV(&v, 0, &a);
    assert(fabs(a - 1.7) < EPS);
}

void test_shrinkToFit() {
    test_shrinkToFit_vectorIsNotFull1();
    test_shrinkToFit_vectorIsNotFull2();
    test_shrinkToFit_vectorEmpty();
    test_shrinkToFit_vectorFull();
    test_shrinkToFit_vectorIsNotFull1Float();
    test_shrinkToFit_vectorIsNotFull2Float();
    test_shrinkToFit_vectorEmptyFloat();
    test_shrinkToFit_vectorFullFloat();
}

void test_deleteVector_vectorIsNotFull() {
    vectorVoid v = createVectorV(2, sizeof(int));
    int a = 1;
    pushBackV(&v, &a);
    deleteVectorV(&v);
    assert(v.data == NULL);
    assert(v.capacity == 0);
    assert(v.size == 0);
}

void test_deleteVector_vectorFull() {
    vectorVoid v = createVectorV(2, sizeof(int));
    int a = 1;
    int b = 2;
    pushBackV(&v, &a);
    pushBackV(&v, &b);
    deleteVectorV(&v);
    assert(v.data == NULL);
    assert(v.capacity == 0);
    assert(v.size == 0);
}

void test_deleteVector_vectorEmpty() {
    vectorVoid v = createVectorV(0, sizeof(int));
    deleteVectorV(&v);
    assert(v.data == NULL);
    assert(v.capacity == 0);
    assert(v.size == 0);
}

void test_deleteVector_vectorIsNotFullFloat() {
    vectorVoid v = createVectorV(2, sizeof(float));
    int a = 1;
    pushBackV(&v, &a);
    deleteVectorV(&v);
    assert(v.data == NULL);
    assert(v.capacity == 0);
    assert(v.size == 0);
}

void test_deleteVector_vectorFullFloat() {
    vectorVoid v = createVectorV(2, sizeof(float));
    int a = 1;
    int b = 2;
    pushBackV(&v, &a);
    pushBackV(&v, &b);
    deleteVectorV(&v);
    assert(v.data == NULL);
    assert(v.capacity == 0);
    assert(v.size == 0);
}

void test_deleteVector_vectorEmptyFloat() {
    vectorVoid v = createVectorV(0, sizeof(float));
    deleteVectorV(&v);
    assert(v.data == NULL);
    assert(v.capacity == 0);
    assert(v.size == 0);
}

void test_deleteVector() {
    test_deleteVector_vectorIsNotFull();
    test_deleteVector_vectorFull();
    test_deleteVector_vectorEmpty();
    test_deleteVector_vectorIsNotFullFloat();
    test_deleteVector_vectorFullFloat();
    test_deleteVector_vectorEmptyFloat();
}

void test_isEmpty_vectorEmpty() {
    vectorVoid v = createVectorV(0, sizeof(int));
    assert(isEmptyV(&v) == 1);
}

void test_isEmpty_vectorNotEmpty() {
    vectorVoid v = createVectorV(1, sizeof(int));
    int a = 1;
    pushBackV(&v, &a);
    assert(isEmptyV(&v) == 0);
    getVectorValueV(&v, 0, &a);
    assert(a == 1);
    assert(v.capacity == 1);
    assert(v.size == 1);
}

void test_isEmpty_vectorEmptyFloat() {
    vectorVoid v = createVectorV(0, sizeof(float));
    assert(isEmptyV(&v) == 1);
}

void test_isEmpty_vectorNotEmptyFloat() {
    vectorVoid v = createVectorV(1, sizeof(float));
    float a = 1.4f;
    pushBackV(&v, &a);
    assert(isEmptyV(&v) == 0);
    getVectorValueV(&v, 0, &a);
    assert(fabs(a - 1.4) < EPS);
    assert(v.capacity == 1);
    assert(v.size == 1);
}

void test_isEmpty() {
    test_isEmpty_vectorEmpty();
    test_isEmpty_vectorNotEmpty();
    test_isEmpty_vectorEmptyFloat();
    test_isEmpty_vectorNotEmptyFloat();
}

void test_isFull_vectorFull() {
    vectorVoid v = createVectorV(1, sizeof(int));
    int a = 1;
    pushBackV(&v, &a);
    assert(isFullV(&v) == 1);
    getVectorValueV(&v, 0, &a);
    assert(a == 1);
    assert(v.capacity == 1);
    assert(v.size == 1);
}

void test_isFull_vectorEmpty() {
    vectorVoid v = createVectorV(1, sizeof(int));
    assert(isFullV(&v) == 0);
    assert(v.capacity == 1);
    assert(v.size == 0);
}

void test_isFull_vectorFullFloat() {
    vectorVoid v = createVectorV(1, sizeof(float));
    int a = 1;
    pushBackV(&v, &a);
    assert(isFullV(&v) == 1);
    getVectorValueV(&v, 0, &a);
    assert(a == 1);
    assert(v.capacity == 1);
    assert(v.size == 1);
}

void test_isFull_vectorEmptyFloat() {
    vectorVoid v = createVectorV(1, sizeof(float));
    assert(isFullV(&v) == 0);
    assert(v.capacity == 1);
    assert(v.size == 0);
}

void test_isFull() {
    test_isFull_vectorFull();
    test_isFull_vectorEmpty();
    test_isFull_vectorFullFloat();
    test_isFull_vectorEmptyFloat();
}

void test_getVectorValue_returnsIndexOfElement() {
    vectorVoid v = createVectorV(2, sizeof(int));
    int a = 1;
    int b = 2;
    pushBackV(&v, &a);
    pushBackV(&v, &b);
    getVectorValueV(&v, 0, &a);
    getVectorValueV(&v, 1, &b);
    assert(a == 1);
    assert(b == 2);
    assert(v.capacity == 2);
    assert(v.size == 2);
}

void test_pushBack_emptyVector() {
    vectorVoid v = createVectorV(0, sizeof(int));
    int a = 3;
    pushBackV(&v, &a);
    assert(v.size == 1);
    assert(v.capacity == 1);
    getVectorValueV(&v, 0, &a);
    assert(a == 3);
}

void test_pushBack_fullVector1() {
    vectorVoid v = createVectorV(1, sizeof(int));
    int a = 3;
    int b = 5;
    pushBackV(&v, &a);
    pushBackV(&v, &b);
    assert(v.size == 2);
    assert(v.capacity == 2);
    getVectorValueV(&v, 0, &a);
    getVectorValueV(&v, 1, &b);
    assert(a == 3);
    assert(b == 5);
}

void test_pushBack_fullVector2() {
    vectorVoid v = createVectorV(2, sizeof(int));
    int a = 3;
    int b = 5;
    int c = 7;
    pushBackV(&v, &a);
    pushBackV(&v, &b);
    pushBackV(&v, &c);
    assert(v.size == 3);
    assert(v.capacity == 4);
    getVectorValueV(&v, 0, &a);
    getVectorValueV(&v, 1, &b);
    getVectorValueV(&v, 2, &c);
    assert(a == 3);
    assert(b == 5);
    assert(c == 7);
}

void test_pushBack_emptyVectorFloat() {
    vectorVoid v = createVectorV(0, sizeof(float));
    float a = 3.6f;
    pushBackV(&v, &a);
    assert(v.size == 1);
    assert(v.capacity == 1);
    getVectorValueV(&v, 0, &a);
    assert(fabs(a - 3.6) < EPS);
}

void test_pushBack_fullVector1Float() {
    vectorVoid v = createVectorV(1, sizeof(float));
    float a = 3.4f;
    float b = 5.7f;
    pushBackV(&v, &a);
    pushBackV(&v, &b);
    assert(v.size == 2);
    assert(v.capacity == 2);
    getVectorValueV(&v, 0, &a);
    getVectorValueV(&v, 1, &b);
    assert(fabs(a - 3.4) < EPS);
    assert(fabs(b - 5.7) < EPS);
}

void test_pushBack_fullVector2Float() {
    vectorVoid v = createVectorV(2, sizeof(float));
    float a = 3.4f;
    float b = 5.7f;
    float c = 7.3f;
    pushBackV(&v, &a);
    pushBackV(&v, &b);
    pushBackV(&v, &c);
    assert(v.size == 3);
    assert(v.capacity == 4);
    getVectorValueV(&v, 0, &a);
    getVectorValueV(&v, 1, &b);
    getVectorValueV(&v, 2, &c);
    assert(fabs(a - 3.4) < EPS);
    assert(fabs(b - 5.7) < EPS);
    assert(fabs(c - 7.3) < EPS);
}

void test_pushBack() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector1();
    test_pushBack_fullVector2();
    test_pushBack_emptyVectorFloat();
    test_pushBack_fullVector1Float();
    test_pushBack_fullVector2Float();
}

void test_popBack_notEmptyVector() {
    vectorVoid v = createVectorV(0, sizeof(int));
    int a = 10;
    pushBackV(&v, &a);
    assert (v.size == 1);
    popBackV(&v);
    assert (v.size == 0);
    assert (v.capacity == 1);
}

void test_popBack_notEmptyVectorFloat() {
    vectorVoid v = createVectorV(0, sizeof(float));
    float a = 10.5f;
    pushBackV(&v, &a);
    assert (v.size == 1);
    popBackV(&v);
    assert (v.size == 0);
    assert (v.capacity == 1);
}

void test_popBack() {
    test_popBack_notEmptyVector();
    test_popBack_notEmptyVectorFloat();
}

void test() {
    test_reserveV();
    test_clearV_oneElementInVector();
    test_shrinkToFit();
    test_deleteVector();
    test_isEmpty();
    test_isFull();
    test_getVectorValue_returnsIndexOfElement();
    test_pushBack();
    test_popBack();
}

int main() {
    test();
    return 0;
}
