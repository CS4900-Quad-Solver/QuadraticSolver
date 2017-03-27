#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <errno.h>
#include "calc_quad.h"
#include "calc_discrim.h"
#include "calc_denom.h"
#include "ieee_comply.h"

/*Calculates the quadratic, then stores answers in answers array*/
int calculate_quadratic(double A, double B, double C, float * answers)
{
    double denominator;
    double discriminate;
	int error = 0;
	
    /*Checks if function returns -1, if so, there are no solutions*/
	if ((denominator = calculate_denominator(A)) == 0)
	{
		error = -2;
	}
	else
	{
		/*Checks if function returns -1, if so there are no read solutions*/
		if((discriminate = calculate_discriminate(A,B,C)) == -1)
		{
			error = -1;
		}
		else
		{
			/*Calcuating X1 and X2, then return them.*/
			answers[0] = (-B + sqrt(discriminate))/denominator;
			answers[1] = (-B - sqrt(discriminate))/denominator;
			error = check_output(answers);
		}
	}		
    return error;
}