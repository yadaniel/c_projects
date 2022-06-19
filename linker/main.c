#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#include "foo.h"
#include "bar.h"

// show default linker script
// gcc -Wl,--verbose

/*
gcc -o main -DINFO='"nolib1"' main.c foo1.c bar1.c
./main

gcc -c -DINFO='"nolib2"' foo1.c bar1.c main.c
gcc -o main main.o foo1.o bar1.o
./main

gcc -c -DINFO='"lib"' main.c
gcc -c foo1.c bar1.c
ar -r libfoo.a foo1.o
ar -r libbar.a bar1.o
gcc -o main main.o -lfoo -lbar -L.
./main

// OK
// takes unresolved foo from main.o and resolves it in libfoo.a
// takes unresolved bar from libfoo.a  and resolves it in libbar.a
gcc -o main main.o -lfoo -lbar -L.
gcc -o main -L. -Wl,--start-group -lbar -lfoo main.o -Wl,--end-group
gcc -o main -L. -Wl,'-(' -lbar -lfoo main.o -Wl,'-)'

// NOT OK
gcc -o main -lfoo -lbar -L. main.o
gcc -o main -lbar -lfoo main.o -L.
gcc -o main main.o -lbar -lfoo -L.

*/

#define STRINGIFY(T)            #T
#define CONCATINATE(T1,T2)      T1 ## T2

#ifndef INFO
#define INFO_TXT    "default"
#else
#define INFO_TXT    INFO
#endif

uint32_t foo_wrapper(uint32_t n, uint32_t v);

int main(void) {
    printf("v = %u " INFO_TXT "\n", foo(10, 0));
    printf("v = %u " INFO_TXT "\n", foo_wrapper(10, 0));
    return 0;
}

