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
	int somaTempo;
	float media;

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
	float velocidadeMedia;
	Etapa etapas[3];

}Prova;

/*Estrutura para guardar o n�mero de etapas e concorrentes da prova*/
typedef struct detalhesProva {

	
	int nEtapas;
	int nConcorrentes;

}DetalhesProva;

/*Estrutura para guardar o tempo minimo de cada etapa*/
typedef struct tempoEtapa {

	int tempo;
	char etapa[3];

}TempoEtapa;

typedef struct leaderBoard {

	int rank;
	int id;
	char nome[20];
	char marca[20];
	int tempoProva;
	int difAnterior;
	int difLider;

}LeaderBoard;

typedef struct provasInvalidas {

	int id;
	char nome[20];
	char marca[20];
}ProvasInvalidas;


//Fun��es
void leFicheiroConcorrentes(concorrentes);
void leFicheiroEtapas(etapas);
void leFicheiroProvas(provas, detalhes);

int verificarProvasValidas(provas, provasValidas, nConcorrentesT, nEtapas);
void listagemTempoProva(provasValidas, nEtapas, nConcorrentes);
void concorrenteRapidoLento(provasValidas, nEtapas, nConcorrentes);
void tempoMinimoProva(provas, nConcorrentes, nEtapas);
void velocidadeMedia(provasValidas, etapas, nConcorrentes, nEtapas);
void guardarLeaderBoard(concorrente, provasInvalidas, nConcorrentesPI, nConcorrentesPV);