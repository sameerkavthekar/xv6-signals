#include "types.h"
#include "stat.h"
#include "user.h"
#include "signal.h"

void handler(int signal) {
    int a = 3, b = 7;
    int c = a + b;
    printf(1, "Testing SIGSEGV handler\n");
}

void child_handler(int signal) {
    int a = 3, b = 7;
    int c = a + b;
    printf(1, "Testing SIGCHLD handler\n");
}

// int main(int argc, char *argv[]) {
//   sigaction(SIGSEGV, handler);
//   *(int *)0 = 0;
//   while(1);
//   exit();
// }

int main(int argc, char *argv[]) {
  sigaction(SIGCHLD, child_handler);
  int pid = fork();
  if(pid < 0) {
    printf(1, "fork failed\n");
    exit();
  }
  if(pid == 0) {
    sleep(1);
    printf(1, "Exiting Child\n");
    exit();
  }
  wait();
  sleep(2);
  exit();
}
