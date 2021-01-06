#include "battleship.h"

void welcome_screen(void) // prints welcome screen
{
	printf("*****Welcome to Battleship!*****\n");
	printf("Rules of the Game:\n");
	printf("1. This is a two player game.\n");
	printf("2. Player 1 is you and Player 2 is the computer.\n");
	printf("To play, first choose if you want to manually place ships on the board, or have the program do it randomly.\n");
	printf("If you choose manually, when placing ships, place the coordinates right to left or up and down. Doing it in any other order will not work.\n");
	printf("Then you will choose coordinates, between 0 and 9, to try and find the other players ships. If you hit the ship, a ""*"" will print, indicating a hit. If you miss the ship, a ""m"" will print, indicating a miss.\n");
	printf("The computer will then randomly pick a point. To win, the first person to sink all the ships will win. Stats and Moves will be printed to the battleship.log.\n");
	printf("Hit 1 to start the game!\n");
	int option = 0;
	scanf("%d", &option);
	if (option == 1)
	{
		system("cls");
	}
}

void initialize_game_board(char board[row][col]) 
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			board[i][j] = '-';
		}
	}
}
int check_if_sunk_ship(int ships[5], int *ptr) // ships array is an array of the five placed ships, that goes 5,4,3,3,2, which the numbers being the size of the ships. Once that size hits 0, it has sunk then I change it to -1 so it isn't counted anymore.
{
	int number_sunk_ships = 0;
	for (int i = 0; i < 5; i++)
	{
		if (ships[i] == 0)
		{
			number_sunk_ships++;
			ships[i] = -1;
			*ptr = i;
		}
	}
	if (number_sunk_ships != 1)
	{
		return -1;
	}
	else
	{
		return number_sunk_ships;
	}
	
}
void update_board(char board[row][col], int row1, int col1, int ships[5]) // need to test
{
	int check = check_shot(board,row1, col1);
	if (check == 1)
	{
		if (board[row1][col1] == 'c')
		{
			ships[0]--;
		}
		else if (board[row1][col1] == 'd')
		{
			ships[4]--;
		}
		else if (board[row1][col1] == 'b')
		{
			ships[1]--;
		}
		else if (board[row1][col1] == 's')
		{
			ships[2]--;
		}
		else if (board[row1][col1] == 'r')
		{
			ships[3]--;
		}
		board[row1][col1] = '*';
	}
	else if (check == 0)
	{
		board[row1][col1] = 'm';
	}
	else if (check == 2)
	{
		return 0;
	}
}
int check_shot(char board[row][col], int row1, int col1) // need to test
{
	if (board[row1][col1] == '*' || board[row1][col1] == 'm')
	{
		return 2;
	}
	else if (board[row1][col1] != '-')
	{
		
		return 1;
	}
	return 0;
}
int shoot_for_computer(int *ptr) // need to test
{
	int coordinate_one = rand() % 9 + 1;
	int coordinate_two = rand() % 9 + 1;
	*ptr = coordinate_one;
	return coordinate_two;
}
void display_board(int flag, char board[row][col]) // working
{
	
	if (flag == 1)
	{
		printf("Player 1's Board: \n");
		printf("  0 1 2 3 4 5 6 7 8 9\n");
		for (int i = 0; i < row; i++)
		{
			printf("%d ", i);
			for (int j = 0; j < col; j++)
			{
				printf("%c ", board[i][j]);
			
			}
			printf("\n");
		}
	}
	else if (flag == 2)
	{
		printf("Player 2's Board: \n");
		printf("  0 1 2 3 4 5 6 7 8 9\n");
		for (int i = 0; i < row; i++)
		{
			printf("%d ", i);
			for (int j = 0; j < col; j++)
			{
				if (board[i][j] == '*')
				{
					printf("%c ", '*');
				}
				else if (board[i][j] == 'm')
				{
					printf("%c ", 'm');
				}
				else
				{
					printf("%c ", '-');
				}
				

			}
			printf("\n");
		}
	}
}

