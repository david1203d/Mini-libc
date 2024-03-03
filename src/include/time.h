/* SPDX-License-Identifier: BSD-3-Clause */

#ifndef TIME_H
#define TIME_H

#ifdef __cplusplus
extern "C" {
#endif

struct timespec {
    long tv_sec;  
    long tv_nsec;   
};

int nanosleep(const struct timespec *ft, struct timespec *st);

#ifdef __cplusplus
}
#endif

#endif
