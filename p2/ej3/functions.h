#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct Ficha_jugador{
	char nombre[50];
	int dorsal;
	int peso;
	int estatura;
}ficha;

ficha* BuildVector(int size);
ficha RegisterNewPlayer(ficha *player);
void PrintPlayerInfo(ficha *player);
void FildPlayerArray(ficha *team,int size);
void ShowPlayers(ficha *team,int size);
int KickPlayer(ficha *team, char caracter,int size);
#endif
