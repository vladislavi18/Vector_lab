#ifndef UNTITLED7_VECTOR_H
#define UNTITLED7_VECTOR_H

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct vector {
    int *data;
    size_t size;
    size_t capacity;
} vector;

vector createVector(size_t n);

void reserve (vector *v, size_t newCapacity);

void clear (vector *v);

void shrinkToFit(vector *v);

void deleteVector(vector *v);

#endif
