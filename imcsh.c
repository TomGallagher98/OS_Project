#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    setbuf(stdout, NULL);

    char* user = (char*)malloc(50*sizeof(char));
    getlogin_r(user, 50);

    char* host = (char*)malloc(50*sizeof(char));
    gethostname(host, 50);

    char* cmd = (char*)malloc(255*sizeof(char));

    char* qa = (char*)malloc(5*sizeof(char));

    char args[10][30] = {};

    while (1) {
        printf("%s@%s> ", user, host);
        scanf("%s", cmd);
        int i = 0;
        char* arg = strtok(cmd, " ");
        while (arg != NULL) {
            strcpy(args[i], arg);
            arg = strtok(NULL, " ");
            i++;
        }
        if (strcmp(args[0],"globalusage") == 0) {
            printf("IMCSH Version 1.0 created by Tom Gallagher, Dennis Waswa Simiyu, Maximilian Mandel\n");
        }
        else if (strcmp(args[0], "quit") == 0) {
            printf("The following processes are running, are you sure you want to quit? [Y/n] ");
            //List all running processes
            scanf("%s", qa);
            if (strcmp(qa, "Y") == 0) {
                exit(0);
            }
            else if (strcmp(qa, "n") == 0) {
            }
        }
    }
}
