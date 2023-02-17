#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    printf("Je suis le programme 2, voici mon identité : %i\n",getpid());
    //int i=execl("/home/e20200007056/Bureau/Cours/L2/Systeme/Exo38-39/exo38","./exo38",NULL);
    return 0;
}