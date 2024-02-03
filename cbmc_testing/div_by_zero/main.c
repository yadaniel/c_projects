#include <stdio.h>

// cbmc -gcc
// --div-by-zero-check
// --trace
// --function f0
// --function f1

int f0(int x, int y) {
    if((x > 0) && (y > 0)) {
        return (x - y)/(x + y);
    }
    return 0;
}

int f1(int x, int y) {
    if((x > 0) && (y > 0)) {
        return (x + y)/(x - y);
    }
    return 0;
}

// f2(101,-101)
int f2(int x, int y) {
    if ((x >= -100) && (x <= 100)) {
        return 0;
    }
    if ((y >= -100) && (y <= 100)) {
        return 1;
    }
    return (x * y)/(x + y);
}

int f3(int x, int y, int XMIN) {
    if ((x >= XMIN) && (x <= 100)) {
        return 0;
    }
    if ((y >= -100) && (y <= 100)) {
        return 1;
    }
    return (x * y)/(x + y);
}

int main(void) {
    f0(1,1);
    f0(-1,1);

    f1(1,1);
    f1(-1,1);

    f2(1,1);
    f2(-1,1);

    f3(1,1,-100);
    return 0;
}

