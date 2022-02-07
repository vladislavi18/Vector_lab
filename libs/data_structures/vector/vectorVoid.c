#include "vectorVoid.h"

void badAlloc(const int *data) {
    if (data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
}

// возвращает структуру-дескриптор вектор из n значений.
vectorVoid createVectorV(const size_t n, size_t baseTypeSize) {
    int *data = (int *) malloc(sizeof(baseTypeSize) * n);
    badAlloc(data);
    return (vectorVoid) {data, 0, n, sizeof(baseTypeSize)};
}

// изменяет количество памяти, выделенное
// под хранение элементов вектора
void reserveV(vectorVoid *v, size_t newCapacity) {
    if (newCapacity) {
        v->data = (int *) realloc(v->data, sizeof(v->baseTypeSize) * newCapacity);
        badAlloc(v->data);
        v->capacity = newCapacity;
        if (newCapacity < v->size)
            v->size = newCapacity;
    } else {
        deleteVectorV(v);
    }
}

// освобождает память, выделенную под
// неиспользуемые элементы
void shrinkToFitV(vectorVoid *v) {
    reserveV(v, v->size);
}

// удаляет элементы из контейнера, но не освобождает выделенную память.
void clearV(vectorVoid *v) {
    v->size = 0;
}

// освобождает память, выделенную вектору
void deleteVectorV(vectorVoid *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

// возвращает 1, если вектор пустой, иначе 0
bool isEmptyV(vectorVoid *v) {
    return v->size == 0;
}

// возвращает 1, если вектор полный, иначе 0
bool isFullV(vectorVoid *v) {
    return v->size == v->capacity;
}

// записывает по адресу destination index-ый элемент вектора v.
// вычисление адреса местоположения элемента и его копирование
void getVectorValueV(vectorVoid *v, size_t index, void *destination) {
    if (index >= v->size)
        fprintf(stderr, "IndexError: a[%d] is not exists", index);
    char *source = (char *) v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);

}

// записывает на index-ый элемент вектора v
// значение, расположенное по адресу source
void setVectorValueV(vectorVoid *v, size_t index, void *source) {
    if (index > v->size)
        fprintf(stderr, "IndexError: a[%d] is not exists", index);
    char *destination = (char *) v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
}

// удаляет последний элемент из вектора v
void popBackV(vectorVoid *v) {
    if (isEmptyV(v)) {
        fprintf(stderr, "Vector is Empty");
        exit(1);
    }
    v->size--;
}

// добавляет значение по адресу source в конец вектора v
void pushBackV(vectorVoid *v, void *source) {
    if (v->capacity == 0)
        reserveV(v, 1);
    else if (isFullV(v))
        reserveV(v, v->capacity * 2);
    setVectorValueV(v, v->size++, source);
}