#ifndef __DEBUG_H
#define __DEBUG_H
#include <stdio.h>

#define EXIT(m) ({ fprintf(stderr, m); exit(1); })

#endif
