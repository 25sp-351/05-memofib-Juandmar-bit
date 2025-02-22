#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "memoize.h"

#define MAX_MEMOIZE 150000
Pair *MEMO[MAX_MEMOIZE] = {NULL};

void add_val (long long key, long long value) {
    for (long long xx = 0; xx < MAX_MEMOIZE; xx++) {
        if (MEMO[xx] == NULL) {
            MEMO[xx] = (Pair *) malloc(sizeof(Pair));
            MEMO[xx]->key = key;
            MEMO[xx]->value = value;
            return;
        }
    }
}

long long memoize(long long key) {
    for (long long xx = 0; xx < MAX_MEMOIZE; xx++) {
        if (MEMO[xx] != NULL && MEMO[xx]->key == key) {
            return MEMO[xx]->value;
        }
    }
    return -1;
}

void free_memo() {
    for (long long xx = 0; xx < MAX_MEMOIZE; xx++) {
        if (MEMO[xx] != NULL) {
            free(MEMO[xx]);
            MEMO[xx] = NULL;
        }
    }
}