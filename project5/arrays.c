//Name: arrays.c
//Purpose: To have users enter an array and displaying a number count
//Author: Chris Diewtragulchai

#include <stdio.h>
#include <stdbool.h>

int main (void)
{
    int input_rows, input_columns, array[10][10], rows, columns, number_count[10] = {0}, count;

    printf("This program counts occurences of digits 0 through 9 in an NxM array.\n");
    printf("Enter the size of the array (Row Column): ");
    scanf("%1d %1d", &input_rows, &input_columns);

    for (rows = 0; rows < input_rows; rows++)
    {
        printf("Enter row %d: ", rows);
        
        for (columns = 0; columns < input_columns; columns++)
        {
            scanf("%1d", &array[rows][columns]);
        } 
    }

    for (rows = 0; rows < input_rows; rows++)
    {
        for (columns = 0; columns < input_columns; columns++)
        {
          switch (array[rows][columns])
            {
                case 0:
                    number_count[0] += 1;
                    break;
                case 1:
                    number_count[1] += 1;
                    break;
                case 2:
                    number_count[2] += 1;
                    break;
                case 3:
                    number_count[3] += 1;
                    break;
                case 4:
                    number_count[4] += 1;
                    break;
                case 5:
                    number_count[5] += 1;
                    break;
                case 6:
                    number_count[6] += 1;
                    break;
                case 7:
                    number_count[7] += 1;
                    break;
                case 8:
                    number_count[8] += 1;
                    break;
                case 9:
                    number_count[9] += 1;
                    break;
                default:
                    break; 
            }
        }
    }

    printf("Total counts for each digit:\n");

    for (count = 0; count < 10; count++)
    {
        printf("Digit %d occurs %d times\n", count, number_count[count]);
    }

    printf("The digit counts directly from the 1D array:\n");

    for (count = 0; count < 10; count++)
    {
        printf("%d ", number_count[count]);
    }

    printf("\n");
    printf("The original 2D array entered by the user:\n");

    for (columns = 0; columns < input_columns; columns++)
    {
        printf("%d ", array[0][columns]);
    }

    printf("\n");

    for (columns = 0; columns < input_columns; columns++)
    {
        printf("%d ", array[1][columns]);
    }

    printf("\n");

    return 0;
}