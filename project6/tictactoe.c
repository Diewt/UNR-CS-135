//Name: tictactoe.c
//Purpose: Creating an interactable game of tictactoe
//Author: Chris Diewtragulchai

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

#define SIZE 3

void display_table(char board[SIZE][SIZE]);
//Shows the current state of the game.
void clear_table(char board[SIZE][SIZE]);
//resets the game board to "_"
int check_table_full(char board[SIZE][SIZE]);
//checks if the board is full of X and O
void update_table(char board[SIZE][SIZE], int row, int col, char token);
//updates the table to include the latest input
int check_legal_option(char board[SIZE][SIZE], int row, int col);
//Checks if the input move is within the 3x3 board and if the selected space is a "_"
void generate_player2_move(char board[SIZE][SIZE], int row, int col);
//generates a random move for the computer if the game isn't over
int check_three_in_a_row(char board[SIZE][SIZE]);
//checks to see if anyone got 3 in a row 
int check_end_of_game(char board[SIZE][SIZE]);
//returns a 0 or 1 depending on if the game is over or not
void get_player1_move(char board[SIZE][SIZE], int row, int col);
//ask the player to input a move, if the move is not valid ask for input again.
//should also update the board with the given move and print out the current state of the board
void print_winner(char board[SIZE][SIZE]);
//use switch to indicate if a player has won or if it is a tie. Also be sure to indicate which player won

//main function should utilize all the other smaller functions
int main()
{
    //Declare the tic-tac-toeboard
    char board[SIZE][SIZE];

    //The row and column of the move fore either player 1 or 2
    int row, col;

    //clear the table
    clear_table(board);

    //Display the table
    display_table(board);

    do
    {
        //Have player 1 enter their move
        get_player1_move(board, row, col);

        //generate player 2 move
        generate_player2_move(board, row, col);
    }
    //Do this while the game hasn't ended
    while(check_end_of_game(board) == 0);

    //after the game is over, print who won
    print_winner(board);

    return 0;
}

//Shows the current state of the game.
void display_table(char board[SIZE][SIZE])
{
    int col, row;

    printf("The current state of the game is:");

    for (row = 0; row < SIZE; row++)
    {
        printf("\n");

        for (col = 0; col < SIZE; col++)
        {
            printf("%c ", board[row][col]);
        }
    }

    return;
}

//resets the game board to "_"
void clear_table(char board[SIZE][SIZE])
{
    int col, row;
    char *blank;

    blank = "_" ;

    for (row = 0; row < SIZE; row++)
    {
        for (col = 0; col < SIZE; col++)
        {
            board[row][col] = *blank;
        }
    }

    return;
}

//checks if the board is full of X and O
int check_table_full(char board[SIZE][SIZE])
{
    int check = 0, row, col;

    for (row = 0; row < SIZE; row++)
    {
        for (col = 0; col < SIZE; col++)
        {
            if(board[row][col] == 'X')
            {
                check++;
            }
            else if(board[row][col] == 'O')
            {
                check++;
            }
        }
    }

    if(check == 9)
    {
        check = 1;
    }
    else
    {
        check = 0;
    }

    return check;
}

//updates the table to include the latest input
void update_table(char board[SIZE][SIZE], int row, int col, char token)
{
    board[row][col] = token;

    return;
}

//Checks if the input move is within the 3x3 board and if the selected space is a "_"
int check_legal_option(char board[SIZE][SIZE], int row, int col)
{
    int illegal = 0, legal = 1, boundry, space_occupation;

    if (row < 3)
    {
        if(col < 3)
        {
            boundry = 1;
        }
        else
        {
            boundry = 0;
        }
    }
    else 
    {
        boundry = 0;
    }

    if (board[row][col] != 'X' && board[row][col] != 'O')
    {
        space_occupation = 1;
    }
    else
    {
        space_occupation = 0;
    }

    if(boundry && space_occupation)
    {
        return legal;
    }
    else
    {
        return illegal;
    }
}

