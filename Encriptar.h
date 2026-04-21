#pragma once
#define R 3
#define M 100
#define N 10

typedef struct
{
	char msgOriginal[R][M];
	char msgEncriptada[R][M];
	int chave[N];
	int chaveDefinida;
	int totalMsg;
}Msgcripto;

void limpaBuffer();
int menu();
void addmsg(Msgcripto* controle);
void msgGravada(Msgcripto* controle);
void criarchave(Msgcripto* controle);
void encriptar(Msgcripto* controle);
void desencriptar(Msgcripto* controle);
void saida();
