#include <stdio.h>

// cbmc -gcc main.c -16 --function f0 --signed-overflow-check --unwind 700 => pass
// cbmc -gcc main.c -16 --function f0 --signed-overflow-check --unwind 769 => fail
// cbmc -gcc main.c -32 --function f0 --signed-overflow-check --unwind 769 => pass

// overflow
int f0(int n) {
    // 32768
    int s = 32000;
    for(int i=0; i<n; i++) {
        s += 1;
    }
    return s;
}

// underflow
int f1(int n) {
    // -32769
    int s = -32000;
    for(int i=0; i<n; i++) {
        s -= 1;
    }
    return s;
}

int main(void) {
    return 0;
}

