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
    int x = SIGKILL, y = 0, z = 4784130;
    sigprocmask(SIG_BLOCK, &x, &y);
    sigprocmask(SIG_SETMASK, &z, &y);
    while(1);
    exit();
}
