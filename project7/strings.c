//Name: strings.c
//Purpose: To learn more about strings and pointers
//Author: Chris Diewtragulchai

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_LEN 50

int strlength(char *string);
int strcomp(char *string1, char *string2);
void strconcat(char *destination_string, char *source_string);
void strcopy(char *destination_string, char *source_string);

int main(void)
{
    int string_length1, string_length2, compare;
    char string1[MAX_LEN + 1], string2[MAX_LEN + 1], *s1, *s2;

    s1 = string1;
    s2 = string2;

    printf("Please enter the first string: ");
    scanf("%50s", string1);

    printf("Please enter the second string: ");
    scanf("%50s", string2);

    string_length1 = strlength(s1);
    string_length2 = strlength(s2);

    printf("The length of string 1 is: %d\n", string_length1);
    printf("The length of string 2 is: %d\n", string_length2);

    compare = strcomp(s1, s2);

    if(compare == 1)
    {
        printf("String 1 comes before string 2 alphabetically.\n");
    }
    else if(compare == -1)
    {
        printf("String 2 comes before string 1 alphabetically.\n");
    }
    else if(compare == 0)
    {
        printf("The two strings are the same.\n");
    }

    strconcat(s2, s1);

    printf("String 1 after concatenation: %s\n", string1);
    printf("String 2 after concatenation: %s\n", string2);

    strcopy(s1, s2);

    printf("String 1 after copying: %s\n", string1);
    printf("String 2 after copying: %s\n", string2);

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

int strcomp(char *string1, char *string2)
{
    int compare = 0, count;

    for(count = 0;count < MAX_LEN; string1++, string2++)
    {
        if(*string1 > *string2)
        {
            compare = 1;
            return compare;
        }
        else if(*string2 > *string1)
        {
            compare = -1;
            return compare;
        }
        else
        {
            return compare;
        }
    }
}

void strconcat(char *destination_string, char *source_string)
{
    int size1, size2;

    for(size1 = 0; *destination_string != '\0'; destination_string++)
    {
       
    }

    for(size2 = 0; *source_string != '\0'; source_string++, destination_string++)
    {
        *destination_string = *source_string;
    }

    *destination_string = '\0';
}

void strcopy(char *destination_string, char *source_string)
{
    for(; *source_string != '\0'; source_string++, destination_string++)
    {
        *source_string = *destination_string;
    }
}