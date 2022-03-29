#include "types.h"
#include "stat.h"
#include "user.h"
void handler(int signal) {
    printf(1, "Testing user handler\n");
}
int main(int argc, char *argv[]) {
    signal(9, handler);
    sigkill(1, 9);
    return 0;
}