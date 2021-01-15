#include <stdio.h>
#include <string.h>
#include "Header.h"
#pragma warning(disable : 4996)


/*Função que lê o ficheiro com a informação das provas*/
void leFicheiroProvas(Prova provas[], DetalhesProva detalhes[]) {

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

				provas[i-1].etapas[j] = novaEtapa;

				j++;
			}
		}
		j = 0;
		
		fseek(f, 2, SEEK_SET);
	}

	fclose(f);

	/*for (int i = 0; i < nConcorrentes; i++) {

		for (int k = 0; k < nEtapas; k++) {
			printf("Aqui%d %s %s %d\n", provas[i].etapas->idConcorrente, provas[i].etapas[k].etapa1, provas[i].etapas[k].etapa2, provas[i].etapas[k].tempo);
		}
	}*/
}

//Concorrentes com prova válida (tempo > 0)
int verificarProvasValidas(Prova provas[], Prova provasValidas[], int nConcorrentesT, int nEtapas) {


	int k = 0, z = 0, nProvasV = 0;
	Etapa novaEtapa;


	for (int i = 0 ; i < nConcorrentesT; i++) {

		//Calcula se todas as provas são válidas
		if (provas[i].etapas[i].idConcorrente == i+1) {
		
			for (int j = 0; j < nEtapas; j++) {

				if (provas[i].etapas[j].tempo > 0) {
					k++;
					
				}
			}
		}

		//Se todas as etapas forem válidas
		if (k == nEtapas) {
			
				for (int j = 0; j < nEtapas; j++) {

					
					novaEtapa.idConcorrente = provas[i].etapas[j].idConcorrente;
					strcpy(novaEtapa.etapa1, provas[i].etapas[j].etapa1);
					strcpy(novaEtapa.etapa2, provas[i].etapas[j].etapa2);
					novaEtapa.tempo = provas[i].etapas[j].tempo;

					provasValidas[z].etapas[j] = novaEtapa;

				}
				z++;
			
			nProvasV++;
		}

		k = 0;
	}

	return nProvasV;
}

//Ex 4 - Listagem, ordenada por ordem decrescente de tempo da prova, de todos os concorrentes que efetuaram uma prova válida
void listagemTempoProva(Prova provasValidas[], int nEtapas, int nConcorrentes) {

	int tempoTotal = 0, i = 0, aux = 0;

	/*for (int i = 0; i < nConcorrentes; i++) {

		for (int k = 0; k < nEtapas; k++) {
			printf("PV %d %s %s %d\n", provasValidas[i].etapas->idConcorrente, provasValidas[i].etapas[k].etapa1, provasValidas[i].etapas[k].etapa2, provasValidas[i].etapas[k].tempo);
		}
	}*/

	//if (provasValidas[i].etapas->idConcorrente == i + 1) {

		for (i = 0; i < nConcorrentes; i++) {
			for (int j = 0; j < nEtapas; j++) {
				
				tempoTotal += provasValidas[i].etapas[j].tempo;
			}

			provasValidas[i].tempoTotal = tempoTotal;
			tempoTotal = 0;
		}
	//}

	//Ordena por ordem decrescente os tempos totais das provas
	for (int cont = 1; cont < nConcorrentes; cont++) {
		for (i = 0; i < nEtapas - 1; i++) {
			if (provasValidas[i].tempoTotal < provasValidas[i + 1].tempoTotal) {
				aux = provasValidas[i].tempoTotal;
				provasValidas[i].tempoTotal = provasValidas[i + 1].tempoTotal;
				provasValidas[i + 1].tempoTotal = aux;
			}
		}
	}

	printf("\nTempos de provas validas ordenados por ordem decrescente:\n");
	for (i = 0; i < nConcorrentes; i++) {
		printf("%d\n", provasValidas[i].tempoTotal);
	}
}

//9 - Tabela classificativa da prova
void tabelaClassificativa() {

}