#include <glob.h>
#include <stdio.h>
#include <stdlib.h>

#define PAT  "/etc/a*.conf"

#if 0

int errfunc_(char *errpath, int eerrrno){
    puts(errpath);
    strerror(stderr,"ERROR MSG:%s\n",strerror(eerror));
}
#endif

int main(){
    glob_t globres;
    int i, err;
    err = glob(PAT,0,NULL,&globres);
    if(err)
    {
        printf("Error code = %d\n",err);
        exit(1);
    }

    for(i = 0;i<globres.gl_pathc;i++)
        puts(globres.gl_pathv[i]);

    globfree(&globres);

    exit(0);
}