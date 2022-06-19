#include "bar.h"
#include "foo.h"

uint32_t bar(uint32_t n, uint32_t v) {
    if(n > 0) {
        return foo(n-1, 2*v);
    } else {
        return v;
    }
}

