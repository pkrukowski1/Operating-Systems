#include<stdio.h>
#include<signal.h>
#include<unistd.h>
/*Nie możemy przechwycić takich sygnałów, jak SIGKILL czy SIGSTOP */
void sig_handler(int signo)
{
    if (signo == SIGUSR1)
        printf("Otrzymałem sygnał SIGUSR1\n");
    else if (signo == SIGKILL)
        printf("Otrzymałem sygnał SIGKILL\n");
    else if (signo == SIGSTOP)
        printf("Otrzymałem sygnał SIGSTOP\n");
    else if(signo == SIGINT)
	    printf("Otrzymałem sygnał SIGINT\n");
}

int main(void)
{
    if (signal(SIGUSR1, sig_handler) == SIG_ERR)
        printf("\nNie mogę złapać\n");
    if (signal(SIGKILL, sig_handler) == SIG_ERR)
        printf("\nNie mogę złapać\n");
    if (signal(SIGSTOP, sig_handler) == SIG_ERR)
        printf("\nNie mogę złapać\n");
    if (signal(SIGINT, sig_handler) == SIG_ERR)
	    printf("\nNie mogę złapać\n");
    while(1) 
        sleep(1);
    return 0;
}
