//Name: sq_root.c
//Purpose: to calculate a guess close to the square root of a number
//Author: Chris Diewtragulchai

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main(void)
{
    float input, guess, sum;

    printf("Enter a number: ");
    scanf("%f", &input);

    guess = 1.0;

    while (fabs((guess * guess) - input) > 0.00001)
        {
            printf("%10.5f\n", guess);
            
            sum = ( (guess + (input / guess)) / 2 );
            guess = sum;
        }

    printf("Estimated square root of %.5f: %.5f\n", input, guess);

    return 0;
}