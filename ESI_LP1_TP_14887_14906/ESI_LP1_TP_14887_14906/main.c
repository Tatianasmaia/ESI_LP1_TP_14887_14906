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
    leFicheiroConcorrentes(concorrentes);
    leFicheiroEtapas(etapas);
    leFicheiroProvas(provas, detalhes);
    
    //Atribuição do número de etapas e concorrentes às respetivas variáveis
    nEtapas = detalhes[0].nEtapas;
    nConcorrentesT = detalhes[0].nConcorrentes;

    //Função que verifica as provas válidas e retorna o número de concorrentes que efetuaram uma prova válida
    nConcorrentesPV = verificarProvasValidas(provas, provasValidas, nConcorrentesT, nEtapas);

    //Menu
    do {
        opcao = menu();

        switch (opcao)
        {
        case 2:
            system("cls");
            printf("\nNumero de concorrentes em prova: %d\n", nConcorrentesT);
            
            break;

        case 3:
            system("cls");
            printf("\nNumero de concorrentes que efetuaram uma prova valida: %d\n", nConcorrentesPV);
           
            break;

        case 4:
            system("cls");
            listagemTempoProva(provasValidas, nEtapas, nConcorrentesPV);
            break;

        case 5:
            system("cls");
            mediaEtapas(provasValidas, etapas, nEtapas, nConcorrentesPV);
            break;
        
        case 6:
            system("cls");
            concorrenteRapidoLento(provasValidas, nEtapas, nConcorrentesPV);
            break;

        case 7:
            system("cls");
            tempoMinimoProva(provas, nConcorrentesT, nEtapas);
            break;

        case 8:
            system("cls");
            velocidadeMedia(provasValidas, etapas, nConcorrentesT, nEtapas);
            break;

        case 9:
            system("cls");

            break;

        default:
            printf("\bEscolha uma opcao valida!");
            break;
        }
    } while (opcao != 1);
    
    
}

int menu() {

    int opcao = -1;

    printf("\n-----Menu-----\n");
    printf("\n1 - Sair");
    printf("\n2 - Numero de concorrentes em prova");
    printf("\n3 - Numero de concorrentes que efetuaram uma prova valida");
    printf("\n4 - Listagem (por ordem decrescente) dos tempos de cada prova valida");
    printf("\n5 - Listagem das medias dos tempos de cada etapa (utilizando tempos de provas validas)");
    printf("\n6 - Apresentacao do concorrente mais rapido e do mais lento (que efetuaram provas validas). E necessario executar a opcao 4 primeiro");
    printf("\n7 - Menor tempo em que e possivel efetuar uma prova na totalidade");
    printf("\n8 - Listagem (por ordem decrescente) das velocidades medias de toda a prova");
    printf("\n9 - Tabela classificativa da prova");
    printf("\n\nOpcao: ");

    scanf("%d", &opcao);
       
    return opcao;
}
