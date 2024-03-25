#include "Header.h"
char player1[10][10];
char cpu[10][10];
char cpudisplay[10][10];

int main(void) {
	
	welcome();
	make_board(player1, cpu, cpudisplay);
	place_ships(player1, cpu); //kinda shitass, and can loop for a LONG time before figuring itself out. 
	place_CPU_ships(cpu);
	int order = player_order();
	game(player1, cpu, cpudisplay, order);
}