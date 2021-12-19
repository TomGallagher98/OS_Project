#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void print_gbl_usage() {
    printf("IMCSH Version 1.1 created by Dennis, Maximillian, Tom");
}
void write_txt(char[], char[]);
void str_comprehend(char[]);

int main() {
    setbuf(stdout, NULL);

    char* user = (char*)malloc(50*sizeof(char));
    getlogin_r(user, 50);

    char* host = (char*)malloc(50*sizeof(char));
    gethostname(host, 50);

    char* cmd = (char*)malloc(255*sizeof(char));

    char args[10][30] = {};

    while (1) {
        // char args[10][30] = {};
        printf("%s@%s>", user, host);
        scanf("%s", cmd);
        int i = 0;
        int j = 0;
        char* arg = strtok(cmd, " ");
        // while (i < 10) {
        //     while (arg != NULL) {
        //         strcpy(args[i], arg);
        //         arg = strtok(NULL, " ");
        //         j++;
        //     } i++;
        // }
        while (arg != NULL){
            strcpy(args[i],arg);
            arg = strtok(NULL, " ");
            ++i;
        }
        
        for (j = 0; j < 4; ++j){
            printf("%i one\n",j);
            if (strcmp(args[j],"a")==0){
                printf("%i", j);
                printf("%s\n",args[3]);
            }
            printf("%i", j);
            printf("%s\n", args[j]);
        
        }
        
        // for (int i = 0; i < 1; ++i) {
        //     if (strcmp(args[i],"globalusage") == 0) {
        //         print_gbl_usage();
        //     }
        //     if (strcmp(args[i], ">") == 0){
        //         printf("%s", args[10]);
        //         write_txt("test.txt", "Hello");
        //     }
        //     else {
        //     printf("%s", args[i]);
        //     printf("\n");
        //     }
        }
    //}
}

void write_txt(char* txt, char* str){
    printf("%s", txt);
    FILE *open_file = fopen("t.txt", "w+");
    //FILE *write_file = fwrite(txt, "w+");
    fputs(str, open_file);
    fclose(open_file);
 }

void str_comprehend(char* str){}