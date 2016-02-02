#ifndef __DISPATCH_SHIMS_PTHREAD_MAIN_NP__
#define __DISPATCH_SHIMS_PTHREAD_MAIN_NP__

#if !HAVE_PTHREAD_MAIN_NP

#if __linux__
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>
#endif

static inline int
pthread_main_np()
{
#if __linux__
	return syscall(SYS_gettid) == getpid() ? 1 : 0;
#else
#error "No suported way to determine if the current thread is the main thread."
#endif
}
#endif /* !HAVE_PTHREAD_MAIN_NP */
#endif /* __DISPATCH_SHIMS_PTHREAD_MAIN_NP__ */
