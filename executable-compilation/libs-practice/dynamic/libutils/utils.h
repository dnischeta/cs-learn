#ifndef LIB_H
#define LIB_H

#ifdef __APPLE__
    #define EXPORT __attribute__((visibility("default")))
#else
    #define EXPORT
#endif

EXPORT void hello(void);
EXPORT int add(int a, int b);

#endif