#include "equations.h" //included the header so I could create these functions and use the stdio.h and math.h functions

double read_double(FILE *infile) // called fscanf() on the given file to take out the file in the stream and set it to my number variable then deleted it
{
	double number = 0.0;
	fscanf(infile, "%lf", &number);
	return number;
}
int read_integer(FILE *infile) // same as read_double except for integers
{
	int number = 0;
	fscanf(infile, "%d", &number);
	return number;
}
double calculate_sum(double number1, double number2, double number3, double number4, double number5) // added up all the parameters to get the sum
{
	double sum = 0.0;
	sum = number1 + number2 + number3 + number4 + number5;
	return sum;
}
double calculate_mean(double sum, int number) // make sure to check if the number was 0, and if it wasnt i divided the sum by the number to get the average and return it. If the number was 0, the  I would return -1.
{
	double mean = 0.0;
	if (number != 0)
	{
		mean = sum / number;
		return mean;
	}
	else
	{
		return -1.0;
	}
}
double calculate_deviation(double number, double mean) // calculated deviation by doing number-mean and returning it.
{
	double deviation = 0.0;
	deviation = number - mean;
	return deviation;
}
double calculate_variance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number) // The variance is similar to the mean, so I called my mean function with the sum being ann the deviations^2 and the number being whatever the number was in the parameter.
{
	double variance = 0.0;
	variance = calculate_mean((pow(deviation1,2)) + (pow(deviation2 , 2)) + (pow(deviation3 , 2)) + (pow(deviation4 , 2)) + (pow(deviation5 , 2)), number);
	return variance;

}
double calculate_standard_deviation(double variance) // calculated standard deviation by square rooting the variance.
{
	double deviation = 0.0;
	deviation = sqrt(variance);
	return deviation;
}
double find_max(double number1, double number2, double number3, double number4, double number5) // set the max to the first parameter, and compared every parameter after that to max to see if it was bigger, and if it was I changed max to that larger parameter. At the end I returned Max.
{
	double max = number1;
	if (number2 > max)
	{
		max = number2;
	}
	if (number3 > max)
	{
		max = number3;
	}
	if (number4 > max)
	{
		max = number4;
	}
	if (number5 > max)
	{
		max = number5;
	}
	return max;
}
double find_min(double number1, double number2, double number3, double number4, double number5) // set the min to the first parameter, and compared every parameter after that to min to see if it was smaller, and if it was I changed min to that smaller parameter. At the end I returned Min.
{
	double min = number1;
	if (number2 < min)
	{
		min = number2;
	}
	if (number3 < min)
	{
		min = number3;
	}
	if (number4 < min)
	{
		min = number4;
	}
	if (number5 < min)
	{
		min = number5;
	}
	return min;
}
void print_double(FILE *outfile, double number) // called fprintf on the outfile to print out the number in the Output.dat file.
{
	
	fprintf(outfile, "%.2lf\n", number);

}