#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define MD5_BLOCK_SIZE 64
#define F(x, y, z) (((x) & (y)) | ((~x) & (z)))
#define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | (~z)))
#define LEFT_ROTATE(x, n) (((x) << (n)) | ((x) >> (32 - (n))))

typedef struct {
    uint32_t A, B, C, D;
} MD5_STATE;

void md5_transform(uint32_t state[4], const uint8_t block[64]) {
    uint32_t a = state[0];
    uint32_t b = state[1];
    uint32_t c = state[2];
    uint32_t d = state[3];
    uint32_t x[16];

    int i;
    for (i = 0; i < 16; i++)
        x[i] = *((uint32_t*)(block + i * 4));

    for (i = 0; i < 16; i++) {
        uint32_t temp = F(b, c, d) + x[i] + 0x5A827999 + a;
        a = d; d = c; c = b; b = b + LEFT_ROTATE(temp, 5);
    }

    // Rest of the function remains unchanged
    // ...
}

void md5_hash(const uint8_t *data, size_t length, uint8_t hash[16]) {
    MD5_STATE state;
    state.A = 0x67452301;
    state.B = 0xEFCDAB89;
    state.C = 0x98BADCFE;
    state.D = 0x10325476;
    size_t block_count = length / MD5_BLOCK_SIZE;
    size_t i;
    for (i = 0; i < block_count; i++) {
        md5_transform((uint32_t*)&state, data + i * MD5_BLOCK_SIZE);
    }
    memcpy(hash, &state, 16);
}

int main() {
    const char *input = "123ashraf123";
    uint8_t hash[16];
    int i;
    md5_hash((uint8_t*)input, strlen(input), hash);

    printf("Input: %s\n", input);
    printf("MD5 Hash: ");
    for (i = 0; i < 16; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    return 0;
}
