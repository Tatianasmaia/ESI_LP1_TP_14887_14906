#include <stdio.h>
#include "Header.h"
#pragma warning(disable : 4996)

/*Fun��o que l� o ficheiro com a informa��o das provas*/
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

//Concorrentes com prova v�lida (>0)
int NrConcorrentesProvaValida(Prova provas[], int idProvasValidas[]) {

	int j = 0;
	for (int i = 0; i < 6; i++) {

		//for (int j = 0; j < 1; j++) {

			if (provas[i].idConcorrente != idProvasValidas[j]) {
				idProvasValidas[j] = provas[i].idConcorrente;
				
				j++;
			}
		
	}
	

	for (int i = 0; i < j; i++) {
			printf("%d", idProvasValidas[j]);
	}

	








	/*int k = 0;

	

	for (int i = 0; i < 10; i++) {


		if (provas[i].tempo > 0) {


			for (int j = 0; j < 2; j++) {

				if (provas[i].idConcorrente != idProvasValidas[j]) {
					idProvasValidas[j] = provas[i].idConcorrente;
					k++;
				}
			}

			

		}
		else {
			printf("prova invalida %d", provas[i].idConcorrente);
		}
	}
	


	for (int i = 0; i < k; i++) {
		printf("%d \n", idProvasValidas[i]);
	}*/

}