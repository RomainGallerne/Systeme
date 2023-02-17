#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    if (argc != 3){
        printf("Nombre de paramètres incorrect\n");
        exit(EXIT_FAILURE);
    }
    char* chemin = argv[1];
    char recherche = argv[2][0];
    int f = open(chemin,O_RDONLY);
    if (f==-1){
        printf("Impossible d'ouvrir le fichier %s\n",chemin);
        return 2;
    }
    char tmp[200];
    int position;
    int balise1 = 0;
    int balise2 = 0;
    while(read(f,&tmp,1)){
        balise2++;
    }
    do {
        position = (balise2-balise1)/2;
        read(f,tmp,1);
        if (recherche > tmp) {
            printf(" %c %c ",recherche, tmp);
            printf("plus grand !\n");
            balise1 = lseek(f,position,SEEK_CUR);
        }
        if (recherche < tmp) {
            printf(" %c %c ",recherche, tmp);
            printf("plus petit !\n");
            balise2 = lseek(f,-position,SEEK_CUR);
        }
    } while (tmp != recherche);
    if (balise1 == read(f,&tmp,1)) {
        printf("La position du caractère est : %i",balise1);
    }
    else {
        printf("La position du caractère est : %i",balise2);
    }
    close(f);
    return 0;
}