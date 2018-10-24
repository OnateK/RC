#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <math.h>

int main(){

	char command[100];
	int quit=1;
	while(quit){
	
	printf("Enter command: ");
	scanf("%s", command);
	if(strcmp(command,"quit")==0){
	printf("S-a introdus comanda %s \n",command);
	quit=0;
	}
	else
	printf("comanda gresita.Reintroduceti comanda \n");
	}
return 0;
}
