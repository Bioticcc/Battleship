#include "Header.h"



void update_stats(Stats* stats_ptr, int status) {
	if (status) {
		(*stats_ptr).num_hits++;
	}
	else {
		(*stats_ptr).num_misses++;
	}
	(*stats_ptr).total_shots++;
}










//makes empty board and returns it.
char make_board(char player[10][10], char cpu[10][10], char cpudisplay[10][10], char tempboard[10][10], char CPUtempboard[10][10]) {
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

	//copying board to cpudisplay
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cpudisplay[i][j] = board[i][j];
		}
	}
	//copying board to tempboard
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			tempboard[i][j] = board[i][j];
		}
	}
	//copying board to CPUtempboard
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			CPUtempboard[i][j] = board[i][j];
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
char place_ships(char player[10][10], char cpu[10][10], char tempboard[10][10]) {

	//ships!
	int carrier[5][2] = { //alright, so the idea here is saving the coordinates that each ship is at. like the full ship idk. Id imagine this will come in handy but at this point its between the code and god
		{0,0},
		{0,0},
		{0,0},
		{0,0},
		{0,0}
	};

	int battle[4][2] = {
		{0,0},
		{0,0},
		{0,0},
		{0,0}
	};

	int cruiser[3][2] = {
		{0,0},
		{0,0},
		{0,0},
	};

	int sub[3][2] = {
		{0,0},
		{0,0},
		{0,0}
	};

	int destroyer[2][2] = {
		{0,0},
		{0,0}
	};
	
	//sleep(500);
	int R = 0;
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
		//guard code ensuring they dont try to play ships out of bounds

		//GUARD CODE WORKS, JUST REMEMBER TO ADD THAT SHIT LATER CAUSE IM BUSY!
		while(x > 9 || x < 0 || y>9 || y < 0|| x1 > 9 || x1 < 0 || y1>9 || y1 < 0) {
			printf("Placing your ships too far away will result in loss of communication. Please keep them within bounds of the grid. \n");
			printf("Enter drop coordinates for your carrier bow:(x,y), aft:(x1,y1) format:(x y x1 y1): \n");
			scanf("%d%d%d%d", &x, &y, &x1, &y1);
		}
		//then need to check that the coordinates are the appropriate length away from each other.
		int c = 1;
		while (c) {
			if(x!=x1){
				if (x1 - x != 4) {
					printf("Your Carrier is only 5 units long! Re-enter your coordinates. ");
					printf("Enter drop coordinates for your carrier bow:(x,y), aft:(x1,y1) format:(x y x1 y1): \n");
					scanf("%d%d%d%d", &x, &y, &x1, &y1);
				}
				else if (x1 - x == 4) {
					c = 0;
				}
			}
			else if (y != y1) {
				if (y1 - y != 4) {
					printf("Your Carrier is only 5 units long! Re-enter your coordinates. ");
					printf("Enter drop coordinates for your carrier bow:(x,y), aft:(x1,y1) format:(x y x1 y1): \n");
					scanf("%d%d%d%d", &x, &y, &x1, &y1);
				}
				else if (y1 - y == 4) {
					c = 0;
				}
			}
		}




		//should mean its vertical
		int row = 0;
		if (x == x1) {
			for (int i = y; i < y1 + 1; i++) {
				player[i][x] = 'o';
				carrier[row][0] = x;
				carrier[row][1] = i;
				
				R++;
				row++;
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
				carrier[row][0] = i;
				carrier[row][1] = y;
				
				R++;
				row++;
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


		while (x > 9 || x < 0 || y>9 || y < 0 || x1 > 9 || x1 < 0 || y1>9 || y1 < 0) {
			printf("Placing your ships too far away will result in loss of communication. Please keep them within bounds of the grid. \n");
			printf("Enter drop coordinates for your battleship bow:(x,y), aft:(x1,y1) format:(x y x1 y1): \n");
			scanf("%d%d%d%d", &x, &y, &x1, &y1);
		}
		//then need to check that the coordinates are the appropriate length away from each other.
		c = 1;
		while (c) {
			if (x != x1) {
				if (x1 - x != 3) {
					printf("Your battleship is only 4 units long! Re-enter your coordinates. ");
					printf("Enter drop coordinates for your battleship bow:(x,y), aft:(x1,y1) format:(x y x1 y1): \n");
					scanf("%d%d%d%d", &x, &y, &x1, &y1);
				}
				else if (x1 - x == 3) {
					c = 0;
				}
			}
			else if (y != y1) {
				if (y1 - y != 3) {
					printf("Your battleship is only 4 units long! Re-enter your coordinates. ");
					printf("Enter drop coordinates for your battleship bow:(x,y), aft:(x1,y1) format:(x y x1 y1): \n");
					scanf("%d%d%d%d", &x, &y, &x1, &y1);
				}
				else if (y1 - y == 3) {
					c = 0;
				}
			}
		}
		//should mean its horizontal
		row = 0;
		if (x == x1) {
			for (int i = y; i < y1 + 1; i++) {
				player[i][x] = 'o';
				battle[row][0] = x;
				battle[row][1] = i;
				
				R++;
				row++;
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
				battle[row][0] = i;
				battle[row][1] = y;
				
				R++;
				row++;
			}
			player[y][x] = '<';
			player[y1][x1] = '>';
			system("cls");
			show_board(player);
		}

		printf("\nTime for your cruiser [Length: 3]! dont underestimate this little guy, hes got spirit!\n");
		printf("Enter drop coordinates for you cruiser bow:(x,y), aft:(x1,y1) format:(x y x1 y1): \n");
		scanf("%d%d%d%d", &x, &y, &x1, &y1);

		while (x > 9 || x < 0 || y>9 || y < 0 || x1 > 9 || x1 < 0 || y1>9 || y1 < 0) {
			printf("Placing your ships too far away will result in loss of communication. Please keep them within bounds of the grid. \n");
			printf("Enter drop coordinates for your cruiser bow:(x,y), aft:(x1,y1) format:(x y x1 y1): \n");
			scanf("%d%d%d%d", &x, &y, &x1, &y1);
		}
		//then need to check that the coordinates are the appropriate length away from each other.
		c = 1;
		while (c) {
			if (x != x1) {
				if (x1 - x != 2) {
					printf("Your cruiser is only 3 units long! Re-enter your coordinates. ");
					printf("Enter drop coordinates for your cruiser bow:(x,y), aft:(x1,y1) format:(x y x1 y1): \n");
					scanf("%d%d%d%d", &x, &y, &x1, &y1);
				}
				else if (x1 - x == 2) {
					c = 0;
				}
			}
			else if (y != y1) {
				if (y1 - y != 2) {
					printf("Your battleship is only 3 units long! Re-enter your coordinates. ");
					printf("Enter drop coordinates for your cruiser bow:(x,y), aft:(x1,y1) format:(x y x1 y1): \n");
					scanf("%d%d%d%d", &x, &y, &x1, &y1);
				}
				else if (y1 - y == 2) {
					c = 0;
				}
			}
		}

		//should mean its horizontal
		row = 0;
		if (x == x1) {
			for (int i = y; i < y1 + 1; i++) {
				player[i][x] = 'o';
				cruiser[row][0] = x;
				cruiser[row][1] = i;
				
				R++;
				row++;
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
				cruiser[row][0] = i;
				cruiser[row][1] = y;
				
				R++;
				row++;
			}
			player[y][x] = '<';
			player[y1][x1] = '>';
			system("cls");
			show_board(player);
		}
		printf("\nThe terror of the deep ocean, the stealthy submarine! [Length: 3] \n");
		printf("Enter drop coordinates for you submarine bow:(x,y), aft:(x1,y1) format:(x y x1 y1): \n");
		scanf("%d%d%d%d", &x, &y, &x1, &y1);


		while (x > 9 || x < 0 || y>9 || y < 0 || x1 > 9 || x1 < 0 || y1>9 || y1 < 0) {
			printf("Placing your ships too far away will result in loss of communication. Please keep them within bounds of the grid. \n");
			printf("Enter drop coordinates for your submarine bow:(x,y), aft:(x1,y1) format:(x y x1 y1): \n");
			scanf("%d%d%d%d", &x, &y, &x1, &y1);
		}
		//then need to check that the coordinates are the appropriate length away from each other.
		c = 1;
		while (c) {
			if (x != x1) {
				if (x1 - x != 2) {
					printf("Your submarine is only 3 units long! Re-enter your coordinates. ");
					printf("Enter drop coordinates for your submarine bow:(x,y), aft:(x1,y1) format:(x y x1 y1): \n");
					scanf("%d%d%d%d", &x, &y, &x1, &y1);
				}
				else if (x1 - x == 2) {
					c = 0;
				}
			}
			else if (y != y1) {
				if (y1 - y != 2) {
					printf("Your submarine is only 3 units long! Re-enter your coordinates. ");
					printf("Enter drop coordinates for your submarine bow:(x,y), aft:(x1,y1) format:(x y x1 y1): \n");
					scanf("%d%d%d%d", &x, &y, &x1, &y1);
				}
				else if (y1 - y == 2) {
					c = 0;
				}
			}
		}
		row = 0;
		//should mean its horizontal
		if (x == x1) {
			for (int i = y; i < y1 + 1; i++) {
				player[i][x] = 'o';
				sub[row][0] = x;
				sub[row][1] = i;
				
				R++;
				row++;
			}
			player[y][x] = 'U';
			player[y1][x1] = 'U';
			system("cls");
			show_board(player);
		}
		//should mean its horizontal
		else if (y == y1) {
			for (int i = x; i < x1 + 1; i++) {
				player[y][i] = 'o';
				sub[row][0] = i;
				sub[row][1] = y;
				
				R++;
			}
			player[y][x] = 'U';
			player[y1][x1] = 'U';
			system("cls");
			show_board(player);
		}

		printf("\nThe smallest of your fleet, your destroyer! [Length: 2] \n");
		printf("Enter drop coordinates for you destroyer bow:(x,y), aft:(x1,y1) format:(x y x1 y1): \n");
		scanf("%d%d%d%d", &x, &y, &x1, &y1);

		while (x > 9 || x < 0 || y>9 || y < 0 || x1 > 9 || x1 < 0 || y1>9 || y1 < 0) {
			printf("Placing your ships too far away will result in loss of communication. Please keep them within bounds of the grid. \n");
			printf("Enter drop coordinates for your destroyer bow:(x,y), aft:(x1,y1) format:(x y x1 y1): \n");
			scanf("%d%d%d%d", &x, &y, &x1, &y1);
		}
		//then need to check that the coordinates are the appropriate length away from each other.
		c = 1;
		while (c) {
			if (x != x1) {
				if (x1 - x != 1) {
					printf("Your destroyer is only 2 units long! Re-enter your coordinates. ");
					printf("Enter drop coordinates for your destroyer bow:(x,y), aft:(x1,y1) format:(x y x1 y1): \n");
					scanf("%d%d%d%d", &x, &y, &x1, &y1);
				}
				else if (x1 - x == 1) {
					c = 0;
				}
			}
			else if (y != y1) {
				if (y1 - y != 1) {
					printf("Your destroyer is only 3 units long! Re-enter your coordinates. ");
					printf("Enter drop coordinates for your destroyer bow:(x,y), aft:(x1,y1) format:(x y x1 y1): \n");
					scanf("%d%d%d%d", &x, &y, &x1, &y1);
				}
				else if (y1 - y == 1) {
					c = 0;
				}
			}
		}
		row = 0;
		//should mean its vertical
		if (x == x1) {
			for (int i = y; i < y1 + 1; i++) {
				player[i][x] = 'o';
				destroyer[row][0] = x;
				destroyer[row][1] = i;
				
				R++;
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
				destroyer[row][0] = i;
				destroyer[row][1] = y;
				
				R++;
			}
			player[y][x] = '<';
			player[y1][x1] = '>';
			system("cls");
			show_board(player);
		}


	}
	else if (a == 2) {
		int b = 1;
		int shiptotalmass = 0;
		R = 0;
		//AUTOMATIC DEPLOY
		unsigned int random = time(0);
		srand(random);
		int VH = rand() % 2 + 1; //determines if the ship will be placed horizontally or vertically

		//randomly places carrier
		int row = 0;
		int x = rand() % 5 + 1;
		int y = rand() % 5 + 1;
		int y1 = 0;
		int x1 = 0;
		

		if (VH == 1) { //horizontal
			x1 = (x + 4);
			y1 = y;
			for (int i = x; i < x1 + 1; i++) {
				player[y][i] = 'o';
				tempboard[y][i] = 'o';
				carrier[row][0] = i;
				carrier[row][1] = y; row++;

				R++;
			}
			player[y][x] = '<';
			player[y1][x1] = '>';
			tempboard[y][x] = '<';
			tempboard[y1][x1] = '>';

		}
		else if (VH == 2) { //vertical
			x1 = x;
			y1 = y + 4;
			for (int i = y; i < y1 + 1; i++) {
				player[i][x] = 'o';
				tempboard[i][x] = 'o';
				carrier[row][0] = x;
				carrier[row][1] = i; row++;

				R++;
			}
			player[y][x] = '<';
			player[y1][x1] = '>';
			tempboard[y][x] = '<';
			tempboard[y1][x1] = '>';
		}
		//randomly places battleship
		int kek = 1;
		
		while (kek) {
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					player[i][j] = tempboard[i][j]; //so this should hopefully save the previous state of the board, updating only the correct board. idk 
				}
			}
			
			row = 0;
			VH = rand() % 2 + 1;
			x = rand() % 6 + 1;
			y = rand() % 6 + 1;
			x1 = 0;
			y1 = 0;

			if (VH == 1) { //horizontal
				x1 = (x + 3);
				y1 = y;
				for (int i = x; i < x1 + 1; i++) {
					player[y][i] = 'o';
					battle[row][0] = i;
					battle[row][1] = y; row++;	
				}
				player[y][x] = '<';
				player[y1][x1] = '>';

			}
			else if (VH == 2) { //vertical
				x1 = x;
				y1 = y + 3;
				for (int i = y; i < y1 + 1; i++) {
					player[i][x] = 'o';
					battle[row][0] = x;
					battle[row][1] = i; row++;

					R++;
				}
				player[y][x] = '<';
				player[y1][x1] = '>';

			}
			
			shiptotalmass = 0;
			for (int i = 1; i < 10; i++) {
				for (int j = 1; j < 10; j++) {
					if (player[i][j] != '-') { shiptotalmass++; }
				}
			}
			if (shiptotalmass != 9) {
				kek = 1;
			}

			else if (shiptotalmass == 9) { kek = 0; }
		}

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				tempboard[i][j] = player[i][j]; //so this should hopefully save the previous state of the board, updating only the correct board. idk 
			}
		}
		
		//placing cruiser
		kek = 1;
		while (kek) {
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					player[i][j] = tempboard[i][j]; //so this should hopefully save the previous state of the board, updating only the correct board. idk 
				}
			}
			
			row = 0;
			VH = rand() % 2 + 1;
			x = rand() % 6 + 1;
			y = rand() % 6 + 1;
			x1 = 0;
			y1 = 0;

			if (VH == 1) { //horizontal
				x1 = (x + 2);
				y1 = y;
				for (int i = x; i < x1 + 1; i++) {
					player[y][i] = 'o';
					cruiser[row][0] = i;
					cruiser[row][1] = y; row++;
				}
				player[y][x] = '<';
				player[y1][x1] = '>';

			}
			else if (VH == 2) { //vertical
				x1 = x;
				y1 = y + 2;
				for (int i = y; i < y1 + 1; i++) {
					player[i][x] = 'o';
					cruiser[row][0] = x;
					cruiser[row][1] = i; row++;

					R++;
				}
				player[y][x] = '<';
				player[y1][x1] = '>';

			}
			
			shiptotalmass = 0;
			for (int i = 1; i < 10; i++) {
				for (int j = 1; j < 10; j++) {
					if (player[i][j] != '-') { shiptotalmass++; }
				}
			}
			if (shiptotalmass != 12) {
				kek = 1;
			}

			else if (shiptotalmass == 12) { kek = 0; }
		}

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				tempboard[i][j] = player[i][j]; //so this should hopefully save the previous state of the board, updating only the correct board. idk 
			}
		}
		
		//placing submarine
		kek = 1;
		while (kek) {
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					player[i][j] = tempboard[i][j]; //so this should hopefully save the previous state of the board, updating only the correct board. idk 
				}
			}
			
			row = 0;
			VH = rand() % 2 + 1;
			x = rand() % 6 + 1;
			y = rand() % 6 + 1;
			x1 = 0;
			y1 = 0;

			if (VH == 1) { //horizontal
				x1 = (x + 2);
				y1 = y;
				for (int i = x; i < x1 + 1; i++) {
					player[y][i] = 'o';
					cruiser[row][0] = i;
					cruiser[row][1] = y; row++;
				}
				player[y][x] = 'U';
				player[y1][x1] = 'U';

			}
			else if (VH == 2) { //vertical
				x1 = x;
				y1 = y + 2;
				for (int i = y; i < y1 + 1; i++) {
					player[i][x] = 'o';
					cruiser[row][0] = x;
					cruiser[row][1] = i; row++;

					R++;
				}
				player[y][x] = 'U';
				player[y1][x1] = 'U';

			}
			
			shiptotalmass = 0;
			for (int i = 1; i < 10; i++) {
				for (int j = 1; j < 10; j++) {
					if (player[i][j] != '-') { shiptotalmass++; }
				}
			}
			if (shiptotalmass != 15) {
				kek = 1;
			}

			else if (shiptotalmass == 15) { kek = 0; }
		}

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				tempboard[i][j] = player[i][j]; //so this should hopefully save the previous state of the board, updating only the correct board. idk 
			}
		}
		
		//placing destroyer
		kek = 1;
		while (kek) {
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					player[i][j] = tempboard[i][j]; //so this should hopefully save the previous state of the board, updating only the correct board. idk 
				}
			}
			
			row = 0;
			VH = rand() % 2 + 1;
			x = rand() % 6 + 1;
			y = rand() % 6 + 1;
			x1 = 0;
			y1 = 0;

			if (VH == 1) { //horizontal
				x1 = (x + 1);
				y1 = y;
				for (int i = x; i < x1 + 1; i++) {
					player[y][i] = 'o';
					cruiser[row][0] = i;
					cruiser[row][1] = y; row++;
				}
				player[y][x] = '<';
				player[y1][x1] = '>';

			}
			else if (VH == 2) { //vertical
				x1 = x;
				y1 = y + 1;
				for (int i = y; i < y1 + 1; i++) {
					player[i][x] = 'o';
					cruiser[row][0] = x;
					cruiser[row][1] = i; row++;

					R++;
				}
				player[y][x] = '<';
				player[y1][x1] = '>';

			}
			
			shiptotalmass = 0;
			for (int i = 1; i < 10; i++) {
				for (int j = 1; j < 10; j++) {
					if (player[i][j] != '-') { shiptotalmass++; }
				}
			}
			if (shiptotalmass != 17) {
				kek = 1;
			}

			else if (shiptotalmass == 17) { kek = 0; }
		}

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				tempboard[i][j] = player[i][j]; //so this should hopefully save the previous state of the board, updating only the correct board. idk 
			}
		}

			

		system("cls");
		printf("Ships strategically placed, captain!\n");
		show_board(player);
		//testing - displaying coordinates of all ships, for now just carrier
		system("pause");
	}

}

