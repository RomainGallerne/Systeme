#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    int a = 3;
    int *b = malloc(sizeof(int));
    *b = 8;
    int pid;
    switch(pid = fork()){
        case -1 : {break;} //echec de la création
        case 0 : {
            printf("Je suis le fils\n");
            a+=5;
            *b+=6;
            break;
            } //on est dans le fils
        default : {
            printf("Je suis le père\n");
            a+=2;
        } //on est dans le père
    }
    printf ("Ma variable a vaut : %i\n",a);
    printf ("Ma variable a a pour pointeur %p\n",&a);
    printf ("Ma variable b vaut : %i\n",*b);
    printf ("Ma variable b a pour pointeur %p\n",b);
    free(b);
    return 0;
}