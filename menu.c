#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <conio.h>

/*	Criado por Renan Marcos Ferreira
	ADSMA2 - FATEC SCS, 2017.
	MENU - CAIXA ELETRÔNICO */

float static somaSaques[4] = {0, 0, 0, 0};
float static menorSaque[4] = {99999, 99999, 99999, 99999};
float static maiorSaque[4] = {-1, -1, -1, -1};
int static contarSaques[4] = {0, 0, 0, 0};
extern int dinheiroNoCaixa;

void carregarMenu() {
	setlocale(LC_ALL, "portuguese");
	system("cls");
	printf("\nMenu Principal\n\n");
	printf("1 - Carregar Notas\n");
	printf("2 - Retirar Notas\n");
	printf("3 - Estatística\n");
	printf("9 - Fim\n\n");
}

void gravarEstatistica (float valorSaque, int codigoBanco) {
	
	somaSaques[codigoBanco - 1] += valorSaque;
	contarSaques[codigoBanco - 1]++;
				
	if (valorSaque > maiorSaque[codigoBanco - 1]) {
		maiorSaque[codigoBanco - 1] = valorSaque;
	}
				
	if (valorSaque < menorSaque[codigoBanco - 1]) {
		menorSaque[codigoBanco - 1] = valorSaque;
	}
}

void mostrarEstatistica () {
	int codigoBanco;
	system("cls");
		do {
			printf("\nDigite o código do banco:\n\n1. Banco do Brasil\n2. Santander\n3. Itaú\n4. Caixa\n");
			scanf("%d", &codigoBanco);
		} while (codigoBanco <= 0 || codigoBanco > 4);
		
		if (contarSaques[codigoBanco - 1] == 0) {
			printf("\nNenhum saque realizado para esse banco.");
		} else {
			printf("\nMaior valor sacado: %.2f", maiorSaque[codigoBanco - 1]);
			printf("\nMenor valor sacado: %.2f", menorSaque[codigoBanco - 1]);
			printf("\nMédia dos saques: %.2f", somaSaques[codigoBanco - 1] / contarSaques[codigoBanco - 1]);
			printf("\nValor total dos saques: %.2f", somaSaques[codigoBanco - 1]);
			printf("\nValor das sobras do caixa: %d", dinheiroNoCaixa);	
		}
		getch();
}
