#include <stdio.h>
#include <string.h>
#include <internal/io.h>
#include <internal/syscall.h>
#include <internal/types.h>
#include <errno.h>

int puts(const char *str)
{
int pun = write(1, str, strlen(str));
if (pun == -1)
return errno;
pun = write(1, "\n", 1);
if (pun = -1)
return errno;
return 0;
}
