#include <stdio.h> // included this header so I can use printf and scanf.
#include <stdlib.h> // included this header so I can use rand(), srand()
#include <time.h> // included this header so I can use time for my srand()
extern int global_win_or_lose; // I created a global variable to track whether the previous roll was a win or a loss because it made sense  
							   // in my head for it to constantly change and I would change this in multiple functions.

/*
	Below are all the function headers for my functions. I used the standard function headers Andy gave us and added 
	a couple of functions such as is_valid_menu_option, play_game and print_main_menu.
*/

void print_game_rules(void);
int is_valid_menu_option(int n);
int print_main_menu(void);
double get_bank_balance(void);
double get_wager_amount(void);
int check_wager_amount(double wager, double balance);
int roll_die(void);
int calculate_sum_dice(int die1_value, int die2_value);
int is_win_loss_or_point(int sum_dice);
int is_point_loss_or_neither(int sum_dice, int point_value);
double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract);
void chatter_messages(int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance);
double play_game(double balance, double wager);