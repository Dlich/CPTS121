/**********************************************************************************************
*	Name: Daniel Lichtchouk																	  *
*	Class: CptS 121, Fall 2018;																  *
*	Programming Assignmen: PA2																  *
*	Date: 9/14/18																			  *
*	Description: This program is a continuation of PA1 that evaulates						  *
*	different equations based on inputs given by the user, however,							  *
*	this project utilizes the 3 file format with 2 source files and 1 header file.			  *
*	The equations.c source file is where all the function bodies are made and equations.h	  *
*	is the header file where the functions headers are made to intiialize the functions and,  *
*	main.c is where all the functions are called and user inputs are asked for.				  *
*																							  *
**********************************************************************************************/

	
/* To call the functions in equations.c, I include the header equations.h, and in the header 
   there is PI, <math.h> and <stdio.h>, so I can use all the methods in those headers as well. */

#include "equations.h" 

void main(void)
{
	/*
		1. I created variables for force, mass and acceleration. I asked the user for inputs for mass and
		   acceleration and called my newtons function to calculate the force, then I printed out the force
		   and the calculations I did to get the force.
	*/

	double force, mass = 0.0, acceleration = 0.0;
	printf("Please enter the mass and acceleration <both floating-point values> for use in Newton's Second Law: ");
	scanf("%lf%lf", &mass, &acceleration);
	force = calculate_newtons_2nd_law(mass, acceleration);
	printf("Newton's Second Law: Force = Mass * Acceleration = %lf * %lf = %.2lf \n\n", mass, acceleration, force);

	/*
		2. I created variables for volume, radius and height. I asked the user for inputs for radius and
		   height and called my volume function to calculate the volume of the cylinder, then I printed out the volume
		   and the calculations I did.
	*/

	double volume_cylinder = 0.0, radius=0.0, height=0.0;
	printf("Please enter the radius and height <both floating-point values> for use in a volume of a cylinder equation: ");
	scanf("%lf%lf", &radius, &height);
	volume_cylinder = calculate_volume_cylinder(radius, height);
	printf("Volume of a cylinder: volume = PI * radius^2 * height = 3.1415926 * %lf * %lf = %.2lf \n\n", radius, height, volume_cylinder);

	/*
		3. I created variables for encoded character, plain character and shift. I asked the user for inputs for shift and
	       plaintext character and called my character encoding function to encoded the character, then I printed out the
		   encoded character.
	*/

	char plaintext_character = '\0', encoded_character = '\0';
	int shift = 0;
	printf("Enter a plaintext character <Letter> and an integer shift value: ");
	scanf(" %c%d", &plaintext_character, &shift);
	encoded_character = perform_character_encoding(plaintext_character, shift);
	printf("Encoded char: %c\n\n", encoded_character);

	/*
		4. I created variables for all my coordinate points and the distance. I asked the user for inputs for the coordinate
	       points and called my distaance function to calculate the distance between the 2 coordinates, then I printed the distance
		   and what I did to find the distance.
	*/

	double x1 = 0.0, x2 = 0.0, y1 = 0.0, y2 = 0.0, distance = 0.0;
	printf("Please enter 2 coordinate points <Both floating-point values> for use in finding h distance between the two points. Input the points as so(firstX firstY secondX SecondY): ");
	scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
	distance = calculate_distance_between_2pts(x1, x2, y1, y2);
	printf("Distance between 2 points: sqrt((%lf - %lf)^2 + (%lf - %lf)^2) = %.2lf\n\n", x1, x2, y1, y2, distance);

	/*
		5. I created variables for tangent and theta. I asked the user for inputs for theta and called
	       my calculate tangent function to calculate the tangent based on theta. Then I printed the answer
		   as well as the work to show how I got to the answer.
	*/

	double tangent_theta = 0.0, theta = 0.0;
	printf("Please enter a value for Theta<floating-point value> to find the Tangent of that value: ");
	scanf("%lf", &theta);
	tangent_theta = calculate_tangent_theta(theta);
	printf("tan(%lf) = sin(%lf) / cos(%lf) = %.2lf\n\n", theta, theta, theta, tangent_theta);

	/*
		6. I created variables for R1, R2, R3, and the Parallel resistance. I asked the user for inputs for R1, R2 and R3
	       and called my calculate parallel resistance function. I set that to my parallel resistance variable and printed
		   out the result as well as the work to show how I got to the answer.
	*/

	int R1 = 0, R2 = 0, R3 = 0;
	double parallel_resistance = 0.0;
	printf("Please input 3 integer values to determine the Parallel Resistance:  ");
	scanf("%d%d%d", &R1, &R2, &R3);
	parallel_resistance = calculate_parallel_resistance(R1, R2, R3);
	printf("Parallel_resistance = 1 / ((1 / %d) + (1 / %d) + (1 / %d) = %.2lf\n\n", R1, R2, R3, parallel_resistance);

	/*
		7. I created variables for A, Y, X, Z and Answer. I asked the user for inputs for a, y, x and z
	       and called my calculate general equation function with those parameters. I set that to my answer variable and printed
		   out the result as well as the work to show how I got to the answer.
	*/

	int a = 0;
	double y = 0.0, x = 0.0, z = 0.0;
	printf("Please input 4 values, the first value being an integer and the last three being floating-point values for use in a general equation:  ");
	scanf("%d%lf%lf%lf", &a, &y, &x, &z);
	double answer = 0.0;
	answer = calculate_general_equation(a, y, x, z);
	printf("y = (2 / 3) - %lf + %lf*%lf / (%d %% 2) + PI = %.2lf\n", y, z, x, a, answer);

}