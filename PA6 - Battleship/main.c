#include "Header.h"
char player1[10][10];
char cpu[10][10];
char cpudisplay[10][10];
char tempboard[10][10];
char CPUtempboard[10][10];
int main(void) {
	
	welcome();
	make_board(player1, cpu, cpudisplay, tempboard, CPUtempboard);
	place_ships(player1, cpu, tempboard); //kinda shitass, and can loop for a LONG time before figuring itself out. 
	place_CPU_ships(cpu, CPUtempboard);
	int order = player_order();
	game(player1, cpu, cpudisplay, order);
}