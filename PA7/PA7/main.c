#include "poker.h"




int main(void)
{
	/* initialize suit array */
	const char *suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };

	/* initialize face array */
	const char *face[13] = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight",
		"Nine", "Ten", "Jack", "Queen", "King" };

	/* initalize deck array */
	
	srand((unsigned)time(NULL)); /* seed random-number generator */

	play_game(face, suit);
	return 0;
}