/* test1.c
 * Unit tests for quad.c
 * Uses cunit framework written by John Kapenga
 * Uses calc_quad which uses:
 *	 calc_discrim.h, calc_denom.h, check_output from ieee_comply.h
 *   and sqrt() from math library
 * Uses check_input() from ieee_comply.h
 */
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include "cunit.h"
#include "calc_quad.h"
#include "calc_discrim.h"
#include "calc_denom.h"
#include "ieee_comply.h"

int main()
{
	double a, b, c;		//coefficients for quadratic equation
	double discrim;		//return from calculate_discriminate b^2-4AC
	double denom;		//return from calculate_denominator 2a
	float * answer = malloc(sizeof(float) * 2);		//assigned in calculate_quadratic two roots
	int error;			//check if input or output is within bounds
	
	cunit_init();
	
	
	//a test?
	a = 1.0;
	b = 9.2;
	c = 4.6;
	discrim = calculate_discriminate(a,b,c);
	denom =  calculate_denominator(a);
	calculate_quadratic(a,b,c, answer);
	printf("\n%d\n",discrim);
	assert_eq("discriminant",discrim,66.24); //manually calculated descriminant
	assert_eq("denominator",denom,2.0);
	assert_feq("root1",answer[0],-.530602);	//answer grabbed from wolfram alpha
	assert_feq("root2",answer[1],-8.6694);	//answer grabbed from wolfram alpha
	
	
	
	
	//another more complicated test?
	answer[0]=14.3;
	answer[1]=14.5;
	a = 1;
	b = -answer[0] + -answer[1];
	c = answer[0] * answer[1];
	
	error = check_input(a,b,c);
	assert_eq("error",error,0);

	calculate_quadratic(a,b,c,answer);
	assert_eq("error",error,0);

	calculate_discriminate(a,b,c);
	calculate_denominator(a);
	assert_eq("discriminator",discrim,0.2);
	assert_eq("denominator",denom,2.0);
	assert_feqrerr("root1",answer[0],answer[1],10.0*cunit_dmacheps);
	assert_feqrerr("root1",answer[1],answer[0],cunit_dmacheps);
	
	
	
	//input test?
	
	a=8532784298432784329843287357249532227984215124.13;
	b=9.3189328932e37;
	c=-389328942982390328130943.1;
	
	error = check_input(a,b,c);
	
	assert_fgt("Coefficient A",a,FLT_MAX);	//should be out of bounds of a float
	assert_fle("Coefficient B",b,FLT_MAX);	//within bounds
	assert_flt("Coefficient C",c,FLT_MAX);	//within bounds
	assert_neq("error",error,0);			//error should not be 0, a is out of bounds
	assert_eq("error",error,-3);			//should return properly with -3
	
	error = calculate_quadratic(a,b,c,answer);		
	
	assert_eq("error",error,-4);			
	
	
}