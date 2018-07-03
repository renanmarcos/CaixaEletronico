#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <conio.h>

/*	Criado por Renan Marcos Ferreira
	ADSMA2 - FATEC SCS, 2017.
	GERENCIAMENTO DE C�DULAS - CAIXA ELETR�NICO */
	
int static cedulas[6] = {100, 100, 100, 100, 100, 100}, dinheiroNoCaixa;

void carregarNotas() {
	int i;
	
	for (i = 0; i < 6; i++) {
		cedulas[i] = 100;
	}
}

void sacar(float valorSaque, int qtdCelulas, int codigoBanco) {
	int acabouTodasAsCedulas = 0;
	
	do {
		
		if (cedulas[0] <= 0 && cedulas[1] <= 0 && cedulas[2] <= 0 && cedulas[3] <= 0 && cedulas[4] <= 0 && cedulas[5] <= 0) {
			printf("\nN�o existem c�dulas suficientes para sacar.");
			getch();
			break;
		} else if (cedulas[0] <= 0 && cedulas[1] > 0 && cedulas[2] <= 0 && cedulas[3] <= 0 && cedulas[4] <= 0 && cedulas[5] <= 0) {
			acabouTodasAsCedulas = 1;
		}
		
		if (cedulas[1] <= 0 && fmod(valorSaque, 2) != 0) {
			printf("\nN�o � poss�vel sacar esse valor pois n�o temos c�dulas de 5 reais.");
			getch();
			break;
		}
		
		if (fmod(valorSaque, 5) != 0 && acabouTodasAsCedulas == 1) { // N�o sacar caso seja �mpar e s� tenha c�dulas de 5 reais
		
			printf("\nN�o � poss�vel sacar esse valor, pois n�o h� c�dulas o suficiente.");
			getch();
			break;
			
		} else {
			
			sacar5:
			if (cedulas[1] <= 0 && fmod(valorSaque, 2) != 0) {
				printf("\nN�o temos c�dulas suficientes para esse valor.");
				getch();
				break;	
			}
			
			if (fmod(valorSaque, 2) != 0) { // Sacar 5 reais apenas se for �mpar
				cedulas[1]--;
				valorSaque -= 5;	
			}		
		}
						
		if (qtdCelulas == 1) { // Tirar uma c�dula de 20 reais
			if (cedulas[3] > 0) {
				cedulas[3]--;
				valorSaque -= 20;	
			}
		}
		
		if (qtdCelulas == 2) { // Tirar duas c�dulas de 10 reais
			if (cedulas[2] > 0) {
				cedulas[2] -= 2;
				valorSaque -= 20;
			}
		}
		
		if (valorSaque >= 100) {
			
			sacar100:
				
			if (cedulas[5] <= 0) {
				goto sacar50;
			}
			
			cedulas[5]--;
			valorSaque -= 100;
				
		} else if (valorSaque >= 50) {
			
			sacar50:
				
			if (cedulas[4] <= 0) {
				goto sacar20;
			}
			
			cedulas[4]--;
			valorSaque -= 50;
			
			} else if (valorSaque >= 20) {
				
				sacar20:
					
				if (cedulas[3] <= 0) {
					goto sacar10;
				}
				
				cedulas[3]--;
				valorSaque -= 20;
				
				} else if (valorSaque >= 10) {
					
					sacar10:
						
					if (cedulas[2] <= 0) {
						goto sacar2;
					}
				
					cedulas[2]--;
					valorSaque -= 10;
					
					} else if (valorSaque >= 2) {
							
							sacar2:
								
							if (cedulas[0] <= 0) {
								goto sacar5;
							}
							
							cedulas[0]--;
							valorSaque -= 2;
						}
		
	} while (valorSaque > 0);
	
	printf("\nSaque realizado com sucesso.");
}

