#include <stdio.h>
#include "Header.h"
#pragma warning(disable : 4996)

/*Função que lê o ficheiro com a informação dos concorrentes*/
void leFicheiroConcorrentes(Concorrente concorrentes[]) {

    char nome[50], marca[50];
    int id;

    FILE* f = fopen("DadosConcorrentes.txt", "r");
    int j = 0;

    while (!feof(f)) {

        fscanf(f, "%d;%[^;];%[a-zA-z]+\n", &id, nome, marca);

        concorrentes[j].id = id;
        strcpy(concorrentes[j].nome, nome);
        strcpy(concorrentes[j].marca, marca);
        
        j++;

    }
    fclose(f);

    for (int i = 0; i < j; i++) {
        printf("%d %s %s\n", concorrentes[i].id, concorrentes[i].nome, concorrentes[i].marca);
    }
}