#include <stdio.h>
#include <stdlib.h>

char matrix[3][3] = { '7', '8', '9', '4', '5', '6', '1', '2', '3' };
char player = 'X';
int n;

void Draw()
{
    printf("Tic Tac Toe!\n\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
}

void Input()
{
    int a;
    printf("\nIt's %c's turn. Press the number of the field: ", player);
    scanf("%d", &a);

    if (a == 7 && matrix[0][0] == '7')
        matrix[0][0] = player;
    else if (a == 8 && matrix[0][1] == '8')
        matrix[0][1] = player;
    else if (a == 9 && matrix[0][2] == '9')
        matrix[0][2] = player;
    else if (a == 4 && matrix[1][0] == '4')
        matrix[1][0] = player;
    else if (a == 5 && matrix[1][1] == '5')
        matrix[1][1] = player;
    else if (a == 6 && matrix[1][2] == '6')
        matrix[1][2] = player;
    else if (a == 1 && matrix[2][0] == '1')
        matrix[2][0] = player;
    else if (a == 2 && matrix[2][1] == '2')
        matrix[2][1] = player;
    else if (a == 3 && matrix[2][2] == '3')
        matrix[2][2] = player;
    else
    {
        printf("Field is already in use or invalid input! Try again!\n");
        Input();
    }
}

void TogglePlayer()
{
    if (player == 'X')
        player = 'O';
    else
        player = 'X';
}

char Win()
{
    // Check for X wins
    if ((matrix[0][0] == 'X' && matrix[0][1] == 'X' && matrix[0][2] == 'X') ||
        (matrix[1][0] == 'X' && matrix[1][1] == 'X' && matrix[1][2] == 'X') ||
        (matrix[2][0] == 'X' && matrix[2][1] == 'X' && matrix[2][2] == 'X') ||
        (matrix[0][0] == 'X' && matrix[1][0] == 'X' && matrix[2][0] == 'X') ||
        (matrix[0][1] == 'X' && matrix[1][1] == 'X' && matrix[2][1] == 'X') ||
        (matrix[0][2] == 'X' && matrix[1][2] == 'X' && matrix[2][2] == 'X') ||
        (matrix[0][0] == 'X' && matrix[1][1] == 'X' && matrix[2][2] == 'X') ||
        (matrix[2][0] == 'X' && matrix[1][1] == 'X' && matrix[0][2] == 'X'))
        return 'X';

    // Check for O wins
    if ((matrix[0][0] == 'O' && matrix[0][1] == 'O' && matrix[0][2] == 'O') ||
        (matrix[1][0] == 'O' && matrix[1][1] == 'O' && matrix[1][2] == 'O') ||
        (matrix[2][0] == 'O' && matrix[2][1] == 'O' && matrix[2][2] == 'O') ||
        (matrix[0][0] == 'O' && matrix[1][0] == 'O' && matrix[2][0] == 'O') ||
        (matrix[0][1] == 'O' && matrix[1][1] == 'O' && matrix[2][1] == 'O') ||
        (matrix[0][2] == 'O' && matrix[1][2] == 'O' && matrix[2][2] == 'O') ||
        (matrix[0][0] == 'O' && matrix[1][1] == 'O' && matrix[2][2] == 'O') ||
        (matrix[2][0] == 'O' && matrix[1][1] == 'O' && matrix[0][2] == 'O'))
        return 'O';

    return '/';
}

int main()
{
    n = 0;
    Draw();
    while (1)
    {
        n++;
        Input();
        Draw();

        if (Win() == 'X')
        {
            printf("X wins!\n");
            break;
        }
        else if (Win() == 'O')
        {
            printf("O wins!\n");
            break;
        }
        else if (Win() == '/' && n == 9)
        {
            printf("It's a draw!\n");
            break;
        }
        TogglePlayer();
    }
    return 0;
}
