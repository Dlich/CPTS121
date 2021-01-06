#ifndef POKER_H
#define POKER_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Card
{
	int index_face_value;
	int index_suit_value;
} Card;

void shuffle(int wDeck[][13]);
void deal(const int wDeck[][13], const char *wFace[], const char *wSuit[], Card arr[], int *ptr, int n);
int contains_one_pair(int parallel_face[], int size);
int contains_two_pair(int parallel_face[], int size);
int contains_three_of_kind(int parallel_face[], int size);
int contains_four_of_kind(int parallel_face[], int size);
int contains_flush(int parallel_suit[], int size);
int contains_straight(int parallel_face[], int size);
void parallel_array(Card arr[], int face[], int suit[], int size);
void deal_specific_cards(const int wDeck[][13], const char *wFace[], const char *wSuit[], Card arr[], int *ptr, int cards_to_replace[]);
void play_game( const char *wFace[], const char *wSuit[]);
int print_rules();
void evaluate_dealer(const int wDeck[][13], const char *wFace[], const char *wSuit[], Card hand[]);
int determine_who_wins(int p1face[], int p1suit[], int cface[], int csuit[]);
#endif