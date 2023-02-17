#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    printf("Un petit programme affichant un texte quelconque\n");
    int i=execl("/bin/ls","ls","-l","-a",NULL);
    printf("Texte d'après execl\n");
    return 0;
}