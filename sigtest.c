#include "types.h"
#include "stat.h"
#include "user.h"
#include "signal.h"

void handler(int signal) {
    int a = 3, b = 7;
    int c = a + b;
    printf(1, "Testing user handler and the sum is: %d \n", c);
}

int main(int argc, char *argv[]) {
    sigsend(3, SIGSEGV);
    while(1);
    exit();
}