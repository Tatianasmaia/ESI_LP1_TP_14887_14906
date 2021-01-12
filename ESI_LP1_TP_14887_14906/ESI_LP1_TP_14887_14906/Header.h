#pragma once
/*Estrutura para guardar a informa��o dos concorrentes*/
typedef struct concorrente {

	int id;
	char nome[50];
	char marca[50];

}Concorrente;

/*Estrutura para guardar a informa��o das distancias das etapas*/
typedef struct distancia {

	char inicio[3];
	char fim[3];
	float distancia;

}Distancia;

/*Estrutura para guardar a informa��o das etapas (cada linha do ficheiro de uma prova)*/
typedef struct etapa {

	int idConcorrente;
	char etapa1[3];
	char etapa2[3];
	int tempo;
	

}Etapa;

/*Estrutura para guardar a informa��o de uma prova*/
typedef struct prova {

	int tempoTotal;
	Etapa etapas[3];

}Prova;

/*Estrutura para guardar o n�mero de etapas e concorrentes da prova*/
typedef struct detalhesProva {

	
	int nEtapas;
	int nConcorrentes;

}DetalhesProva;



//Fun��es
void leFicheiroConcorrentes(concorrentes);
void leFicheiroEtapas(etapas);
void leFicheiroProvas(provas, detalhes);

void ProvasValida(provas, idProvasValidas, nConcorrentes, nEtapas);
void ListagemTempoProva(idProvasValidas);