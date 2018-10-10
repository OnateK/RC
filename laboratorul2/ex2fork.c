#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	printf("hello\n");
        fork();
        printf("Hello world!\n");
        return 0;
}

