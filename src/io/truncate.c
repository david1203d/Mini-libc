// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>
#include <fcntl.h>

int truncate(const char *path, off_t length)
{
    if (path == NULL || length < 0) {
        errno = EINVAL;
        return -1;
    }

    int fd = open(path, O_WRONLY);
    if (fd == -1) {
		
        return -1;
    }
   
    if (ftruncate(fd, length) == -1) {
        
        close(fd);
        return -1;
    }

  
    close(fd);
    return 0;
}
