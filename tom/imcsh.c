#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

void print_gbl_usage() {
    printf("IMCSH Version 1.1 created by Dennis, Maximillian, Tom\n");
}
void write_txt(char[], char[]);

void print_cmd(char *cmmd){
    // char cmds[10][30] = {};
    printf("%s = cmmd\n" ,cmmd);
    // char* arg = strtok(cmmd, "\n ");
    // char* exec_list[] = {};
    pid_t pid;
    pid = fork();
    if (pid == -1){
        printf("Cannot fork");
    }
    else if (pid == 0){
        printf("forked\n");
        int i = 0;
        // while (cmmd != NULL){
        //         strcpy(cmds[i],cmmd);
        //         cmmd = strtok(NULL, "\n ");
        //         ++i;
        //     }
        // for (i = 0; i < 4; ++i){
        //     exec_list[i] = cmmd[i+1];
        // }
        // printf("%s", exec_list[0]);
        // execv(exec_list[0], exec_list);
        // char * argv_list[] = {"test", NULL};
        // printf("%s\n", argv_list[0]);
        exit(0);
        
    }
    printf("pid = %i", pid);
}


void printShell(char* user, char* host){
    printf("%s@%s>", user, host);
}

int main() {
    setbuf(stdout, NULL);

    char* user = (char*)malloc(50*sizeof(char));
    getlogin_r(user, 50);

    char* host = (char*)malloc(50*sizeof(char));
    gethostname(host, 50);
    #define MAX_INPUT 256
    char* cmd = (char*)malloc(MAX_INPUT);
    char args[10][30] = {};

    while (1) {
        char args[10][30] = {};
        char* input_str = (char*)malloc(MAX_INPUT);
        printShell(user, host);
        fgets(cmd, MAX_INPUT, stdin);
        
        int i = 0;
        int j = 0;

        
        
        //Creates arg pointers, splits cmd at spaces and new line separators
        
        char* arg = strtok(cmd, "\n ");
        // printf("%s", arg);
        while (arg != NULL){
            strcpy(args[i],arg);
            arg = strtok(NULL, " ");
            ++i;
        }

        

        for (i = 0; i < 10; ++i){
            if (strcmp(args[i], ">")==0){
                write_txt(args[i+1],"test2");
                break;
            }   
        }
        if (strcmp(args[0], "exec") == 0){
                char* exec_list[] = {};
                pid_t pid, wpid;
                pid = fork();
                int status = 0;
                if (pid == -1){
                    printf("Cannot fork");
                }
                else if (pid == 0){
                    // printf("forked\n");
                    for (i = 0; i < 4; ++i){
                        exec_list[i] = strtok(args[i+1],"\n");
                        }
                    printf("%s function \n", exec_list[0]);
                    execv(exec_list[0], exec_list);
                    
                    
                    exit(0);
                    }
                else {
                    wpid = wait(NULL);
                }
                printf("Pid = %u\n", getpid());

        }       
        if (strcmp(args[0],"globalusage")==0){ 
                print_gbl_usage();
        }
        
        
    }
}

void write_txt(char* txt, char* str){
    // printf("%s", txt);
    FILE *open_file = fopen(txt,"a");
    fprintf(open_file, "%s\n", str);
    fclose(open_file);
 }
