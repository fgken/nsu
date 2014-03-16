#ifndef __DEBUGLIB_H__
#define __DEBUGLIB_H__

#ifdef __DEBUG__
#define printd(fmt, ...) printf(fmt, ##__VA_ARGS__)

#else
#define printd(fmt, ...)

#endif


#endif /* __DEBUGLIB_H__ */
