#include <stdio.h> // included both stdio.h and math.h so I could use functions from these classes such as scanf, printf, sqrt(), etc.
#include <math.h>

/*
	I initialized the function headers here so that I didn't have to do it in main, and so
	the functions would return values other than int. 
*/

double read_double(FILE *infile);
int read_integer(FILE *infile);
double calculate_sum(double number1, double number2, double number3, double number4, double number5);
double calculate_mean(double sum, int number);
double calculate_deviation(double number, double mean);
double calculate_variance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number);
double calculate_standard_deviation(double variance);
double find_max(double number1, double number2, double number3, double number4, double number5);
double find_min(double number1, double number2, double number3, double number4, double number5);
void print_double(FILE *outfile, double number);