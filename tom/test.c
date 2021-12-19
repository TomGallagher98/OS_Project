#include <stdio.h>
#include <string.h>

void write_text(char[],char[]);
char* gbl() {
    return "IMCSH Version 1.1 created by Dennis, Maximillian, Tom";
}

int main ()
{
    char str[]= "globalusage is > test.txt";
    char * pch;
    char ch_arr[4][20] = {};
    int i = 0;
    pch = strtok(str, " ");
    while (pch != NULL)
    {
        // printf("%s\n",pch);
        strcpy(ch_arr[i], pch);
        pch = strtok(NULL, " ");
        ++i;
    }
    int j = 0;
    for (j=0; j<4; ++j){
        if (strcmp(ch_arr[j],"globalusage")==0){
            printf("%s\n",gbl());
        }
        // printf("%s\n", ch_arr[j]);
        if (strcmp(ch_arr[j],">")==0){
            write_text(ch_arr[j+1], gbl());
            printf("%s\n",ch_arr[j+1]);
        }

    }

    return 0;
}

void write_text(char* txt, char* str){
    printf("%s", txt);
    FILE *open_file = fopen(txt, "a");
    fprintf(open_file, "%s\n", str);
    // fprintf(open_file,"\n");
    fclose(open_file);
 }
