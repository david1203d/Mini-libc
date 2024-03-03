// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	long map = syscall(__NR_mmap, addr, length, prot, flags, fd, offset); 
	if(map < 0) {
		errno = -map;
		return -1;
	}
	return (void *)map;
}


void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
	long map = syscall(__NR_mremap, old_address, old_size, new_size, flags);
	if(map < 0) {
		errno = -map;
		return -1;
	}
	return (void *)map;
}

int munmap(void *addr, size_t length)
{
	long map = syscall(__NR_munmap, addr, length);
	if(map < 0) {
		errno = -map;
		return -1;
	}
	return (void *)map;
}
