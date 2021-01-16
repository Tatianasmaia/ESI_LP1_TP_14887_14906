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

	if (f == NULL)
	{
		printf("Erro na abertura do ficheiro\n");
		return;
	}

	//Lê a primeira linha do ficheiro
	fscanf(f, "%d;%d\n", &nEtapas, &nConcorrentes);

	detalhes[0].nEtapas = nEtapas;
	detalhes[0].nConcorrentes = nConcorrentes;

	
	for (int i = 0; i < nConcorrentes; i++)
	{

		while (!feof(f)) {

			fscanf(f, "%d;%[^;];%[^;];%d\n", &idConcorrente, etapa1, etapa2, &tempo);

			if (idConcorrente == i+1)
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
		
		//Percorre o ficheiro para todos os id's
		fseek(f, 2, SEEK_SET);
	}

	fclose(f);

	/*for (int i = 0; i < nConcorrentes; i++) {

		for (int k = 0; k < nEtapas; k++) {
			printf("%d %s %s %d\n", provas[i].etapas->idConcorrente, provas[i].etapas[k].etapa1, provas[i].etapas[k].etapa2, provas[i].etapas[k].tempo);
		}
	}*/
}

//Verifica os concorrentes com prova válida (tempo > 0)
int verificarProvasValidas(Prova provas[], Prova provasValidas[], ProvasInvalidas provasInvalidas[], int nConcorrentesT, int nEtapas) {


	int k = 0, z = 0, l = 0, nProvasV = 0;
	Etapa novaEtapa;

	//Percorre o array de provas
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
		//Caso a prova seja inválida
		else{

			//Percorre o array de provas inválidas e atribui os id's dos concorrentes com prova inválida
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

	OrdenarTempos temposOrdenados[10] = { 0 };
	int tempoTotal = 0, i = 0, auxId = 0, auxTempo = 0;

	
	//Percorre o array de provasValidas para calcular o tempo total das provas
	for (i = 0; i < nConcorrentes; i++) {
		for (int j = 0; j < nEtapas; j++) {
				
			tempoTotal += provasValidas[i].etapas[j].tempo;
		}

		provasValidas[i].tempoTotal = tempoTotal;
		tempoTotal = 0;
	}

	//Atribuição de valores ao array temposOrdenados
	for (int i = 0; i < nConcorrentes; i++) {

		temposOrdenados[i].id = provasValidas[i].etapas[i].idConcorrente;
		temposOrdenados[i].tempoTotal = provasValidas[i].tempoTotal;

	}

	//Ordena por ordem decrescente os tempos totais das provas
	for (int i = 0; i < nConcorrentes; i++) {
		for (int j = i + 1; j < nConcorrentes; j++) {

			if (temposOrdenados[i].tempoTotal < temposOrdenados[j].tempoTotal) {

				auxId = temposOrdenados[i].id;
				auxTempo = temposOrdenados[i].tempoTotal;


				temposOrdenados[i].tempoTotal = temposOrdenados[j].tempoTotal;
				temposOrdenados[i].id = temposOrdenados[j].id;

				temposOrdenados[j].tempoTotal = auxTempo;
				temposOrdenados[j].id = auxId;

			}
		}
	}

	
	printf("\nTempos de provas validas ordenados por ordem decrescente:\n");
	for (i = 0; i < nConcorrentes; i++) {
		printf("%d %d\n", temposOrdenados[i].id, temposOrdenados[i].tempoTotal);
	}
}

//9 - Tabela classificativa da prova
void tabelaClassificativa(Concorrente concorrentes[], Prova provasValidas[], ProvasInvalidas provasInvalidas[], int nConcorrentesT, int nConcorrentesPV, int nEtapas) {

	LeaderBoard concorrente[10] = { 0 };
	int auxId, auxTempo, nConcorrentesPI;
	char auxNome[20], auxMarca[20];

	//Atribuição de valores ao array concorrente 
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

	//Atribui a posicao do concorrente a cada concorrente de acordo com o seu tempo de prova
	for (int i = 0; i < nConcorrentesPV; i++) {
		concorrente[i].rank = i + 1;
	}

	//Calculo do número de concorrentes com prova inválida
	nConcorrentesPI = nConcorrentesT - nConcorrentesPV;

	//Atribui a informação dos concorrentes (nome e marca) com provas inválidas de acordo com o seu id
	for (int i = 0; i < nConcorrentesPI ; i++) {
		for (int j = 0; j < nConcorrentesT; j++) {
			if (provasInvalidas[i].id == concorrentes[j].id) {
				strcpy(provasInvalidas[i].marca, concorrentes[j].marca);
				strcpy(provasInvalidas[i].nome, concorrentes[j].nome);
			}
		}
	}

	//Ordena os ids dos concorrentes com a prova inválida (por ordem crescente)
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

	//Percorre o array concorrente para calcular a diferença do tempo de prova com o concorrente anterior
	for (int i = 1; i <= nConcorrentesPV; i++) {
		
		concorrente[i].difAnterior = concorrente[i].tempoProva - concorrente[i-1].tempoProva;
	}

	//Percorre o array concorrente para calcular a diferença do tempo de prova com o concorrente em primeiro lugar
	for (int i = 1; i <= nConcorrentesPV; i++) {

		concorrente[i].difLider = concorrente[i].tempoProva - concorrente[0].tempoProva;
	}

	//Mostra a tabela na consola
	printf("Posicao | Numero | Nome | Carro | Tempo de Prova | Di. Ant. | Di. Ldr.\n");

	//Percorre e mostra o array concorrente (que contém apenas concorrentes com prova válida)
	for (int i = 0; i < nConcorrentesPV; i++) {
		printf(" %d | %d | %s | %s | %d | %d | %d\n", concorrente[i].rank, concorrente[i].id, concorrente[i].nome, concorrente[i].marca, concorrente[i].tempoProva, concorrente[i].difAnterior, concorrente[i].difLider);
	}
	//Percorre e mostra o array com os concorrentes com provas inválidas
	for (int i = 0; i < nConcorrentesPI; i++) {
		printf("   | %d | %s | %s | \n", provasInvalidas[i].id, provasInvalidas[i].nome, provasInvalidas[i].marca);
	}

	//Função que guarda num ficheiro binário os concorrentes com provas válidas e inválidas
	guardarLeaderBoard(concorrente, provasInvalidas, nConcorrentesPI, nConcorrentesPV);
}

//Função que guarda num ficheiro binário os concorrentes com provas válidas e inválidas
void guardarLeaderBoard(LeaderBoard concorrente[], ProvasInvalidas provasInvalidas[], int nConcorrentesPI, int nConcorrentesPV)
{

	FILE* f;

	f = fopen("LeaderBoard.bin", "wb"); 
	
	if (f == NULL) 
	{
		printf("Erro na abertura do ficheiro\n");
		return;
	}
	
	//Escreve no ficheiro
	fwrite(&concorrente, sizeof(LeaderBoard), nConcorrentesPV, f);
	fwrite(&provasInvalidas, sizeof(ProvasInvalidas), nConcorrentesPI, f);

	
	fclose(f);
}