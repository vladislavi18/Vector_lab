#include "vector.h"

vector createVector(const size_t n) {
    int *a = (int *) malloc(sizeof (int)* n);
    if(a == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    } else
        return (vector) {a, 0, n};
}

void reserve (vector *v, size_t newCapacity){
    if(newCapacity == 0)
        v->data = NULL;
    if(newCapacity < v->size)
        v->size = newCapacity;
    v->capacity = newCapacity;
}

void clear (vector *v){
    v->size = 0;
}

void shrinkToFit(vector *v) {
    v->capacity = v->size;
}

void deleteVector(vector *v){
    free(v->data);
}