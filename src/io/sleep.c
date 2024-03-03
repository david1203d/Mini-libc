#include <time.h>
#include <errno.h>
#include <internal/syscall.h>
#include <internal/arch/x86_64/syscall_list.h>
#include <time.h>

void sleep(unsigned int seconds)
{
struct timespec ft, st;
ft.tv_sec = seconds;
ft.tv_nsec = 0;
int tim = nanosleep(&ft, &st);
if (tim < 0) {
errno = -tim;
return -1;
}
return tim;
}
