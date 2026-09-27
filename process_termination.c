#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int main()
{
    int i;
    int status;
    pid_t pid;

    printf("Parent Process Started\n");
    printf("Parent PID: %d\n\n", getpid());

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
            if (i == 1)
            {
                printf("Child 1 (PID %d): Performing calculation task...\n",
                       getpid());

                sleep(2);

                printf("Child 1: Task completed successfully.\n");
                exit(10);
            }
            else if (i == 2)
            {
                printf("Child 2 (PID %d): Performing file processing task...\n",
                       getpid());

                sleep(3);

                printf("Child 2: Task completed successfully.\n");
                exit(20);
            }
            else
            {
                printf("Child 3 (PID %d): Performing monitoring task...\n",
                       getpid());

                sleep(1);

                printf("Child 3: Terminating using SIGTERM.\n");

                kill(getpid(), SIGTERM);
            }
        }
    }

    for (i = 0; i < 3; i++)
    {
        pid = wait(&status);

        if (pid == -1)
        {
            perror("wait failed");
            exit(1);
        }

        printf("\n--- Child Termination Detected ---\n");
        printf("Terminated Child PID: %d\n", pid);

        if (WIFEXITED(status))
        {
            printf("Termination Type: Normal\n");
            printf("Exit Status: %d\n", WEXITSTATUS(status));
        }
        else if (WIFSIGNALED(status))
        {
            printf("Termination Type: Abnormal\n");
            printf("Terminated by Signal: %d\n", WTERMSIG(status));
        }
    }

    printf("\nAll child processes have been collected.\n");
    printf("No zombie processes remain.\n");

    return 0;
}