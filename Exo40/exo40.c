#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
    pid_t pid;
    int compteur = atoi(argv[1]);
    for (int i=0; i<compteur; i++){
        switch(pid = fork()){
            case -1 : {return 1;} //echec de la création
            case 0 : {
                printf("Hey ! Je suis un clone et j'existe !\n");
                i = compteur;
                return 0;
            } //on est dans le fils
            default : {} //on est dans le père
        }
    }
    sleep(1);
    return 0;
}