int select_who_starts_first() // works
{
	int roll = rand() % 2 + 1;
	return roll;
}
void manually_place_ships_on_board(char board[row][col]) 
{
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0, x4 = 0, y4 = 0, x5 = 0, y5 = 0;
	printf("Please enter the five cells to place the Carrier across: \n");
	scanf("%d%d%d%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4, &x5, &y5);
	if ((x1 != x2 && x1 != x3 && x1 != x4 && x1 != x5) || (y1 != y2 && y1 != y3 && y1 != y4 && y1 != y5))
	{
		while ((x1 != x2 && x1 != x3 && x1 != x4 && x1 != x5) && (y1 != y2 && y1 != y3 && y1 != y4 && y1 != y5))
		{
			printf("Please enter a valid input!\n");
			printf("Please enter the five cells to place the Carrier across: \n");
			scanf("%d%d%d%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4, &x5, &y5);
		}
	}
	if ((x1 == x2 && x1 == x3 && x1 == x4 && x1 == x5) || (y1 == y2 && y1 == y3 && y1 == y4 && y1 == y5))
	{
		if (x1 == x2 && x1 == x3 && x1 == x4 && x1 == x5)
		{
			if (y5 - y4 == 1 && y4 - y3 == 1 && y3 - y2 == 1 && y2 - y1 == 1)
			{
				board[x1][y1] = 'c';
				board[x2][y2] = 'c';
				board[x3][y3] = 'c';
				board[x4][y4] = 'c';
				board[x5][y5] = 'c';
			}
			else
			{
				while (y5 - y4 != 1 && y4 - y3 != 1 && y3 - y2 != 1 && y2 - y1 != 1)
				{
					printf("Please select valid input:\n");
					printf("Please enter the five cells to place the Carrier across: \n");
					scanf("%d%d%d%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4, &x5, &y5);
				}
				board[x1][y1] = 'c';
				board[x2][y2] = 'c';
				board[x3][y3] = 'c';
				board[x4][y4] = 'c';
				board[x5][y5] = 'c';
			}
		}
		else
		{
			if (x5 - x4 == 1 && x4 - x3 == 1 && x3 - x2 == 1 && x2 - x1 == 1)
			{
				board[x1][y1] = 'c';
				board[x2][y2] = 'c';
				board[x3][y3] = 'c';
				board[x4][y4] = 'c';
				board[x5][y5] = 'c';
			}
			else
			{
				while (x5 - x4 != 1 && x4 - x3 != 1 && x3 - x2 != 1 && x2 - x1 != 1)
				{
					printf("Please select valid input:\n");
					printf("Please enter the five cells to place the Carrier across: \n");
					scanf("%d%d%d%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4, &x5, &y5);
				}
				board[x1][y1] = 'c';
				board[x2][y2] = 'c';
				board[x3][y3] = 'c';
				board[x4][y4] = 'c';
				board[x5][y5] = 'c';
			}
		}


	}
	printf("Please enter the four cells to place the Battleship across: \n");
	scanf("%d%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
	if ((x1 != x2 && x1 != x3 && x1 != x4) || (y1 != y2 && y1 != y3 && y1 != y4))
	{
		while ((x1 != x2 && x1 != x3 && x1 != x4) && (y1 != y2 && y1 != y3 && y1 != y4))
		{
			printf("Please enter a valid input!\n");
			printf("Please enter the four cells to place the Battleship across: \n");
			scanf("%d%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
		}
	}
	if ((x1 == x2 && x1 == x3 && x1 == x4) || (y1 == y2 && y1 == y3 && y1 == y4))
	{
		if (x1 == x2 && x1 == x3 && x1 == x4)
		{
			if (y4 - y3 == 1 && y3 - y2 == 1 && y2 - y1 == 1)
			{
				board[x1][y1] = 'b';
				board[x2][y2] = 'b';
				board[x3][y3] = 'b';
				board[x4][y4] = 'b';
			}
			else
			{
				while (y4 - y3 != 1 && y3 - y2 != 1 && y2 - y1 != 1)
				{
					printf("Please select valid input:\n");
					printf("Please enter the four cells to place the Battleship across: \n");
					scanf("%d%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
				}
				board[x1][y1] = 'b';
				board[x2][y2] = 'b';
				board[x3][y3] = 'b';
				board[x4][y4] = 'b';
			}
		}
		else
		{
			if (x4 - x3 == 1 && x3 - x2 == 1 && x2 - x1 == 1)
			{
				board[x1][y1] = 'b';
				board[x2][y2] = 'b';
				board[x3][y3] = 'b';
				board[x4][y4] = 'b';
			}
			else
			{
				while (x4 - x3 != 1 &&x3 - x2 != 1 && x2 - x1 != 1)
				{
					printf("Please select valid input:\n");
					printf("Please enter the four cells to place the Battleship across: \n");
					scanf("%d%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
				}
				board[x1][y1] = 'b';
				board[x2][y2] = 'b';
				board[x3][y3] = 'b';
				board[x4][y4] = 'b';
			}
		}


	}
	printf("Please enter the 3 cells to place the Cruiser across: \n");
	scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
	if ((x1 != x2 && x1 != x3) || (y1 != y2 && y1 != y3))
	{
		while ((x1 != x2 && x1 != x3) && (y1 != y2 && y1 != y3))
		{
			printf("Please enter a valid input!\n");
			printf("Please enter the 3 cells to place the Cruiser across: \n");
			scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
		}
	}
	if ((x1 == x2 && x1 == x3) || (y1 == y2 && y1 == y3))
	{
		if (x1 == x2 && x1 == x3)
		{
			if (y3 - y2 == 1 && y2 - y1 == 1)
			{
				board[x1][y1] = 'r';
				board[x2][y2] = 'r';
				board[x3][y3] = 'r';
			}
			else
			{
				while (y3 - y2 != 1 && y2 - y1 != 1)
				{
					printf("Please select valid input:\n");
					printf("Please enter the 3 cells to place the Cruiser across: \n");
					scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
				}
				board[x1][y1] = 'r';
				board[x2][y2] = 'r';
				board[x3][y3] = 'r';
			}
		}
		else
		{
			if (x3 - x2 == 1 && x2 - x1 == 1)
			{
				board[x1][y1] = 'r';
				board[x2][y2] = 'r';
				board[x3][y3] = 'r';
			}
			else
			{
				while (x3 - x2 != 1 && x2 - x1 != 1)
				{
					printf("Please select valid input:\n");
					printf("Please enter the 3 cells to place the Cruiser across: \n");
					scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
				}
				board[x1][y1] = 'r';
				board[x2][y2] = 'r';
				board[x3][y3] = 'r';
			}
		}


	}
	printf("Please enter the 3 cells to place the Submarine across: \n");
	scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
	if ((x1 != x2 && x1 != x3) || (y1 != y2 && y1 != y3))
	{
		while ((x1 != x2 && x1 != x3) && (y1 != y2 && y1 != y3))
		{
			printf("Please enter a valid input!\n");
			printf("Please enter the 3 cells to place the Submarine across: \n");
			scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
		}
	}
	if ((x1 == x2 && x1 == x3) || (y1 == y2 && y1 == y3))
	{
		if (x1 == x2 && x1 == x3)
		{
			if (y3 - y2 == 1 && y2 - y1 == 1)
			{
				board[x1][y1] = 's';
				board[x2][y2] = 's';
				board[x3][y3] = 's';
			}
			else
			{
				while (y3 - y2 != 1 && y2 - y1 != 1)
				{
					printf("Please select valid input:\n");
					printf("Please enter the 3 cells to place the Submarine across: \n");
					scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
				}
				board[x1][y1] = 's';
				board[x2][y2] = 's';
				board[x3][y3] = 's';
			}
		}
		else
		{
			if (x3 - x2 == 1 && x2 - x1 == 1)
			{
				board[x1][y1] = 's';
				board[x2][y2] = 's';
				board[x3][y3] = 's';
			}
			else
			{
				while (x3 - x2 != 1 && x2 - x1 != 1)
				{
					printf("Please select valid input:\n");
					printf("Please enter the 3 cells to place the Submarine across: \n");
					scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
				}
				board[x1][y1] = 's';
				board[x2][y2] = 's';
				board[x3][y3] = 's';
			}
		}


	}
	printf("Please enter the 2 cells to place the Destroyer across: \n");
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	if (x1 != x2 || y1 != y2)
	{
		while (x1 != x2 && y1 != y2)
		{
			printf("Please enter a valid input!\n");
			printf("Please enter the 3 cells to place the Submarine across: \n");
			scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
		}
	}
	if (x1 == x2 || y1 == y2)
	{
		if (x1 == x2)
		{
			if (y2 - y1 == 1)
			{
				board[x1][y1] = 'd';
				board[x2][y2] = 'd';
			}
			else
			{
				while (y2 - y1 != 1)
				{
					printf("Please select valid input:\n");
					printf("Please enter the 2 cells to place the Destroyer across: \n");
					scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
				}
				board[x1][y1] = 'd';
				board[x2][y2] = 'd';
			}
		}
		else
		{
			if (x2 - x1 == 1)
			{
				board[x1][y1] = 'd';
				board[x2][y2] = 'd';
			}
			else
			{
				while (x2 - x1 != 1)
				{
					printf("Please select valid input:\n");
					printf("Please enter the 2 cells to place the Destroyer across: \n");
					scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
				}
				board[x1][y1] = 'd';
				board[x2][y2] = 'd';
			}
		}
		
		
	}

	//display_board(0, board); // testing
}

void randomly_place_ships_on_board(char board[row][col])
{
	int roll = rand() % 4 + 1;
	if (roll == 1)
	{
		board[0][2] = 'c';
		board[0][3] = 'c';
		board[0][4] = 'c';
		board[0][5] = 'c';
		board[0][6] = 'c';
		board[3][4] = 'b';
		board[4][4] = 'b';
		board[5][4] = 'b';
		board[6][4] = 'b';
		board[1][0] = 'd';
		board[1][1] = 'd';
		board[2][9] = 's';
		board[3][9] = 's';
		board[4][9] = 's';
		board[7][3] = 'r';
		board[7][4] = 'r';
		board[7][5] = 'r';
		
	}
	else if (roll == 2)
	{
		board[8][4] = 'c';
		board[8][5] = 'c';
		board[8][6] = 'c';
		board[8][7] = 'c';
		board[8][8] = 'c';
		board[0][9] = 'b';
		board[1][9] = 'b';
		board[2][9] = 'b';
		board[3][9] = 'b';
		board[5][5] = 'd';
		board[6][5] = 'd';
		board[7][0] = 's';
		board[7][1] = 's';
		board[7][2] = 's';
		board[7][3] = 'r';
		board[8][3] = 'r';
		board[9][3] = 'r';
	}
	else if (roll == 3)
	{
		board[4][0] = 'c';
		board[4][1] = 'c';
		board[4][2] = 'c';
		board[4][3] = 'c';
		board[4][4] = 'c';
		board[3][7] = 'b';
		board[4][7] = 'b';
		board[5][7] = 'b';
		board[6][7] = 'b';
		board[3][3] = 'd';
		board[3][4] = 'd';
		board[0][9] = 's';
		board[0][9] = 's';
		board[0][9] = 's';
		board[9][0] = 'r';
		board[9][1] = 'r';
		board[9][2] = 'r';
	}
	else if (roll == 4)
	{
		board[9][2] = 'c';
		board[9][3] = 'c';
		board[9][4] = 'c';
		board[9][5] = 'c';
		board[9][6] = 'c';
		board[3][6] = 'b';
		board[3][7] = 'b';
		board[3][8] = 'b';
		board[3][9] = 'b';
		board[5][4] = 'd';
		board[5][5] = 'd';
		board[2][0] = 's';
		board[3][0] = 's';
		board[4][0] = 's';
		board[7][9] = 'r';
		board[8][9] = 'r';
		board[9][9] = 'r';
	}
	
}

void print_sunks(int index, FILE *logfile)
{
	if (index == -1)
	{
		return 0;
	}
	else if (index == 0)
	{
		fprintf(logfile, "Sunk Carrier!");
	}
	else if (index == 1)
	{
		fprintf(logfile, "Sunk Battleship!");
	}
	else if (index == 2)
	{
		fprintf(logfile, "Sunk Submarine!");
	}
	else if (index == 3)
	{
		fprintf(logfile, "Sunk Cruiser!");
	}
	else if (index == 4)
	{
		fprintf(logfile, "Sunk Destroyer!");
	}
}
void play_game()
{
	char p1_board[row][col] = { {'\0'} }, p2_board[row][col] = { {'\0'} };
	int p1_ships[5] = { 5,4,3,3,2 }, p2_ships[5] = { 5,4,3,3,2 };
	int option = 0, game_has_ended = 0, who_starts_game = 0;
	FILE *logfile = NULL;
	Stats p1 = { 0,0,0,0.0,0 };
	Stats p2 = { 0,0,0,0.0,0 };
	logfile = fopen("battleship.log", "w");
	int x = 0;
	
	welcome_screen();
	initialize_game_board(p1_board);
	initialize_game_board(p2_board);
	randomly_place_ships_on_board(p2_board);
	printf("Would you like to manually place ships or have the computer randomly place them for you? Type 1 for manual, 2 for random.\n");
	scanf("%d", &option);
	if (option == 1)
	{
		manually_place_ships_on_board(p1_board);
	}
	else if (option == 2)
	{
		randomly_place_ships_on_board(p1_board);
	}
	system("cls");
	who_starts_game = select_who_starts_first();
	if (who_starts_game == 1)
	{
		int p1x = -1;
		int p1y = -1;

		printf("Player 1 has been randomly selected to go first.\n");
		printf("Player 1, What x-coordinate and y-coordinate do you pick? (Remember: Pick X's and Y's between 0 and 9 for the grid.\n");
		display_board(1, p1_board);
		display_board(2, p2_board);
		scanf("%d%d", &p1x, &p1y);
		update_board(p2_board, p1x, p1y, p2_ships);
		p1.total_shots++;
		if (p2_board[p1x][p1y] == 'm')
		{
			printf("%d %d is a miss!\n", p1x, p1y);
			p1.number_of_misses++;
			fprintf(logfile, "Player1: %d,%d ""miss""\n", p1x, p1y);
		}
		else if (p2_board[p1x][p1y] == '*')
		{
			printf("%d %d is a hit!\n", p1x, p1y);
			p1.number_of_hits++;
			fprintf(logfile, "Player1: %d,%d ""hit""\n", p1x, p1y);
		}
		system("pause");
		display_board(1, p1_board);
		display_board(2, p2_board);
		int y = shoot_for_computer(&x);
		p2.total_shots++;
		update_board(p1_board, x, y, p1_ships);
		printf("Player 2 selects: %d %d\n", x, y);
		if (p1_board[x][y] == 'm')
		{
			printf("%d %d is a miss!\n", x, y);
			p2.number_of_misses++;
			fprintf(logfile, "Player2: %d,%d ""miss""\n", x, y);
		}
		else if (p1_board[x][y] == '*')
		{
			printf("%d %d is a hit!\n", x, y);
			p2.number_of_hits++;
			fprintf(logfile, "Player2: %d,%d ""hit""\n", x, y);
		}
		display_board(1, p1_board);
		display_board(2, p2_board);
	}
	else if (who_starts_game == 2)
	{
		int p1x = -1;
		int p1y = -1;
		printf("Player 2 has been randomly selected to go first.\n");
		display_board(1, p1_board);
		display_board(2, p2_board);
		int y = shoot_for_computer(&x);
		update_board(p1_board, x, y, p1_ships);
		printf("Player 2 selects: %d %d\n", x, y);
		p2.total_shots++;
		if (p1_board[x][y] == 'm')
		{
			printf("%d %d is a miss!\n", x, y);
			p2.number_of_misses++;
			fprintf(logfile, "Player2: %d,%d ""miss""\n", x, y);
		}
		else if (p1_board[x][y] == '*')
		{
			printf("%d %d is a hit!\n", x, y);
			p2.number_of_hits++;
			fprintf(logfile, "Player2: %d,%d ""hit""\n", x, y);

		}
		display_board(1, p1_board);
		display_board(2, p2_board);
	}
	system("pause");
	system("cls");
	int p1_won = 0;
	int p2_won = 0;
	while (game_has_ended == 0)
	{
		display_board(1, p1_board);
		display_board(2, p2_board);
		int p1x = -1;
		int p1y = -1;
		printf("Player 1, What x-coordinate and y-coordinate do you pick? (Remember: Pick X's and Y's between 0 and 9 for the grid.");
		scanf("%d%d", &p1x, &p1y);
		update_board(p2_board, p1x, p1y, p2_ships);
		p1.total_shots++;
		if (p2_board[p1x][p1y] == 'm')
		{
			printf("%d %d is a miss!\n", p1x, p1y);
			p1.number_of_misses++;
			fprintf(logfile, "Player1: %d,%d ""miss""\n", p1x, p1y);
		}
		else if (p2_board[p1x][p1y] == '*')
		{
			printf("%d %d is a hit!\n", p1x, p1y);
			p1.number_of_hits++;
			fprintf(logfile, "Player1: %d,%d ""hit""", p1x, p1y);
			int index_sunk_ship = -1;
			int sunk = check_if_sunk_ship(p2_ships, &index_sunk_ship);
			if (sunk != -1)
			{
				p2.sunk_ships += sunk;
				print_sunks(index_sunk_ship, logfile);
			}
			
			fprintf(logfile," \n");
		}
		system("pause");
		display_board(1, p1_board);
		display_board(2, p2_board);
		int y = shoot_for_computer(&x);
		update_board(p1_board, x, y, p1_ships);
		printf("Player 2 selects: %d %d\n", x, y);
		p2.total_shots++;
		if (p1_board[x][y] == 'm')
		{
			printf("%d %d is a miss!\n", x, y);
			p2.number_of_misses++;
			fprintf(logfile, "Player2: %d,%d ""miss""\n", x, y);
		}
		else if (p1_board[x][y] == '*')
		{
			printf("%d %d is a hit!\n", x, y);
			p2.number_of_hits++;
			fprintf(logfile, "Player2: %d,%d ""hit""", x, y);
			int index_sunk_ship = -1;
			int sunk = check_if_sunk_ship(p1_ships, &index_sunk_ship);
			if (sunk != -1)
			{
				p1.sunk_ships += sunk;
				print_sunks(index_sunk_ship, logfile);
			}
			fprintf(logfile," \n");
		}
		system("pause");
		system("cls");
		if (p1.sunk_ships == 5)
		{
			game_has_ended = 1;
			p2_won = 1;
		}
		else if (p2.sunk_ships == 5)
		{
			game_has_ended = 1;
			p1_won = 1;
		}
	}
	if (p1_won == 1)
	{
		printf("Player 1 Wins!\n");
	}
	else if (p2_won == 1)
	{
		printf("Player 2 Wins!\n");
	}
	p1.hit_to_miss_ratio = p1.number_of_hits / p1.number_of_misses;
	p2.hit_to_miss_ratio = p2.number_of_hits / p2.number_of_misses;
	output_stats(p1, 1, logfile);
	output_stats(p2, 2, logfile);
	fclose(logfile);
}
void output_stats(Stats stat, int flag, FILE *logfile) // works
{
	fprintf(logfile, "***** Player%d Stats *****\n", flag);
	fprintf(logfile, "Number Hits: %d\n", stat.number_of_hits);
	fprintf(logfile, "Number Misses: %d\n", stat.number_of_misses);
	fprintf(logfile, "Total Shots: %d\n", stat.total_shots);
	fprintf(logfile, "Hit/Miss Ratio: %.1lf%%\n", stat.hit_to_miss_ratio);
}
