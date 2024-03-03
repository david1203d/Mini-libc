#include <time.h>
#include <errno.h>
#include <internal/syscall.h>
#include <internal/arch/x86_64/syscall_list.h>

int nanosleep (const struct timespec *ft, struct timespec *st)
{
int tim = syscall (__NR_nanosleep, ft, st);
if (tim < 0) {
errno = -tim;
return -1;
}
return tim;
}