#include <stdio.h>
#include "Header.h"

#pragma warning(disable : 4996)

void main() {
    
    Distancia etapas[3];
    Concorrente concorrentes[10];
    Prova provas[10];
    int nEtapas = 0, nConcorrentes = 0;
    DetalhesProva detalhes[1] = { 0 };
    Prova provasValidas[30] = { 0 };

    

    //Funções para ler os três ficheiros
    //leFicheiroConcorrentes(concorrentes);
    //leFicheiroEtapas(etapas);
    leFicheiroProvas(provas, detalhes);
    
    nEtapas = detalhes[0].nEtapas;
    nConcorrentes = detalhes[0].nConcorrentes;

    ProvasValida(provas, provasValidas, nConcorrentes, nEtapas);

    ListagemTempoProva(provasValidas, nEtapas, nConcorrentes);

    

    //printf("%d\n", nEtapas);
    //printf("nr de conc : %d", nConcorrentes); //Exercício 2
   /* nConcorrentes = detalhes[1];

    printf("%d", &nEtapas);
    printf("%d", &nConcorrentes);*/
}


