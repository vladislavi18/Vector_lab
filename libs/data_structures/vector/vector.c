#include "vector.h"

// возвращает структуру-дескриптор вектор из n значений.
vector createVector(const size_t n) {
    int *a = (int *) malloc(sizeof(int) * n);
    if (a == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    return (vector) {a, 0, n};
}

// изменяет количество памяти, выделенное
// под хранение элементов вектора
void reserve(vector *v, size_t newCapacity) {
    if (newCapacity) {
        v->data = (int *) realloc(v->data, sizeof(int) * newCapacity);
        if (v->data == NULL) {
            fprintf(stderr, "bad alloc");
            exit(1);
        }
        v->capacity = newCapacity;
        if (newCapacity < v->size)
            v->size = newCapacity;
    } else {
        deleteVector(v);
    }
}

// удаляет элементы из контейнера, но не освобождает выделенную память.
void clear(vector *v) {
    v->size = 0;
}

// освобождает память, выделенную под
// неиспользуемые элементы
void shrinkToFit(vector *v) {
    reserve(v, v->size);
}

// освобождает память, выделенную вектору
void deleteVector(vector *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

// возвращает 1, если вектор пустой, иначе 0
bool isEmpty(vector *v) {
    return v->size == 0;
}

// возвращает 1, если вектор полный, иначе 0
bool isFull(vector *v) {
    return v->size == v->capacity;
}

// возвращает i-ый элемент вектора v
int getVectorValue(vector *v, size_t i) {
    return v->data[i];
}

// добавляет элемент x в конец вектора v
void pushBack(vector *v, int x) {
    if (v->capacity == 0)
        reserve(v, 1);
    else if (isFull(v))
        reserve(v, v->capacity * 2);
    v->data[v->size++] = x;
}

// удаляет последний элемент из вектора v
void popBack(vector *v) {
    if (isEmpty(v)) {
        fprintf(stderr, "Vector is Empty");
        exit(1);
    }
    v->size--;
}

// возвращает указатель на index-ый элемент вектора v
int *atVector(vector *v, size_t index) {
    if (index > v->size)
        fprintf(stderr, "IndexError: a[%d] is not exists", index);
    else
        return &v->data[index];
}

// возвращает указатель на последний элемент вектора v
int *back(vector *v) {
    return atVector(v, v->size - 1);
}

// возвращает указатель на последний элемент вектора v
int *front(vector *v) {
    return atVector(v, 0);
}