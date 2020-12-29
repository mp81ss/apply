#ifndef APPLY_H_
#define APPLY_H_
#if ((!defined __STDC_VERSION__) || (__STDC_VERSION__ >= 199901L))
#define APPLY(r, ...) ((r)apply(__VA_ARGS__))
#endif
void* apply(void* func, ...);
#endif /* APPLY_H_ */
