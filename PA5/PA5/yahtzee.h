#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_game_menu(); // prints main menu
int get_menu_option(); // gets the menu option from the user
void display_array(int p1arr[], int p2arr[], int p1bonus, int p2bonus, int p1finalscore, int p2finalscore); // displays the final scores of every combo for each player and final score
void play_game(int end); // runs the game
int three_of_kind(int orig_die[], int count_die[]); // determines if there is a 3 of a kind
int four_of_kind(int orig_die[], int count_die[]); // determines if there is a 4 of a kind
int full_house(int arr[], int size); // determines if there is a full house
int small_straight(int arr[], int size); //determines if there is a small straight
int large_straight(int arr[], int size); // determines if there is a large straight
int yahtzee(int arr[], int size); // determines if there is a yahtzee
int chance(int arr[], int size); //determines if there is a chance
int sum_of_ones(int arr[]); // determines if there is sum of ones
int sum_of_twos(int arr[]); // determines if there is sum of twos
int sum_of_threes(int arr[]); // determines if there is sum of threes
int sum_of_fours(int arr[]); // determines if there is sum of fours
int sum_of_fives(int arr[]); // determines if there is sum of fives
int sum_of_sixes(int arr[]); // determines if there is sum of sixes
int is_three_of_kind(int arr[], int size); // determines if there is a 3 of a kind
int is_four_of_kind(int arr[], int size); // determines if there is a 4 of a kind
void roll_dice(int dice[], int size); // rolls all 5 dice
void count_dice(int dice[], int dice_count[], int size); // puts the rolled dice into dice_count array
void print_dice(int *dice_ptr, int size); // prints the dice
int get_total_sum(int arr[], int size); // gets the sum
void print_rules(); //prints the rules
void roll(int arr[], int index); // rolls one die for 1 index in the array
void print_game_combos(); // prints game combinations
int combo_points(int n, int dice[], int count_dice[], int *index); // calculates the score for which combination is chosen
void dice_reroll(int dice[], int amount); // rerolls the dice selected by user
void reroll(int dice[], int seconddice[]); // rerolls a single die
int add_extra_points(int arr[]); // ads the bonus if the player earned it
int valid_combo(int index, int comboarr[]); // checks if the combo chosen by the user hasn't already been picked
void clear_array(int arr[], int size); // clears the array