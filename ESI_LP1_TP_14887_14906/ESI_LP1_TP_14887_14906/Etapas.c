#include <stdio.h>
#include "Header.h"
#pragma warning(disable : 4996)

///*Função que lê o ficheiro com a informação das distâncias das etapas*/
//void leFicheiroEtapas(Etapa etapas[]) {
//
//	char inicio[50], fim[50];
//	float distancia;
//
//	FILE* f = fopen("DistanciaEtapas.txt", "r");
//
//    int j = 0;
//	while (!feof(f)) {
//
//		fscanf(f, "%[^;];%[^;];%f\n", inicio, fim, &distancia);
//
//        strcpy(etapas[j].inicio, inicio);
//        strcpy(etapas[j].fim, fim);
//		etapas[j].distancia = distancia;
//        j++;
//
//	}
//
//	fclose(f);
//
//	for (int i = 0; i < j; i++) {
//		printf("%s %s %f\n", etapas[i].inicio, etapas[i].fim, etapas[i].distancia);
//	}
//}
