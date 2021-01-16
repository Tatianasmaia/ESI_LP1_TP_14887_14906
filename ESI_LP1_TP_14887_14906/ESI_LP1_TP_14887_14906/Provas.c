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
			printf("%d %s %s %d\n", provas[i].etapas->idConcorrente, provas[i].etapas[k].etapa1, provas[i].etapas[k].etapa2, provas[i].etapas[k].tempo);
		}
	}*/
}

//Concorrentes com prova válida (tempo > 0)
int verificarProvasValidas(Prova provas[], Prova provasValidas[], ProvasInvalidas provasInvalidas[], int nConcorrentesT, int nEtapas) {


	int k = 0, z = 0, l = 0, nProvasV = 0;
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
		else{

			for (int j = 0; j < nEtapas; j++) {

				provasInvalidas[l].id = provas[i].etapas[j].idConcorrente;
			}
			l++;

		}
		k = 0;
	}
	

	return nProvasV;
}

//Exercício 4 - Listagem, ordenada por ordem decrescente de tempo da prova, de todos os concorrentes que efetuaram uma prova válida
void listagemTempoProva(Prova provasValidas[], int nEtapas, int nConcorrentes) {

	int tempoTotal = 0, i = 0, aux = 0;

	/*for (int i = 0; i < nConcorrentes; i++) {

		for (int k = 0; k < nEtapas; k++) {
			printf("PV %d %s %s %d\n", provasValidas[i].etapas->idConcorrente, provasValidas[i].etapas[k].etapa1, provasValidas[i].etapas[k].etapa2, provasValidas[i].etapas[k].tempo);
		}
	}*/

	//Percorre o array de provasValidas para calcular o tempo total de uma prova
	for (i = 0; i < nConcorrentes; i++) {
		for (int j = 0; j < nEtapas; j++) {
				
			tempoTotal += provasValidas[i].etapas[j].tempo;
		}

		provasValidas[i].tempoTotal = tempoTotal;
		//printf("%d %d\n", provasValidas[i].etapas[i].idConcorrente, provasValidas[i].tempoTotal);
		tempoTotal = 0;
	}
	

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
		printf("%d %d\n", provasValidas[i].etapas[i].idConcorrente, provasValidas[i].tempoTotal);
	}
}

//9 - Tabela classificativa da prova
void tabelaClassificativa(Concorrente concorrentes[], Prova provasValidas[], ProvasInvalidas provasInvalidas[], int nConcorrentesT, int nConcorrentesPV, int nEtapas) {

	LeaderBoard concorrente[10] = { 0 };
	int m = nConcorrentesT; //linhas
	int n=7; //colunas
	int auxId, auxTempo, nConcorrentesPI;
	char auxNome[20], auxMarca[20];

	//Atribui ao array concorrente os concorrentes do ar
	for (int i = 0; i < nConcorrentesPV; i++) {
		
		if (provasValidas[i].etapas[i].idConcorrente == concorrentes[i].id) {
			concorrente[i].id = concorrentes[i].id;
			strcpy(concorrente[i].nome, concorrentes[i].nome);
			strcpy(concorrente[i].marca, concorrentes[i].marca);
			concorrente[i].tempoProva = provasValidas[i].tempoTotal;

		}
	}

	//Ordena o array de concorrente de acordo com os tempos de prova
	for (int i = 0; i < nConcorrentesPV; i++) {
		for (int j = i + 1; j < nConcorrentesPV; j++) {

			if (concorrente[i].tempoProva > concorrente[j].tempoProva)
			{
				auxId = concorrente[i].id;
				strcpy(auxNome , concorrente[i].nome);
				strcpy(auxMarca, concorrente[i].marca);
				auxTempo = concorrente[i].tempoProva;


				concorrente[i].tempoProva = concorrente[j].tempoProva;
				concorrente[i].id = concorrente[j].id;
				strcpy(concorrente[i].nome, concorrente[j].nome);
				strcpy(concorrente[i].marca, concorrente[j].marca);

				concorrente[j].tempoProva = auxTempo;
				concorrente[j].id = auxId;
				strcpy(concorrente[j].nome, auxNome);
				strcpy(concorrente[j].marca, auxMarca);

			}
		}

	}

	for (int i = 0; i < nConcorrentesPV; i++) {
		concorrente[i].rank = i + 1;
	}

	nConcorrentesPI = nConcorrentesT - nConcorrentesPV;

	//Atribui a informação dos concorrentes com provas inválidas de acordo com o seu id
	for (int i = 0; i < nConcorrentesPI ; i++) {
		for (int j = 0; j < nConcorrentesT; j++) {
			if (provasInvalidas[i].id == concorrentes[j].id) {
				strcpy(provasInvalidas[i].marca, concorrentes[j].marca);
				strcpy(provasInvalidas[i].nome, concorrentes[j].nome);
			}
		}
	}

	//Ordena os ids dos concorrentes com a prova inválida
	for (int i = 0; i < nConcorrentesPI; i++) {
		for (int j = i + 1; j < nConcorrentesPI; j++) {

			if (provasInvalidas[i].id > provasInvalidas[j].id)
			{
				auxId = provasInvalidas[i].id;
				strcpy(auxNome, provasInvalidas[i].nome);
				strcpy(auxMarca, provasInvalidas[i].marca);

				provasInvalidas[i].id = provasInvalidas[j].id;
				strcpy(provasInvalidas[i].marca, provasInvalidas[j].marca);
				strcpy(provasInvalidas[i].nome, provasInvalidas[j].nome);

				provasInvalidas[j].id = auxId;
				strcpy(provasInvalidas[i].marca, auxMarca);
				strcpy(provasInvalidas[j].nome, auxNome);

			}
		}

	}


	for (int i = 1; i <= nConcorrentesPV; i++) {
		
		concorrente[i].difAnterior = concorrente[i].tempoProva - concorrente[i-1].tempoProva;
	}
	for (int i = 1; i <= nConcorrentesPV; i++) {

		concorrente[i].difLider = concorrente[i].tempoProva - concorrente[0].tempoProva;
	}

	//Printf da tabela
	printf("Posicao | Numero | Nome | Carro | Tempo de Prova | Di. Ant. | Di. Ldr.\n");

	for (int i = 0; i < nConcorrentesPV; i++) {
		printf(" %d | %d | %s | %s | %d | %d | %d\n", concorrente[i].rank, concorrente[i].id, concorrente[i].nome, concorrente[i].marca, concorrente[i].tempoProva, concorrente[i].difAnterior, concorrente[i].difLider);
	}

	for (int i = 0; i < nConcorrentesPI; i++) {
		printf("   | %d | %s | %s | \n", provasInvalidas[i].id, provasInvalidas[i].nome, provasInvalidas[i].marca);
	}
	guardarLeaderBoard(concorrente, provasInvalidas, nConcorrentesPI, nConcorrentesPV);
}

void guardarLeaderBoard(LeaderBoard concorrente[], ProvasInvalidas provasInvalidas[], int nConcorrentesPI, int nConcorrentesPV)
{

	FILE* f;

	
	f = fopen("LeaderBoard.bin", "wb"); 
	

	if (f == NULL) 
	{
		printf("Erro na abertura do ficheiro\n");
		return;
	}
	
	fwrite(&concorrente, sizeof(LeaderBoard), nConcorrentesPV, f);
	fwrite(&provasInvalidas, sizeof(ProvasInvalidas), nConcorrentesPI, f);

	
	fclose(f);
}