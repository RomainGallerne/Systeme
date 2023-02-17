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

//PAS FINI
int x=-1;

bool rappel = true;

void Action (int sig){
    if (x<0) {
        printf("Grouille toi.");
        rappel = false;
    }
}

voi Action2 (int sig) {
    if (x == 2022) {
        printf("Bravo.");
        exit(0);
    }
    else if (x <=)
}

int main(){
    struct sigaction gere;
    gere.sa_handler = Action;
    struct sigaction gere2;
    gere2.sa_handler = Action2;
    printf("Après 2021, il y a?\n");
    sigaction(SIGALRM,&gere,NULL);
    alarm(10);
    scanf("%d",&x);
    while(rappel);
    if (x<0){
        alarm(10);
        scanf("%d",&x);
        sigaction(SIGALRM,&gere2,NULL);
    }
}