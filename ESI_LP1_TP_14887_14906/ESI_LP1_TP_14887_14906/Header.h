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

/*Estrutura para guardar o tempo minimo de cada etapa*/
typedef struct tempoEtapa {

	int tempo;
	char etapa[3];

}TempoEtapa;

/*Estrutura para guadar os concorrentes para a leaderboard*/
typedef struct leaderBoard {

	int rank;
	int id;
	char nome[20];
	char marca[20];
	int tempoProva;
	int difAnterior;
	int difLider;

}LeaderBoard;

/*Estrutura para guardar as provas inválidas*/
typedef struct provasInvalidas {

	int id;
	char nome[20];
	char marca[20];

}ProvasInvalidas;

/*Estrutura para guardar os tempos totais de provas ordenados*/
typedef struct ordenarTempos {
	int id;
	int tempoTotal;
}OrdenarTempos;


//Funções
void leFicheiroConcorrentes(concorrentes);
void leFicheiroEtapas(etapas);
void leFicheiroProvas(provas, detalhes);

int verificarProvasValidas(provas, provasValidas, provasInvalidas, nConcorrentesT, nEtapas);
void listagemTempoProva(provasValidas, nEtapas, nConcorrentesPV);
void mediaEtapas(provasValidas, etapas, nEtapas, nConcorrentesPV);
void concorrenteRapidoLento(provasValidas, nEtapas, nConcorrentesPV);
void tempoMinimoProva(provas, nConcorrentesT, nEtapas);
void velocidadeMedia(provasValidas, etapas, nConcorrentesPV, nEtapas);
void tabelaClassificativa(concorrentes, provasValidas, provasInvalidas, nConcorrentesT, nConcorrentesPV, nEtapas);

void guardarLeaderBoard(LeaderBoard concorrente[], ProvasInvalidas provasInvalidas[], int nConcorrentesPI, int nConcorrentesPV);