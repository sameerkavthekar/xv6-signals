#include "types.h"
#include "stat.h"
#include "user.h"
#include "signal.h"

void handler(int signal) {
    int a = 3, b = 7;
    int c = a + b;
    printf(1, "Testing user handler\n");
}

int main(int argc, char *argv[]) {
  sigaction(SIGUSR1, handler);
  int pid = fork();
  if(pid < 0) {
    printf(1, "fork failed\n");
    exit();
  }
  if(pid == 0) {
    pause();
    exit();
  }
  sleep(1);
  sigkill(pid, SIGUSR1);
  wait();
  exit();
}
