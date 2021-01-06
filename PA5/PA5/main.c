/*
Programmer: Daniel Lichtchouk
Class: CptS 121, Fall 2018
Programming Assignment: PA5
Date: 10/24/18

Description: This is a command prompt C program that plays Yahtzee in text-based format.

*/
#include "yahtzee.h"

void main(void)
{
	srand((unsigned int)time(NULL));
	play_game(0); // runs the game and takes in 0 so the user can keep playing without closing the game. If 0 is changed then game is finished and has to be restarted.
}
