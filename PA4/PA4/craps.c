#include "craps.h"
int global_win_or_lose = -1;

void print_game_rules(void) // prints the rules of the game.
{
	printf("A player rolls two dice. Each die has six faces. These faces contain 1, 2, 3, 4, 5, and 6 spots. After the dice have come to rest, the sum of the spots on the two upward faces is calculated.\n");
	printf("If the sum is 7 or 11 on the first throw, the player wins. If the sum is 2, 3, or 12 on the first throw (called ""craps""), the player loses (i.e. the ""house"" wins).\n");
	printf("If the sum is 4, 5, 6, 8, 9, or 10 on the first throw, then the sum becomes the player's ""point.""\n");
	printf("To win, you must continue rolling the dice until you ""make your point."" The player loses by rolling a 7 before making the point.\n\n");
}
int is_valid_menu_option(int n) // checks if the user chose a valid menu option, aka 1, 2 or 3.
{
	if (n == 1 || n == 2 || n == 3)
	{
		return 1;
	}
	return 0;
}
int print_main_menu(void) // prints main menu that tells the user to choose 3 options.
{
	int option = 0;
	printf("Hello! Welcome to ""Craps,"" a game of chance. Press 1 to learn the rules, press 2 to play the game, or press 3 to exit.\n");
	scanf("%d", &option);
	return option;
}
double get_bank_balance(void) // prompts the user for a bank balance
{
	double balance = 0.0;
	printf("Enter an amount for your bank balance\n");
	scanf("%lf", &balance);
	return balance;
}
double get_wager_amount(void) // prommpts the user for a wager amount
{
	double wager = 0.0;
	printf("Enter a wager for your roll\n");
	scanf("%lf", &wager);
	return wager;
}
int check_wager_amount(double wager, double balance) // verifies that the wager is greater than 0 and not greater than the balance.
{
	if (wager <= balance && wager > 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int roll_die(void) // rolls a die and returns the number rolled
{
	int die_value = 0;
	die_value = rand() % 6 + 1;

	return die_value;
}
int calculate_sum_dice(int die1_value, int die2_value) // calculates the sum of two rolled die
{
	int sum = die1_value + die2_value;
	return sum;
}
int is_win_loss_or_point(int sum_dice) // checks to see if the first roll is a win, a loss or just determines the point
{
	if (sum_dice == 7 || sum_dice == 11)
	{
		return 1;
	}
	else if (sum_dice == 2 || sum_dice == 3 || sum_dice == 12)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}
int is_point_loss_or_neither(int sum_dice, int point_value) // checks to see if a roll is a win, a loss or neither.
{
	if (sum_dice == point_value)
	{
		return 1;
	}
	else if (sum_dice == 7)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}
double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract) // adds wager to balance or subtracts wager from balance depending on if the user won or lost.
{
	if (add_or_subtract == 1)
	{
		bank_balance = bank_balance + wager_amount;
		return bank_balance;
	}
	else if (add_or_subtract == 0)
	{
		bank_balance = bank_balance - wager_amount;
		return bank_balance;
	}
	else
	{
		return bank_balance;
	}
}
void chatter_messages(int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance) // prints chatter messages depending on how good or bad a user is doing.
{
	int i = 0;
	i = roll_die();
	if (win_loss_neither == 1 && (current_bank_balance < initial_bank_balance) && i==1)
	{
		printf("Well Played! Dare to roll again?\n\n");
	}
	else if (win_loss_neither == 1 && current_bank_balance>0 && (i == 2))
	{
		printf("Thats playing to win baby!\n\n");
	}
	else if (win_loss_neither == 1 && current_bank_balance>0 && (current_bank_balance < initial_bank_balance) && (i >= 3 || i <= 4))
	{
		printf("Congrats on staying in the game!\n\n");
	}
	else if (win_loss_neither == 1 && current_bank_balance>0 && (current_bank_balance > initial_bank_balance) && (i >= 5 || i <= 6))
	{
		printf("Dominating the game, good for you!\n\n");
	}
	else if (win_loss_neither == 0 && current_bank_balance>0 && i <=2)
	{
		printf("I'm sorry for your loss. Maybe you can win next round?\n\n");
	}
	else if (win_loss_neither == 0 && current_bank_balance>0 && (i >=3 || i <=4))
	{
		printf("Try again, dont mess up this time!\n\n");
	}
	else if (win_loss_neither == 0 && current_bank_balance>0 && (i >= 5 || i <= 6))
	{
		printf("That was questionable at best...\n\n");
	}
	
}

double play_game(double balance, double wager) // plays the game.
{
	
	int valid_wager = -1, die1 = 0, die2 = 0, first_sum = 0, point = 0, win_or_lose = -1, cur_sum = 0;
	valid_wager = check_wager_amount(wager, balance); // checks to see if the wager the user entered is in range
	while (valid_wager == 0) // if wager is not in range it keeps prompting the user for a wager until it does get in range.
	{
		printf("Please enter a valid wager!\n");
		wager = get_wager_amount();
		valid_wager = check_wager_amount(wager, balance);
	}
	

	die1 = roll_die();
	die2 = roll_die();
	first_sum = calculate_sum_dice(die1, die2); // calculates the sum of the first roll
	if (is_win_loss_or_point(first_sum) == 1) // if the first sum results in a win, the wager is added to the balance and the user is prompted for a new wager.
	{
		balance = adjust_bank_balance(balance, wager, 1);
		printf("Congrats you rolled %d. You win! Balance is now %lf\n\n", first_sum, balance);
		global_win_or_lose = 1;
		
	}
	else if (is_win_loss_or_point(first_sum) == 0) // if the first sum results in a loss, the wager is subtracted from the balance and the user is prompted for a new wager.
	{
		balance = adjust_bank_balance(balance, wager, 0);
		printf("Sorry, you rolled %d. You lose! Balance is now %lf\n\n", first_sum, balance);
		global_win_or_lose = 0;
		
	}
	else // if the first sum is neither a win or loss, then the sum becomes the user's point and they have to roll until they win or lose.
	{
		
		point = first_sum;
		printf("Your point is %d. To win you have to roll that number.\n", point);
		
		while (win_or_lose == -1) // if win_or_lose is -1 then its neither a win or loss so it keeps rolling
		{
			//system("pause");
			/*
				Rolls the dice again and calculates new sum
			*/
			die1 = roll_die();
			die2 = roll_die();
			cur_sum = calculate_sum_dice(die1, die2);
			if (is_point_loss_or_neither(cur_sum, point)==1) // determines if the sum is the same as the point and results in a win
			{
				win_or_lose = 1;
				global_win_or_lose = 1;
			}
			else if (is_point_loss_or_neither(cur_sum, point) == 0) // determines if the sum results in a loss.
			{
				win_or_lose = 0;
				global_win_or_lose = 0;
			}
			// if neither of the if statements are hit then win_or_lose stays at -1 and keeps rolling dice until the user wins or losses.
		}
	}
	if (win_or_lose == 1) // if user wins after the first roll then it adds the wager to the balance and prints out a statement saying how much they won and what their current balance is.
	{
		balance = adjust_bank_balance(balance, wager, 1);
		printf("You win! You rolled %d. Balance is now %lf.\n\n", cur_sum, balance);
	}
	else if (win_or_lose == 0) // if the user losses after the first roll, then it subtracts the wager from the balance and prints out the statement saying how much they won and what their curent baalnce is.
	{
		balance = adjust_bank_balance(balance, wager, 0);
		printf("You lose. You rolled %d. Balance is now %lf.\n\n", cur_sum, balance);
	}
	return balance;
}