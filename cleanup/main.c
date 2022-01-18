#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>     // malloc
#include <unistd.h>     // sleep

// void f(T * pvar) { /* cleanup var */ }
// T var __attribute__((cleanup(f))) = var_init;
// function provided to cleanup() must have prototype as given above

// === static storage

void data_clear(int * p) {
    printf("clear data\n");
    *p = 0;
}

void foo(void) {
    int data __attribute__((cleanup(data_clear))) = 1;
    printf("data = %d\n", data);
}


// === dynamic storage

// gcc complains with
// note: expected ‘uint32_t *’ {aka ‘unsigned int *’} but argument is of type ‘uint32_t **’ {aka ‘unsigned int **’}
// void free_xs(uint32_t * p) {}

/* void free_xs(uint32_t ** p) { */
void free_xs(uint8_t ** p) {
    if(p == NULL) {
        // gcc fault ... providing NULL instead of &var
        printf("free:p==NULL\n");
    } else if(*p == NULL) {
        // malloc fault ... providing NULL because out of memory
        printf("free:*p==NULL\n");
    } else {
        printf("free:%p\n", *p);
        free(*p);
        *p = NULL;
    }
}

uint32_t bar(size_t n) {
    uint32_t sum = 0;
    //uint32_t * xs  __attribute__((cleanup(free_xs))) = malloc(n)*sizeof(uint32_t);
    uint8_t * xs  __attribute__((cleanup(free_xs))) = malloc(n);
    if(xs == NULL) {
        printf("malloc failed = %p\n", xs);
    } else {
        printf("malloc succeeded = %p\n", xs);
        for(uint32_t i=0; i<n; i++) {
            sum += xs[i];
            xs[i] = 0;
        }
    }
    return sum;
}

#define B(x)    ((x)*1)
#define KB(x)   ((x)*1024)
#define MB(x)   ((x)*KB(1024))
#define GB(x)   ((x)*MB(1024))

int main(void) {
    uint32_t u32 = 0;

    foo();

    u32 = bar(KB(100));
    printf("u32=%d\n", u32);

    u32 = bar(B(100));
    printf("u32=%d\n", u32);

    return 0;
}

