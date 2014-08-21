/**
 * Enhanced Seccomp MIPS Specific Code
 *
 * Copyright (c) 2014 Imagination Technologies Ltd.
 * Author: Markos Chandras <markos.chandras@imgtec.com>
 *
 */

/*
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of version 2.1 of the GNU Lesser General Public License as
 * published by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License
 * for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, see <http://www.gnu.org/licenses>.
 */

#include <string.h>

#include <seccomp.h>

#include "arch.h"
#include "arch-mips.h"

/* O32 ABI */
#define __NR_SYSCALL_BASE	4000

/* NOTE: based on Linux 3.17-rc1+ */
const struct arch_syscall_def mips_syscall_table[] = { \
	{ "_llseek", (__NR_SYSCALL_BASE + 140) },
	{ "_newselect", (__NR_SYSCALL_BASE + 142) },
	{ "_sysctl", (__NR_SYSCALL_BASE + 153) },
	{ "accept", (__NR_SYSCALL_BASE + 168) },
	{ "accept4", (__NR_SYSCALL_BASE + 334) },
	{ "access", (__NR_SYSCALL_BASE + 33) },
	{ "acct", (__NR_SYSCALL_BASE + 51) },
	{ "add_key", (__NR_SYSCALL_BASE + 280) },
	{ "adjtimex", (__NR_SYSCALL_BASE + 124) },
	{ "afs_syscall", __NR_SYSCALL_BASE + 137 },
	{ "alarm", (__NR_SYSCALL_BASE + 27) },
	{ "arm_fadvise64_64", __PNR_arm_fadvise64_64 },
	{ "arm_sync_file_range", __PNR_arm_sync_file_range },
	{ "arch_prctl", __PNR_arch_prctl },
	{ "bdflush", (__NR_SYSCALL_BASE + 134) },
	{ "bind", (__NR_SYSCALL_BASE + 169) },
	{ "break", __NR_SYSCALL_BASE + 17 },
	{ "brk", (__NR_SYSCALL_BASE + 45) },
	{ "cachectl", (__NR_SYSCALL_BASE + 148) },
	{ "cacheflush", (__NR_SYSCALL_BASE + 147) },
	{ "capget", (__NR_SYSCALL_BASE + 204) },
	{ "capset", (__NR_SYSCALL_BASE + 205) },
	{ "chdir", (__NR_SYSCALL_BASE + 12) },
	{ "chmod", (__NR_SYSCALL_BASE + 15) },
	{ "chown", (__NR_SYSCALL_BASE + 202) },
	{ "chown32", (__PNR_chown32) },
	{ "chroot", (__NR_SYSCALL_BASE + 61) },
	{ "clock_adjtime", (__NR_SYSCALL_BASE + 341) },
	{ "clock_getres", (__NR_SYSCALL_BASE + 264) },
	{ "clock_gettime", (__NR_SYSCALL_BASE + 263) },
	{ "clock_nanosleep", (__NR_SYSCALL_BASE + 265) },
	{ "clock_settime", (__NR_SYSCALL_BASE + 262) },
	{ "clone", (__NR_SYSCALL_BASE + 120) },
	{ "close", (__NR_SYSCALL_BASE + 6) },
	{ "connect", (__NR_SYSCALL_BASE + 170) },
	{ "creat", (__NR_SYSCALL_BASE + 8) },
	{ "create_module", __NR_SYSCALL_BASE + 127 },
	{ "delete_module", (__NR_SYSCALL_BASE + 129) },
	{ "dup", (__NR_SYSCALL_BASE + 41) },
	{ "dup2", (__NR_SYSCALL_BASE + 63) },
	{ "dup3", (__NR_SYSCALL_BASE + 327) },
	{ "epoll_create", (__NR_SYSCALL_BASE + 248) },
	{ "epoll_create1", (__NR_SYSCALL_BASE + 326) },
	{ "epoll_ctl", (__NR_SYSCALL_BASE + 249) },
	{ "epoll_ctl_old", __PNR_epoll_ctl_old },
	{ "epoll_pwait", (__NR_SYSCALL_BASE + 313) },
	{ "epoll_wait", (__NR_SYSCALL_BASE + 250) },
	{ "epoll_wait_old", __PNR_epoll_wait_old },
	{ "eventfd", (__NR_SYSCALL_BASE + 319) },
	{ "eventfd2", (__NR_SYSCALL_BASE + 325) },
	{ "execve", (__NR_SYSCALL_BASE + 11) },
	{ "exit", (__NR_SYSCALL_BASE + 1) },
	{ "exit_group", (__NR_SYSCALL_BASE + 246) },
	{ "faccessat", (__NR_SYSCALL_BASE + 300) },
	{ "fadvise64", __NR_SYSCALL_BASE + 254 },
	{ "fadvise64_64", __PNR_fadvise64_64 },
	{ "fallocate", (__NR_SYSCALL_BASE + 320) },
	{ "fanotify_init", (__NR_SYSCALL_BASE + 336) },
	{ "fanotify_mark", (__NR_SYSCALL_BASE + 337) },
	{ "fchdir", (__NR_SYSCALL_BASE + 133) },
	{ "fchmod", (__NR_SYSCALL_BASE + 94) },
	{ "fchmodat", (__NR_SYSCALL_BASE + 299) },
	{ "fchown", (__NR_SYSCALL_BASE + 95) },
	{ "fchown32", (__PNR_fchown32) },
	{ "fchownat", (__NR_SYSCALL_BASE + 291) },
	{ "fcntl", (__NR_SYSCALL_BASE + 55) },
	{ "fcntl64", (__NR_SYSCALL_BASE + 220) },
	{ "fdatasync", (__NR_SYSCALL_BASE + 152) },
	{ "fgetxattr", (__NR_SYSCALL_BASE + 229) },
	{ "finit_module", (__NR_SYSCALL_BASE + 348) },
	{ "flistxattr", (__NR_SYSCALL_BASE + 232) },
	{ "flock", (__NR_SYSCALL_BASE + 143) },
	{ "fork", (__NR_SYSCALL_BASE + 2) },
	{ "fremovexattr", (__NR_SYSCALL_BASE + 235) },
	{ "fsetxattr", (__NR_SYSCALL_BASE + 226) },
	{ "fstat", (__NR_SYSCALL_BASE + 108) },
	{ "fstat64", (__NR_SYSCALL_BASE + 215) },
	{ "fstatat64", (__NR_SYSCALL_BASE + 293) },
	{ "fstatfs", (__NR_SYSCALL_BASE + 100) },
	{ "fstatfs64", (__NR_SYSCALL_BASE + 256) },
	{ "fsync", (__NR_SYSCALL_BASE + 118) },
	{ "ftime", (__NR_SYSCALL_BASE + 35) },
	{ "ftruncate", (__NR_SYSCALL_BASE + 93) },
	{ "ftruncate64", (__NR_SYSCALL_BASE + 212) },
	{ "futex", (__NR_SYSCALL_BASE + 238) },
	{ "futimesat", (__NR_SYSCALL_BASE + 292) },
	{ "get_kernel_syms", (__NR_SYSCALL_BASE + 130) },
	{ "get_mempolicy", (__NR_SYSCALL_BASE + 269) },
	{ "get_robust_list", (__NR_SYSCALL_BASE + 310) },
	{ "get_thread_area", __PNR_get_thread_area },
	{ "getcpu", (__NR_SYSCALL_BASE + 312) },
	{ "getcwd", (__NR_SYSCALL_BASE + 203) },
	{ "getdents", (__NR_SYSCALL_BASE + 141) },
	{ "getdents64", (__NR_SYSCALL_BASE + 219) },
	{ "getegid", (__NR_SYSCALL_BASE + 50) },
	{ "getegid32", __PNR_getegid32 },
	{ "geteuid", (__NR_SYSCALL_BASE + 49) },
	{ "geteuid32", __PNR_geteuid32 },
	{ "getgid", (__NR_SYSCALL_BASE + 47) },
	{ "getgid32", __PNR_getgid32 },
	{ "getgroups", (__NR_SYSCALL_BASE + 80) },
	{ "getgroups32", __PNR_getgroups32 },
	{ "getitimer", (__NR_SYSCALL_BASE + 105) },
	{ "getpeername", (__NR_SYSCALL_BASE + 171) },
	{ "getpgid", (__NR_SYSCALL_BASE + 132) },
	{ "getpgrp", (__NR_SYSCALL_BASE + 65) },
	{ "getpid", (__NR_SYSCALL_BASE + 20) },
	{ "getpmsg", (__NR_SYSCALL_BASE + 208) },
	{ "getppid", (__NR_SYSCALL_BASE + 64) },
	{ "getpriority", (__NR_SYSCALL_BASE + 96) },
	{ "getrandom", __PNR_getrandom },
	{ "getresgid", (__NR_SYSCALL_BASE + 191) },
	{ "getresgid32", __PNR_getresgid32 },
	{ "getresuid", (__NR_SYSCALL_BASE + 186) },
	{ "getresuid32", __PNR_getresuid32 },
	{ "getrlimit", (__NR_SYSCALL_BASE + 76) },
	{ "getrusage", (__NR_SYSCALL_BASE + 77) },
	{ "getsid", (__NR_SYSCALL_BASE + 151) },
	{ "getsockname", (__NR_SYSCALL_BASE + 172) },
	{ "getsockopt", (__NR_SYSCALL_BASE + 173) },
	{ "gettid", (__NR_SYSCALL_BASE + 222) },
	{ "gettimeofday", (__NR_SYSCALL_BASE + 78) },
	{ "getuid", (__NR_SYSCALL_BASE + 24) },
	{ "getuid32", __PNR_getuid32 },
	{ "getxattr", (__NR_SYSCALL_BASE + 227) },
	{ "gtty", (__NR_SYSCALL_BASE + 32) },
	{ "idle", (__NR_SYSCALL_BASE + 112) },
	{ "init_module", (__NR_SYSCALL_BASE + 128) },
	{ "inotify_add_watch", (__NR_SYSCALL_BASE + 285) },
	{ "inotify_init", (__NR_SYSCALL_BASE + 284) },
	{ "inotify_init1", (__NR_SYSCALL_BASE + 329) },
	{ "inotify_rm_watch", (__NR_SYSCALL_BASE + 286) },
	{ "io_cancel", (__NR_SYSCALL_BASE + 245) },
	{ "io_destroy", (__NR_SYSCALL_BASE + 242) },
	{ "io_getevents", (__NR_SYSCALL_BASE + 243) },
	{ "io_setup", (__NR_SYSCALL_BASE + 241) },
	{ "io_submit", (__NR_SYSCALL_BASE + 244) },
	{ "ioctl", (__NR_SYSCALL_BASE + 54) },
	{ "ioperm", (__NR_SYSCALL_BASE + 101) },
	{ "iopl", (__NR_SYSCALL_BASE + 110) },
	{ "ioprio_get", (__NR_SYSCALL_BASE + 315) },
	{ "ioprio_set", (__NR_SYSCALL_BASE + 314) },
	{ "ipc", (__NR_SYSCALL_BASE + 117) },
	{ "kcmp", (__NR_SYSCALL_BASE + 347)  },
	{ "kexec_file_load", __PNR_kexec_file_load },
	{ "kexec_load", (__NR_SYSCALL_BASE + 311) },
	{ "keyctl", (__NR_SYSCALL_BASE + 282) },
	{ "kill", (__NR_SYSCALL_BASE + 37) },
	{ "lchown", (__NR_SYSCALL_BASE + 16) },
	{ "lchown32", __PNR_lchown32 },
	{ "lgetxattr", (__NR_SYSCALL_BASE + 228) },
	{ "link", (__NR_SYSCALL_BASE + 9) },
	{ "linkat", (__NR_SYSCALL_BASE + 296) },
	{ "listen", (__NR_SYSCALL_BASE + 174) },
	{ "listxattr", (__NR_SYSCALL_BASE + 230) },
	{ "llistxattr", (__NR_SYSCALL_BASE + 231) },
	{ "lock", (__NR_SYSCALL_BASE + 53) },
	{ "lookup_dcookie", (__NR_SYSCALL_BASE + 247) },
	{ "lremovexattr", (__NR_SYSCALL_BASE + 234) },
	{ "lseek", (__NR_SYSCALL_BASE + 19) },
	{ "lsetxattr", (__NR_SYSCALL_BASE + 225) },
	{ "lstat", (__NR_SYSCALL_BASE + 107) },
	{ "lstat64", (__NR_SYSCALL_BASE + 214) },
	{ "madvise", (__NR_SYSCALL_BASE + 218) },
	{ "mbind", (__NR_SYSCALL_BASE + 268) },
	{ "memfd_create", __PNR_memfd_create },
	{ "migrate_pages", (__NR_SYSCALL_BASE + 287) },
	{ "mincore", (__NR_SYSCALL_BASE + 217) },
	{ "mkdir", (__NR_SYSCALL_BASE + 39) },
	{ "mkdirat", (__NR_SYSCALL_BASE + 289) },
	{ "mknod", (__NR_SYSCALL_BASE + 14) },
	{ "mknodat", (__NR_SYSCALL_BASE + 290) },
	{ "mlock", (__NR_SYSCALL_BASE + 154) },
	{ "mlockall", (__NR_SYSCALL_BASE + 156) },
	{ "mmap", (__NR_SYSCALL_BASE + 90) },
	{ "mmap2", (__NR_SYSCALL_BASE + 210) },
	{ "modify_ldt", (__NR_SYSCALL_BASE + 123) },
	{ "mount", (__NR_SYSCALL_BASE + 21) },
	{ "move_pages", (__NR_SYSCALL_BASE + 308) },
	{ "mprotect", (__NR_SYSCALL_BASE + 125) },
	{ "mpx", (__NR_SYSCALL_BASE + 56) },
	{ "mq_getsetattr", (__NR_SYSCALL_BASE + 276) },
	{ "mq_notify", (__NR_SYSCALL_BASE + 275) },
	{ "mq_open", (__NR_SYSCALL_BASE + 271) },
	{ "mq_timedreceive", (__NR_SYSCALL_BASE + 274) },
	{ "mq_timedsend", (__NR_SYSCALL_BASE + 273) },
	{ "mq_unlink", (__NR_SYSCALL_BASE + 272) },
	{ "mremap", (__NR_SYSCALL_BASE + 167) },
	{ "msgctl", __PNR_msgctl },
	{ "msgget", __PNR_msgget },
	{ "msgrcv", __PNR_msgrcv },
	{ "msgsnd", __PNR_msgsnd },
	{ "msync", (__NR_SYSCALL_BASE + 144) },
	{ "munlock", (__NR_SYSCALL_BASE + 155) },
	{ "munlockall", (__NR_SYSCALL_BASE + 157) },
	{ "munmap", (__NR_SYSCALL_BASE + 91) },
	{ "name_to_handle_at", (__NR_SYSCALL_BASE + 339) },
	{ "nanosleep", (__NR_SYSCALL_BASE + 166) },
	{ "newfstatat", __PNR_newfstatat },
	{ "nfsservctl", (__NR_SYSCALL_BASE + 189) },
	{ "nice", (__NR_SYSCALL_BASE + 34) },
	{ "oldfstat", __PNR_oldfstat },
	{ "oldlstat", __PNR_oldlstat },
	{ "oldolduname", __PNR_oldolduname },
	{ "oldstat", __PNR_oldstat },
	{ "olduname", __PNR_olduname },
	{ "oldwait4", __PNR_oldwait4 },
	{ "open", (__NR_SYSCALL_BASE + 5) },
	{ "open_by_handle_at", (__NR_SYSCALL_BASE + 340) },
	{ "openat", (__NR_SYSCALL_BASE + 288) },
	{ "pause", (__NR_SYSCALL_BASE + 29) },
	{ "pciconfig_iobase", __PNR_pciconfig_iobase },
	{ "pciconfig_read", __PNR_pciconfig_read },
	{ "pciconfig_write", __PNR_pciconfig_write },
	{ "perf_event_open", (__NR_SYSCALL_BASE + 333) },
	{ "personality", (__NR_SYSCALL_BASE + 136) },
	{ "pipe", (__NR_SYSCALL_BASE + 42) },
	{ "pipe2", (__NR_SYSCALL_BASE + 328) },
	{ "pivot_root", (__NR_SYSCALL_BASE + 216) },
	{ "poll", (__NR_SYSCALL_BASE + 188) },
	{ "ppoll", (__NR_SYSCALL_BASE + 302) },
	{ "prctl", (__NR_SYSCALL_BASE + 192) },
	{ "pread64", (__NR_SYSCALL_BASE + 200) },
	{ "preadv", (__NR_SYSCALL_BASE + 330) },
	{ "prlimit64", (__NR_SYSCALL_BASE + 338) },
	{ "process_vm_readv", (__NR_SYSCALL_BASE + 345) },
	{ "process_vm_writev", (__NR_SYSCALL_BASE + 346) },
	{ "prof", (__NR_SYSCALL_BASE + 44) },
	{ "profil", (__NR_SYSCALL_BASE + 98) },
	{ "pselect6", (__NR_SYSCALL_BASE + 301) },
	{ "ptrace", (__NR_SYSCALL_BASE + 26) },
	{ "putpmsg", (__NR_SYSCALL_BASE + 209) },
	{ "pwrite64", (__NR_SYSCALL_BASE + 201) },
	{ "pwritev", (__NR_SYSCALL_BASE + 331) },
	{ "query_module", (__NR_SYSCALL_BASE + 187) },
	{ "quotactl", (__NR_SYSCALL_BASE + 131) },
	{ "read", (__NR_SYSCALL_BASE + 3) },
	{ "readahead", (__NR_SYSCALL_BASE + 223) },
	{ "readdir", (__NR_SYSCALL_BASE + 89) },
	{ "readlink", (__NR_SYSCALL_BASE + 85) },
	{ "readlinkat", (__NR_SYSCALL_BASE + 298) },
	{ "readv", (__NR_SYSCALL_BASE + 145) },
	{ "reboot", (__NR_SYSCALL_BASE + 88) },
	{ "recv", (__NR_SYSCALL_BASE + 175) },
	{ "recvfrom", (__NR_SYSCALL_BASE + 176) },
	{ "recvmmsg", (__NR_SYSCALL_BASE + 335) },
	{ "recvmsg", (__NR_SYSCALL_BASE + 177) },
	{ "remap_file_pages", (__NR_SYSCALL_BASE + 251) },
	{ "removexattr", (__NR_SYSCALL_BASE + 233) },
	{ "rename", (__NR_SYSCALL_BASE + 38) },
	{ "renameat", (__NR_SYSCALL_BASE + 295) },
	{ "renameat2", (__NR_SYSCALL_BASE + 351) },
	{ "request_key", (__NR_SYSCALL_BASE + 281) },
	{ "restart_syscall", (__NR_SYSCALL_BASE + 253) },
	{ "rmdir", (__NR_SYSCALL_BASE + 40) },
	{ "rt_sigaction", (__NR_SYSCALL_BASE + 194) },
	{ "rt_sigpending", (__NR_SYSCALL_BASE + 196) },
	{ "rt_sigprocmask", (__NR_SYSCALL_BASE + 195) },
	{ "rt_sigqueueinfo", (__NR_SYSCALL_BASE + 198) },
	{ "rt_sigreturn", (__NR_SYSCALL_BASE + 193) },
	{ "rt_sigsuspend", (__NR_SYSCALL_BASE + 199) },
	{ "rt_sigtimedwait", (__NR_SYSCALL_BASE + 197) },
	{ "rt_tgsigqueueinfo", (__NR_SYSCALL_BASE + 332) },
	{ "sched_get_priority_max", (__NR_SYSCALL_BASE + 163) },
	{ "sched_get_priority_min", (__NR_SYSCALL_BASE + 164) },
	{ "sched_getaffinity", (__NR_SYSCALL_BASE + 240) },
	{ "sched_getattr", (__NR_SYSCALL_BASE + 350) },
	{ "sched_getparam", (__NR_SYSCALL_BASE + 159) },
	{ "sched_getscheduler", (__NR_SYSCALL_BASE + 161) },
	{ "sched_rr_get_interval", (__NR_SYSCALL_BASE + 165) },
	{ "sched_setaffinity", (__NR_SYSCALL_BASE + 239) },
	{ "sched_setattr", (__NR_SYSCALL_BASE + 349) },
	{ "sched_setparam", (__NR_SYSCALL_BASE + 158) },
	{ "sched_setscheduler", (__NR_SYSCALL_BASE + 160) },
	{ "sched_yield", (__NR_SYSCALL_BASE + 162) },
	{ "seccomp", (__NR_SYSCALL_BASE + 352) },
	{ "security", __PNR_security },
	{ "select", __PNR_select },
	{ "semctl", __PNR_semctl },
	{ "semget", __PNR_semget },
	{ "semop", __PNR_semop },
	{ "semtimedop", __PNR_semtimedop },
	{ "send", (__NR_SYSCALL_BASE + 178) },
	{ "sendfile", (__NR_SYSCALL_BASE + 207) },
	{ "sendfile64", (__NR_SYSCALL_BASE + 237) },
	{ "sendmmsg", (__NR_SYSCALL_BASE + 343) },
	{ "sendmsg", (__NR_SYSCALL_BASE + 179) },
	{ "sendto", (__NR_SYSCALL_BASE + 180) },
	{ "set_mempolicy", (__NR_SYSCALL_BASE + 270) },
	{ "set_robust_list", (__NR_SYSCALL_BASE + 309) },
	{ "set_thread_area", (__NR_SYSCALL_BASE + 283) },
	{ "set_tid_address", (__NR_SYSCALL_BASE + 252) },
	{ "setdomainname", (__NR_SYSCALL_BASE + 121) },
	{ "setfsgid", (__NR_SYSCALL_BASE + 139) },
	{ "setfsgid32", __PNR_setfsgid32 },
	{ "setfsuid", (__NR_SYSCALL_BASE + 138) },
	{ "setfsuid32", __PNR_setfsuid32 },
	{ "setgid", (__NR_SYSCALL_BASE + 46) },
	{ "setgid32", __PNR_setgid32 },
	{ "setgroups", (__NR_SYSCALL_BASE + 81) },
	{ "setgroups32", __PNR_setgroups32 },
	{ "sethostname", (__NR_SYSCALL_BASE + 74) },
	{ "setitimer", (__NR_SYSCALL_BASE + 104) },
	{ "setns", (__NR_SYSCALL_BASE + 344) },
	{ "setpgid", (__NR_SYSCALL_BASE + 57) },
	{ "setpriority", (__NR_SYSCALL_BASE + 97) },
	{ "setregid", (__NR_SYSCALL_BASE + 71) },
	{ "setregid32", __PNR_setregid32 },
	{ "setresgid", (__NR_SYSCALL_BASE + 190) },
	{ "setresgid32", __PNR_setresgid32 },
	{ "setresuid", (__NR_SYSCALL_BASE + 185) },
	{ "setresuid32", __PNR_setresuid32 },
	{ "setreuid", (__NR_SYSCALL_BASE + 70) },
	{ "setreuid32", __PNR_setreuid32 },
	{ "setrlimit", (__NR_SYSCALL_BASE + 75) },
	{ "setsid", (__NR_SYSCALL_BASE + 66) },
	{ "setsockopt", (__NR_SYSCALL_BASE + 181) },
	{ "settimeofday", (__NR_SYSCALL_BASE + 79) },
	{ "setuid", (__NR_SYSCALL_BASE + 23) },
	{ "setuid32", __PNR_setuid32 },
	{ "setxattr", (__NR_SYSCALL_BASE + 224) },
	{ "sgetmask", (__NR_SYSCALL_BASE + 68) },
	{ "shmat", __PNR_shmat },
	{ "shmctl", __PNR_shmctl },
	{ "shmdt", __PNR_shmdt },
	{ "shmget", __PNR_shmget },
	{ "shutdown", (__NR_SYSCALL_BASE + 182) },
	{ "sigaction", (__NR_SYSCALL_BASE + 67) },
	{ "sigaltstack", (__NR_SYSCALL_BASE + 206) },
	{ "signal", (__NR_SYSCALL_BASE + 48) },
	{ "signalfd", (__NR_SYSCALL_BASE + 317) },
	{ "signalfd4", (__NR_SYSCALL_BASE + 324) },
	{ "sigpending", (__NR_SYSCALL_BASE + 73) },
	{ "sigprocmask", (__NR_SYSCALL_BASE + 126) },
	{ "sigreturn", (__NR_SYSCALL_BASE + 119) },
	{ "sigsuspend", (__NR_SYSCALL_BASE + 72) },
	{ "socket", (__NR_SYSCALL_BASE + 183) },
	{ "socketcall", (__NR_SYSCALL_BASE + 102) },
	{ "socketpair", (__NR_SYSCALL_BASE + 184) },
	{ "splice", (__NR_SYSCALL_BASE + 304) },
	{ "ssetmask", (__NR_SYSCALL_BASE + 69) },
	{ "stat", (__NR_SYSCALL_BASE + 106) },
	{ "stat64", (__NR_SYSCALL_BASE + 213) },
	{ "statfs", (__NR_SYSCALL_BASE + 99) },
	{ "statfs64", (__NR_SYSCALL_BASE + 255) },
	{ "stime", (__NR_SYSCALL_BASE + 25) },
	{ "stty", (__NR_SYSCALL_BASE + 31) },
	{ "swapoff", (__NR_SYSCALL_BASE + 115) },
	{ "swapon", (__NR_SYSCALL_BASE + 87) },
	{ "symlink", (__NR_SYSCALL_BASE + 83) },
	{ "symlinkat", (__NR_SYSCALL_BASE + 297) },
	{ "sync", (__NR_SYSCALL_BASE + 36) },
	{ "sync_file_range", (__NR_SYSCALL_BASE + 305) },
	{ "sync_file_range2", __PNR_sync_file_range2 },
	{ "syncfs", (__NR_SYSCALL_BASE + 342) },
	{ "syscall", (__NR_SYSCALL_BASE + 0) },
	{ "sysfs", (__NR_SYSCALL_BASE + 135) },
	{ "sysinfo", (__NR_SYSCALL_BASE + 116) },
	{ "syslog", (__NR_SYSCALL_BASE + 103) },
	{ "sysmips", (__NR_SYSCALL_BASE + 149) },
	{ "tee", (__NR_SYSCALL_BASE + 306) },
	{ "tgkill", (__NR_SYSCALL_BASE + 266) },
	{ "time", (__NR_SYSCALL_BASE + 13) },
	{ "timer_create", (__NR_SYSCALL_BASE + 257) },
	{ "timer_delete", (__NR_SYSCALL_BASE + 261) },
	{ "timer_getoverrun", (__NR_SYSCALL_BASE + 260) },
	{ "timer_gettime", (__NR_SYSCALL_BASE + 259) },
	{ "timer_settime", (__NR_SYSCALL_BASE + 258) },
	{ "timerfd", (__NR_SYSCALL_BASE + 318) },
	{ "timerfd_create", (__NR_SYSCALL_BASE + 321) },
	{ "timerfd_gettime", (__NR_SYSCALL_BASE + 322) },
	{ "timerfd_settime", (__NR_SYSCALL_BASE + 323) },
	{ "times", (__NR_SYSCALL_BASE + 43) },
	{ "tkill", (__NR_SYSCALL_BASE + 236) },
	{ "truncate", (__NR_SYSCALL_BASE + 92) },
	{ "truncate64", (__NR_SYSCALL_BASE + 211) },
	{ "tuxcall", __PNR_tuxcall },
	{ "ugetrlimit", __PNR_ugetrlimit },
	{ "ulimit", (__NR_SYSCALL_BASE + 58) },
	{ "umask", (__NR_SYSCALL_BASE + 60) },
	{ "umount", (__NR_SYSCALL_BASE + 22) },
	{ "umount2", (__NR_SYSCALL_BASE + 52) },
	{ "uname", (__NR_SYSCALL_BASE + 122) },
	{ "unlink", (__NR_SYSCALL_BASE + 10) },
	{ "unlinkat", (__NR_SYSCALL_BASE + 294) },
	{ "unshare", (__NR_SYSCALL_BASE + 303) },
	{ "uselib", (__NR_SYSCALL_BASE + 86) },
	{ "ustat", (__NR_SYSCALL_BASE + 62) },
	{ "utime", (__NR_SYSCALL_BASE + 30) },
	{ "utimensat", (__NR_SYSCALL_BASE + 316) },
	{ "utimes", (__NR_SYSCALL_BASE + 267) },
	{ "vfork", __PNR_vfork },
	{ "vhangup", (__NR_SYSCALL_BASE + 111) },
	{ "vm86", (__NR_SYSCALL_BASE + 113) },
	{ "vm86old", __PNR_vm86old },
	{ "vmsplice", (__NR_SYSCALL_BASE + 307) },
	{ "vserver", (__NR_SYSCALL_BASE + 277) },
	{ "wait4", (__NR_SYSCALL_BASE + 114) },
	{ "waitid", (__NR_SYSCALL_BASE + 278) },
	{ "waitpid", (__NR_SYSCALL_BASE + 7) },
	{ "write", (__NR_SYSCALL_BASE +  4) },
	{ "writev", (__NR_SYSCALL_BASE + 146) },
	{ NULL, __NR_SCMP_ERROR },
};

