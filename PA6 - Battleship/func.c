#include "Header.h"

//makes empty board and returns it.
char make_board(char player[10][10], char cpu[10][10]) {
	printf("\nBOARD CREATED\n");
	printf(" -------------CPU-------------");
	char board[10][10] = {
		{'0','1','2','3','4','5','6','7','8','9'},
		{'1','-','-','-','-','-','-','-','-','-'},
		{'2','-','-','-','-','-','-','-','-','-'},
		{'3','-','-','-','-','-','-','-','-','-'},
		{'4','-','-','-','-','-','-','-','-','-'},
		{'5','-','-','-','-','-','-','-','-','-'},
		{'6','-','-','-','-','-','-','-','-','-'},
		{'7','-','-','-','-','-','-','-','-','-'},
		{'8','-','-','-','-','-','-','-','-','-'},
		{'9','-','-','-','-','-','-','-','-','-'},
	};
	//copying board to cpu
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cpu[i][j] = board[i][j];
		}
	}

	//displaying cpu board
	for (int i = 0; i < 10; i++) {
		printf("\n");
		for (int j = 0; j < 10; j++) {
			printf(" %c ", cpu[i][j]);
		}
	}
	printf("\n");
	printf(" ------------PLAYER------------");
	//copying board to player
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			player[i][j] = board[i][j];
		}
	}
	//displaying player board
	for (int i = 0; i < 10; i++) {
		printf("\n");
		for (int j = 0; j < 10; j++) {
			printf(" %c ", player[i][j]);
		}
	}
}

int welcome() {
	int choice = 0;
	while (choice == 0) {
		printf("|------------------------BATTLESHIP------------------------|\n");
		printf("|                   Welcome! To! Valhalla!                 |\n");
		printf("|  Before we begin, take a moment to familiarize yourself! |\n");
		printf("|1. Begin by placing your chosen combination of various    |\n");
		printf("|	ships on the battle field, or have it set randomly.|\n");
		printf("|2. Using the grid-like board, choose coordinates          |\n");
		printf("|   the enemy ships are hiding! if you choose correctly,   |\n");
		printf("|your ships will bombard that location, devastating the    |\n");
		printf("|   ships hull below.                                      |\n");
		printf("|3. The enemy then selects coordinates to hit YOU!         |\n");
		printf("|   I Hope you chose your ship locations wisely ;3         |\n");
		printf("|                         GOOD LUCK!                       |\n");
		printf("|----------------------------------------------------------|\n");
		printf("\n\nENTER THE BATTLEFIELD? (y/n): ");
		char input;
		scanf(" %c", &input);
		system("cls");
		if (input == 'y') { choice = 1; return 1; }
	}
}

//allowing players to manually or randomly place ship pieces
char place_ships(char player[10][10], char cpu[10][10]) {
	//sleep(500);
	system("cls");
	int a=0;
	while (a != 1 || a != 2) {
		printf("Manually deploy your fleet? (1)\nAllow for strategic auto placement? (2)\n");
		scanf("%d", &a);
		system("cls");
	}
	if (a == 1) {
		//MANUALLY DEPLOY
	}
	else if (a == 2) {
		//AUTOMATIC DEPLOY
	}

}
