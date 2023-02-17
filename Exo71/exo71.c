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

void Action (int sig){
    printf("Pressez encore une fois le signal %d pour terminer le processus\n",sig);
}

int main(){
    struct sigaction gere;
    gere.sa_handler = Action;
    gere.sa_flags = SA_RESETHAND;
    sigaction(SIGINT,&gere,NULL);
    while(1);
}