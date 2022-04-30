#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}
int
sys_sigsend(void)
{
  int signalno, pid;
  if(argint(0, &pid) < 0)
    return -1;
  argint(1, &signalno);
  return sigsend(pid, signalno);
}
int
sys_signal(void)
{
  int signalno;
  void (*funcptr)(int);
  if(argint(0, &signalno) < 0)
    return -1;
  if(argptr(1, (void*)&funcptr, sizeof(*funcptr)) < 0)
    return -1;
  signal(signalno, funcptr);
}

int
sys_sigreturn(void)
{
  cprintf("In Sigreturn\n");
  struct proc *p = myproc();
  char *sp = (char *)p->tf->esp;
  int signum = *(uint *)sp;
  sp += 4;
  sp += 8;
  p->sigpending[signum]  = 0;
  struct trapframe old_trapframe = *(struct trapframe *)sp;
  memmove(p->tf, &old_trapframe, sizeof(struct proc));
  return 0;
}