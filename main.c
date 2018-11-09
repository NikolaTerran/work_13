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
		int file = open("errmsg.txt", O_CREAT | O_WRONLY, 0444);
		write(file,hey,strlen(hey));
		exit(1);
	}
}

static void sighandler2 (int signo){
	if(signo == SIGUSR1){
		printf("respect paid.\n");
	}
}

int main(){

	signal(SIGINT,sighandler);
	//signal(SIGUSR1,sighandler2);

	while(1){
		printf("press f to pay respect\n");
		sleep(1);
	}
	
	return 0;
}
