//Name: calc.c
//Purpose: interactive program with a calculator
//Author: Chris Diewtragulchai

#include <stdio.h>
#include <math.h>

int main(void)
{
    int command, mode, i_input1, i_input2, i_sum;
    double d_input1, d_input2, d_sum;

    mode = 0;

    printf("This program implements a calculator.\n");

    for (;;)
    {
        printf("Options:\n");
        printf("1 - addition\n2 - subtraction\n3 - multiplication\n4 - division\n");
        printf("5 - toggle calculator type\n6 - exit program\n");
        printf("Please enter your option: ");
        scanf("%d", &command);

        switch (command)
        {
            case 1: 
                if ((mode%2) == 0)
                {
                    printf("Enter first term: ");
                    scanf("%lf", &d_input1);

                    printf("Enter second term: ");
                    scanf("%lf", &d_input2);

                    d_sum = d_input1 + d_input2;

                    printf("The sum is: %.15f\n", d_sum);
                }
                else
                {
                    printf("Enter first term: ");
                    scanf("%d", &i_input1);

                    printf("Enter second term: ");
                    scanf("%d", &i_input2);

                    i_sum = i_input1 + i_input2;

                    printf("The sum is: %d\n", i_sum);
                }
                break;
            case 2:
                if ((mode%2) == 0)
                {
                    printf("Enter first term: ");
                    scanf("%lf", &d_input1);

                    printf("Enter second term: ");
                    scanf("%lf", &d_input2);

                    d_sum = d_input1 - d_input2;

                    printf("The difference is: %.15f\n", d_sum);
                }
                else
                {
                    printf("Enter first term: ");
                    scanf("%d", &i_input1);

                    printf("Enter second term: ");
                    scanf("%d", &i_input2);

                    i_sum = i_input1 - i_input2;

                    printf("The difference is: %d\n", i_sum);
                }
                break;
            case 3:
                if ((mode%2) == 0)
                {
                    printf("Enter first term: ");
                    scanf("%lf", &d_input1);

                    printf("Enter second term: ");
                    scanf("%lf", &d_input2);

                    d_sum = d_input1 * d_input2;

                    printf("The product is: %.15f\n", d_sum);
                }
                else
                {
                    printf("Enter first term: ");
                    scanf("%d", &i_input1);

                    printf("Enter second term: ");
                    scanf("%d", &i_input2);

                    i_sum = i_input1 * i_input2;

                    printf("The product is: %d\n", i_sum);
                }
                break;
            case 4:
                if ((mode%2) == 0)
                {
                    printf("Enter first term: ");
                    scanf("%lf", &d_input1);

                    printf("Enter second term: ");
                    scanf("%lf", &d_input2);

                    if (d_input2 > 0)
                    {
                        d_sum = d_input1 / d_input2;

                        printf("The quotient is: %.15f\n", d_sum);
                    }
                    else
                    {
                        printf("Cannot divide by zero!\n");
                    }
                }
                else
                {
                    printf("Enter first term: ");
                    scanf("%d", &i_input1);

                    printf("Enter second term: ");
                    scanf("%d", &i_input2);

                    if (i_input2 > 0)
                    {
                        i_sum = i_input1 / i_input2;

                        printf("The quotient is: %d\n", i_sum);
                    }
                    else
                    {
                        printf("Cannot divide by zero!\n");
                    }
                }
                break;
            case 5:
                ++mode;

                if ((mode%2) == 0)
                {
                    printf("Calculator now works with doubles.\n");
                }
                else
                {
                    printf("Calculator now works with integers.\n");
                }
                break;
            case 6:
                return 0;
            default:
                printf("Invalid Option.\n");
                break;
        }
    }
}