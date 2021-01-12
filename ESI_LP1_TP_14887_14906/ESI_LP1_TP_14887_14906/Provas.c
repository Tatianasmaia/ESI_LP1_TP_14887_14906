#include <stdio.h>
#include "Header.h"
#pragma warning(disable : 4996)


/*Função que lê o ficheiro com a informação das provas*/
int leFicheiroProvas(Prova provas[], DetalhesProva detalhes[]) {

	int nEtapas = 0, nConcorrentes = 0;
	char etapa1[50], etapa2[50];
	int  idConcorrente, tempo;
	int j = 0;
	Etapa novaEtapa;

	FILE* f = fopen("DadosProva.txt", "r");

	fscanf(f, "%d;%d\n", &nEtapas, &nConcorrentes);
	detalhes[0].nEtapas = nEtapas;
	detalhes[0].nConcorrentes = nConcorrentes;

	
	
	for (int i = 1; i <= nConcorrentes; i++)
	{


		while (!feof(f)) {


			fscanf(f, "%d;%[^;];%[^;];%d\n", &idConcorrente, etapa1, etapa2, &tempo);

			if (idConcorrente == i)
			{
				
				novaEtapa.idConcorrente = idConcorrente;
				strcpy(novaEtapa.etapa1, etapa1);
				strcpy(novaEtapa.etapa2, etapa2);
				novaEtapa.tempo = tempo;

				provas[i].etapas[j] = novaEtapa;

				j++;
			}
			
		}

		j = 0;
		
		fseek(f, 2, SEEK_SET);
	}


	fclose(f);

	for (int i = 1; i < nEtapas; i++) {

		for (int k = 0; k < nEtapas; k++) {
			printf("%d %s %s %d\n", provas[i].etapas->idConcorrente, provas[i].etapas[k].etapa1, provas[i].etapas[k].etapa2, provas[i].etapas[k].tempo);
		}
	}

}
//
////Concorrentes com prova válida (>0)
//int NrConcorrentesProvaValida(Prova provas[], int idProvasValidas[]) {
//
//	int j = 0;
//	for (int i = 0; i < 6; i++) {
//
//		//for (int j = 0; j < 1; j++) {
//
//			if (provas[i].idConcorrente != idProvasValidas) {
//				idProvasValidas[j] = provas[i].idConcorrente;
//				
//				j++;
//			}
//		
//	}
//	
//
//	for (int i = 0; i < j; i++) {
//			printf("%d", idProvasValidas[j]);
//	}
//