#include "syscall.h"
#include "traps.h"

.globl trampoline
trampoline:
  movl $SYS_sigreturn, %eax
  int $T_SYSCALL