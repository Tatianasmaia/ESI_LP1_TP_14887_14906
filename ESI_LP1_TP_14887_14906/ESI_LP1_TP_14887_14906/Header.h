#pragma once
/*Estrutura para guardar a informação dos concorrentes*/
typedef struct concorrente {

	int id;
	char nome[50];
	char marca[50];

}Concorrente;

/*Estrutura para guardar a informação das distancias das etapas*/
typedef struct distancia {

	char inicio[3];
	char fim[3];
	float distancia;
	int somaTempo;
	float media;

}Distancia;

/*Estrutura para guardar a informação das etapas (cada linha do ficheiro de uma prova)*/
typedef struct etapa {

	int idConcorrente;
	char etapa1[3];
	char etapa2[3];
	int tempo;
	

}Etapa;

/*Estrutura para guardar a informação de uma prova*/
typedef struct prova {

	int tempoTotal;
	float velocidadeMedia;
	Etapa etapas[3];

}Prova;

/*Estrutura para guardar o número de etapas e concorrentes da prova*/
typedef struct detalhesProva {

	
	int nEtapas;
	int nConcorrentes;

}DetalhesProva;

typedef struct tempoEtapa {

	int tempo;
	char etapa[3];

}TempoEtapa;

//Funções
void leFicheiroConcorrentes(concorrentes);
void leFicheiroEtapas(etapas);
void leFicheiroProvas(provas, detalhes);

int verificarProvasValidas(provas, provasValidas, nConcorrentesT, nEtapas);
void listagemTempoProva(provasValidas, nEtapas, nConcorrentes);
void concorrentesRapidos(provasValidas, nEtapas, nConcorrentes);
void tempoMinimoProva(provas, etapas, nConcorrentes, nEtapas);
void velocidadeMedia(provasValidas, etapas, nConcorrentes, nEtapas);