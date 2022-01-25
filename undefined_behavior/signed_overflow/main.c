#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>

// -ftrapv => core dump when signed overflow or underflow
void ub_signed(void) {

#if defined(SIGNMAX)
    int i = INT_MAX;
    int j = i + 1;  // signed overflow

#elif defined(SIGNMIN)
    int i = INT_MIN;
    int j = i - 1;  // signed underflow

#else
    int i = 0;
    int j = i;

#endif
 
    printf("[%16s]: 0x%08X, 0x%08X\n", __FUNCTION__, i, j);
}

// -ftrapv => no effect on unsigned
void check_unsigned(void) {
    unsigned int i = UINT_MAX;
    unsigned int j = i + 1;

    printf("[%16s]: 0x%08X, 0x%08X\n", __FUNCTION__, i, j);
}

int main(void) {
    ub_signed();
    check_unsigned();   // with -ftrapv
    return 0;
}

