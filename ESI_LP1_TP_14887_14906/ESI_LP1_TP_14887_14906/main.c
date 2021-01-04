#include <stdio.h>
#include "Header.h"

#pragma warning(disable : 4996)

int main() {

	FILE* f = fopen("DistanciaEtapas.txt", "r");

	//declaração e inicialização de variáveis
	char linha[500] = { 0 };
	char* token;
	char* aux[3] = { 0 };
	int contador = 0;

	Etapa novaEtapa[3];
	
	int j = 0;
	while (fgets(linha, sizeof(linha), f))
	{
		int i = 0;

		
		if ((linha[0] >= 'a' && linha[0] <= 'z') || (linha[0] >= 'A' && linha[0] <= 'Z')) {


			token = strtok(linha, ";");
			aux[0] = token;
			i++;

			while (token != NULL)
			{
				token = strtok(NULL, ";");

				if (token) {
					aux[i] = strdup(token);
				
					i++;
				}
			}

			
			strcpy(novaEtapa[j].inicio, aux[0]);
			strcpy(novaEtapa[j].fim, aux[1]);
			novaEtapa[j].distancia = atoi(aux[2]);
		}

		j++;

			
	}
	for (int x = 0; x < 3; x++) {
		printf("%s, %s, %f\n", novaEtapa[x].inicio, novaEtapa[x].fim, novaEtapa[x].distancia);
	}

	fclose(f);
}

    /*FILE* fp = fopen("DistanciaEtapas.txt", "r");
    const char s[3] = ";";
    char* token;
    int i;
    if (fp != NULL)
    {
        char line[20];
        while (fgets(line, sizeof line, fp) != NULL)
        {
            token = strtok(line, s);
            for (i = 0; i < 3; i++)
            {
                if (i == 0)
                {
                    printf("%s\t", token);
                    token = strtok(NULL, s);
                }
                else {
                    printf("%d\n", atoi(token));
                }
            }
        }
        fclose(fp);
    }
    else {
        perror("DadosConcorrentes.txt");
    }*/

	/*FILE *f;
	f = open("DadosConcorrentes.txt", "r");

	if (f == NULL) {
		printf("Erro de abertura do ficheiro");
	}
	else {
		int line = 0;

		char input[512] = { 0 };

		while (fgets(input, 512, f)) {
			line++;
			printf("Line:%d -> %s", line, input);
		}

		printf("\n\nEnd Of Program\n");

		fclose(f);

		
	}
	return 0;*/
//}