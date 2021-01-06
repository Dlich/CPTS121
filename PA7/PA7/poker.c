#include "poker.h"

void shuffle(int wDeck[][13])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

					/* for each of the 52 cards, choose slot of deck randomly */
	for (card = 1; card <= 52; card++)
	{
		/* choose new random location until unoccupied slot found */
		do
		{
			row = rand() % 4;
			column = rand() % 13;
		} while (wDeck[row][column] != 0);

		/* place card number in chosen slot of deck */
		wDeck[row][column] = card;
	}
}

/* deal cards in deck */
void deal(const int wDeck[][13], const char *wFace[], const char *wSuit[], Card arr[], int *ptr, int n)
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */
	int counter = 0;
					/* deal each of the 52 cards */
	for (card = *ptr; card <= 52; card++)
	{
		/* loop through rows of wDeck */
		for (row = 0; row <= 3; row++)
		{
			/* loop through columns of wDeck for current row */
			for (column = 0; column <= 12; column++)
			{
				/* if slot contains current card, display card */
				if (wDeck[row][column] == card && n == 0)
				{
					printf("%5s of %-8s%c", wFace[column], wSuit[row], card % 2 == 0 ? '\n' : '\t');
					arr[counter].index_face_value = column;
					arr[counter].index_suit_value = row;
					counter++;
					*ptr = *ptr + 1;
				}
				else if (wDeck[row][column] == card && n == 1)
				{
					arr[counter].index_face_value = column;
					arr[counter].index_suit_value = row;
					counter++;
					*ptr = *ptr + 1;
				}
				if (counter != 0 && counter % 5 == 0)
				{
					
					return 0;
				}

			}
		}
	}
}
void deal_specific_cards(const int wDeck[][13], const char *wFace[], const char *wSuit[], Card arr[], int *ptr, int cards_to_replace[]) // this function is used to re-deal the players cards if he chooses to.
{
	const char *suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };

	/* initialize face array */
	const char *face[13] = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight",
		"Nine", "Ten", "Jack", "Queen", "King" };
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */
	int counter = 0;
	int arr_counter = 1;
	/* deal each of the 52 cards */
	for (card = *ptr; card <= 52; card++)
	{
		/* loop through rows of wDeck */
		for (row = 0; row <= 3; row++)
		{
			/* loop through columns of wDeck for current row */
			for (column = 0; column <= 12; column++)
			{
				/* if slot contains current card, display card */
				if (wDeck[row][column] == card)
				{
					if (cards_to_replace[arr_counter] == 1)
					{

						arr[arr_counter-1].index_face_value = column;
						arr[arr_counter-1].index_suit_value = row;
						counter++;
						*ptr = *ptr + 1;
					}
					//printf("%s of %s\n", wFace[i], wSuit[j]);
					arr_counter++;
					
				}
				if (arr_counter % 6 == 0)
				{
					for (int i = 0; i < 5; i++)
					{
						//printf("%s of %s\n", face[arr[i].index_face_value], suit[arr[i].index_suit_value]);
						printf("%5s of %-8s%c", face[arr[i].index_face_value], suit[arr[i].index_suit_value], i % 2 == 0 ? '\n' : '\t');
					}
					return 0;
				}
				
			}
		}
	}
}
int contains_one_pair(int parallel_face[], int size) // takes in a parallel array of the face values of the users cards and checks if there is 1 pair
{
	int has_pair = 0;
	for (int i = 0; i < size; i++)
	{
		if (parallel_face[i] == 2)
		{
			has_pair = 1;
		}
	}
	return has_pair;
}
int contains_two_pair(int parallel_face[], int size) // takes in a parallel array of the face values of the users cards and checks if there is 2 pairs
{
	int has_2_pair = 0;
	for (int i = 0; i < size; i++)
	{
		if (parallel_face[i] == 2)
		{
			has_2_pair++;
		}
	}
	if (has_2_pair == 2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int contains_three_of_kind(int parallel_face[], int size) // takes in a parallel array of the face values of the users cards and checks if there is a 3 of a kind
{
	int contains_three = 0;
	for (int i = 0; i < size; i++)
	{
		if (parallel_face[i] == 3)
		{
			contains_three = 1;
		}
	}
	return contains_three;
}
int contains_four_of_kind(int parallel_face[], int size) // takes in a parallel array of the face values of the users cards and checks if there is a 4 of a kind
{
	int contains_four = 0;
	for (int i = 0; i < size; i++)
	{
		if (parallel_face[i] == 4)
		{
			contains_four = 1;
		}
	}
	return contains_four;
}
int contains_flush(int parallel_suit[], int size) // takes in a parallel array of the suit values of the users cards and checks if there is a flush
{
	int has_flush = 0;
	for (int i = 0; i < size; i++)
	{
		if (parallel_suit[i] == 5)
		{
			has_flush = 1;
		}
	}
	return has_flush;
}
int contains_straight(int parallel_face[], int size) // takes in a parallel array of the face values of the users cards and checks if there is a straight
{
	int is_straight = 0;
	for (int i = 0; i < size; i++)
	{
		int cur_seq = 0;
		for (int j = i + 1; j < size; j++)
		{
			if (parallel_face[i] != 0 && parallel_face[j] != 0)
			{
				cur_seq++;
			}
			else if (parallel_face[i] == 0 || parallel_face[j] == 0)
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
		return 1;
	}
	return 0;
}
void parallel_array(Card arr[], int face[], int suit[], int size) // creates parallel arrays for the face and suit values of the player/computers hands
{
	for (int i = 0; i < size; i++)
	{
		face[arr[i].index_face_value]+= 1;
		suit[arr[i].index_suit_value]+= 1;
	}
}
void play_game(const char *wFace[], const char *wSuit[]) // plays the game
{

	Card player1_hand[5] = { 0 }, computer_hand[5] = { 0 };
	int player_wins = 0, computer_wins = 0;
	int k = print_rules();
	int option = 1;
	system("cls");
	while (option <= 10) // plays ten matches between user and computer
	{
		/*
			Creates the deck and shuffles it right off the bat. Then it deals the cards to both computer and player.
			The player then gets asked if they want to change any cards, and if they do, then they can replace 3 cards.
			If they say no, then it determines who wins and prints out who wins and replays the game.
		*/
		int card_pointer = 1;
		int wDeck[4][13] = { 0 };
		shuffle(wDeck);
		deal(wDeck, wFace, wSuit, player1_hand, &card_pointer, 0);
		deal(wDeck, wFace, wSuit, computer_hand, &card_pointer, 1);
		printf("Would you like to draw any different cards? Press 1 for yes, 0 for no.\n");
		int card_changer = 0;
		scanf("%d", &card_changer);
		int cards_to_replace[6] = { 0 };
		while (card_changer == 1)
		{
			
			int cards = 0;
			printf("How many cards do you want to replace?\n");
			scanf("%d", &cards);
			if (cards == 1)
			{
				int value = 0;
				printf("Which card do you want to replace?\n");
				scanf("%d", &value);
				cards_to_replace[value] = 1;
				card_changer++;
			}
			else if (cards == 2)
			{
				printf("Which cards do you want to replace?\n");
				for (int i = 0; i < 2; i++)
				{
					int value = 0;
					scanf("%d", &value);
					cards_to_replace[value] = 1;
					card_changer++;
				}
			}
			else if (cards == 3)
			{
				printf("Which cards do you want to replace?\n");
				for (int i = 0; i < 3; i++)
				{
					int value = 0;
					scanf("%d", &value);
					cards_to_replace[value] = 1;
					card_changer++;
				}
			}
			else
			{
				printf("Please choose between 1 or 3 cards.\n");
			}
			
			
		}
		deal_specific_cards(wDeck, wFace, wSuit, player1_hand, &card_pointer, cards_to_replace);
		evaluate_dealer(wDeck, wFace, wSuit, computer_hand);
		int player_pArrSuit[4] = { 0 };
		int player_pArrFace[13] = { 0 };
		int computer_pArrSuit[4] = { 0 };
		int computer_pArrFace[13] = { 0 };
		parallel_array(player1_hand, player_pArrFace, player_pArrSuit, 5);
		parallel_array(computer_hand, computer_pArrFace, computer_pArrSuit, 5);
		if (determine_who_wins(player_pArrFace, player_pArrSuit, computer_pArrFace, computer_pArrSuit) == 1)
		{
			player_wins++;
			printf("Player won!\n");
		}
		else
		{
			computer_wins++;
			printf("Computer won!\n");
		}
		system("pause");
		system("cls");
		
		
		option++;
	} 
	printf("Player won %d rounds!\n", player_wins);
	printf("Computer won %d rounds!\n", computer_wins);
	
}
int print_rules()
{
	int option = 0;
	printf("Hi and Welcome to 5 Card Draw Poker! The rules of this game are pretty simple! \n");
	printf("The program will randomly choose 5 cards. There are 6 different possible combinations of the cards. \n");
	printf("A pair is two cards with the same face value, and a two pair is 2 sets of cards with the same face values. \n");
	printf("A three of a kind is 3 cards with the same face value and a four of a kind is 4 cards with the same value. \n");
	printf("A flush is 5 cards with the same suit, e.g. 5 hearts and a straight is 5 cards with the same consective face values, e.g. 2,3,4,5,6. \n");
	printf("if you want to change your draw, you can select up to three cards to discard and re-draw new cards. \n");
	printf("You play versus the computer. Whoever has the higher draw wins the game. Have Fun! \n");
	printf("Press any number to start the game!\n");
	scanf("%d", &option);
	return 1;
}
void evaluate_dealer(const int wDeck[][13], const char *wFace[], const char *wSuit[], Card hand[])
{
	Card pArrSuit[4] = { 0 };
	Card pArrFace[13] = { 0 };
	parallel_array(hand, pArrFace, pArrSuit, 5);
	if (contains_straight(pArrFace, 13) == 1 || contains_flush(pArrSuit,4) == 1 || contains_four_of_kind(pArrFace, 13))
	{
		return 0;
	}
	}

int determine_who_wins(int p1face[], int p1suit[], int cface[], int csuit[]) // figures out who wins by check each hand and seeing who has the higher draw
{
	int value = -1;
	if (contains_straight(p1face, 13) == 1 && contains_straight(cface, 13) == 0)
	{
		value = 1;
	}
	else if (contains_straight(p1face, 13) == 0 && contains_straight(cface, 13) == 1)
	{
		value = 0;
	}
	else if (contains_flush(p1suit, 4) == 1 && contains_flush(csuit, 4) == 0)
	{
		value = 1;
	}
	else if (contains_flush(p1suit, 4) == 0 && contains_flush(csuit, 4) == 1)
	{
		value = 0;
	}
	else if (contains_four_of_kind(p1face, 13) == 1 && contains_four_of_kind(cface, 13) == 0)
	{
		value = 1;
	}
	else if (contains_four_of_kind(p1face, 13) == 0 && contains_four_of_kind(cface, 13) == 1)
	{
		value = 0;
	}
	else if (contains_three_of_kind(p1face, 13) == 0 && contains_three_of_kind(cface, 13) == 0)
	{
		value = 1;
	}
	else if (contains_three_of_kind(p1face, 13) == 0 && contains_three_of_kind(cface, 13) != 0)
	{
		value = 0;
	}
	else if (contains_two_pair(p1face, 13) == 1 && contains_two_pair(cface, 13) == 0)
	{
		value = 1;
	}
	else if (contains_two_pair(p1face, 13) == 0 && contains_two_pair(cface, 13) == 1)
	{
		value = 0;
	}
	else if (contains_one_pair(p1face, 13) == 1 && contains_one_pair(cface, 13) == 0)
	{
		value = 1;
	}
	else if (contains_one_pair(p1face, 13) == 0 && contains_one_pair(cface, 13) == 1)
	{
		value = 0;
	}
	return value;
}
