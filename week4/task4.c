#include <stdio.h>
#include <sys/types.h>

void main(int argcount, char *argv[])
{
	if (argcount < 2)
		return;

	char *args[argcount];

	for (int i = 0; i < argcount - 1; i++)
		args[i] = argv[i + 1];

	args[argcount - 1] = NULL;

	pid_t id = fork();

	execvp(args[0], args, 0);
}
