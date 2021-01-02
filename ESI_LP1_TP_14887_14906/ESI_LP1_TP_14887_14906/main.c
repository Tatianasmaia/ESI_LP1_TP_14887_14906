#include <stdio.h>

int main() {

	FILE *f;
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
	return 0;
}