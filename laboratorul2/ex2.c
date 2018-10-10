
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
  
int main()
{
    int i;
    int pid = fork();
    if (pid==0)
    {
        execlp("ls", "ls", "-a","-l", (char*)NULL);
    }
    else
    {
        wait(NULL);
        printf("Child just executed ls -a -l\n");
    }
}

