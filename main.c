#include "hamming_numbers.h"
#include <stdio.h>

int main(int argc, char *argv[argc + 1])
{
    printf("\n Hamming(0-20): ");
    for (size_t i = 0; i < 21; i++) {
        printf("%lu ", hamming(i));
    }
    printf("\nHamming(1691)=%lu", hamming(1691));
    printf("\n");
    return 0;
}
