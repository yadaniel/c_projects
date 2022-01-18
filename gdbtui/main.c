#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>

typedef struct {
    uint32_t key;
    uint32_t value;
} pair_t;

uint8_t upper(uint16_t x) {
    return (x>>8) & 0xFF;
}

uint8_t lower(uint16_t x) {
    return x & 0xFF;
}

int main(void) {
    uint16_t u16 = 0;
    scanf("%hu", &u16);
    assert((u16 != 0) && "must be non-zero");
    printf("example: 0x%02X, 0x%02X\n", upper(u16), lower(u16));
    return 0;
}

