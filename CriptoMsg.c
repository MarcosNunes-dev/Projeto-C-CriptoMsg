#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "Encriptar.h" 

int main()
{
	int  escolha;
	//char continuar;
	Msgcripto controle = { 0 };
	setlocale(LC_ALL, "Portuguese");
	do
	{ 
		escolha = menu();
		if (escolha == 1)
			addmsg(&controle);// gravar mensagem
		else if (escolha == 2) 
			msgGravada(&controle);// escolher msg j� gravadas
		else if (escolha == 3) 
			criarchave(&controle);// criar chave mestra
		else if (escolha == 4)  
			chavegravada(&controle);// mostra chave mestra
		else if (escolha == 5) 
			encriptar(&controle);// encriptar
		else if (escolha == 6)
			desencriptar(&controle); // desencripta msg
		else  
			saida(); // sai do programa
	} while (escolha != 7);
		return 0;
}