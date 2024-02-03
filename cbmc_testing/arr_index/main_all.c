#include <stdio.h>

int arr[10];

// general options
// --trace
// --function <name>
// --unwind <num>

// cbmc --gcc main.c --function arr_access --bounds-check --unwind 10 => SUCCESS
// cbmc --gcc main.c --function arr_access --bounds-check --unwind 11 => FAIL

// --bounds-check
void arr_access(int n) {
    for(int i=0; i<n; i++) {
        arr[i] = i;
    }
}

// --pointer-check
void ptr_access(int n) {
    int * ptr = &arr[0];
    int s = ptr[0] + ptr[9] + ptr[n];
    printf("s = %d\n", s);
}

int main(void) {
    arr_access(11);
    ptr_access(11);
    return 0;
}

