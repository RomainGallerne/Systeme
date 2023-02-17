#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    int pid;
    switch(pid = fork()){
        case -1 : {break;} //echec de la création
        case 0 : {
            printf("Je suis le fils\n");
            break;
            } //on est dans le fils
        default : {printf("Je suis le père\n");} //on est dans le père
    }

    printf ("Mon identifiant est : %i\n",getpid());
    printf ("Mon père est : %i\n",getppid());
    return 0;
}