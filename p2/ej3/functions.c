#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

ficha* BuildVector(int size){
	ficha * vector;
	vector = calloc(size,sizeof(ficha));
	if (vector == NULL){
		printf("Fallo al reservar memoria");
		exit(1);
	}
	else{
		printf("Vector start on %p\n",vector );
		return vector;
	}
}

ficha RegisterNewPlayer(ficha *player){
	char name[50];
	int dorsal,estatura, peso;
	printf("Introduce el nombre del jugador\n");
	gets(name);
	strcpy(player->nombre,name);
	printf("Introduce el dorsal del jugador\n");
	scanf("%i\n",&dorsal );
	player->dorsal = dorsal;
	printf("Introduce el peso del jugador\n" );
	scanf("%i\n",&peso );
	player->peso = peso;
	printf("Introduce la estatura del jugador\n" );
	scanf("%i\n",&estatura );
	player->estatura = estatura;
	return *player;
}

void PrintPlayerInfo(ficha *player){
	printf("Datos del juagdor %s\n",player->nombre );
	printf("Dorsal:\t%i\n",player->dorsal );
	printf("Peso:\t%i\n",player->peso );
	printf("Altura:\t%i\n",player->estatura );

}

void FildPlayerArray(ficha *team,int size){
	for (int i = 0;i<size;i++){
		RegisterNewPlayer((team+i));
		printf("\n");
	}
	printf("Team register correctly\n");
}

void ShowPlayers(ficha *team,int size){
	for (int i = 0;i<size;i++){
		PrintPlayerInfo((team+i));
		printf("\n");
	}
}

int KickPlayer(ficha *team, char *caracter,int size){
	int aux = 0;
	for (int i = 0;i<size;i++){
		if (strstr(((team+i)->nombre),caracter)){
			printf("Caracter found\n");
			*(team) = *(team+1);
			aux++;
		}
		printf("\n");
	}
	(ficha *)realloc(team,(size-aux));
	return (size-aux);
}
