#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>
#include <stdbool.h>

void crible(int in[]){
    int *buf;
    int pid;
    close(in[1]);
    int P;
    if (0!=(P=read(in[0],buf,sizeof(int)))){
        printf("%i ",P);
        int out[2];
        pipe(out);
        switch(pid=fork()){
            case -1 : {
                printf("Critique : Erreur du fork");
                exit(-1);
                break;
            }
            case 1 : {
                close(in[0]);
                return crible(out);
            }
            default : {
                close(out[0]);
                int i;
                while (i=read(in[0],buf,sizeof(int))){
                    if (i%P != 0) {
                        write(out[1],&i,sizeof(int));
                    }
                }
                close(in[0]);
                close(out[1]);
            }
        }
    }
}

int main(){
    int tube[2];
    pipe(tube);
    close(tube[0]);
    for(int i=2;i<1000;i++){
        write(tube[1],&i,sizeof(int));
    }
    printf("Liste des nombres premiers :\n");
    crible(tube);
    return 0;
}