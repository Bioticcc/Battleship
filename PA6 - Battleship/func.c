#include "Header.h"

//makes empty board and returns it.
char make_board(char player[10][10], char cpu[10][10]) {
	printf("\nBOARD CREATED\n");
	printf(" -------------CPU-------------");
	char board[10][10] = {
		{'0','1','2','3','4','5','6','7','8','9'},
		{'1','-','-','-','-','-','-','-','-','-'},//(1,1), (5, 1) input
		{'2','-','-','-','-','-','-','-','-','-'},//(1, 1),(1, 5) actual
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
	return board;
}

char show_board(char player[10][10]) {
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

void display_ships() {
	printf("\n|----------FLEET----------|\n");
	printf("|(1)carrier: < o o o >    |\n");
	printf("|(2)battleship: < o o >   |\n");
	printf("|(3)cruiser: < o >        |\n");
	printf("|(4)submarine: z o z      |\n");
	printf("|(5)destroyer: < >        |\n");
	printf("|-------------------------|\n");
}


//allowing players to manually or randomly place ship pieces
char place_ships(char player[10][10], char cpu[10][10]) {
	//ships!
	char carrier[5] = { '<','o','o','o','>' };
	char battlship[4] = { '<','o','o','>'};
	char cruiser[3] = { '<','o','>' };
	char submarine[3] = { 'z','o','z' };
	char destroyer[2] = { '<','>' };

	//sleep(500);
	
	int a=0;
	while (a != 1 && a != 2) {
		printf("\nManually deploy your fleet? (1)\nAllow for strategic auto placement? (2)\n");
		scanf("%d", &a);
		system("cls");
	}
	if (a == 1) {
		//MANUALLY DEPLOY
		//bow
		int x = 0;
		int y = 0;
		//aft
		int x1 = 0;
		int y1 = 0;
		
		
		system("cls");
		//MAKE PROPER EXPLANATION FOR PLAYERS ON HOW TO PLACE A SHIP
		show_board(player);
		display_ships();
		printf("To begin, deploy your carrier [length: 5]. remember, its the core of your fleet, so choose wisely!\n");
		printf("Enter drop coordinates for your carrier bow:(x,y), aft:(x1,y1) format:(x y x1 y1): \n");
		scanf("%d%d%d%d", &x, &y, &x1, &y1);
		//placing ships good fucking god im getting an aneurysm		
		//step two: connect the two
		//WORKS FOR VERTICAL IG
		
		//should mean its vertical
		if (x == x1) {
			for (int i = y; i < y1 + 1; i++) {
				player[i][x] = 'o';
			}
			player[y][x] = '<';
			player[y1][x1] = '>';
			system("cls");
			show_board(player);
		}
		//should mean its horizontal
		else if (y == y1) {
			for (int i = x; i < x1+1; i++) {
				player[y][i] = 'o';
			}
			player[y][x] = '<';
			player[y1][x1] = '>';
			system("cls");
			show_board(player);
		}
		
		//carrier done. on to the next (btw the reason im not doing this all with one loop, whitch albeit would be faster most likely, it lets me do 
		//more with the printfs n such

		printf("\nGood job! next, depsloy your battleship [Length: 4].\n");
		printf("Enter drop coordinates for you battleship bow:(x,y), aft:(x1,y1) format:(x y x1 y1): \n");
		scanf("%d%d%d%d", &x, &y, &x1, &y1);
		//should mean its horizontal
		if (x == x1) {
			for (int i = y; i < y1 + 1; i++) {
				player[i][x] = 'o';
			}
			player[y][x] = '<';
			player[y1][x1] = '>';
			system("cls");
			show_board(player);
		}
		//should mean its horizontal
		else if (y == y1) {
			for (int i = x; i < x1 + 1; i++) {
				player[y][i] = 'o';
			}
			player[y][x] = '<';
			player[y1][x1] = '>';
			system("cls");
			show_board(player);
		}

		//battleship identical to carrier placement! thank god it works first try :)
		printf("\nTime for your cruiser [Length: 3]! dont underestimate this little guy, hes got spirit!\n");



	}
	else if (a == 2) {
		//AUTOMATIC DEPLOY
		exit(1);
	}

}
