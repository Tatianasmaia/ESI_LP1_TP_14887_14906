#include <stdio.h>
#include "Header.h"

#pragma warning(disable : 4996)

void main() {
    
    Etapa etapas[3];
    Concorrente concorrentes[10];
    Prova provas[10];
    int nEtapas = 0, nConcorrentes = 0;
    DetalhesProva detalhes[1];

    leFicheiroConcorrentes(concorrentes);
    leFicheiroEtapas(etapas);
    leFicheiroProvas(provas, detalhes);

    nEtapas = detalhes[0].nEtapas;
    nConcorrentes = detalhes[0].nConcorrentes;

    printf("%d\n", nEtapas);
    printf("nr de conc : %d", nConcorrentes); //Exercício 2
   /* nConcorrentes = detalhes[1];

    printf("%d", &nEtapas);
    printf("%d", &nConcorrentes);*/
    //CalculaNrConcorrentes(provas);
    
}
