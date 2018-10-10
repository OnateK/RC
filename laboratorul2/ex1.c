#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

int main(){
	int pfd[2];
	if(-1 == pipe(pfd)){
		printf("Eroare pipe %d \n", errno);
		exit(1);
	}

	int pid = fork();
	if(-1 == pid){
		printf("Eroare fork %d\n", errno);
		exit(2);
	}

	if(0 == pid){//child
		close(pfd[1]);
		char* buffer = (char*)malloc(8);
		if(-1 == read(pfd[0], buffer, 8)){
			printf("Eroare read %d\n", errno);
			exit(3);
		}
		printf("%s\n", buffer);
		close(pfd[0]);
		exit(0);
	}

	//parent
	//printf("pid fiu: %d\n", pid);
	close(pfd[0]);
	if(0 == pid % 2){
		if(-1 == write(pfd[1], "fortune", 7)){
			printf("Eroare write %d\n", errno);
			exit(4);
		}
	} else {
		if(-1 == write(pfd[1], "lost", 4)){
			printf("Eroare write %d\n", errno);
			exit(4);
		}
		close(pfd[1]);
		exit(0);
	}
	wait(NULL);
	close(pfd[1]);
	return 0;
}
