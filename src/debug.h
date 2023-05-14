#ifndef __DEBUG_H
#define __DEBUG_H
#include <stdio.h>

#define EXIT(m) ({ fprintf(stderr, m); exit(1); })
#define PRINT_BINARY(num) \
    do { \
        printf("%s = ", #num); \
        for (int i = sizeof(num) * 8 - 1; i >= 0; i--) \
            printf("%d", (num >> i) & 1); \
        printf("\n"); \
    } while (0)

#endif
