#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <errno.h>
#include <float.h>
#include "calc_quad.h"
#include "calc_discrim.h"
#include "calc_denom.h"
#include "ieee_comply.h"

#define BOLDBLUE	 "\033[1m\033[34m"		/* Bold Blue 	*/
#define BOLDRED	  "\033[1m\033[31m"		/* Bold Red 		*/
#define RESET	"\033[0m"		/* Reset 	*/

int main()
{
    /*Variables for pars==54946==   total heap usage: 2 allocs, 0 frees, 1,0ing input*/
    size_t size = 1024;
    int error;

    char * buffer = malloc(sizeof(char) * size);
    char temp = ' ';
    char * char_A = &temp;
    char * char_B;
    char * char_C;
    char * endptr;
    float * answers = malloc(sizeof(float) * 2);
	
	while (char_A[0] != 'q')
    {
        error = 0;
        fprintf(stdout, "Please Enter the Coefficients of X^2, X, X^0 as A,B,C\nSo we can solve for X using the quadratic equation\nEnter q to quit\n");
        getline(&buffer, &size, stdin);
        char_A = strtok(buffer, ",");
        char_B = strtok(NULL, ",");
        char_C = strtok(NULL, ",");

        /*Tons of error checking to ensure the user gets the right response from his mistype*/
        if (char_A[0] == 'q' && char_B == NULL && char_C == NULL)
        {
            fprintf(stdout, "\nExiting...\n");
        }
        else
        {
            if (char_A == NULL || char_B == NULL || char_C == NULL)
            {
                printf( BOLDRED "\nNOTICE: Please make sure to type in three arguments (A,B,C)\n\n" RESET);
            }
            else
            {
                /*Variables used to calculate X*/
                double A = strtod(char_A, &endptr); /*Coefficient of X^2*/
                double B = strtod(char_B, &endptr); /*Coefficient of X*/
                double C = strtod(char_C, &endptr); /*Coefficient of X^0*/
				
				/*Checks if input is within single floating-point precision*/
				error = check_input(A, B, C);
				
                if (char_A == endptr || char_B == endptr || char_C == endptr)
                {
                    fprintf(stdout, BOLDRED "\nNOTICE: Please make sure Arguments are numbers\n\n" RESET);
                }
				else if (error == -3)
				{
					fprintf(stdout, BOLDRED "\nNOTICE: Input is NOT within single-point precision\n\n" RESET);
				}
                else
                {

                    error = calculate_quadratic(A, B, C, answers);
					
                    if (error == 0)
                    {
                        if (answers[0] == answers[1])
                        {
                            fprintf(stdout, BOLDBLUE "\nOnly one solution\nX: %f\n\n" RESET, answers[0]);
                        }
                        else
                        {
                            fprintf(stdout, BOLDBLUE "\nX1: %f\nX2: %f\n\n" RESET, answers[0], answers[1]);
                        }
                    }
                    else if (error == -1)
                    {
                        printf( BOLDRED "\nNo real solutions\n\n" RESET);
                    }
                    else if (error == -2)
                    {
                        printf( BOLDRED "\nNo solution, A cannot be 0\n\n" RESET);
                    }
					else if (error == -4)
					{
						fprintf(stdout, BOLDRED "\nSolution is not within single-point precision\n\n" RESET);
					}
                    else
                    {
                        fprintf(stdout, BOLDRED "\nERROR: Unknown\n\n" RESET);
                    }
                }
            }
        }
    }
    free(buffer);
    free(answers);
    return error;
}