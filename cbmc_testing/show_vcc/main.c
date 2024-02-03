#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>

// cbmc -gcc main.c --function f --trace

// -show-vcc = show verification conditions
// cbmc -gcc main.c --function f --trace --show-vcc

void f(bool cond) {

    int x = 10;             // input
    int y0 = 0, y1 = 0;     // output

    if (cond) {
        y0 = x + 1;
    } else {
        y1 = x - 1;
    }

    // must pass
    assert((y0 == 0) || (y0 == 11));
    assert((y1 == 0) || (y1 == 9));

    // must fail
    /* assert((y0 == 1) || (y0 == 11)); */
    /* assert((y0 == 0) || (y0 == 12)); */
    /* assert((y1 == 1) || (y1 == 9)); */
    /* assert((y1 == 0) || (y1 == 10)); */

    /* assert(0); */
    /* assert(false); */

    printf("y0=%d, y1=%d\n", y0, y1);

}

int main(void) {
    printf("before f\n");
    f(false);
    f(true);
    printf("after f\n");
    return 0;
}

