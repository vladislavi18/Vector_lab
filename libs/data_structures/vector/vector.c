#include "vector.h"

vector createVector(const size_t n) {
    int *a = (int *) malloc(sizeof(int) * n);
    if (a == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    return (vector) {a, 0, n};
}

void reserve(vector *v, size_t newCapacity) {
    if (newCapacity) {
        v->data = (int *) realloc(v->data, sizeof(int) * newCapacity);
        if (v->data == NULL) {
            fprintf(stderr, "bad alloc");
            exit(1);
        }
    }
    else
        v->data = NULL;
    if (newCapacity < v->size)
        v->size = newCapacity;
    v->capacity = newCapacity;

}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    reserve(v, v->size);
}

void deleteVector(vector *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

bool isEmpty(vector *v) {
    return v->size == 0;
}

bool isFull(vector *v) {
    return v->size == v->capacity;
}

int getVectorValue(vector *v, size_t i) {
    return v->data[i];
}

void pushBack(vector *v, int x) {
    if (v->capacity == 0)
        reserve(v, 1);
    else if (isFull(v))
        reserve(v, v->capacity * 2);
    v->data[v->size++] = x;
}

void popBack(vector *v) {
    if (v->data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    v->size--;
}