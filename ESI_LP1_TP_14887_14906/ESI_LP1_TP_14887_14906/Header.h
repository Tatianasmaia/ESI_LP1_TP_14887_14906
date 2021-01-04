#pragma once
/*Estrutura para guardar a informação dos concorrentes*/
typedef struct concorrente {

	int id;
	char nome[50];
	char marca[50];

}Concorrente;

/*Estrutura para guardar a informação das etapas*/
typedef struct etapa {

	char inicio[50];
	char fim[50];
	float distancia;

}Etapa;

/*Estrutura para guardar a informação de uma prova*/
typedef struct prova {

	int idConcorrente;
	char etapa1[50];
	char etapa2[50];
	int tempo;
	int nEtapas;
	int nConcorrentes;

}Prova;