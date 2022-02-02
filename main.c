# include <stdio.h>
# include <stdint.h>
# include "libs/data_structures/vector/vector.h"

void inputArray(int *a, size_t size){
    for(size_t i = 0; i < size; i++) {
        scanf("%d", &a[i]);
    }
}

void outputArray(int *a, size_t size){
    for(size_t i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    vector v = createVector(4);
    inputArray(v.data, v.size);
    outputArray(v.data, v.size);
    clear(&v);
    outputArray(v.data, v.size);
    return 0;
}
