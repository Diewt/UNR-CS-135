//Name: combine_strings.c
//Purpose: To enhance understanding of command line arguments, dma, and double pointers
//Author: Chris Diewtragulchai

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 30

int strlength(char *string);
int strcomp(char *input, char *command1, char *command2);
char intersperse(char *string1, char *string2, char *endstring);
char widen_stars(char *string1, char *string2, char *endstring);

int main(int argc, char *argv[])
{
    int length1, length2, count, compare;
    char input_string1[MAX_LENGTH + 1], input_string2[MAX_LENGTH +1], *s1, *s2;
    char *endstring = malloc((2 * MAX_LENGTH) * sizeof(char));

    s1 = input_string1;
    s2 = input_string2;

    compare = strcomp(argv[1], "i", "w");

    if(compare == 0)
    {
        return 0;
    }

    printf("Please enter a string of maximum 30 characters: ");
    scanf("%30s", input_string1);

    printf("Please enter a string of maxumum 30 characters: ");
    scanf("%30s", input_string2);

    length1 = strlength(s1);
    length2 = strlength(s2);

    endstring = malloc((2 * (length2 + length1)) * sizeof(char));

    if(compare == 1)
    {
        intersperse(s1, s2, endstring);
    }   
    else if(compare == 2)
    {
        widen_stars(s1, s2, endstring);
    }
    
    printf("The combined string is: ");
    puts(endstring);

    free(endstring);

    return 0;
}

int strlength(char *string)
{
    int word_size = 0;

    for(; *string != '\0'; string++)
    {
        if(*string != ' ')
        {
            word_size++;
        }
    }

    return word_size;
}

int strcomp(char *input, char *command1, char *command2)
{
    int compare;
    
    input++;

    if(*input == *command1)
    {
        compare = 1;
    }
    else if(*input == *command2)
    {
        compare = 2;
    }
    else
    {
        compare = 0;
    }

    return compare;
}

char intersperse(char *string1, char *string2, char *endstring)
{   
    for(;*string1 != '\0' && *string2 != '\0' ; string1++, string2++)
    {
        *endstring = *string1;
        endstring++;
        *endstring = *string2;
        endstring++;
    }

    for(;*string1 != '\0'; string1++)
    {
        *endstring = *string1;
        endstring++;
    }

    for(;*string2 != '\0'; string2++)
    {
        *endstring = *string2;
        endstring++;
    }

    *endstring = '\0';

    return *endstring;
}

char widen_stars(char *string1, char *string2, char *endstring)
{
    for(;*string1 != '\0'; string1++)
    {
        *endstring = *string1;
        endstring++;
        *endstring = '*';
        endstring++;
    }

    for(;*string2 != '\0'; string2++)
    {
        *endstring = *string2;
        endstring++;
        *endstring = '*';
        endstring++;    
    }

    endstring--;
    *endstring = '\0';

    return *endstring;
}