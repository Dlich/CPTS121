#include "yahtzee.h"

void roll_dice(int dice[], int size) // rolls every dice my using rand()
{
	int index = 0;

	for (; index < size; ++index)
	{
		dice[index] = rand() % 6 + 1;
	}
}
void roll(int arr[], int index) // rols a single die by using rand()
{
	arr[index] = rand() % 6 + 1;
}
void count_dice(int dice[], int dice_count[], int size) // transfers the contents in dice to dice_count to format it in an easier way so i can use it to determine the cores
{
	int index = 0;

	for (; index < size; ++index)
	{
		dice_count[dice[index]] += 1;
	}
}
int get_total_sum(int arr[], int size) // loops through entire array and adds the scores to determine the sum
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	return sum;
}
int sum_of_ones(int arr[]) // checks the dice_count array and index 1 to see how many 1's were rolled and multiplies it by 1 to determine sum
{
	int count = arr[1] * 1;
	return count;
}
int sum_of_twos(int arr[]) // checks the dice_count array and index 2 to see how many 2's were rolled and multiplies it by 2 to determine sum
{
	int count = arr[2] * 2;
	return count;
}
int sum_of_threes(int arr[]) // checks the dice_count array and index 3 to see how many 3's were rolled and multiplies it by 3 to determine sum
{
	int count = arr[3] * 3;
	return count;
}
int sum_of_fours(int arr[]) // checks the dice_count array and index 4 to see how many 4's were rolled and multiplies it by 4 to determine sum
{
	int count = arr[4] * 4;
	return count;
}
int sum_of_fives(int arr[]) // checks the dice_count array and index 5 to see how many 5's were rolled and multiplies it by 5 to determine sum
{
	int count = arr[5] * 5;
	return count;
}
int sum_of_sixes(int arr[]) // checks the dice_count array and index 6 to see how many 6's were rolled and multiplies it by 6 to determine sum
{
	int count = arr[6] * 6;
	return count;
}
int three_of_kind(int orig_die[], int count_die[]) // calls is_three_of_kind to determine if there are 3 of a kind and then calculates total sum
{
	int is_three = is_three_of_kind(count_die, 7);
	int sum = 0;
	if (is_three == 1)
	{
		sum = get_total_sum(orig_die, 5);
	}
	return sum;
}
int four_of_kind(int orig_die[], int count_die[]) // calls is_four_of_kind to determine if there are 4 of a kind and then calculates total sum
{
	int is_four = is_four_of_kind(count_die, 7);
	int sum = 0;
	if (is_four == 1)
	{
		sum = get_total_sum(orig_die, 5);
	}
	return sum;
}
int full_house(int arr[], int size) // checks in dice_count to see if 1 number was rolled twice, and another number rolled three times. If there is a full house then it returns 25.
{
	int is_three = 0;
	int is_there_pair = 0;
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == 2)
		{
			is_there_pair = 1;
		}
		if (arr[i] == 3)
		{
			is_three = 1;
		}
	}
	if (is_three == 1 && is_there_pair == 1)
	{
		sum = 25;
	}
	return sum;
}
int small_straight(int arr[], int size) //goes through dice_count to find the largest sequence, and if that sequence is greater than or equal to 3 then there is a small straight
{
	int sum = 0;
	int is_straight = 0;
	/*for (int i = 0; i < size; i++) // old solution that didn't work for every case
	{
		if ((arr[i]>0 && arr[i] < 7) && ((arr[i + 1] > 0 && arr[i + 1] < 7)))
		{

			is_straight++;
			printf("is_straight = %d. Index I: %d, Size: %d, arr[i] = %d, arr[i+1] = %d\n", is_straight, i, size, arr[i], arr[i + 1]);
		}
		
		
	}*/
	for (int i = 0; i < size; i++)
	{
		int cur_seq = 0;
		for (int j = i+1; j < size; j++)
		{
			if (arr[i]!=0 && arr[j] != 0)
			{
				cur_seq++;
			}
			else if (arr[i] == 0 || arr[j] == 0)
			{
				break;
			}
		}
		if (cur_seq > is_straight)
		{
			is_straight = cur_seq;
		}
	}
	//printf("is_straight = %d", is_straight); // testing project
	if (is_straight >= 3)
	{
		sum = 30;
	}
	return sum;
}
int large_straight(int arr[], int size) //goes through dice_count to find the largest sequence, and if that sequence is greater than or equal to 4 then there is large straight
{
	int sum = 0;
	int is_straight = 0;
	/*for (int i = 0; i < size; i++) // old solution
	{
		if ((arr[i]>0 && arr[i] < 7) && ((arr[i+1] > 0 && arr[i+1] < 7)))
		{
			
			is_straight++;
			printf("is_straight = %d. Index I: %d, Size: %d, arr[i] = %d, arr[i+1] = %d\n", is_straight, i, size, arr[i], arr[i+1]);
		}
	}
	printf("straight = %d", is_straight);
	*/
	for (int i = 0; i < size; i++)
	{
		int cur_seq = 0;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i] != 0 && arr[j] != 0)
			{
				cur_seq++;
			}
			else if (arr[i] == 0 || arr[j] == 0)
			{
				break;
			}
		}
		if (cur_seq > is_straight)
		{
			is_straight = cur_seq;
		}
	}
	if (is_straight >= 4)
	{
		sum = 40;
	}
	return sum;
}
int yahtzee(int arr[], int size) // checks dice_count to see if 1 die value was rolled 5 times, the returns 50.
{
	int count = 0;
	for (int i = 1; i < size; i++)
	{
		if (arr[i] == 5)
		{
			count = 50;
		}
	}
	return count;
}
int chance(int arr[], int size) // gets total sum of the dice array and returns it
{
	int count = get_total_sum(arr,size);
	return count;
}
int is_three_of_kind(int arr[], int size) // checks if dice_counted has a value that was rolled 3 times and returns 1 if yes, 0 if no
{
	int is_three = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == 3)
		{
			is_three = 1;
		}
	}
	return is_three;
}
int is_four_of_kind(int arr[], int size) // checks if dice_counted has a value that was rolled 4 times and returns 1 if yes, 0 if no
{
	int is_four = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == 4)
		{
			is_four = 1;
		}
	}
	return is_four;
}
void print_dice(int *dice_ptr, int size) // prints the rolled dice
{
	int index = 0;

	for (; index < size; ++index)
	{
		printf("die %d: %d\n", index + 1, dice_ptr[index]);
	}
}
void print_game_menu() // prints main menu
{
	printf("Hello! Welcome to the game of Yahtzee! Press 1 to learn the rules. Press 2 to start the game. Press 3 to Exit.\n");


}
int get_menu_option()
{
	int option = -1;
	scanf("%d", &option);
	return option;
}
void display_array(int p1arr[], int p2arr[], int p1bonus, int p2bonus, int p1finalscore, int p2finalscore) // displays final scores and what each player scored by looking at players scorecards
{
	printf("Scoreboard\n");
	printf("Combos			Player 1	Player 2\n");
	printf("Ones			%d		  %d\n", p1arr[1], p2arr[1]);
	printf("Twos			%d		  %d\n", p1arr[2], p2arr[2]);
	printf("Threes			%d		  %d\n", p1arr[3], p2arr[3]);
	printf("Fours			%d		  %d\n", p1arr[4], p2arr[4]);
	printf("Fives			%d		  %d\n", p1arr[5], p2arr[5]);
	printf("Sixes			%d		  %d\n", p1arr[6], p2arr[6]);
	printf("Three of a kind		%d		  %d\n", p1arr[7], p2arr[7]);
	printf("Four of a kind		%d		  %d\n", p1arr[8], p2arr[8]);
	printf("Full house              %d		  %d\n", p1arr[9], p2arr[9]);
	printf("Small straight		%d		  %d\n", p1arr[10], p2arr[10]);
	printf("Large straight		%d		  %d\n", p1arr[11], p2arr[11]);
	printf("Chance			%d		  %d\n", p1arr[12], p2arr[12]);
	printf("YAHTZEE			%d		  %d\n", p1arr[13], p2arr[13]);
	printf("Fours			%d		  %d\n", p1bonus, p2bonus);
	printf("Total Score		%d		  %d\n", p1finalscore, p2finalscore);
}
int is_valid_menu_option(int option)
{
	int t = 0;
	if (option == 1 || option == 2 || option == 3)
	{
		t = 1;
	}
	return t;
}
void clear_array(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = 0;
	}
}
void play_game(int end)
{
	int end1 = end;
	while (end1 == 0)
	{
		int p1_scorecard[14] = { -1, }, p1_combination_used[14] = { 0 }, p2_scorecard[14] = { -1, -1 }, p2_combination_used[14] = { 0 };
		int option = 0, game_has_ended = 0, numberofroll = 0, rounds = 1;
		
		print_game_menu();
		option = get_menu_option();
		int valid_option = is_valid_menu_option(option);
		while (valid_option == 0)
		{
			printf("Please select a valid input.\n");
			option = get_menu_option();
			valid_option = is_valid_menu_option(option);
		}
		system("cls");
		while (option == 1)
		{
			print_rules();
			print_game_menu();
			option = get_menu_option();
			int valid_option = is_valid_menu_option(option);
			while (valid_option == 0)
			{
				printf("Please select a valid input.\n");
				option = get_menu_option();
				valid_option = is_valid_menu_option(option);
			}
		}
		system("cls");

		if (option == 3)
		{
			printf("Goodbye for now. Hope to see you back soon!\n");
			return 0;
		}
		if (option == 2)
		{
			system("pause");
			int round_determiner = 0;
			while (game_has_ended == 0)
			{
				
				if (round_determiner % 2 == 0)
				{
					int dice[5] = { 0 };
					int dice_count[7] = { 0 };
					roll_dice(dice, 5);
					count_dice(dice, dice_count, 5);
					print_dice(dice, 5);
					numberofroll++;
					int combo_chosen = 0;
					while (numberofroll < 4)
					{
						printf("Hi Player One, Would you like to use the roll for any game combinations? Type 1 for Yes, Type 2 for No.\n");
						print_game_combos();
						int combo_option = 0;
						scanf("%d", &combo_option);

						if (numberofroll == 3)
						{
							printf("You just did a final roll please choose a combo!\n");
							int combo = 0;
							printf("Which combo do you choose?\n");
							scanf("%d", &combo);
							combo_chosen = 1;
							int index = combo;

							int temp_sum = 0;
							while (p1_combination_used[combo] == 1)
							{
								combo = valid_combo(combo, p1_combination_used);
							}
							temp_sum = combo_points(combo, dice, dice_count, &index);
							//printf("temp_sum = %d", temp_sum); // test code
							p1_combination_used[combo] = 1;
							p1_scorecard[index] = temp_sum;
							numberofroll = 3;
							combo_chosen = 0;
						}
						else if (combo_option == 1)
						{
							int combo = 0;
							printf("Which combo do you choose?\n");
							scanf("%d", &combo);
							combo_chosen = 1;
							int index = combo;
							
							int temp_sum = 0;
							while (p1_combination_used[combo] == 1)
							{
								combo = valid_combo(combo, p1_combination_used);
							}
							temp_sum = combo_points(combo, dice, dice_count, &index);
							//printf("temp_sum = %d", temp_sum); test code
							p1_combination_used[combo] = 1;
							p1_scorecard[index] = temp_sum;
							numberofroll = 3;
							
						}
						else if (combo_option == 2)
						{

							printf("How many dice would you like to reroll? 0, 1, 2, 3, 4, and/or 5?\n");
							int amount_dice = 0;
							scanf("%d", &amount_dice);
							dice_reroll(dice, amount_dice);
							print_dice(dice, 5);
							clear_array(dice_count, 7);
							count_dice(dice, dice_count, 5);
						}
						numberofroll++;

					}
					
				}
				round_determiner++;
				numberofroll = 0;
				//printf("round = %d\n", rounds); test code
				system("pause");
				system("cls");
				if ((round_determiner % 2) != 0)
				{
					int dice[5] = { 0 };
					int dice_count[7] = { 0 };
					roll_dice(dice, 5);
					count_dice(dice, dice_count, 5);
					print_dice(dice, 5);
					numberofroll++;
					int combo_chosen = 0;
					while (numberofroll < 4)
					{
						printf("Hi, Player Two. Would you like to use the roll for any game combinations? Type 1 for Yes, Type 2 for No.\n");
						print_game_combos();
						int combo_option = 0;
						scanf("%d", &combo_option);
						if (numberofroll == 3)
						{
							printf("You just did a final roll please choose a combo!\n");
							int combo = 0;
							printf("Which combo do you choose?\n");
							scanf("%d", &combo);
							combo_chosen = 1;
							int index = combo;

							int temp_sum = 0;
							while (p2_combination_used[combo] == 1)
							{
								combo = valid_combo(combo, p2_combination_used);
							}
							temp_sum = combo_points(combo, dice, dice_count, &index);
							//printf("temp_sum = %d", temp_sum); // test code
							p2_combination_used[combo] = 1;
							p2_scorecard[index] = temp_sum;
							numberofroll = 3;
							combo_option = 0;
						}
						else if (combo_option == 1)
						{
							int combo = 0;
							printf("Which combo do you choose?\n");
							scanf("%d", &combo);
							combo_chosen = 1;
							int index = combo;
							int temp_sum = 0;
							while (p2_combination_used[combo] == 1)
							{
								combo = valid_combo(combo, p2_combination_used);
							}
							temp_sum = combo_points(combo, dice, dice_count, &index);
							//printf("temp_sum = %d", temp_sum); test code
							p2_combination_used[combo] = 1;
							p2_scorecard[index] = temp_sum;
							numberofroll = 3;
							
						}
						else if (combo_option == 2)
						{

							printf("How many dice would you like to reroll? 0, 1, 2, 3, 4, and/or 5?\n");
							int amount_dice = 0;
							scanf("%d", &amount_dice);
							dice_reroll(dice, amount_dice);
							print_dice(dice, 5);
							clear_array(dice_count, 7);
							count_dice(dice, dice_count, 5);
						}
						numberofroll++;

					}
					
				}
				numberofroll = 0;
				round_determiner++;
				rounds++;
				if (rounds == 14)
				{
					game_has_ended = 1;
				}
				//printf("round = %d\n", rounds); test code
				system("pause");
				system("cls");

			}
			int p1_sum = get_total_sum(p1_scorecard, 14) + 1;
			int p2_sum = get_total_sum(p2_scorecard, 14) + 1;
			int p1_bonus = 0;
			int p2_bonus = 0;
			if (add_extra_points(p1_scorecard) >= 63)
			{
				p1_sum += 35;
				p1_bonus = add_extra_points(p1_scorecard);
			}
			if (add_extra_points(p2_scorecard) >= 63)
			{
				p2_sum += 35;
				p2_bonus = add_extra_points(p2_scorecard);
			}
			if (p1_sum > p2_sum)
			{
				printf("Congrats Player 1 you won! Player 1 score: %d, Player 2 score: %d\n", p1_sum, p2_sum);
			}
			else if (p2_sum > p1_sum)
			{
				printf("Congrats Player 2 you won! Player 2 score: %d, Player 1 score: %d\n", p2_sum, p1_sum);
			}
			display_array(p1_scorecard, p2_scorecard, p1_bonus, p2_bonus, p1_sum, p2_sum);
			system("pause");
			system("cls");
			printf("Would you like to play again? Press 0 for Yes, Press any other number for No.\n");
			scanf("%d", &end1);
		}
	}

}
int valid_combo(int index, int comboarr[])
{
	int combo = -1;
	printf("You have already chosen this combo please choose a different combo!\n");
	scanf("%d", &combo);
	return combo;
}
int add_extra_points(int arr[])
{
	int sum = 0;
	sum = get_total_sum(arr, 7) + 1;
	return sum;
}
void reroll(int dice[], int seconddice[])
{
	for (int i = 0; i < 5; i++)
	{
		int j = seconddice[i];
		if (seconddice[i] != 0)
		{
			roll(dice, j - 1);
		}
	}
}
void dice_reroll(int dice[], int amount)
{
	int temp_dice[5] = { 0 };
	printf("Which dice would you like to reroll? (Put a space between each die).\n");
	if (amount == 0)
	{
		return 0;
	}
	else if (amount == 1)
	{
		scanf("%d" ,&temp_dice[0]);
		reroll(dice, temp_dice);
	}
	else if (amount == 2)
	{
		scanf("%d%d", &temp_dice[0], &temp_dice[1]);
		//printf("1st: %d, 2nd: %d", temp_dice[0], temp_dice[1]);
		reroll(dice, temp_dice);
	}
	else if (amount == 3)
	{
		scanf("%d%d%d", &temp_dice[0], &temp_dice[1], &temp_dice[2]);
		//printf("1st: %d, 2nd: %d", temp_dice[0], temp_dice[1]);
		reroll(dice, temp_dice);
	}
	else if (amount == 4)
	{
		scanf("%d%d%d%d", &temp_dice[0], &temp_dice[1], &temp_dice[2], &temp_dice[3]);
		//printf("1st: %d, 2nd: %d", temp_dice[0], temp_dice[1]);
		reroll(dice, temp_dice);
	}
	else if (amount == 5)
	{
		scanf("%d%d%d%d%d", &temp_dice[0], &temp_dice[1], &temp_dice[2], &temp_dice[3], &temp_dice[4]);
		//printf("1st: %d, 2nd: %d", temp_dice[0], temp_dice[1]);
		reroll(dice, temp_dice);
	}
}
void print_rules()
{
	printf("The scorecard used for Yahtzee is composed of two sections. A upper section and a lower section. A total of thirteen boxes or thirteen scoring combinations are divided amongst the sections.\n");
	printf("The upper section consists of boxes that are scored by summing the value of the dice matching the faces of the box. If a player rolls four 3's, then the score placed in the 3's box is the sum of the dice which is 12.\n");
	printf("Once a player has chosen to score a box, it may not be changed and the combination is no longer in play for future rounds.\n");
	printf("If the sum of the scores in the upper section is greater than or equal to 63, then 35 more points are added to the players overall score as a bonus. The lower section contains a number of poker like combinations.\n");
	printf("Combo One: Three-of-a-kind: Three dice with the same face. Score: Sum of all face values on the 5 dice\n");
	printf("Combo Two: Four-of-a-kind: Four dice with the same face. Score: Sum of all face values on the 5 dice\n");
	printf("Combo Three: Full House: One pair and a three-of-a-kind. Score: 25\n");
	printf("Combo Four: Small straight: A sequence of four dice. Score: 30\n");
	printf("Combo Five: Large straight: A sequence of five dice, Score: 40\n");
	printf("Combo Six: Yahtzee: Five dice with the same face. Score: 50\n");
	printf("Combo Seven: Chance: May be used for any sequence of dice. This is the catch all combination. Score: Sum of all face values on the 5 dice\n");

}
void print_game_combos()
{
	printf("1. Sum of 1's		7. Three-of-a-kind\n");
	printf("2. Sum of 2's		8. Four-of-a-kind\n");
	printf("3. Sum of 3's		9. Full House\n");
	printf("4. Sum of 4's		10. Small straight\n");
	printf("5. Sum of 5's		11. Large straight\n");
	printf("6. Sum of 6's		12. Yahtzee\n");
	printf("	     13. Chance\n");
}
int combo_points(int n, int dice[], int count_dice[], int *index)
{
	int score = 0;

	if (n == 1)
	{
		score = sum_of_ones(count_dice);
		*index = 1;
	}
	else if (n == 2)
	{
		score = sum_of_twos(count_dice);
		*index = 2;
	}
	else if (n == 3)
	{
		score = sum_of_threes(count_dice);
		*index = 3;
	}
	else if (n == 4)
	{
		score = sum_of_fours(count_dice);
		*index = 4;
	}
	else if (n == 5)
	{
		score = sum_of_fives(count_dice);
		*index = 5;
	}
	else if (n == 6)
	{
		score = sum_of_sixes(count_dice);
		*index = 6;
	}
	else if (n == 7)
	{
		score = three_of_kind(dice, count_dice);
		*index = 7;
	}
	else if (n == 8)
	{
		score = four_of_kind(dice, count_dice);
		*index = 8;
	}
	else if (n == 9)
	{
		score = full_house(count_dice, 7);
		*index = 9;
	}
	else if (n == 10)
	{
		score = small_straight(count_dice, 7);
		*index = 10;
	}
	else if (n == 11)
	{
		score = large_straight(count_dice, 7);
		*index = 11;
	}
	else if (n == 12)
	{
		score = yahtzee(count_dice, 7);
		*index = 12;
	}
	else if (n == 13)
	{
		score = chance(dice, 5);
		*index = 13;
	}
	return score;

}