/**
 * Resolve a syscall name to a number
 * @param name the syscall name
 *
 * Resolve the given syscall name to the syscall number using the syscall table.
 * Returns the syscall number on success, including negative pseudo syscall
 * numbers; returns __NR_SCMP_ERROR on failure.
 *
 */
int mips_syscall_resolve_name(const char *name)
{
	unsigned int iter;
	const struct arch_syscall_def *table = mips_syscall_table;

	/* XXX - plenty of room for future improvement here */
	for (iter = 0; table[iter].name != NULL; iter++) {
		if (strcmp(name, table[iter].name) == 0)
			return table[iter].num;
	}

	return __NR_SCMP_ERROR;
}

/**
 * Resolve a syscall number to a name
 * @param num the syscall number
 *
 * Resolve the given syscall number to the syscall name using the syscall table.
 * Returns a pointer to the syscall name string on success, including pseudo
 * syscall names; returns NULL on failure.
 *
 */
const char *mips_syscall_resolve_num(int num)
{
	unsigned int iter;
	const struct arch_syscall_def *table = mips_syscall_table;

	/* XXX - plenty of room for future improvement here */
	for (iter = 0; table[iter].num != __NR_SCMP_ERROR; iter++) {
		if (num == table[iter].num)
			return table[iter].name;
	}

	return NULL;
}

/**
 * Iterate through the syscall table and return the syscall name
 * @param spot the offset into the syscall table
 *
 * Return the syscall name at position @spot or NULL on failure.  This function
 * should only ever be used internally by libseccomp.
 *
 */
const char *mips_syscall_iterate_name(unsigned int spot)
{
	/* XXX - no safety checks here */
	return mips_syscall_table[spot].name;
}
