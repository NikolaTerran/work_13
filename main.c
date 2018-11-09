#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

static void sighandler(int signo){
	if(SIGINT == signo){
		char * hey = "hey, you haven't paid your respect yet!\n";	
		printf("\n%s",hey);	
		int file = open("errmsg.txt", O_CREAT | O_APPEND, 0644);
		write(file,hey,strlen(hey));
		close(file);
		exit(1);
	}
}

static void sighandler2 (int signo){
	if(signo == SIGUSR1){
		printf("respect paid. ppid:%d\n",getppid());
	}
}

int main(){

	signal(SIGINT,sighandler);
	signal(SIGUSR1,sighandler2);

	while(1){
		printf("press f to pay respect. pid:%d\n",getpid());
		sleep(1);
	}
	
	return 0;
}
