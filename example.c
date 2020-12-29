#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "apply.h"


static void banner(void)
{
    puts("Hello, world!");
}

int fib(int n)
{
    return (n < 2) ? n : fib(n - 1) + fib(n - 2);
}

int sum(int count, ...)
{
    va_list args;
    va_list copy;
    int i, sum = 0;

    va_start(args, count);
    va_copy(copy, args);
    for (i = 0; i < count; i++) {
        sum += va_arg(args, int);
    }
    va_end(copy);

    return sum;
}

int main(int argc, char* argv[])
{
    const int n = (argc > 1) ? atoi(argv[1]) : 0;
    apply(&banner);
    printf("Fib of %d is %d\n", n, APPLY(int, &fib, n));
    printf("Sum is %d\n", (int)apply(&sum, 6, 1, 2, 3, 4, 5, 6));
    return 0;
}
