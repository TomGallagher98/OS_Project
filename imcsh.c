#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    setbuf(stdout, NULL);

    char* user = (char*)malloc(50*sizeof(char)); //Allocating 50 chars for the username
    getlogin_r(user, 50); //Getting the username of the current machine

    char* host = (char*)malloc(50*sizeof(char)); //Allocating 50 chars for the hostname
    gethostname(host, 50); //Geting the hostname of the current machine

    char cmd[255]; //Variable for the command input

    char* qa = (char*)malloc(5*sizeof(char)); //Variable for storing yes or no answer from quit command

    char *args[255]; //Separate variable for storing arguments of commands

    while (1) {
        printf("%s@%s> ", user, host); //Print of user and host for command prompt
        fgets(cmd, 255, stdin); //Command input from user
        int i = 0;
        char* arg = strtok(cmd, " "); //Splitting string with a space as a delimiter
        while (arg != NULL) { //While there is still a split string piece available
            if (arg[strlen(arg)-1] == '\n') { //Remove new line from the end of the string and replace it with a string end character
                arg[strlen(arg)-1] = '\0';
            }
            args[i++] = arg; //Add each argument to the args variable for later use
            arg = strtok(NULL, " "); //Get new split string piece
        }

        if (strcmp(args[0],"globalusage") == 0) { //Check if command is "globalusage"
            printf("IMCSH Version 1.0 created by Tom Gallagher, Dennis Waswa Simiyu, Maximilian Mandel\n");
        }
        else if (strcmp(args[0], "quit") == 0) { //Check if command is "quit"
            pid_t ap = fork(); //Get all running processes
            if (ap > 0) {
                printf("The following processes are running:\n");
                printf("%d\n", ap); //Print all running processes
                printf("Are you sure you want to quit? [Y/n] ");
            }
            fgets(qa, 3, stdin); //Get input on quit - yes or no
            qa[strlen(qa)-1] = '\0'; //Remove new line from string and replace with string end character
            if (strcmp(qa, "Y") == 0) { //Check if input is "Y" (yes)
                exit(0); //Exit
            }
            else if (strcmp(qa, "n") == 0) {  //Check if input is "n" (no)
            }
        }
        else if (strcmp(args[0], "exec") == 0) { //Check if command is "exec"
            int le = 0;

            for (int i = 0; i <= 254; i++) { //
                if (args[i] == NULL) {       //
                    le = (i-1);              // Find last element of args array
                    break;                   //
                }                            //
            }                                //
            printf("%s", args[le]);
            if (strcmp(args[le], "&") == 0) { //Check if "&" modifier has been input
                pid_t pid = fork();

                if (pid < 0) { //Check if fork failed
                    fprintf(stderr, "Fork failed");
                }
                else if (pid == 0) { //Check if pid is 0 (child process)
                    execv(args[0], args);
                }
                else {
                    printf("Executing %d in the background\n", pid); //Print background execution message
                }
            }
            else {
                
            }
        }
    }
    free(user);
    free(host);
    free(qa);
}
