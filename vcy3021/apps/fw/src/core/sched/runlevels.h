/* Copyright (c) 2016 Qualcomm Technologies International, Ltd. */
/*   Part of 6.3.0 */
/**
 * \file
 * Scheduler run levels
 *
 * Allow implementation of limited sched facilities
 * during early stages of boot
 *
 */

#ifndef RUNLEVELS_H
#define RUNLEVELS_H

#ifndef SCHEDULER_WITHOUT_RUNLEVELS
#define RUNLEVEL_BOOT (0)
#define RUNLEVEL_BASIC (1)
#define RUNLEVEL_FINAL (2)
#define N_RUNLEVELS (3)
#endif

#endif /* _RUNLEVELS_H */
