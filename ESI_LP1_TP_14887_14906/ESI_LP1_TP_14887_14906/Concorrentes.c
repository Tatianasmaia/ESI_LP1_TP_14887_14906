#include <stdio.h>
#include <string.h>
#include "Header.h"
#pragma warning(disable : 4996)

/*Fun��o que l� o ficheiro com a informa��o dos concorrentes*/
void leFicheiroConcorrentes(Concorrente concorrentes[]) {

    char nome[50], marca[50];
    int id, j = 0;

    FILE* f = fopen("DadosConcorrentes.txt", "r");

	if (f == NULL)
	{
		printf("Erro na abertura do ficheiro\n");
		return;
	}
    

    while (!feof(f)) {

        fscanf(f, "%d;%[^;];%[a-zA-z]+\n", &id, nome, marca);

        concorrentes[j].id = id;
        strcpy(concorrentes[j].nome, nome);
        strcpy(concorrentes[j].marca, marca);
        
        j++;

    }
    fclose(f);

    /*for (int i = 0; i < j; i++) {
        printf("%d %s %s\n", concorrentes[i].id, concorrentes[i].nome, concorrentes[i].marca);
    }*/
}

//Exerc�cio 6 - Apresenta��o do concorrente mais r�pido e mais lento a efetuar uma prova v�lida
//Nota: � necess�rio executar primeiro a fun��o listagemTempoProva() pois � nessa fun��o que s�o atribu�dos os valores � vari�vel "tempoTotal" de cada concorrente
void concorrenteRapidoLento(Prova provasValidas[], int nEtapas, int nConcorrentes) {

	int maiorTempo, menorTempo;

	//Atriubui o tempo total da posi��o 0 do array de provasValidas �s vari�veis
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

	printf("Tempo do concorrente mais rapido: %d\n", maiorTempo);
	printf("Tempo do concorrente mais lento: %d\n", menorTempo);
}

//Exerc�cio 8 - Calculo das velocidades medias de toda a prova
void velocidadeMedia(Prova provasValidas[], Distancia etapas[], int nConcorrentes, int nEtapas) {

	int distanciaTotal = 0;

	//Soma a dist�ncia total da prova
	for (int i = 0; i < nEtapas; i++) {
		distanciaTotal += etapas[i].distancia;
	}

	//Convers�o de milisegundos para minutos dos tempos totais
	for (int i = 0; i < nEtapas; i++) {
		provasValidas[i].tempoTotal = provasValidas[i].tempoTotal / 3600;
	}

	//Calcula a velocidade m�dia dos concorrentes
	for (int j = 0; j < nConcorrentes; j++) {
		provasValidas[j].velocidadeMedia = (float)distanciaTotal / provasValidas[j].tempoTotal;
		printf("\nVelocidade media do concorrente %d: %.2f", provasValidas[j].etapas[j].idConcorrente, provasValidas[j].velocidadeMedia);
	}
}