char place_CPU_ships(char cpu[10][10], char CPUtempboard[10][10]) {

	//ships! except these ones are the CPU's ships
	int CPUcarrier[5][2] = { //alright, so the idea here is saving the coordinates that each ship is at. like the full ship idk. Id imagine this will come in handy but at this point its between the code and god
		{0,0},
		{0,0},
		{0,0},
		{0,0},
		{0,0}
	};

	int CPUbattle[4][2] = {
		{0,0},
		{0,0},
		{0,0},
		{0,0}
	};

	int CPUcruiser[3][2] = {
		{0,0},
		{0,0},
		{0,0},
	};

	int CPUsub[3][2] = {
		{0,0},
		{0,0},
		{0,0}
	};

	int CPUdestroyer[2][2] = {
		{0,0},
		{0,0}
	};
	int b = 1;
	int shiptotalmass = 0;
	
	//AUTOMATIC DEPLOY
	unsigned int random = time(0);
	srand(random);
	int VH = rand() % 2 + 1; //determines if the ship will be placed horizontally or vertically

	//randomly places carrier
	int row = 0;
	int x = rand() % 5 + 1;
	int y = rand() % 5 + 1;
	int y1 = 0;
	int x1 = 0;


	if (VH == 1) { //horizontal
		x1 = (x + 4);
		y1 = y;
		for (int i = x; i < x1 + 1; i++) {
			cpu[y][i] = 'o';
			CPUtempboard[y][i] = 'o';
			CPUcarrier[row][0] = i;
			CPUcarrier[row][1] = y; row++;

			
		}
		cpu[y][x] = '<';
		cpu[y1][x1] = '>';
		CPUtempboard[y][x] = '<';
		CPUtempboard[y1][x1] = '>';

	}
	else if (VH == 2) { //vertical
		x1 = x;
		y1 = y + 4;
		for (int i = y; i < y1 + 1; i++) {
			cpu[i][x] = 'o';
			CPUtempboard[i][x] = 'o';
			CPUcarrier[row][0] = x;
			CPUcarrier[row][1] = i; row++;

		
		}
		cpu[y][x] = '<';
		cpu[y1][x1] = '>';
		CPUtempboard[y][x] = '<';
		CPUtempboard[y1][x1] = '>';
	}
	//randomly places battleship
	int kek = 1;

	while (kek) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				cpu[i][j] = CPUtempboard[i][j]; //so this should hopefully save the previous state of the board, updating only the correct board. idk 
			}
		}

		row = 0;
		VH = rand() % 2 + 1;
		x = rand() % 6 + 1;
		y = rand() % 6 + 1;
		x1 = 0;
		y1 = 0;

		if (VH == 1) { //horizontal
			x1 = (x + 3);
			y1 = y;
			for (int i = x; i < x1 + 1; i++) {
				cpu[y][i] = 'o';
				CPUbattle[row][0] = i;
				CPUbattle[row][1] = y; row++;
			}
			cpu[y][x] = '<';
			cpu[y1][x1] = '>';

		}
		else if (VH == 2) { //vertical
			x1 = x;
			y1 = y + 3;
			for (int i = y; i < y1 + 1; i++) {
				cpu[i][x] = 'o';
				CPUbattle[row][0] = x;
				CPUbattle[row][1] = i; row++;

			}
			cpu[y][x] = '<';
			cpu[y1][x1] = '>';

		}

		shiptotalmass = 0;
		for (int i = 1; i < 10; i++) {
			for (int j = 1; j < 10; j++) {
				if (cpu[i][j] != '-') { shiptotalmass++; }
			}
		}
		if (shiptotalmass != 9) {
			kek = 1;
		}

		else if (shiptotalmass == 9) { kek = 0; }
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			CPUtempboard[i][j] = cpu[i][j]; //so this should hopefully save the previous state of the board, updating only the correct board. idk 
		}
	}

	//placing cruiser
	kek = 1;
	while (kek) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				cpu[i][j] = CPUtempboard[i][j]; //so this should hopefully save the previous state of the board, updating only the correct board. idk 
			}
		}

		row = 0;
		VH = rand() % 2 + 1;
		x = rand() % 6 + 1;
		y = rand() % 6 + 1;
		x1 = 0;
		y1 = 0;

		if (VH == 1) { //horizontal
			x1 = (x + 2);
			y1 = y;
			for (int i = x; i < x1 + 1; i++) {
				cpu[y][i] = 'o';
				CPUcruiser[row][0] = i;
				CPUcruiser[row][1] = y; row++;
			}
			cpu[y][x] = '<';
			cpu[y1][x1] = '>';

		}
		else if (VH == 2) { //vertical
			x1 = x;
			y1 = y + 2;
			for (int i = y; i < y1 + 1; i++) {
				cpu[i][x] = 'o';
				CPUcruiser[row][0] = x;
				CPUcruiser[row][1] = i; row++;

			}
			cpu[y][x] = '<';
			cpu[y1][x1] = '>';

		}

		shiptotalmass = 0;
		for (int i = 1; i < 10; i++) {
			for (int j = 1; j < 10; j++) {
				if (cpu[i][j] != '-') { shiptotalmass++; }
			}
		}
		if (shiptotalmass != 12) {
			kek = 1;
		}

		else if (shiptotalmass == 12) { kek = 0; }
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			CPUtempboard[i][j] = cpu[i][j]; //so this should hopefully save the previous state of the board, updating only the correct board. idk 
		}
	}

	//placing submarine
	kek = 1;
	while (kek) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				cpu[i][j] = CPUtempboard[i][j]; //so this should hopefully save the previous state of the board, updating only the correct board. idk 
			}
		}

		row = 0;
		VH = rand() % 2 + 1;
		x = rand() % 6 + 1;
		y = rand() % 6 + 1;
		x1 = 0;
		y1 = 0;

		if (VH == 1) { //horizontal
			x1 = (x + 2);
			y1 = y;
			for (int i = x; i < x1 + 1; i++) {
				cpu[y][i] = 'o';
				CPUcruiser[row][0] = i;
				CPUcruiser[row][1] = y; row++;
			}
			cpu[y][x] = 'U';
			cpu[y1][x1] = 'U';

		}
		else if (VH == 2) { //vertical
			x1 = x;
			y1 = y + 2;
			for (int i = y; i < y1 + 1; i++) {
				cpu[i][x] = 'o';
				CPUcruiser[row][0] = x;
				CPUcruiser[row][1] = i; row++;

			}
			cpu[y][x] = 'U';
			cpu[y1][x1] = 'U';

		}

		shiptotalmass = 0;
		for (int i = 1; i < 10; i++) {
			for (int j = 1; j < 10; j++) {
				if (cpu[i][j] != '-') { shiptotalmass++; }
			}
		}
		if (shiptotalmass != 15) {
			kek = 1;
		}

		else if (shiptotalmass == 15) { kek = 0; }
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			CPUtempboard[i][j] = cpu[i][j]; //so this should hopefully save the previous state of the board, updating only the correct board. idk 
		}
	}

	//placing destroyer
	kek = 1;
	while (kek) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				cpu[i][j] = CPUtempboard[i][j]; //so this should hopefully save the previous state of the board, updating only the correct board. idk 
			}
		}

		row = 0;
		VH = rand() % 2 + 1;
		x = rand() % 6 + 1;
		y = rand() % 6 + 1;
		x1 = 0;
		y1 = 0;

		if (VH == 1) { //horizontal
			x1 = (x + 1);
			y1 = y;
			for (int i = x; i < x1 + 1; i++) {
				cpu[y][i] = 'o';
				CPUcruiser[row][0] = i;
				CPUcruiser[row][1] = y; row++;
			}
			cpu[y][x] = '<';
			cpu[y1][x1] = '>';

		}
		else if (VH == 2) { //vertical
			x1 = x;
			y1 = y + 1;
			for (int i = y; i < y1 + 1; i++) {
				cpu[i][x] = 'o';
				CPUcruiser[row][0] = x;
				CPUcruiser[row][1] = i; row++;

			}
			cpu[y][x] = '<';
			cpu[y1][x1] = '>';

		}

		shiptotalmass = 0;
		for (int i = 1; i < 10; i++) {
			for (int j = 1; j < 10; j++) {
				if (cpu[i][j] != '-') { shiptotalmass++; }
			}
		}
		if (shiptotalmass != 17) {
			kek = 1;
		}

		else if (shiptotalmass == 17) { kek = 0; }
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			CPUtempboard[i][j] = cpu[i][j]; //so this should hopefully save the previous state of the board, updating only the correct board. idk 
		}
	}



	system("cls");
	printf("*cpu ships placed*");
	//testing - displaying coordinates of all ships, for now just carrier
	system("pause");

}


