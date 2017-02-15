#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <errno.h>

#define BOLDBLUE	 "\033[1m\033[34m"		/* Bold Blue 	*/
#define BOLDRED	  "\033[1m\033[31m"		/* Bold Red 		*/
#define RESET	"\033[0m"		/* Reset 	*/

/*Calculate B^2 - 4AC, if it is less than 0, returns -1 to tell main that their are no real solutions*/
double calculate_discriminate(double A, double B, double C)
{
    double discriminate = (B*B) - (4*A*C);

    if (discriminate < 0)
    {
        discriminate = -1;
    }

    return discriminate;
}

/*Calculate 2A, if 2A is 0 there will be no solutions*/
double calculate_denominator(double A)
{
    double denominator = 2*A;
    return denominator;
}

/*Calculates the quadratic, then stores answers in answers array*/
int calculate_quadratic(double A, double B, double C, double * answers)
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
        }
    }
    return error;
}

int main()
{
    /*Variables for parsing input*/
    size_t size = 1024;
    int error;

    char * buffer = malloc(sizeof(char) * size);

    char * char_A;
    char * char_B;
    char * char_C;
    char * endptr;
    double * answers = malloc(sizeof(double) * 2);

    while (char_A[0] != 'q')
    {
        error = 0;
        fprintf(stdout, "Please Enter the Coefficients of X^2, X, X^0 as A,B,C\nSo we can solve for X using the quadratic equation\nEnter q to quit\n");
        getline(&buffer, &size, stdin);
        char_A = strtok(buffer, ",");
        char_B = strtok(NULL, ",");
        char_C = strtok(NULL, ",");

        /*If 3 arguments where not entered, one of the char_*s will return NULL, if so, inform user he much enter 3 arguments*/
        if (char_A[0] != 'q')
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

                if (char_A == endptr || char_B == endptr || char_C == endptr)
                {
                    fprintf(stdout, BOLDRED "\nNOTICE: Please make sure Arguments are numbers\n" RESET);
                }
                else
                {

                    error = calculate_quadratic(A, B, C, answers);

                    if (error == 0)
                    {
                        fprintf(stdout, BOLDBLUE "\nX1: %f\nX2: %f\n\n" RESET, answers[0], answers[1]);
                    }
                    else if (error == -1)
                    {
                        printf( BOLDRED "\nNo real solutions\n\n" RESET);
                    }
                    else if (error == -2)
                    {
                        printf( BOLDRED "\nNo solutions\n\n" RESET);
                    }
                    else
                    {
                        fprintf(stdout, BOLDRED "\nERROR: Unknown\n\n" RESET);
                    }
                }
            }
        }
        else
        {
            fprintf(stdout, "Exiting...\n");
        }
    }

    free(buffer);
    free(answers);
    return error;
}
