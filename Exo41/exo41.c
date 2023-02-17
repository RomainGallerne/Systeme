#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
    int pid;
    char* commande = argv[1];
    switch(pid = fork()){
        case -1 : {return 1;} //echec de la création
        case 0 : {execl(commande,commande,NULL);} //on est dans le fils
        default : {} //on est dans le père
    }
    sleep(1);
    return 0;
}