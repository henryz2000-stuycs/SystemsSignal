#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>

static void sighandler(int signo){
  if(signo == SIGINT){
    int fd = open("msgs", O_CREAT|O_WRONLY, 0644);
    char msg[] = "bleep bloop SIGINT detected\n";
    write(fd,msg,sizeof(msg));
    close(fd);
    exit(0);
  }

  if(signo == SIGUSR1){
    printf("Hi I'm the parent: %d\n", getppid());
  }
}

int main(){

  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);

  while(1){
    printf("Hi I'm: %d\n", getpid());
    sleep(1);
  }
  return 0;

}