int player_order() {
	char a = '\0';

	system("cls");
	printf("Now that your ships are prepared, let us return to the battlefield. \n");
	printf("Unfortunately, due to severe fog conditions there is no way to tell who will be in range first!\nYou, or your enemy? it will truly be luck of the draw...\n\n");
	printf("Nothing we can do but hope for good fortune. ENTER THE FOGGY OCEANS WITH YOUR FLEET? (y/n): ");
	scanf(" %c", &a);
	while (a != 'y') {
		printf("\n Now now, dont be a coward, captain. ENTER THE FOGGY OCEANS WITH YOUR FLEET? (y/n): ");
		scanf(" %c", &a);
	}
	system("cls");
	unsigned int random = time(0);
	srand(random);
	int b = rand() % 2 + 1;
	if (b == 1) {
		//player first
		printf("THERE! ON THE HORIZON I CAN SEE THEM! the enemys fleet! unfortunately, they are still heavily obstructed by fog,\nso we wont know where their ships are...\nno matter! FIRE AWAY!\n\n");
		system("pause");
		return 1;

	}
	else if (b == 2) {
		//cpu first
		printf("An explosion rocks the side of your main carrier, alerting you to the enemies prescence.\nARGH! They got us... Thankfully we are still covered by the fog, so they dont know our precise location!\nLet the battle begin.\n\n");
		system("pause");
		return 2;
	}
	else {
		printf("testroll\n\n");
		return 3;
	}


}


int game(char player[10][10], char cpu[10][10], char cpudisplay[10][10], int order) {
	int x = 0;
	int y = 0;
	system("cls");
	printf("Now that we are in range, lets show those bastards what we can do!");
	printf("\n---------ENEMY FLEET----------");
	show_board(cpudisplay);
	printf("\n---------YOUR FLEET----------");
	show_board(player);
	system("pause");
	if (order == 1) {
		//player goes first
		system("cls");
		printf("\n---------ENEMY FLEET----------");
		show_board(cpudisplay);
		printf("The cannons are ready! Enter the targeted coordinate! (x y): ");
		scanf("%d%d", &x, &y);

	}
}