#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <errno.h>

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
void calculate_quadratic(double A, double B, double C, double * answers)
{
    double denominator;
    double discriminate;

    /*Checks if function returns -1, if so, there are no solutions*/
    if ((denominator = calculate_denominator(A)) == 0)
    {
        printf("\nNo solutions\n");
    }
    else
    {
        /*Checks if function returns -1, if so there are no read solutions*/
        if((discriminate = calculate_discriminate(A,B,C)) == -1)
        {
            printf("\nNo real solutions\n");
        }
        else
        {
            /*Calcuating X1 and X2, then return them.*/
            answers[0] = (-B + sqrt(discriminate))/denominator;
            answers[1] = (-B - sqrt(discriminate))/denominator;
        }
    }
}

int main()
{
    /*Variables for parsing input*/
    size_t size = 1024;
    char * buffer = malloc(sizeof(char) * size);

    char * char_A;
    char * char_B;
    char * char_C;

    double * answers = malloc(sizeof(double) * 2);

    fprintf(stdout, "Please Enter the Coefficients of X^2, X, X^0 as A,B,C\nSo we can solve for X using the quadratic equation\n");
    getline(&buffer, &size, stdin);
    char_A = strtok(buffer, ",");
    char_B = strtok(NULL, ",");
    char_C = strtok(NULL, ",");

    /*If 3 arguments where not entered, one of the char_*s will return NULL, if so, inform user he much enter 3 arguments*/
    if (char_A == NULL || char_B == NULL || char_C == NULL)
    {
        printf("\nPlease make sure to type in three arguments (A,B,C)\n");
    }
    else
    {
        /*Variables used to calculate X*/
        double A = strtod(char_A, NULL); /*Coefficient of X^2*/
        double B = strtod(char_B, NULL); /*Coefficient of X*/
        double C = strtod(char_C, NULL); /*Coefficient of X^0*/
        if ((A == 0 || B == 0 || C == 0) & (errno == ERANGE))
        {

        }
        else
        {
            calculate_quadratic(A, B, C, answers);
            fprintf(stdout, "X1: %f\nX2: %f\n", answers[0], answers[1]);
        }
    }

    free(buffer);
    free(answers);
    return 1;
}
