#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
int main(){
	ficha *team;
	//ficha hector;
	team = BuildVector(3);
	FildPlayerArray(team,3);
	ShowPlayers(team,3);
	ShowPlayers(team,KickPlayer(team,'H',3));
	return 0;
}