//generates a random move for the computer if the game isn't over
void generate_player2_move(char board[SIZE][SIZE], int row, int col)
{
    int legal, game_status, win_condition;
    char X;

    X = 'X';
    row = rand() % 3;
    col = rand() % 3;

    legal = check_legal_option(board, row, col);
    game_status = check_table_full(board);
    win_condition = check_three_in_a_row(board);

    if(game_status == 0)
    {
        if(win_condition == 0)
        {
                 while(legal == 0)
            {
                row = rand() % 3;
                col = rand() % 3;

                legal = check_legal_option(board, row, col);
            }

            update_table(board, row, col, X);
    
            printf("\nPlayer 2 has entered [row, col]: %d,%d\n", row + 1, col + 1);
    
            display_table(board);

            return;   
        }
        else
        {
            check_end_of_game(board);
        }
    }
    else
    {
        check_end_of_game(board);
    }
}

//checks to see if anyone got 3 in a row
int check_three_in_a_row(char board[SIZE][SIZE])
{
    int win_condition;

    if(board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O')
    {
        win_condition = 1;
    }
    else if(board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O')
    {
        win_condition = 1;
    }
    else if(board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O')
    {
        win_condition = 1;
    }
    else if(board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O')
    {
        win_condition = 1;
    }
    else if(board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O')
    {
        win_condition = 1;
    }
    else if(board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O')
    {
        win_condition = 1;
    }
    else if(board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')
    {
        win_condition = 1;
    }
    else if(board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')
    {
        win_condition = 1;
    }
    else if(board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X')
    {
        win_condition = 2;
    }
    else if(board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X')
    {
        win_condition = 2;
    }
    else if(board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X')
    {
        win_condition = 2;
    }
    else if(board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X')
    {
        win_condition = 2;
    }
    else if(board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X')
    {
        win_condition = 2;
    }
    else if(board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X')
    {
        win_condition = 2;
    }
    else if(board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
    {
        win_condition = 2;
    }
    else if(board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')
    {
        win_condition = 2;
    }
    else
    {
        win_condition = 0;
    }

    return win_condition;
}

//returns a 0 or 1 depending on if the game is over or not
int check_end_of_game(char board[SIZE][SIZE])
{
    int full_board, win_condition, game_status;

    full_board = check_table_full(board);
    win_condition = check_three_in_a_row(board);

    if (win_condition == 0)
    {
        if (full_board == 0)
        {
            game_status = 0;

            return game_status;
        }
        else
        {
            game_status = 1;

            return game_status;
        }
    }
    else
    {
        game_status = 1;

        return game_status;
    }

}

//ask the player to input a move, if the move is not valid ask for input again.
//should also update the board with the given move and print out the current state of the board
void get_player1_move(char board[SIZE][SIZE], int row, int col)
{
    int legal;
    char O;

    O = 'O';

    printf("\nPlayer 1 enter your selection [row, col]: ");
    scanf("%d, %d", &row, &col);

    row -= 1;
    col -= 1;    
    legal = check_legal_option(board, row, col);

    while(legal == 0)
    {
        printf("Player 1 enter your selection [row, col]: ");
        scanf("%d, %d", &row, &col);

        row -= 1;
        col -= 1;

        legal = check_legal_option(board, row, col);
    }

    update_table(board, row, col, O);
    display_table(board);

    return;
}

//use switch to indicate if a player has won or if it is a tie. Also be sure to indicate which player won
void print_winner(char board[SIZE][SIZE])
{
    int win_condition;

    win_condition = check_three_in_a_row(board);

    switch (win_condition)
    {
        case 0:
            printf("\nGame over, no player wins.\n");
            break;
        case 1:
            printf("\nCongratulations, Player 1 wins!\n");
            break;
        case 2:
            printf("\nCongratulations, Player 2 wins!\n");
            break;
    }
}