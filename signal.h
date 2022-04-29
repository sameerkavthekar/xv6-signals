#define MAXSIGNALS  32

#define SIGINT      2
#define SIGKILL     9
#define SIGSEGV     11
#define SIGUSR1     16
#define SIGCHLD     18
#define SIGSTOP     23
#define SIGCONT     25

#define SIG_IGN     0
#define SIG_DFL     1

void defaulthandler_terminate();
void defaulthandler_continue();
void defaulthandler_stop();