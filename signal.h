#define MAXSIGNALS  32

#define SIGINT      2
#define SIGFPE			8
#define SIGKILL     9
#define SIGSEGV     11
#define SIGTERM			15
#define SIGUSR1     16
#define SIGCHLD     18
#define SIGSTOP     23
#define SIGCONT     25
#define SIGSYS			31

#define SIG_IGN     0
#define SIG_DFL     1

#define SIG_UNBLOCK 0
#define SIG_BLOCK   1
#define SIG_SETMASK 2