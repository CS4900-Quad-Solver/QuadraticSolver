#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calc_discrim.h"

double calculate_discriminate(double A, double B, double C)
{
    double discriminate = (B*B) - (4*A*C);

    if (discriminate < 0)
    {
        discriminate = -1;
    }

    return discriminate;
}