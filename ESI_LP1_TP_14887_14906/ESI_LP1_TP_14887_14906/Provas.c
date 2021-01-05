#include <stdio.h>
#include "Header.h"
#pragma warning(disable : 4996)

/*Função que lê o ficheiro com a informação das provas*/
int leFicheiroProvas(Prova provas[], DetalhesProva detalhes[]) {

	int nEtapas = 0, nConcorrentes = 0;
	char etapa1[50], etapa2[50];
	int  idConcorrente, tempo;
	int j = 0;

	FILE* f = fopen("DadosProva.txt", "r");

	fscanf(f, "%d;%d\n", &nEtapas, &nConcorrentes);
	detalhes[0].nEtapas = nEtapas;
	detalhes[0].nConcorrentes = nConcorrentes;
	
	while (!feof(f)) {

		
		fscanf(f, "%d;%[^;];%[^;];%d\n", &idConcorrente, &etapa1, &etapa2, &tempo);

		
		provas[j].idConcorrente = idConcorrente;
		strcpy(provas[j].etapa1, etapa1);
		strcpy(provas[j].etapa2, etapa2);
		provas[j].tempo = tempo;
		j++;

	}

	fclose(f);

	for (int i = 0; i < j; i++) {
		printf("%d %s %s %d\n", provas[i].idConcorrente, provas[i].etapa1, provas[i].etapa2, provas[i].tempo);
	}

}

int CalculaNrConcorrentes(Prova provas[]) {

	
}