/*
	Name: Daniel Lichtchouk
	Class: CptS 121, Fall 2018;
	Programming Assignmen: PA1
	Date: 9/4/18
	Description: This program evaulates different equations based on inputs given by the user. 
	Equations include Newton's Second Law of Motion, Volume of a cylinder and more!

*/
#include <stdio.h>
#include <math.h>
#define PI 3.1415926;
int main(void)
{
	/* 1. I created variables for force, mass and acceleration because im going to calculate the force by doing mass*acceleration, 
		  and the mass and acceleration variables are given to me by the user. I use scan to get the values for the variables and 
		  print out what I did to find the force. 
	*/

	double force = 0.0, mass = 0.0, acceleration = 0.0;
	printf("Please enter the mass and acceleration <both floating-point values> for use in Newton's Second Law: ");
	scanf("%lf%lf", &mass, &acceleration);
	force = mass * acceleration;
	printf("Newton's Second Law: Force = Mass * Acceleration = %lf * %lf = %lf \n\n", mass, acceleration, force);

	/* 2. I created variables for the volume, radius and height. The radius and height are given by the user as inputs 
		  and I stored those inputs in the variables. I also defined PI at the top because I was gonna use PI multiple times
		  throughout my code. At the end I printed out what I used to calculate the volume, and printed out the answer.
	*/

	double volume_cylinder = 0.0, radius = 0.0, height = 0.0;
	printf("Please enter the radius and height <both floating-point values> for use in a volume of a cylinder equation: ");
	scanf("%lf%lf", &radius, &height);
	volume_cylinder = (radius*radius) * height * PI;
	printf("Volume of a cylinder: volume = PI * radius^2 * height = 3.1415926 * %lf * %lf = %lf \n\n",radius, height, volume_cylinder);

	/* 3. I created 3 variables, 2 char variables and 1 integer variable. I asked the user for a letter and a shift value, and then updated
		  the variables with the user's inputs. I then used the calculation to encode the character and printed out my solution to show the
		  user the encoded character.
	*/

	char plaintext_character = '\0', encoded_character = '\0';
	int shift = 0;
	printf("Enter a plaintext character <Letter> and an integer shift value: ");
	scanf(" %c%d", &plaintext_character, &shift);
	encoded_character = (plaintext_character - 'A') + 'a' - shift;
	printf("Encoded char: %c\n\n", encoded_character);

	/* 4. I created 5 floating point variables. Theses variables represent the x-coordinates, y-coordinates and the distance. The coordinates are determined from the
		  user inputs, in which the first pair of numbers are the first x and y's, and the second pair of numbers are the second x and y's. I then calculated the distance
		  by using the distance formula and printed my result and how I got there to show the user.
	*/

	double x1 = 0.0, x2 = 0.0, y1 = 0.0, y2 = 0.0, distance = 0.0;
	printf("Please enter 2 coordinate points <Both floating-point values> for use in finding h distance between the two points. Input the points as so(firstX First Y SecondX SecondY): ");
	scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
	distance = sqrt(((x1 - x2)*(x1 - x2)) + ((y1 - y2)*(y1 - y2)));
	printf("Distance between 2 points: sqrt((%lf - %lf)^2 + (%lf - %lf)^2) = %lf\n\n", x1, x2, y1, y2, distance);

	/* 5. I created two variables, one to represent the value Theta, and one to represent the answer (tangent of theta). I used the input of the user to
		  get my theta variable, and included <math.h> in order to call the sin and cos functions. I then diveded the sin(theta) by cos(theta) and printed
		  out my result to show the user how I got to the answer.
	*/

	double tangent_theta = 0.0, theta = 0.0;
	printf("Please enter a value for Theta<floating-point value> to find the Tangent of that value: ");
	scanf("%lf", &theta);
	tangent_theta = sin(theta) / cos(theta);
	printf("tan(%lf) = sin(%lf) / cos(%lf) = %lf\n\n", theta, theta, theta, tangent_theta);

	/* 6. I created 4 variables, 3 integers and 1 floating-point value. The floating point value would be the parallel resistance and the final answer, while
		  the three integers are inputs given by the user. I then calculated the parallel resistance with the equation and printed out the results to show the user
		  the answer and how I got there.
	*/

	int R1 = 0, R2 = 0, R3 = 0;
	double parallel_resistance = 0.0;
	printf("Please input 3 integer values to determine the Parallel Resistance:  ");
	scanf("%d%d%d", &R1, &R2, &R3);
	parallel_resistance = 1.0 / ((1.0 / R1) + (1.0 / R2) + (1.0 / R3));
	printf("Parallel_resistance = 1 / ((1 / %d) + (1 / %d) + (1 / %d) = %lf\n\n", R1, R2, R3, parallel_resistance);

	/* 7. I created 5 variables, 1 integer and 4 floating point values. I asked the user for 1 integer, and 3 floating point values and used the general equation
		  to find the answer. My yes variable was the final answer, and every other variable I used to calculate the result. In the end, I printed my result to show the
		  user the answer and the steps provided to find the answer.
	*/

	int a = 0;
	double y = 0.0, x = 0.0, z = 0.0;
	printf("Please input 4 values, the first value being an integer and the last three being floating-point values for use in a general equation:  ");
	scanf("%d%lf%lf%lf", &a, &y, &x, &z);
	double yes = 0.0;
	yes = ((double)2 / (double)3) - y + z*x / (a % 2) + PI;
	printf("y = (2 / 3) - %lf + %lf*%lf / (%d %% 2) + PI = %lf\n", y, z, x, a, yes);

	return 0;
}