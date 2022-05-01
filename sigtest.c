#include "types.h"
#include "stat.h"
#include "user.h"
#include "signal.h"

void handler(int signal) {
    int a = 3, b = 7;
    int c = a + b;
    printf(1, "Testing user handler and the sum is: %d & Signal number is: %d \n", c, signal);
}

int main(int argc, char *argv[]) {
    int x = SIGUSR1, y = 0;
    sigaction(SIGUSR1, handler);
    sigprocmask(SIG_BLOCK, &x, &y);
    printf(1, "1 %d\n", y);
    sigkill(3, SIGUSR1);
    sigprocmask(SIG_UNBLOCK, &x, &y);
    printf(1, "2 %d\n", y);
    sigkill(3, SIGUSR1);
    pause();
    printf(1, "After Pause");
    while(1);
    exit();
}
