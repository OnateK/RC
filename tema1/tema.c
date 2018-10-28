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
	printf("The command  %s  was executed successfully.\n",command);
	quit=0;
	}
	else
	printf("The command  %s  is not a valid one.Please try again.\n",command);
	}
return 0;
}
