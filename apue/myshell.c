#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <glob.h>
#include <string.h>

#define DELIMS " \t\n"


struct cmd_t{
    glob_t globres;
};

static void prompt(){
    printf("mysh-0.1$ ");
}


static parse(char* line, struct cmd_t* res){
    char* tok;
    int i = 0;
    while(1){
        tok = strsep(&line,DELIMS);
        if(tok == NULL)
            break;
        if(tok[0]=='\0')
            continue;
        glob(tok,GLOB_NOCHECK | GLOB_APPEND,NULL,&res->globres);
    }   
}

int main()
{
    char* linebuf = NULL;
    size_t linebuf_size = 0;
    pid_t pid;
    struct cmd_t cmd;
    while(1){
        prompt();

        if(getline(&linebuf,&linebuf_size,stdin)<0)
            break;
        
        parse(linebuf, &cmd);

        if(0){
            
        }else{
            pid = fork();
            if(pid <0){
                perror("fork()");
                exit(1);
            }

            if(pid==0){
                execvp(cmd.globres.gl_pathv[0],cmd.globres.gl_pathv);
                perror("execvp()");
                exit(1);
            }
            else{
                wait(NULL);
            }
        }
    }


    exit(0);
}