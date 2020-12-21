/*
*   SHA-256 implementation.
*
*   Copyright (c) 2010 Ilya O. Levin, http://www.literatecode.com
*
*   Permission to use, copy, modify, and distribute this software for any
*   purpose with or without fee is hereby granted, provided that the above
*   copyright notice and this permission notice appear in all copies.
*
*   THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
*   WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
*   MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
*   ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
*   WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
*   ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
*   OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/

/*
 * note: the original code was modified => look up original
 * simplified and formatted
 * 
 * */

#ifndef SHA256_INCLUDED
#define SHA256_INCLUDED

#include <stdint.h>

typedef struct {
    uint32_t buf[16];   // buffer with indata
    uint32_t hash[8];   // working hash
    uint32_t len[2];    // buffer length
} sha256_context_t;

void sha256_init(sha256_context_t *);
void sha256_hash(sha256_context_t * self, uint8_t * indata, uint32_t len);
void sha256_done(sha256_context_t * self, uint8_t * hash);

#endif

