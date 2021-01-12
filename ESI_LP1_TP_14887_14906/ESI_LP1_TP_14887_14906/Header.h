#pragma once
/*Estrutura para guardar a informação dos concorrentes*/
typedef struct concorrente {

	int id;
	char nome[50];
	char marca[50];

}Concorrente;

/*Estrutura para guardar a informação das distancias das etapas*/
typedef struct distancia {

	char inicio[50];
	char fim[50];
	float distancia;

}Distancia;

/*Estrutura para guardar a informação das etapas (cada linha do ficheiro de uma prova)*/
typedef struct etapa {

	int idConcorrente;
	char etapa1[50];
	char etapa2[50];
	int tempo;

}Etapa;

/*Estrutura para guardar a informação de uma prova*/
typedef struct prova {

	int idConcorrente;

	Etapa etapas[3];

}Prova;

/*Estrutura para guardar o número de etapas e concorrentes da prova*/
typedef struct detalhesProva {

	
	int nEtapas;
	int nConcorrentes;

}DetalhesProva;


//Funções
void leFicheiroConcorrentes();
void leFicheiroEtapas();
int leFicheiroProvas();