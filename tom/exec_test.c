#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>

void write_text(char[],char[]);
char* execute() {
    pid_t pid;
    int ret = 1;
    int status;
    pid = fork();

    if (pid == -1){
        printf("Can't fork only spoon\n");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0){
        printf("child process = %u\n", getpid());
        printf("parent of child process = %u\n", getppid());
        //I want to change the below section so that
        //argv_list is inputted by the user in the 
        //execute function
        char * argv_list[] = {"ls","-lart","/home", NULL};

        execv("ls",argv_list);
        exit(0);
    }
    else{
        printf("Parent of parent process = %u\n", getppid());
        printf("Parent process = %u\n", getpid());

        if (waitpid(pid, &status, 0 )> 0) {
            
            if (WIFEXITED(status) && !WEXITSTATUS(status))
            printf("execution successful\n");
        
            else if (WIFEXITED(status) && WEXITSTATUS(status)){
                if (WEXITSTATUS(status) == 127){
                    printf("execv failed\n");
                }
                else 
                printf("terminated normally with non-zero status\n");
            }
            else
            printf("program didn't terminate normally\n");
        }
        else {
        printf("waitpid() failed\n");
        }
        return "Worked";
        exit(0);
    } 
    printf( "Worked\n");
}
int main(){
    // printf ("My PID = %u", getpid());
    write_text("exec.txt", execute());
    printf("%s", execute());
    
}

void write_text(char* txt, char* str){
    printf("%s", txt);
    FILE *open_file = fopen(txt, "a");
    fprintf(open_file, "%s\n",str);
    fclose(open_file);
 }
