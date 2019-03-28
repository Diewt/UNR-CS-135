//Name:dynamic_strings.c
//Purpose: Learning more about dma 
//Author: Chris Diewtragulchai

#include <stdio.h>
#include <stdlib.h>

//additional functions 
//#1 strlength will take a character pointer to a string and return the length of the string(not including the null terminal)
int strlength(char *string);
//#2 strcopy will take two character pointers to two strings(a source string and a destination string)
//the function must first reallocate enough memory to hold the souce string in the destination string
//then it will add the source string into the destination string including null terminal
//return a pointer to the beinning of the destination string
char *strcopy(char *source, char *destination);
//#3 strcat should take two character pointers to 2 strings(a source string and a destination string)
//reallocate memory to add source string to the end of destination string
//add source to destination and return pointer to beginning of destination string
char *strconcat(char *source, char *destination);
//#4 strcomp takes 2 character pointers to 2 strings(s1 and s2)
//compare the 2 strings, if string 1 comes first slpahbeitcall return 1, if not return -1, if same return 0
//should compare two strings one character at a time and return appropriate value
int strcomp(char *s1, char *s2);

//the variable inputed into the command line is the amount of strings that are going to be entered into the program
int main(int argc, char *argv[])
{
    int count, command, input, input2, length_input, compare;
    //input is constant used for additional number input for selecting strings for functions
    //input2 is the second constant
    //count is a constant to be used in any for loops
    //length_input represents the input on the string length
    //compare will track the value returned by strcomp
    char *string[atoi(argv[1])];
    //*string is an array of seperate pointer that will generate the storage for the user input

    //loop to check the amount strings that need to be inputed
    for(count = 0; count < atoi(argv[1]); count++)
    {
        printf("Please enter the length of string %d: ", (count + 1));
        scanf("%d", &length_input);

        string[count] = malloc((length_input + 1) * sizeof(char));

        printf("Please enter string %d: ", (count + 1));
        scanf("%s", string[count]);
    }


    //infinite for loop to use as the menu
    for(;;)
    {
        //printing out the results of the input strings
        printf("Your strings are: \n");

        //loop to print out the inputed strings
        for(count = 0; count < atoi(argv[1]); count++)
        {
            printf("String number %d - \"%s\"\n", (count + 1), string[count]);
        }

        //list of commands
        printf("Options:\n");
        printf("1 - Find string length\n");
        printf("2 - Compare strings\n");
        printf("3 - Copy strings\n");
        printf("4 - concatenate strings\n");
        printf("5 - Quit\n");
        printf("Please enter you option: ");
        scanf("%d", &command);

        //switch statement for the command input
        switch(command)
        {
            case 1:
                //ask the user to enter the number of the string that they want to find the length of
                printf("Enter a string number: ");
                scanf("%d", &input);

                //run the selected string through function strlength and return the size of the string
                printf("The length of string %d is: %d\n", input, strlength(string[input - 1]));
                break;
            case 2:
                //ask user to enter the 2 string numbers
                printf("Enter the number of the first string: ");
                scanf("%d", &input);
                printf("Enter the number of the second string: ");
                scanf("%d", &input2);

                compare = strcomp(string[input - 1], string[input2 - 1]);

                if(compare == 1)
                {
                    printf("String %d comes before string %d alphabetically.\n", input, input2);
                }
                else if(compare == -1)
                {
                    printf("String %d comes before string %d alphabetically.\n", input2, input);
                }
                else if(compare == 0)
                {
                    printf("The two strings are the same.\n");
                }
                break;
            case 3:
                //ask user to enter the 2 string numbers
                printf("Enter the number of the source string: ");
                scanf("%d", &input);
                printf("Enter the number of the destination string: ");
                scanf("%d", &input2);

                strcopy(string[input - 1], string[input2 - 1]);

                break;
            case 4:
                //ask user to enter the 2 string numbers
                printf("Enter the number of the source string: ");
                scanf("%d", &input);
                printf("Enter the number of the destination string: ");
                scanf("%d", &input2);

                strconcat(string[input - 1], string[input2 - 1]);

                break;
            case 5:
                //loop to free up the memory reserved by dma
                for(count = 0; count < atoi(argv[1]); count++)
                    {
                        free(string[count]);
                    }

                //exits the program
                return 0;
            default:
                printf("Invalid Option\n");
                break;
        }
    }
}

int strlength(char *string)
{
    int word_count;

    word_count = 0;

    //loop to count characters in string
    for(; *string != '\0'; string++)
    {
        word_count++;
    }

    return word_count;
}

char *strcopy(char *source, char *destination)
{
    int length;

    //grabing the length that the destination string has to realloc to
    length = strlength(source);

    //changing the size of the destination to fit the source
    destination = realloc(destination, (length + 1) * sizeof(char));

    //loop replacing the destination with the source
    for(;*source != '\0'; source++, destination++)
    {
        *destination = *source;
    }

    //adding the null terminal to the end of the string
    *destination = '\0';
}

char *strconcat(char *source, char *destination)
{
    int length1, length2, total_length;

    //gets length of the 2 strings sent to the function
    length1 = strlength(source);
    length2 = strlength(destination);
    total_length = length1 + length2 + 1;

    //reallocation to destination memory to increase storage to account for source
    destination = realloc(destination, total_length * sizeof(char));
    
    //loop to get to the end of the destination string
    while(*destination != '\0')
    {
        destination++;
    }

    //loop to add source to the end of the destination string
    for(;*source != '\0'; source++, destination++)
    {
        *destination = *source;
    }

    //adding a null terminal to the end of the destination string
    *destination = '\0';
}

int strcomp(char *s1, char *s2)
{
    int compare = 0;
    //count is the constant in the loop

    //loop comparing the strings up till one hits a null terminal
    for(; *s1 != '\0' && *s2 != '\0'; s1++, s2++)
    {
        if(*s1 < *s2)
        {
            compare = 1;
            return compare;
        }
        else if(*s2 < *s1)
        {
            compare = -1;
            return compare;
        }
        else
        {
            compare = 0;
        }
    }

    //statement checking if one of the sentences has more charcters than the others
    if(*s1 == '\0')
    {
        if(*s2 != '\0')
        {
            compare = -1;
            return compare;            
        }
    }
    else if(*s2 == '\0')
    {
        if(*s1 != '\0')
        {
            compare = 1;
            return compare;
        }
    }
    
    return compare;
}