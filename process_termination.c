#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int i;
    int status;
    pid_t pid;

    printf("Parent Process PID: %d\n", getpid());

    for (i = 1; i <= 3; i++)
    {
        pid = fork();

        if (pid < 0)
        {
            perror("fork failed");
            exit(1);
        }

        if (pid == 0)
        {
            printf("Child %d created. PID: %d\n", i, getpid());

            sleep(i);

            printf("Child %d terminating normally.\n", i);
            exit(i * 10);
        }
    }

    for (i = 0; i < 3; i++)
    {
        pid = wait(&status);

        if (WIFEXITED(status))
        {
            printf("Parent detected Child PID %d terminated normally with exit status %d.\n",
                   pid, WEXITSTATUS(status));
        }
        else
        {
            printf("Parent detected Child PID %d terminated abnormally.\n", pid);
        }
    }

    printf("All child processes have terminated.\n");

    return 0;
}