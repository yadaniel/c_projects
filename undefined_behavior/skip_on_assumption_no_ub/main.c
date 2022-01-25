#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

// ASan = address sanitizer
// UBSan = undefined behavior sanitizer
// MSan = memory sanitizer
// TSan = thread sanitizer
// TySan = type sanitizer


// gcc -o main main.c -Wall && /main && echo $?                     # 0
// gcc -o main main.c -Wall -DWITH_PRINTF &&./main && echo $?       # 1

int main(int argc, char ** argv) {

    char * p = argv[1];

    // printf can assume that p != NULL
#if WITH_PRINTF
    printf("WITH_PRINTF: %s\n", p);
#endif

    // because of usage of p in printf
    // compiler will deduce that p != NULL
    // and discard the check
    if(p == NULL) {
        return 1;
    }

    return 0;
}

