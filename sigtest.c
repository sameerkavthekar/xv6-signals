#include "types.h"
#include "stat.h"
#include "user.h"
void handler(int signal) {
    int a = 3, b = 7;
    int c = a + b;
    printf(1, "Testing user handler and the sum is: %d \n", c);
}
int main(int argc, char *argv[]) {
    signal(0, handler);
    sigkill(3, 0);
    while(1);
    exit();
}