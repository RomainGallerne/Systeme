#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
    struct stat info;
    if (lstat(argv[1],&info)<0) {
        printf("Erreur au lstat");
        exit(EXIT_FAILURE);
    }
    char affichage[10];
    if (S_ISREG(info.st_mode)){affichage[0] = '-';}
    else if (S_ISDIR(info.st_mode)){affichage[0] = 'd';}
    else if (S_ISLNK(info.st_mode)){affichage[0] = 'l';}

    if (S_IRUSR & info.st_mode){affichage[1]='r';} else {affichage[1]='-';}
    if (S_IWUSR & info.st_mode){affichage[2]='w';} else {affichage[2]='-';}
    if (S_IXUSR & info.st_mode){affichage[3]='x';} else {affichage[3]='-';}

    if (S_IRGRP & info.st_mode){affichage[4]='r';} else {affichage[4]='-';}
    if (S_IWGRP & info.st_mode){affichage[5]='w';} else {affichage[5]='-';}
    if (S_IXGRP & info.st_mode){affichage[6]='x';} else {affichage[6]='-';}

    if (S_IROTH & info.st_mode){affichage[7]='r';} else {affichage[7]='-';}
    if (S_IWOTH & info.st_mode){affichage[8]='w';} else {affichage[8]='-';}
    if (S_IXOTH & info.st_mode){affichage[9]='x';} else {affichage[9]='-';}

    printf(affichage);
    printf("\n");
}