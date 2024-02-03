#include <stdio.h>

// cbmc --gcc main.c --pointer-check

int arr[10];

int main(void) {
    int * ptr = &arr[0];
    int s = ptr[0] + ptr[9] + ptr[10];
    printf("s = %d\n", s);
    return 0;
}

