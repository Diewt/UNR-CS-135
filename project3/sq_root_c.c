//Name: sq_root_c.c
//Purpose: Improvementment in calculating a guess close to the square root of a number
//Author: Chris Diewtragulchai

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main(void)
{
    int counter;
    float input, guess, sum;

    printf("Enter a number: ");
    scanf("%f", &input);

    counter = 0;
    guess = 1.0;

    while (fabs((guess * guess) - input) > 0.00001)
        {
            printf("%d\t%10.5f\n", counter, guess);
            
            sum = ( (guess + (input / guess)) / 2 );
            guess = sum;
            counter++;
        }

    printf("Estimated square root of %.5f: %.5f\n", input, guess);

    return 0;
}