#include "hamming_numbers.h"
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define MIN(x, y) ((x) < (y)) ? (x) : (y)
#define MIN3(x, y, z) MIN(MIN(x, y), z)

uint64_t hamming(uint64_t n)
{
    /*returns a single hamming number at a time in increasing order*/
    static size_t size = 1;
    static uint64_t x2 = 0, x3 = 0, x5 = 0;
    static uint64_t H[MAX_MEMO] = {1};
    if (n < size) {
        return H[n];
    } else {
        while (n >= size) { // generate sufficient numbers to reply
            uint64_t a = 2 * H[x2];
            uint64_t b = 3 * H[x3];
            uint64_t c = 5 * H[x5];
            uint64_t candidate = MIN3(a, b, c);
            if (candidate == a)
                x2++;
            if (candidate == b)
                x3++;
            if (candidate == c)
                x5++;
            if (size < MAX_MEMO)
                H[size++] = candidate; // still need to check if the value was
            else {
                puts("Insufficient memory for memoization!");
                exit(EXIT_FAILURE);
            }
        }
        return H[n];
    }
}
