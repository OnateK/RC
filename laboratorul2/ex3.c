#include<stdio.h> 
#include <sys/types.h>
#include <stdlib.h> 
#include <unistd.h>
#include <signal.h>

void sigint(int);

int main(){

	int pid;
	signal(SIGINT, sigint);
	if((pid=fork()) <= 0 ) {
	perror("fork");
	exit(1);
	}

	if(pid == 0){
	//child
	for(;;);

	}
	else{
	//parent
	signal(SIGINT, SIG_DFL);
	if(pid%2 == 0){
		kill(pid,SIGINT);
	}
	else{
	printf("lost\n");
	}
}




return 0;
}

void sigint(int signo) {
    signal(SIGINT,sigint); /* reset signal */
    printf("Fortune\n");
}
