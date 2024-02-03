#include <stdio.h>
#include <assert.h>

// signed char = default
// cbmc --gcc main.c --32 --function f --conversion-check --trace
// cbmc --gcc main.c --32 --unsigned-char --function f --conversion-check --trace

int f(void) {
    char c = 100;
    short s = c;
    int i = s;
    long l = i;

    char c2 = 3*i;
    assert(c2 > i);     // cbmc and runtime

    if (l == 100) {
        return 1;
    } else {
        return 0;
    }

    assert(c == l);
}

int main(void) {

    printf("main\n");

    int i = f();
    assert(i == 1);

    printf("asserted\n");

    return 0;
}

