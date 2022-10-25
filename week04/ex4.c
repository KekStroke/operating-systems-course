#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

// <WRITE YOUR CODE HERE>

int main(void)
{

    char command[1000];
    pid_t main_process = getpid();
    pid_t last_child;
    while (fgets(command, 1000, stdin))
    {
        if (strcmp(command, "exit\n") == 0)
            break;
        if (getpid() == main_process)
        {
            if (command[strlen(command) - 2] != '&')
            {
                last_child = fork();
            }
            else
            {
                fork();
            }
            if (getpid() != main_process)
            {
                int err = system(command);
                return EXIT_SUCCESS;
            }
        }
        // printf("%c\n", command[strlen(command) - 2]);
        if (command[strlen(command) - 2] != '&' && getpid() == main_process)
        {
            waitpid(last_child, NULL, 0);
        }
    }

    return EXIT_SUCCESS;
}

// Example on using system
// https://www.codingunit.com/c-reference-stdlib-h-function-system

// Example on using execve
// https://linuxhint.com/c-execve-function-usage/