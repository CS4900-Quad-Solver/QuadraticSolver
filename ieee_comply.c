#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>
#include "ieee_comply.h"

int check_input(double A, double B, double C)
{
	int error = 0;
	
	if(A > FLT_MAX || B > FLT_MAX || C > FLT_MAX)
	{
		error = -3;
	}
	else if(A < 0 - FLT_MAX || B < 0 - FLT_MAX < C < 0 - FLT_MAX)
	{
		error = -3;
	}
	return error;
}

int check_output(float * answers)
{
	int error = 0;
	
	if(answers[0] > FLT_MAX || answers[1] > FLT_MAX)
	{
		error = -4;
	}
	else if(answers[0] < 0 - FLT_MAX || answers[1] < 0 - FLT_MAX)
	{
		error = -4;
	}
	return error;
}
