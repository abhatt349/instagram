#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <string.h>

#define SEM 17
#define SHM 49

int main() {
  int sem_descriptor;
  sem_descriptor = semget(SEM, 1, 0644);
  int hl = shmget(SHM, 1024);
  
}

