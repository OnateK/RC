#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <math.h>
 
int prim(int);
void errorHandler(const char*, int);
 
int main(int argc, char* argv[]) {
    int p[2];
    if(-1 == pipe(p))
        errorHandler("pipe", errno);
    int pid = fork();
    if(-1 == pid)
        errorHandler("fork", errno);
    if(0 == pid){//child
        int x;
        if(-1 == read(p[0], &x, 4))
            errorHandler("read number", errno);
        close(p[0]);
        if(prim(x)){
            if(-1 == write(p[1], "yes\0", 4))
                errorHandler("write yes", errno);
        } else {
            if(-1 == write(p[1], "no\0", 3))
                errorHandler("write no", errno);
        }
        close(p[1]);
        return 0;
    }
    //parent
    int number = 0;
    if(argc > 1)
        number = atoi(argv[1]);
    if(-1 == write(p[1], &number, 4))
        errorHandler("write number", errno);
    close(p[1]);
    wait(NULL);
    char s[4];
    if(-1 == read(p[0], s, 4))
        errorHandler("read yes/no", errno);
    printf("%s\n", s);
    close(p[0]);   
    return 0;
}
 
int prim(int x) {
    if(0 == x || 1 == x)
        return 0;
    for(int i = 2; i <= x/2; i++){
        if(0 == x % i)
            return 0;
    }
    return 1;
}
 
void errorHandler(const char* e, int n) {
    printf("Eroare %s %d\n", e, n);
    exit(1);
}
