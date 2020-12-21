#include <stdio.h>
#include "sha256.h"

void print_sha256(uint8_t * send_buffer, uint32_t  send_buffer_len, uint8_t * recv_buffer) {
    sha256_context_t ctx;
    sha256_init(&ctx);
    sha256_hash(&ctx, send_buffer, send_buffer_len);
    sha256_done(&ctx, recv_buffer);
}

/* import hashlib as hash */
/* import struct */
/* h = hash.sha256() */
/* h.update(bytes("01234", "ascii")) */
/* m = h.digest() # => b'\x1b\xe2\xe4R\xb4mz\r\x96V\xbb\xb1\xf7h\xe8$\x8e\xba\x1bu\xba\xede\xf5\xd9\x9e\xaf\xa9H\x89\x9aj' */
/* s = struct.unpack("I"*8, m) */
/* list(map(hex, s)) # => ['0x52e4e21b', '0xd7a6db4',  '0xb1bb5696',  '0x24e868f7',  '0x751bba8e',  '0xf565edba',  '0xa9af9ed9',  '0x6a9a8948'] */

int main(void) {
    uint8_t data[5] = "01234";
    uint32_t hash[8] = {0,0,0,0,0,0,0,0};

    print_sha256(&data[0], 5, (uint8_t *)&hash);

    printf("hash => ");
    for(uint8_t i = 0; i < 8; i++) {
        printf("%08X ", hash[i]);
    }
    printf("\n");

    return 0;
}

