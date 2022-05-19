#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
int* number1;
int* number2;
pid_t pid;

number1 = (int*)malloc(sizeof(int));
number2 = (int*)malloc(sizeof(int));

	/* fork a child process */
	pid = fork();

	if (pid < 0) { /* error occured */
		fprintf(stderr, "Fork Failed");
		return 1;
	}
	else if (pid==0) { /* child process */
		printf("Tutaj proces potomny. Mój PID = %u, a PID mojego rodzica to %u.\n", getpid(), getppid());
		while (1)
			scanf("%d", number1);
	}
	else { /* parent process */
		/* parent will wait for the child to complete */
		printf("Tutaj proces macierzysty. Mój PID = %u, a PID procesu potomnego to %u.\n", getpid(), pid);
		printf("Child Complete\n");
		while (1)
			scanf("%d", number2);
	}

	return 0;
}
