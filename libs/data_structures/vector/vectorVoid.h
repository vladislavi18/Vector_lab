#ifndef UNTITLED7_VECTORVOID_H
#define UNTITLED7_VECTORVOID_H

# include <limits.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>

typedef struct vectorVoid {
    void *data; // указатель на нулевой элемент вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
    size_t baseTypeSize; // размер базового типа:
    // например, если вектор хранит int -
    // то поле baseTypeSize = sizeof(int)
    // если вектор хранит float -
    // то поле baseTypeSize = sizeof(float)
} vectorVoid;

// возвращает структуру-дескриптор вектор из n значений
vectorVoid createVectorV(size_t n, size_t baseTypeSize);

// изменяет количество памяти, выделенное
// под хранение элементов вектора
void reserveV(vectorVoid *v, size_t newCapacity);

// освобождает память, выделенную под
// неиспользуемые элементы
void shrinkToFitV(vectorVoid *v);

// удаляет элементы из контейнера, но не освобождает выделенную память.
void clearV(vectorVoid *v);

// освобождает память, выделенную вектору
void deleteVectorV(vectorVoid *v);

// возвращает 1, если вектор пустой, иначе 0
bool isEmptyV(vectorVoid *v);

// возвращает 1, если вектор полный, иначе 0
bool isFullV(vectorVoid *v);

// записывает по адресу destination index-ый элемент вектора v.
// вычисление адреса местоположения элемента и его копирование
void getVectorValueV(vectorVoid *v, size_t index, void *destination);

// записывает на index-ый элемент вектора v
// значение, расположенное по адресу source
void setVectorValueV(vectorVoid *v, size_t index, void *source);

// удаляет последний элемент из вектора v
void popBackV(vectorVoid *v);

// добавляет значение по адресу source в конец вектора v
void pushBackV(vectorVoid *v, void *source);

#endif
