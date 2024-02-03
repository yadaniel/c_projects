#include <stdio.h>

// cbmc --gcc main.c --bounds-check

int arr[10];

void init(void) {
    for(int i=0; i<10; i++) {
        arr[i] = 1;
    }
}

int main(void) {
    init();
    int s = arr[0] + arr[9] + arr[10];
    printf("s = %d\n", s);
    return 0;
}

