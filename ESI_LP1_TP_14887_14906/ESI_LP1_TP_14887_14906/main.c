#include <stdio.h>
#include "Header.h"

#pragma warning(disable : 4996)

void main() {

    //Declaração e inicialização de variáveis
    int opcao = 0, nEtapas = 0, nConcorrentesT = 0, nConcorrentesPV = 0;

    Distancia etapas[3] = { 0 };
    Concorrente concorrentes[10];
    Prova provas[10] = { 0 };
    DetalhesProva detalhes[1] = { 0 };
    Prova provasValidas[30] = { 0 };

        
    //Funções para ler os três ficheiros
    //leFicheiroConcorrentes(concorrentes);
    leFicheiroEtapas(etapas);
    leFicheiroProvas(provas, detalhes);
    
    nEtapas = detalhes[0].nEtapas;
    nConcorrentesT = detalhes[0].nConcorrentes;

    //Verifica as provas válidas
    nConcorrentesPV = verificarProvasValidas(provas, provasValidas, nConcorrentesT, nEtapas);

    //Menu
   /* opcao = menu();

    switch (opcao)
    {
    case 2:

        printf("Numero de concorrentes em prova: %d", nConcorrentesT);
        break;

    case 3:

        printf("Numero de concorrentes que efetuaram uma prova valida: %d", nConcorrentesPV);
        break;

    default:
        break;
    }*/

    //Exercício 4
    listagemTempoProva(provasValidas, nEtapas, nConcorrentesPV);

    ////Exercício 5
    mediaEtapas(provasValidas, etapas, nEtapas, nConcorrentesPV);

    
    ////Exercício 6 - Apresentação do concorrente mais rápido / mais lento a efetuar uma prova válida
    //concorrentesRapidos(provasValidas, nEtapas, nConcorrentesPV);

    //exercicio 7
    tempoMinimoProva(provas, etapas, nConcorrentesT, nEtapas);
    velocidadeMedia(provasValidas, etapas, nConcorrentesT, nEtapas);
    
    //Exercício 2
    //printf("%d\n", nEtapas);
   
}

int menu() {
    int opcao = -1;

    //do {

        printf("-----Menu-----");
        printf("\n1 - Sair");
        printf("\n2 - Numero de concorrentes em prova");
        printf("\n3 - Numero de concorrentes que efetuaram uma prova valida");
        printf("\n4 - Listagem (ordenada por ordem decrescente) dos tempos de cada prova valida");
        printf("\n5 - Listagem das medias dos tempos de cada etapa (utilizando tempos de provas validas)");
        printf("\n6 - Apresentacao do concorrente mais rapido e do mais lento (que efetuaram provas validas)");
        printf("\n7 - ");

        scanf("%d", &opcao);
    //} while (opcao != 1);
       
        return opcao;
}
