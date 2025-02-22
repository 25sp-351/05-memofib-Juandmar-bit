#include <stdio.h>
#include <stdlib.h>
#include "memoize.h"

long long fibonacci(long long value) {
    if (value <= 1) {
        return value;
    }

    long long cached = memoize(value);
    if (cached != -1) { 
        return cached;
    }

    long long result = fibonacci(value - 1) + fibonacci(value - 2);
    add_val(value, result);

    return result;
}

int main() {
    long value;
    printf("Enter a value: ");

    if (scanf("%ld", &value) != 1) {
        printf("Invalid input.\n");
        return 1; 
    }

    if (value < 0) {
        printf("Non-positive values are not allowed.\n");
        return 1;
    }

    if (value > 1000) {  
        printf("Value too large to compute.\n");
        return 1;
    }

    long long result = fibonacci(value);
    printf("Fibonacci(%ld) = %lld\n", value, result);

    free_memo(); 
    return 0;
}

