#define _CRT_SECURE_NO_WARNINGS
#include "Encriptar.h" // inclui minha propria biblioteca (header file)
#include <stdio.h>
void limpaBuffer()
{
	char c;
	while ((c = getchar()) != '\n' && c != EOF); // limpar o buffer
}
int menu()
{
	int opcao, validacao;
	do
	{
		system("cls||clear");
		puts("\n");
		puts("\t+================================================================+");
		puts("\t|                     PROGRAMA DE ENCRIPTAÇÃO                    |");
		puts("\t+----------------------------------------------------------------+");
		puts("\t|  1 - Adicionar Mensagem                                        |");
		puts("\t|  2 - Mostrar Mensagens já gravadas                             |");
		puts("\t|  3 - Criar Chave Mestra                                        |");
		puts("\t|  4 - Mostrar Chave Mestra                                      |");
		puts("\t|  5 - Encriptar Mensagem                                        |");
		puts("\t|  6 - Desencriptar Mensagem                                     |");
		puts("\t|  7 - Sair                                                      |");
		puts("\t+----------------------------------------------------------------+");
		printf("\n\tEscolha uma opção: ");
		scanf("%d", &opcao);
		validacao = opcao;
		if (opcao < 1 || opcao > 7)
		{
			printf("\n\tOpção inválida! Escolha entre 1 e 7.\n");
			limpaBuffer();
			printf("\tPressione ENTER para tentar novamente...");
			getchar();
		}

	} while (opcao < 1 || opcao > 7);
	return opcao;
}
void addmsg(Msgcripto* controle)
{
	char continuar;
	continuar = 's';
	while (continuar == 's' || continuar == 'S')
	{
		system("cls||clear");
		puts("\t+================================================================+");
		puts("\t|                     ADICIONAR NOVA MENSAGEM                    |");
		puts("\t+----------------------------------------------------------------+");
		puts("\t| REGRAS:                                                        |");
		puts("\t| 1. Limite máximo: 10 mensagens no sistema.                     |");
		puts("\t| 2. Tamanho máximo: 100 caracteres por frase.                   |");
		puts("\t+================================================================+");
		if (controle->totalMsg < R)
		{
			printf("\n\tDigite sua %dº Mensagem : ", controle->totalMsg + 1);
			scanf(" %[^\n]s", controle->msgOriginal[controle->totalMsg]); // para ler uma frase
			limpaBuffer();
			printf("\n\tMensagem gravada com sucesso.\n");
			controle->totalMsg++;
			if (controle->totalMsg < R)
			{
				printf("\n\tDeseja adicionar outra mensagem? (s/n): ");
				scanf(" %c", &continuar);
				limpaBuffer();
				while (continuar != 's' && continuar != 'S' && continuar != 'n' && continuar != 'N')
				{
					printf("Opção inválida! Digite apenas 's', 'S' ou 'n', 'N': ");
					scanf(" %c", &continuar);
					limpaBuffer();
				}
			}
			else
			{
				printf("\n\tLimite de mensagens atingido!\n");
				continuar = 'n';
				getchar();
			}
		}
		else
		{
			printf("\n\tAviso: Lista de Mensagens está completa !");
			puts("");
			printf("\n\tPressione ENTER para continuar....");
			continuar = 'n';
			limpaBuffer();
			getchar();
		}
	}
}
void msgGravada(Msgcripto* controle)
{
	system("cls||clear");
	puts("\t+================================================================+");
	puts("\t|                   MENSAGENS NO SISTEMA                         |");
	puts("\t+================================================================+");
	int msgescolhida;
	if (controle->totalMsg == 0)
		printf("\n\tAviso: Nao existem mensagens guardadas!\n");
	else
	{
		printf("\n\tEscolha a Mensagem que deseja ver: ");
		for (int i = 0; i < controle->totalMsg; i++)
		{
			printf("\n\t %dº Mensagem.\n", i + 1);
		}
		scanf(" %d", &msgescolhida);
		limpaBuffer();
		msgescolhida--;
		if (msgescolhida >= 0 && msgescolhida < controle->totalMsg)
			printf("\n\tSua Mensagem : %s", controle->msgOriginal[msgescolhida]);
		else
			printf("\n\tMensagem Escolhida é inexistente!! ");//fazer um ciclo para mostrar as msg
	}
	limpaBuffer();
	getchar();
}
void criarchave(Msgcripto* controle)
{
	system("cls||clear");
	puts("\t+================================================================+");
	puts("\t|                      CONFIGURAR CHAVE MESTRA                   |");
	puts("\t+================================================================+");
	puts("");
	int valida = 0;
	for (int i = 0; i < N; i++)
	{
		do
		{
			printf("\tDigite o %dº Número : ", i + 1);
			valida = scanf(" %d", &controle->chave[i]);
			if (valida== 0)
				printf("\n\tERRO: ao receber o número!\n");
			limpaBuffer();
		} while (valida == 0);
	}
	controle->chaveDefinida++;
	printf("\n\tChave Mestra gravada com sucesso");
	limpaBuffer();
	getchar();
}
void chavegravada(Msgcripto* controle)
{
	system("cls||clear");
	puts("\t+================================================================+");
	puts("\t|                      VISUALIZAR CHAVE MESTRA                   |");
	puts("\t+================================================================+");
	puts("");
	if (controle->chaveDefinida == 0)
		printf("\n\n\tAviso: Não criado uma chave Mestra!\n");
	else
	{
		printf("\nSua Chave Mestra é : ");
		for (int i = 0; i < N; i++)
		{
			printf(" %d,", controle->chave[i]);
		}
		puts("");
	}
	printf("\n\tPressione ENTER para continuar...");
	limpaBuffer();
	getchar();
}
void encriptar(Msgcripto* controle)
{
	system("cls||clear");
	puts("\t+================================================================+");
	puts("\t|                  ENCRIPTAÇÃO DE MENSAGENS		                 |");
	puts("\t+================================================================+");
	int tam, msgescolhida;
	if (controle->chaveDefinida == 0)
		printf("\n\n\tAviso: Não criado uma chave Mestra!\n");
	else if (controle->totalMsg == 0)
		printf("\n\tERRO: Não existem mensagens para encriptar!\n");
	else
	{
		printf("\nEscolha a Mensagem que quer Encripitar:\n ");
		for (int i = 0; i < controle->totalMsg; i++)
			printf(" %dº Mensagem.\n", i + 1);
		scanf(" %d", &msgescolhida);
		limpaBuffer();
		msgescolhida--;
		if (msgescolhida >= 0 && msgescolhida < controle->totalMsg)
		{
			tam = strlen(controle->msgOriginal[msgescolhida]);
			for (int i = 0; i < tam; i++)
				controle->msgEncriptada[msgescolhida][i] = controle->msgOriginal[msgescolhida][i] + controle->chave[i % N] + 5;
			controle->msgEncriptada[msgescolhida][tam] = '\0';
			printf("\nMSG Criptografada: %s\n", controle->msgEncriptada[msgescolhida]);
		}
		else
			printf("Mensagem Escolhida é INVÁLIDA!! ");
	}
	printf("\n\tPressione ENTER para continuar...");
	limpaBuffer();
	getchar();
}
void desencriptar(Msgcripto* controle)
{
	system("cls||clear");
	puts("\t+================================================================+");
	puts("\t|                   DESENCRIPTAÇÃO DE MENSAGENS                  |");
	puts("\t+================================================================+");
	int tam, msgescolhida;
	printf("Escolha a Mensagem que quer Desencriptar:\n ");
	for (int i = 0; i < controle->totalMsg; i++)
		printf(" %dº Mensagem.\n", i + 1);
	scanf(" %d", &msgescolhida);
	limpaBuffer();
	msgescolhida--;
	if (msgescolhida >= 0 && msgescolhida < controle->totalMsg)
	{
		tam = strlen(controle->msgEncriptada[msgescolhida]);
		if (tam == 0)
		{
			printf("\n\tErro: Esta mensagem ainda nao foi encriptada!\n");
			getchar();
		}
		else
		{
			printf("\n\tMensagem desencriptada: ");
			for (int i = 0; i < tam; i++)
				printf("%c", controle->msgEncriptada[msgescolhida][i] - controle->chave[i % N] - 5);
			getchar();
		}
	}
	else
		printf("Mensagem Escolhida é INVÁLIDA!!\n");
}
void saida()
{
	system("cls||clear");
	puts("\t+================================================================+");
	puts("\t|                                                                |");
	puts("\t|                OBRIGADO POR UTILIZAR O PROGRAMA                |");
	puts("\t|                                                                |");
	puts("\t+================================================================+");
	printf("\n\tPressione ENTER para fechar...");
	getchar();
}