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

int main(){
    int tube[2];
    pipe(tube);
    close(0);
    int compteur = 0;
    char *buf;
    int pid;

    switch(pid=fork()){
        case -1 : {
            printf("Critique : Echec du fork()");
            exit(1);
            break;
        }
        case 1 : {
            close(1);
            sleep(1);
            for(int i=0; i<200; i++){
                read(tube[0],buf,1);
                printf("Lecture\n");
            }
            break;
        }
        default :{
            close(0);
            for(int i=0; i<100; i++){
                write(tube[1],buf,2);
                printf("Ecriture\n");
            }
            sleep(20);
        }
    }
    return 0;
}