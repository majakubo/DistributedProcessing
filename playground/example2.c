#include <unistd.h>
#include <stdio.h>
int main()
{
	if(fork() == 0)
	{
		printf("Proces potomny pid: %d ppid: %d\n", getpid(), getppid());
		sleep(10);
		printf("proces potomny konczy dzialanie\n");
		return 0;
	}
	else
	{
		printf("proces macierzysty pid: %d ppid: %d\n", getpid(), getppid());
		sleep(5);
		printf("proces macierzysty konczy dzialanie\n");
		return 0;
	}
}
