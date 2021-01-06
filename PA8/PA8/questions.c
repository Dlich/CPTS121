#include "questions.h"

char *my_str_n_cat(char *destination, char *source)
{
	char *copy = destination;
	while (*copy != '\0')
	{
		copy++;
	}
	
	while (*source != '\0')
	{
		*copy = *source;
		copy++;
		source++;
	}
	return destination;
}

int strlen(char *arr, int len1)
{
	int len = 0;
	if (*(arr) == '\0')
	{
		return len1;
	}
	len++;
	return strlen(arr + 1, len + len1);
}
int sum_primes(unsigned int n, int sum)
{
	if (n == 1) // 1 is not a prime number and its the last number so it returns the sum once it reaches one 
	{
		return sum;
	}
	int cur_sum = 0;
	if (determine_if_prime(n) == 0) // determines if the number is prime then adds it to the sum
	{
		cur_sum += n;
	}
	return sum_primes(n - 1, sum + cur_sum); // calls function again but with n-1 to check the rest of the numbers, since I start at n and subtract 1 until it hits 1.
	
}
int determine_if_prime(int n) // helper method that figures out if a value is prime or not
{
	int return_value = 0;
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
		{
			return_value = 1;
		}
	}

	return return_value;
}
void maximum_occurences(char *string, Occurrences *arr, int *ptr, char *character, int counter)
{
	if (*(string) == '\0') // if the string equals null, then its the end of the string and i should exit out
	{
		return;
	}
	/*
		My occurences array is of size 128 for each ascii character so I can get all the letters.
		I get the ascii from the letter and in my array add 1 to num_occurences for the ascii code of the letter.
		I then check to see if the num_occurences for the word i just checked is bigger than the pointer, and
		if it is a set the ptr to that leters num_occurences and the character to that letter.
	*/
	char c = *(string);
	int ascii = (int)c;
	arr[ascii].num_occurrences++;
	printf("Num_occurences for %c: %d\n", c, arr[ascii].num_occurrences);
	arr[ascii].frequency = arr[ascii].num_occurrences / (counter);
	if (arr[ascii].num_occurrences > *ptr)
	{
		*ptr = arr[ascii].num_occurrences;
		*character = c;
	}
	maximum_occurences(string + 1, arr, ptr, character, counter + 1);

}

int is_palindrome(char *string, int len)
{
	if (*(string) == string[len-1])
	{
		return 1;
	}
	if (*(string) != string[len-1])
	{
		return 0;
	}

	return is_palindrome(string + 1, len - 1);
}
int binary_search(int arr[], int target, int length) // followed exact PA8 instructions for binary search
{
	int left = 0, right = length, targetindex = -1, found = 0;
	
	while (found == 0 && left <= right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] == target)
		{
			found = 1;
			targetindex = mid;
		}
		if (target < arr[mid])
		{
			right = mid - 1;
		}
		if (target > arr[mid])
		{
			left = mid + 1;
		}
	}
	return targetindex;
}

void bubble_sort(char *arr_strings, int num_strings) // followed exact PA8 instructions for bubble sort
{
	int u = num_strings;
	char *temp;
	while (u > 1)
	{
		int c = 1;
		while(c < u)
		{
			if (strcmp(arr_strings[c], arr_strings[c - 1]))
			{
				temp = arr_strings[c];
				arr_strings[c] = arr_strings[c-1];
				arr_strings[c - 1] = temp;
			}
			c++;
		}
		u--;
	}
}