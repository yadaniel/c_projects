#include <stdint.h>
#include <stdio.h>

volatile uint32_t u32;

uint32_t bar(void) {
    return u32;
}

uint32_t foo(uint32_t v) {
    if(v > 0) {
        return bar();
    }
    return v>>2;
}

int main(void) {
    printf("in main\n");
    printf("=> %d\n", foo(100));
    return 0;
}

