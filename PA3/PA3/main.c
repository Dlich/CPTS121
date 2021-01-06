/**********************************************************************************************
*	Name: Daniel Lichtchouk																	  *
*	Class: CptS 121, Fall 2018;																  *
*	Programming Assignmen: PA3																  *
*	Date: 9/21/18																			  *
*	Description: This program takes values from a input file and gets 5 students			  *
*	Student Id numbers, GPA's, Age's and Class standing. With these values, our 			  *
*	objective was to find the average GPA, the class standing average, age average			  *
*   standard deviation of the gpa, the minimum GPA and the maximum GPA.						  *
*																							  *
**********************************************************************************************/


#include "equations.h"



void main(void)
{
	double gpa_mean = 0.0, class_standing_mean = 0.0, age_mean = 0.0, 
		gpa_standard_deviation = 0.0, gpa_min = 0.0, gpa_max = 0.0;

	FILE *infile = NULL, *outfile = NULL;

	infile = fopen("Input.dat", "r");
	outfile = fopen("Output.dat", "w");

	// Created Variables for every students ID, GPA, CLass and Age. ID, GPA and Age were doubles, Class were integers
	double student_id_1 = 0.0, student_gpa_1 = 0.0, student_age_1 = 0.0, student_id_2 = 0.0, student_gpa_2 = 0.0, student_age_2 = 0.0, 
		student_id_3 = 0.0, student_gpa_3 = 0.0, student_age_3 = 0.0, student_id_4 = 0.0, student_gpa_4 = 0.0, student_age_4 = 0.0, 
		student_id_5 = 0.0, student_gpa_5 = 0.0, student_age_5 = 0.0;

	int student_class_1 = 0, student_class_2 = 0, student_class_3 = 0, student_class_4 = 0, student_class_5 = 0;

	/*
		I kept calling read_double and read_integer, and setting those values into my variables that I created for each student.
	*/

	student_id_1 = read_double(infile);
	student_gpa_1 = read_double(infile);
	student_class_1 = read_integer(infile);
	student_age_1 = read_double(infile);
	student_id_2 = read_double(infile);
	student_gpa_2 = read_double(infile);
	student_class_2 = read_integer(infile);
	student_age_2 = read_double(infile);
	student_id_3 = read_double(infile);
	student_gpa_3 = read_double(infile);
	student_class_3 = read_integer(infile);
	student_age_3 = read_double(infile);
	student_id_4 = read_double(infile);
	student_gpa_4 = read_double(infile);
	student_class_4 = read_integer(infile);
	student_age_4 = read_double(infile);
	student_id_5 = read_double(infile);
	student_gpa_5 = read_double(infile);
	student_class_5 = read_integer(infile);
	student_age_5 = read_double(infile);

	double gpa_sum = calculate_sum(student_gpa_1, student_gpa_2, student_gpa_3, student_gpa_4, student_gpa_5);
	double class_gpa = calculate_sum(student_class_1, student_class_2, student_class_3, student_class_4, student_class_5);
	double sum_age = calculate_sum(student_age_1, student_age_2, student_age_3, student_age_4, student_age_5);

	gpa_mean = calculate_mean(gpa_sum, 5);
	print_double(outfile, gpa_mean);

	class_standing_mean = calculate_mean(class_gpa, 5);
	print_double(outfile, class_standing_mean);

	age_mean = calculate_mean(sum_age, 5);
	print_double(outfile, age_mean);

	gpa_standard_deviation = calculate_standard_deviation(calculate_variance(calculate_deviation(student_gpa_1, gpa_mean), calculate_deviation(student_gpa_2, gpa_mean), calculate_deviation(student_gpa_3, gpa_mean), calculate_deviation(student_gpa_4, gpa_mean), calculate_deviation(student_gpa_5, gpa_mean), 5));
	print_double(outfile, gpa_standard_deviation);

	gpa_min = find_min(student_gpa_1, student_gpa_2, student_gpa_3, student_gpa_4, student_gpa_5);
	print_double(outfile, gpa_min);

	gpa_max = find_max(student_gpa_1, student_gpa_2, student_gpa_3, student_gpa_4, student_gpa_5);
	print_double(outfile, gpa_max);

	fclose(infile);
	fclose(outfile);
}