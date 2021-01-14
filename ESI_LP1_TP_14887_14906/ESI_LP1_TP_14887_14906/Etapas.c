#include <stdio.h>
#include <string.h>
#include "Header.h"
#pragma warning(disable : 4996)

///*Função que lê o ficheiro com a informação das distâncias das etapas*/
void leFicheiroEtapas(Distancia etapas[]) {

	char inicio[3], fim[3];
	float distancia;

	FILE* f = fopen("DistanciaEtapas.txt", "r");

    int j = 0;
	while (!feof(f)) {

		fscanf(f, "%[^;];%[^;];%f\n", inicio, fim, &distancia);

        strcpy(etapas[j].inicio, inicio);
        strcpy(etapas[j].fim, fim);
		etapas[j].distancia = distancia;
        j++;

	}

	fclose(f);

	/*for (int i = 0; i < j; i++) {
		printf("%s %s %f\n", etapas[i].inicio, etapas[i].fim, etapas[i].distancia);
	}*/
}

//5 - Calculo da média de tempo por cada etapa
void mediaEtapas(Prova provasValidas[], Distancia etapas[], int nEtapas, int nConcorrentes) {

	float media;

	//Calcula a soma dos tempos de cada etapa
	for (int i = 0; i < nConcorrentes; i++) {
		for (int j = 0; j < nEtapas; j++) {
			for (int k = 0; k < nEtapas; k++) {

				if (strcmp(provasValidas[i].etapas[j].etapa1, etapas[k].inicio) == 0) {

					etapas[k].somaTempo += provasValidas[i].etapas[j].tempo;
				}
			}
		}
	}

	//Calcula a media dos tempos obtido em cada etapa
	for (int i = 0; i < nEtapas; i++) {
		etapas[i].media = (float)etapas[i].somaTempo / nEtapas;
	}


	for (int i = 0; i < nEtapas; i++) {

		if (strcmp(etapas[i].inicio, "P") == 0) {
			printf("Media etapa %s - %s: %f \n", etapas[i].inicio, etapas[i].fim, etapas[i].media);
		}
	}

	for (int i = 0; i < nEtapas; i++) {

		if (strcmp(etapas[i].inicio, "E1") == 0) {
			printf("Media etapa %s - %s: %f \n", etapas[i].inicio, etapas[i].fim, etapas[i].media);
		}
	}

	for (int i = 0; i < nEtapas; i++) {

		if (strcmp(etapas[i].inicio, "E2") == 0) {
			printf("Media etapa %s - %s: %f \n", etapas[i].inicio, etapas[i].fim, etapas[i].media);
		}
	}
}

//Calcula o tempo minimo de cada etapa
void tempoMinimoProva(Prova provas[], Distancia etapas[], int nConcorrentes, int nEtapas) {

	TempoEtapa somaEtapas[3] = { 0 };
	int soma = 0;
	int tempoMenor = 100000;

	for (int i = 0; i < nEtapas; i++) {
		somaEtapas[i].tempo = provas[0].etapas[i].tempo;
		strcpy(somaEtapas[i].etapa, provas[0].etapas[i].etapa1);

	}


	for (int i = 0; i < nConcorrentes; i++) {
		for (int j = 0; j < nEtapas; j++) {
			for (int k = 0; k < nEtapas; k++) {

				if (strcmp(provas[i].etapas[j].etapa1, somaEtapas[k].etapa) == 0) {

					if (provas[i].etapas[j].tempo < somaEtapas[k].tempo && provas[i].etapas[j].tempo != 0) {

						somaEtapas[k].tempo = provas[i].etapas[j].tempo;
							
					}
				}
			}
		}
	}

	for (int i = 0; i < nEtapas; i++) {
		soma = soma + somaEtapas[i].tempo;
		printf("\nTempo minimo de uma prova: %d", somaEtapas[i].tempo);
	}


	printf("Tempo minimo de uma prova: %d", soma);
}