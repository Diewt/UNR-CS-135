//Name: series.c
//Purpose: Calculating a mathematical series
//Author: Chris Diewtragulchai

#include <stdio.h>
#include <math.h>

int main(void)
{
    int input, integer, end_value, serie_value;

    printf("Enter an integer number: ");
    scanf("%d", &input);

    end_value = 0;

    for(integer = 1; integer <= input; integer++)
    {
        serie_value = pow((-1), (integer +1)) * (integer * integer);
        end_value += serie_value;
    }

    printf("The value of the series is: %d\n", end_value);

    return 0;
}