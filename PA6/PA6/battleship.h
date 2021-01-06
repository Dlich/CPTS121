#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define row 10
#define col 10
typedef struct Stats // I use this struct for stats so i can easily print out the stats to my log file
{
	int number_of_hits;
	int number_of_misses;
	int total_shots;
	double hit_to_miss_ratio;
	int sunk_ships;
}Stats;


void welcome_screen(void);
void initialize_game_board(char board[row][col]);
int select_who_starts_first();
void display_board(int flag, char board[row][col]);
void update_board(char board[row][col], int row1, int col1, int ships[5]);
void output_stats(Stats stat, int flag, FILE *logfile);
void randomly_place_ships_on_board(char board[row][col]);
int check_shot(char board[row][col], int row1, int col1);
int shoot_for_computer(int *ptr);
int check_if_sunk_ship(int ships[5], int *ptr);
void manually_place_ships_on_board(char board[row][col]);
void play_game();
void print_sunks(int index, FILE *logfile);



