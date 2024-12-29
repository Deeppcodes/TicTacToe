#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

//board is a 2d char array
char board[3][3];
const char PLAYER = 'X';
const char COMP = 'O';

// function prototypes 
void resetgame();
void printgame();
int freespaces();
void move();
void compmove();
char checkwinner();
void printwinner(char winner);

// main function
int main()
{
    char winner = ' ';

    resetgame();

    while (winner == ' ' && freespaces() != 0)
    {
        printgame();

        move();
        winner = checkwinner();

        if (winner != ' ' || freespaces() == 0)
        {
            break;
        }


        compmove();
        winner = checkwinner();

        if (winner != ' ' || freespaces() == 0)
        {
            break;
        }
    }

    printgame();
    printwinner(winner);


    return 0;
}

// helpers
void resetgame()
{
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3;j++)
        {
            board[i][j] = ' ';
        }
    }
};

void printgame()
{
    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n");

};

int freespaces()
{
    int free = 9;
    
    for(int i =0; i<3; i++)
    {
        for(int j =0; j<3; j++)
        {
            if(board[i][j] != ' ')
            {
                free--;
            }
        }
    }
    return free;

};

void move()
{
    int x;
    int y;

    do{
        printf("enter row num: ");
        scanf("%d", &x); 
        getchar();
        x--; // indexing starts from 0 

        printf("enter column num: ");
        scanf("%d", &y); 
        getchar();
        y--;

        if(board[x][y] != ' ')
        {
            printf("invalid move!\n");
        }
        else{
            board[x][y] = PLAYER;
            break;
        }
    }while (board[x][y] != ' ');

};

void compmove()
{
    // creates a seed based on current time
    srand(time(0));
    int x;
    int y;

    if(freespaces() > 0)
    {
        do
        {
            x = rand() % 3;
            y = rand() % 3;
        } while (board[x][y] != ' ');

        board[x][y] = COMP;
    }
    else
    {
        printwinner(' ');
    }
};

char checkwinner()
{
    // check rows
    for(int i = 0; i<3; i++)
    {
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return board[i][0];
        }
    }

    // check columns 
    for(int i = 0; i<3; i++)
    {
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return board[0][i];
        }
    }

    // check diagonals
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        return board[0][0];
    }
    if(board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        return board[0][2];
    }

    return ' ';

};

void printwinner(char winner)
{
    if(winner == PLAYER)
    {
        printf("you win!");
    }
    else if(winner == COMP)
    {
        printf("you lose!");
    }
    else{
        printf("draw!");
    }
};
