#include "vectorVoid.h"

void badAlloc(const int *data) {
    if (data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
}

// возвращает структуру-дескриптор вектор из n значений.
vectorVoid createVectorV(const size_t n, size_t baseTypeSize) {
    int *data = (int *) malloc(sizeof(int) * n);
    badAlloc(data);
    return (vectorVoid) {data, 0, n, sizeof(baseTypeSize)};
}

void reserveV(vectorVoid *v, size_t newCapacity) {
    if (newCapacity) {
        v->data = (int *) realloc(v->data, sizeof(int) * newCapacity);
        badAlloc(v->data);
        v->capacity = newCapacity;
        if (newCapacity < v->size)
            v->size = newCapacity;
    } else {
        deleteVectorV(v);
    }
}

void shrinkToFitV(vectorVoid *v) {
    reserveV(v, v->size);
}

void clearV(vectorVoid *v) {
    v->size = 0;
}

void deleteVectorV(vectorVoid *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}
