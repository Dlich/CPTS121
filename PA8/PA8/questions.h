#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
typedef struct occurrences
{
	int num_occurrences;
	double frequency;
} Occurrences;

char *my_str_n_cat(char *destination, char *source); 
int strlen(char *arr, int len1); // this is used as a helper method so i can find the length of a string
int sum_primes(unsigned int t, int sum);
int determine_if_prime(int n); // helper for figuring out if a number is prime
void maximum_occurences(char *string, Occurrences *arr, int *ptr, char *character, int counter); 
int is_palindrome(char *string, int len); 
int binary_search(int arr[], int target, int length);
void bubble_sort(char *arr_strings, int num_strings); 