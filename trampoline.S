#include "syscall.h"
#include "traps.h"

.globl trampoline_start
.globl trampoline_end
trampoline_start:
  movl $SYS_sigreturn, %eax
  int $T_SYSCALL
trampoline_end: