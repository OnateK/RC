#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
    //variabila care stocheaza id-ul procesului copil
    pid_t process_id;
    //variabila care stocheaza id-ul procesului parinte
    pid_t p_process_id;

    process_id = getpid();
    p_process_id = getppid();

    //afisarea id-urilor proceselor
    printf("ID-ul procesului copil: %d\n",process_id);
    printf("ID-ul procesului parinte: %d\n",p_process_id);

    return 0;
}

