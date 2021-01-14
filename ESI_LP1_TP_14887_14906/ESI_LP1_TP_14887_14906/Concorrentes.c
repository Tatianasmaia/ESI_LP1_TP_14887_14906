#include <stdio.h>
#include <string.h>
#include "Header.h"
#pragma warning(disable : 4996)

/*Fun��o que l� o ficheiro com a informa��o dos concorrentes*/
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

//Exerc�cio 6 - Apresenta��o do concorrente mais r�pido e mais lento a efetuar uma prova v�lida
void concorrentesRapidos(Prova provasValidas[], int nEtapas, int nConcorrentes) {

	int maiorTempo, menorTempo;

	maiorTempo = provasValidas[0].tempoTotal;
	menorTempo = provasValidas[0].tempoTotal;

	//Calcula o maior tempo total de uma prova v�lida
	for (int i = 1; i < nConcorrentes; i++) {
		if (provasValidas[i].tempoTotal > maiorTempo) {
			maiorTempo = provasValidas[i].tempoTotal;
		}
	}

	//Calcula o menor tempo total de uma prova v�lida
	for (int i = 1; i < nConcorrentes; i++) {
		if (provasValidas[i].tempoTotal < menorTempo) {
			menorTempo = provasValidas[i].tempoTotal;
		}
	}

	printf("Tempo maior: %d", maiorTempo);
	printf("Tempo menor: %d", menorTempo);
}

void velocidadeMedia(Prova provasValidas[], Distancia etapas[], int nConcorrentes, int nEtapas) {

	int distanciaTotal = 0;

	for (int i = 0; i < nEtapas; i++) {
		distanciaTotal += etapas[i].distancia;
	}

	//Convers�o de milisegundos para segundos
	for (int i = 0; i < nEtapas; i++) {
		provasValidas[i].tempoTotal = provasValidas[i].tempoTotal / 3600;
	}

	for (int j = 0; j < nConcorrentes; j++) {
		provasValidas[j].velocidadeMedia = (float)distanciaTotal / provasValidas[j].tempoTotal;
		printf("\nVelocidade media do concorrente %d: %f", provasValidas[j].etapas[j].idConcorrente, provasValidas[j].velocidadeMedia);
	}

}