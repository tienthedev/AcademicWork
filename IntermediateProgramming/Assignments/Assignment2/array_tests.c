#include "array_utils.h"

void print_array(int *arr, int size) {
    printf("[");
    for (int i = 0; i < size - 1; i++) {
        printf("%d, ", *(arr + i));
    }
    printf("%d]\n", *(arr + (size-1)));
}

int main() {
    int arr[MAX_SIZE] = { 1, 2, 3, 4, 5 };
    int size = 5;
    int *p = &arr[0];
    print_array(p, size);
    size = insert(10, 0, p, size);
    print_array(arr, size);
    size = remove_val(0, p, size);
    print_array(p, size); 

    return 0;
}