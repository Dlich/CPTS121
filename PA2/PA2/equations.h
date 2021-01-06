/*
	I included both of these so that I can use the sqrt(), sin(), 
	cos(), printf() and scanf() in my project.
*/

#include <stdio.h>
#include <math.h>

#define PI 3.1415926 //defined  PI here because I'm going to use it multiple times throughout my project.

/*
	I initialized the function headers here so that I didn't have to do it in main, and so
	the functions would return values other than int.
*/
double calculate_newtons_2nd_law(double mass, double acceleration);
double calculate_volume_cylinder(double radius, double height);
char perform_character_encoding(char plaintext_character, int shift);
double calculate_distance_between_2pts(double x1, double x2, double y1, double y2);
double calculate_tangent_theta(double theta);
double calculate_parallel_resistance(int R1, int R2, int R3); // I decided to use these arguments because my equation required them so it made sense for them to be added.
double calculate_general_equation(int a, double y, double x, double z); // Same as above ^