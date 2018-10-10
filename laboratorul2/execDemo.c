#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
int main() 
{   
        //array de pointers 
        char *args[]={"./EXEC",NULL}; 
        execvp(args[0],args); 
      
        /*Toate statementurile sunt ignorate dupa apelul execvp() intrucat procesu execDemo.c este inlocui de procesul EXEC.c
        */
        printf("Ending-----"); 
      
    return 0; 
}

