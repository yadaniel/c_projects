#include "foo.h"
#include "bar.h"

uint32_t foo(uint32_t n, uint32_t v) {
    if(n > 0) {
        return bar(n-1, v+1);
    } else {
        return v;
    }
}

