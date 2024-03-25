#include "Header.h"
char player1[10][10];
char cpu[10][10];

int main(void) {
	
	welcome();
	make_board(player1, cpu);
	place_ships(player1, cpu);
	int order = player_order();

}