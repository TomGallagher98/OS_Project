#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void print_gbl_usage() {
    puts("IMCSH Version 1.1 created by Dennis, Maximillian, Tom");
    return;

}

int main() {
    setbuf(stdout, NULL);

    char* user = (char*)malloc(50*sizeof(char));
    getlogin_r(user, 50);

    char* host = (char*)malloc(50*sizeof(char));
    gethostname(host, 50);

    char* cmd = (char*)malloc(255*sizeof(char));

    char args[10][10] = {};

    while (1) {
        printf("%s@%s>", user, host);
        scanf("%s", cmd);
        int i = 0;
        char* arg = strtok(cmd, " ");
        while (arg != NULL) {
            strcpy(args[i], arg);
            arg = strtok(NULL, " ");
            i++;
        }
        for (int i = 0; i < 1; ++i) {
            if (strcmp(args[i],"globalusage") == 0) {
                print_gbl_usage();
            }
            else {
            printf("%s", args[i]);
            printf("\n");
            }
        
            

        }
    } 

}


