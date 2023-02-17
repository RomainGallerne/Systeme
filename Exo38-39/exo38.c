#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    printf("Je suis le programme 1, voici mon identité : %i\n",getpid());
    int i=execlp("/home/e20200007056/Bureau/Cours/L2/Systeme/Exo38-39/exo38_2","./exo38_2",NULL);
    printf("Salut c'est encore le prog 1");
    return 0;
}