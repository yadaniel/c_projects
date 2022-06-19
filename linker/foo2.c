#include <stdint.h>
#include <stdbool.h>

// for wrapper
#include "foo.h"

/*

gcc -c foo2.c
ar -r libfoo.a foo2.o
nm libfoo.a

// delete, show and add again foo2.o from/to libfoo.a
ar -d libfoo.a foo2.o
ar -t libfoo.a
ar -r libfoo.a foo2.o

*/

int8_t bits_one(uint32_t v) {
    uint8_t cnt = 0;

    while(v) {
        if(v & 1) {
            cnt += 1;
        }
        v >>= 1;
    }

    return cnt;
}

uint32_t foo_wrapper(uint32_t n, uint32_t v) {
    // do something
    return foo(n, v);
}

