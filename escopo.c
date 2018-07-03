#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <math.h>
#include "gerenciamentoCedulas.c"
#include "menu.c"

/*	Criado por Renan Marcos Ferreira
	ADSMA2 - FATEC SCS, 2017. 
	MAIN - CAIXA ELETR�NICO */
	
extern int dinheiroNoCaixa;

int main() {
	setlocale(LC_ALL, "portuguese");
	
	int opcao, i;
	int qtdCedulas, codigoBanco, continuar = 1;
	float valorSaque = 0;

	do {
		dinheiroNoCaixa = 0;
		dinheiroNoCaixa += cedulas[0] * 2;
		dinheiroNoCaixa += cedulas[1] * 5;
		dinheiroNoCaixa += cedulas[2] * 10;
		dinheiroNoCaixa += cedulas[3] * 20;
		dinheiroNoCaixa += cedulas[4] * 50;
		dinheiroNoCaixa += cedulas[5] * 100;
	
		carregarMenu();
		scanf("%d", &opcao);
		
		switch (opcao) {
			case 1: {
				carregarNotas();
				printf("\nTodas as c�dulas foram preenchidas com sucesso.");
				getch();
				break;
			}
			
			case 2: {
				do {
					printf("\nDigite o valor do saque: R$");
					scanf("%f", &valorSaque);	
				} while (valorSaque < 2 || valorSaque == 3);
				system("cls");
				
				if (valorSaque <= dinheiroNoCaixa) {
					
					if (valorSaque >= 20) {
						
						do {
							printf("\nSelecione uma op��o:\n\n1. 1 c�dula de R$ 20\n2. 2 c�dulas de R$ 10\n0. Deixar o caixa decidir\n");
							scanf("%d", &qtdCedulas);
						} while (qtdCedulas < 0 || qtdCedulas > 2);
						system("cls");
						
						do {
							printf("\nDigite o c�digo do banco:\n\n1. Banco do Brasil\n2. Santander\n3. Ita�\n4. Caixa\n");
							scanf("%d", &codigoBanco);
						} while (codigoBanco <= 0 || codigoBanco > 4);
						
						sacar(valorSaque, qtdCedulas, codigoBanco);
						
					} else {
						
						do {
							printf("\nDigite o c�digo do banco:\n\n1. Banco do Brasil\n2. Santander\n3. Ita�\n4. Caixa\n");
							scanf("%d", &codigoBanco);
						} while (codigoBanco <= 0 || codigoBanco > 4);
						
						sacar(valorSaque, 0, codigoBanco);
					}
					
					gravarEstatistica(valorSaque, codigoBanco);
					
					getch();
					
				} else {
					printf("\nValor a sacar maior do que dispon�vel no caixa.");
					getch();
				}
				
				break;
			}
			
			case 3: {
				mostrarEstatistica();
				break;
			}
			
			case 9: {
				continuar = 0;
				printf("\nObrigado por utilizar nossos servi�os! Pressione <ENTER> para encerrar o programa.");
				break;
			}
			
			default: printf("\nOp��o inv�lida. Pressione <ENTER> para continuar."); getch();
		}
	} while (continuar == 1);
}

