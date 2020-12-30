/* gcc -std=c99 -Wall -Wextra -oexample example.c apply.obj */
/* clang -std=c99 -oexample example.c apply.obj */
/* cl /W3 example.c apply.obj */

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

void mult(size_t count, double params[])
{
    size_t i;
    double m = 1.0;
    for (i = 1U; i <= count; i++) {
        m *= params[i];
    }
    *params = m;
}

int main(int argc, char* argv[])
{
    const double doubles[9] = { 0.0, 8.0, 7.0, 6.0, 5.0, 4.0, 3.0, 2.0, 1.0 };
    const int n = (argc > 1) ? atoi(argv[1]) : 0;

    apply(&banner);
    printf("Fib of %d is %d\n", n, APPLY(int, &fib, n));
    printf("Sum is %d\n", (int)apply(&sum, 6, 1, 2, 3, 4, 5, 6));
    APPLY(void, &mult, 8U, doubles);
    printf("Mult is %f\n", *doubles);

    return 0;
}
