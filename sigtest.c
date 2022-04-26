#include "types.h"
#include "stat.h"
#include "user.h"
void handler(int signal) {
    printf(1, "Testing user handler\n");
}
int main(int argc, char *argv[]) {
    signal(0, handler);
    sigkill(3, 0);
    while(1);
    exit();
}