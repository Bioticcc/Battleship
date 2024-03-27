#include "Header.h"
char player1[10][10];
char cpu[10][10];
char cpudisplay[10][10];
char tempboard[10][10];
char CPUtempboard[10][10];

Stats p1_stats = { 0,0,0,0.0 }, p2_stats = { 0,0,0,0.0 };


int main(void) {
	
	welcome();
	make_board(player1, cpu, cpudisplay, tempboard, CPUtempboard);
	place_ships(player1, cpu, tempboard); 
	place_CPU_ships(cpu, CPUtempboard);
	int order = player_order();
	game(player1, cpu, cpudisplay, order);
}