/*
	Programmer: Daniel Lichtchouk                                              
	Class: CptS 121, Fall 2018                                             
	Programming Assignment: PA4                    
	Date: 10/8/18                                                                     
                                                                             
	Description: This program plays the dice game Craps and calls various
				 functions in order to run smoothly and properly.
                                                                              
*/

#include "craps.h"


void main(void)
{
	/*
		I created variables balance and wager since I prompt the user for balance and a wager for the role. 
		Initial_balance is used for the chatter function to help determine what I want to print.
		Die1, die2 are used to determine what dice I rolled, rolls is used for chatter function to
		help me figure out what to print if they win or lose. Option_chosen is to determine which main
		menu number they chose and helps me figure out what while loop to enter. k is used to validate
		their menu option and if they don't choose a correct option, it keeps prompting them to choose
		a valid input.
	*/
	double balance = 0.0, wager = 0.0, initial_balance = 0.0;
	int die1 = 0, die2 = 0, option_chosen = 0, rolls = 0;
	option_chosen = print_main_menu();
	int k = is_valid_menu_option(option_chosen);
	srand((unsigned int)time(NULL));
	while (k == 0)
	{
		printf("Please select a valid input.");
		scanf("%d", &option_chosen);
		k = is_valid_menu_option(option_chosen);
	}
	if (option_chosen == 3) // option 3 is to close the game
	{
		return 0;
	}
	if (option_chosen == 1) // option 1 is to print rules. If chosen it will print rules then allow you to play the game.
	{
		print_game_rules();
	}
	balance = get_bank_balance();
	wager = get_wager_amount();
	initial_balance = balance;
	while (balance != 0) // if option 2 is chosen, it will skip the other if statements and automatically start playing the game. Once balance hits 0 the game ends because you have run out of money.
	{
		balance = play_game(balance, wager); // calls play game with current balance and wager.
		rolls++;
		if (balance != 0) // if balance isnt 0 yet it will print chatter messages and ask for a wager for the next roll.
		{
			chatter_messages(rolls, global_win_or_lose, initial_balance, balance);
			wager = get_wager_amount();
		}
	}
	printf("Sorry you have ran out of funds. Thank you for playing!\n"); 

	
	
}