#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <string.h>

#define SEM 17
#define SHM 49

int main(int argc, char** argv){
  int sem_descriptor;
  if (argc < 2) { //if less than two arguments in the arg vector ./a.out
    printf("Missing arguments\n");
  }

  //to create the semaphore with the -c flag
  else if(!strcmp(argv[1], "-c") && argc == 3){ //if they ran $ ./a.out -c N
    int hl = shmget(SHM, 1024, IPC_CREAT | IPC_EXCL);
    int ab = open( "story", O_TRUNC | O_CREAT);
    
    sem_descriptor = semget(SEM, 1, IPC_CREAT | IPC_EXCL | 0644);
    if(sem_descriptor == -1) {
      printf("Semaphore already existent\n");
    }
    else{
      int val;
      sscanf(argv[2], "%d", &val);
      semctl(sem_descriptor, 0, SETVAL, val);
      printf("Semaphore created: %d\t with value: %d\n",sem_descriptor, val);
    }
  }

  //to view the value of the semaphore with the -v flag
  else if(!strcmp(argv[1], "-v")) {
    //sem_descriptor = semget(SEM, 0, 0);
    //printf("Semaphore value: %d\n",semctl(sem_descriptor, 0, GETVAL));
    int f = fork();
    if (!f) {
      execlp("cat", "cat", "story");
    }

  }

  //to remove the semaphore with the -r flag
  else if(!strcmp(argv[1], "-r")) {
    shmctl( hl, IPC-RMID);
    sem_descriptor = semget(SEM, 0, 0);
    printf("Semaphore removed: %d\n", semctl(sem_descriptor, 0, IPC_RMID));
    int f = fork();
    if (!f) {
      execlp("cat", "cat", "story");
    }
    
  }
  return 0;
}
