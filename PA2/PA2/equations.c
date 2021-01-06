#include "equations.h" //included equations.h so that I could create these methods as well as use the math.h functions and PI.

double calculate_newtons_2nd_law(double mass, double acceleration) // I created a force variable and used the arguments for my calculation then returned that force variable
{
	double force = 0.0;
	force = mass * acceleration;
	return force;
}
double calculate_volume_cylinder(double radius, double height) // I created a volume variable and used the arguments for my calculation, as well as PI which was defined in equations.h
{
	double volume = 0.0;
	volume = (radius*radius) * height * PI;
	return volume;

}
char perform_character_encoding(char plaintext_character, int shift) // I created a char character and used the arguments provided to encoded the character, then I returned the character.
{
	char encoded_character = '\0';
	encoded_character = (plaintext_character - 'A') + 'a' - shift;
	return encoded_character;
}
double calculate_distance_between_2pts(double x1, double x2, double y1, double y2) // I created a distance variable, and used the arguments provided, as well as the sqrt() function to do my calculation, then I returned the distance.
{
	double distance = 0.0;
	distance = sqrt(((x1 - x2)*(x1 - x2)) + ((y1 - y2)*(y1 - y2)));
	return distance;
}
double calculate_tangent_theta(double theta) // I created a tangent variable, and used the sin() and cos() functions from <math.h> to compute the tangent of the value passed in the argument, then returned it.
{
	double tangent = 0.0;
	tangent = sin(theta) / cos(theta);
	return tangent;
}
double calculate_parallel_resistance(int R1, int R2, int R3) // I created a variable to store the result of my equation, and used the arguemnts passed to me for the equation, then returned the variable.
{
	double parallel_resistance = 0.0;
	parallel_resistance = (double)1 / (((double)1 / R1) + ((double)1 / R2) + ((double)1 / R3));
	return parallel_resistance;
}
double calculate_general_equation(int a, double y, double x, double z) // ^same as parallel resistance, I created a variable to store the result of my equation, used the arguments for the equation then returned the variable.
{
	double answer = 0.0;
	answer = ((double)2 / 3) - y + z*x / (double)(a % 2) + PI;
	return answer;
}