#ifndef __DEBUGLIB_H__
#define __DEBUGLIB_H__

#ifdef __DEBUG__
#define printd(fmt, ...) printf(fmt, ##__VA_ARGS__)
void memdump(FILE *f, const char *buf, int size);

#else
#define printd(fmt, ...)
#define memdump(a, b, c)

#endif


#endif /* __DEBUGLIB_H__ */
