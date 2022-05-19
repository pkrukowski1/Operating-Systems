#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>

#define FILLED 0
#define Ready 1
#define NotReady -1

// Definiujemy strukturę danych poniżej

struct memory {
	char buff[100];
	int status, pid1, pid2;
};

// Dynamicznie alokujemy pamięć
struct memory* shmptr;

// Funkcja do przechwytywania wiadomości od drugiego użytkownika
void handler(int signum)
{

	if (signum == SIGUSR1) {
		printf("User2: ");

		// Zapisujemy stringa do strumienia wyjścia
		puts(shmptr->buff);
	}
}

int main()
{

	// Deklarujemy pid
	int pid = getpid();

	int shmid;

	// Klucz do shared memory
	int key = 12345;

	// Tworzymy shared memory
	shmid = shmget(key, sizeof(struct memory), IPC_CREAT | 0666);

	// Załączamy segment shared memory
	shmptr = (struct memory*)shmat(shmid, NULL, 0);

	// Przechowujemy PID user1 w shared memory
	shmptr->pid1 = pid;
	shmptr->status = NotReady;

	// Przechwytujemy sygnał, posiłkując się funkcją wbudowaną signal oraz funkcją zdeklarowaną handler
	signal(SIGUSR1, handler);

	while (1) {
		while (shmptr->status != Ready);
			//continue;
		sleep(1);

		// Pobieramy input od user1

		printf("User1: ");

		// Pobieramy input od user1 i Wczytujemy komunikat do bufora
		
		fgets(shmptr->buff, 100, stdin);
		shmptr->status = FILLED;

		// Wysyłamy wiadomość używając funkcji kill

		kill(shmptr->pid2, SIGUSR2);

		while (shmptr->status == Ready);
			//continue;
	}
	// Odłączamy segment pamięci shared memory od przestrzeni adresowej procesu wywołującego
	shmdt((void*)shmptr);

	// Niszczymy odłączony segment pemięci, zwalniając zasoby
	shmctl(shmid, IPC_RMID, NULL);
	return 0;
}

