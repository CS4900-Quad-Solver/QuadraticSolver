#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <math.h>

/*Calculate B^2 - 4AC, if it is less than 0, returns -1 to tell main that their are no real solutions*/
double calculate_discriminate(double A, double B, double C) {
    double discriminate = (B*B) - (4*A*C);

    if (discriminate < 0) {
        return -1;
    } else {
        return discriminate;
    }
}
/*Calculate 2A, if 2A is 0, returns 0 to tell main that their are no solutions*/
double calculate_denominator(double A) {
    double denominator = 2*A;

    if (denominator == 0) {
        return 0;
    } else {
        return denominator;
    }
}

int main() {
    /*Variables for parsing input*/
    char * buffer = readline("Please Enter the Coefficients of X^2, X, X^0 as A,B,C\nSo we can solve for X using the quadratic equation\n");
    char * char_A = strtok(buffer, ",");
    char * char_B = strtok(NULL, ",");
    char * char_C = strtok(NULL, ",");

    /*If 3 arguments where not entered, one of the char_*s will return NULL, if so, inform user he much enter 3 arguments*/
    if (char_A == NULL || char_B == NULL || char_C == NULL) {
        printf("\nPlease make sure to type in three arguments (A,B,C)\n");
    } else {
        /*Variables used to calculate X*/
        double A = strtod(char_A, NULL); /*Coefficient of X^2*/
        double B = strtod(char_B, NULL); /*Coefficient of X*/
        double C = strtod(char_C, NULL); /*Coefficient of X^0*/
        double discriminate; /*result of B^2 - 4AC*/
        double denominator; /*result of 2A*/
        double x_1; /*result of -B + sqrt(discriminate)/denominator*/
        double x_2; /*result of -B - sqrt(discriminate)/denominator*/

        /*Checks if function returns -1, if so, there are no solutions*/
        if ((denominator = calculate_denominator(A)) == 0) {
            printf("\nNo solutions\n");
        } else {
            /*Checks if function returns -1, if so there are no read solutions*/
            if((discriminate = calculate_discriminate(A,B,C)) == -1) {
                printf("\nNo real solutions\n");
            } else {
                /*Calcuating X1 and X2, then printing them out.*/
                x_1 = (-B + sqrt(discriminate))/denominator;
                x_2 = (-B - sqrt(discriminate))/denominator;
                printf("X1: %f\n", x_1);
                printf("X2: %f\n", x_2);
            }
        }
    }

    free(buffer);
    return 1;
}
