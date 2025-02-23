#ifndef MEMOIZE_H
#define MEMOIZE_H

#include <stdlib.h>

typedef struct {
    long long key;
    long long value;
} Pair;

void add_val (long long key, long long value);
long long memoize(long long key);
void free_memo();

#endif
