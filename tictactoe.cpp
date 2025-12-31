#include <iostream>
#include <windows.h>
#include<cctype>
#include <conio.h>
using namespace std;
// ANSI color codes for terminal output
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define BOLD "\033[1m"
#define STRIKE "\033[9m"

// Displays the current game board state
void drawBoard(char board[3][3])
{
    system("cls"); // Clear console

    cout << endl
         << BOLD MAGENTA << "\t\t\t_____________________________________________________" << RESET << endl
         << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << BOLD MAGENTA << "\t\t\t | " << RESET;
            if (board[i][j] == 'X' || board[i][j] == 'x')
                cout << BOLD RED << board[i][j] << RESET;
            else if (board[i][j] == 'O' || board[i][j] == 'o')
                cout << BOLD BLUE << board[i][j] << RESET;
            else
                cout << BOLD GREEN << board[i][j] << RESET;
            cout << BOLD MAGENTA << " |" << RESET;
        }
        cout << endl
             << endl;
    }
    cout << BOLD MAGENTA << "\t\t\t-----------------------------------------------------" << RESET << endl;
}

int i = 0; // Global move counter
// Places a symbol at the specified position if valid
void move(char *board, int place, char symbol)
{
    // Check if position is empty (not already occupied)
    if (*(board + place - 1) != 'X' && *(board + place - 1) != 'x' && *(board + place - 1) != 'O' && *(board + place - 1) != 'o')
        *(board + place - 1) = symbol;
    else
    {
        // Position already taken
        cout << RED << "Invalid Place" << RESET << endl;
        i--; // Decrement counter to retry the move
    }
}

// Prompts player for their move
void playerTurn(char *board, char symbol)
{
    int place;
    cout << "Enter the place (" << symbol << ") :";
    cin >> place;
    move(board, place, symbol);
}

// Checks for winning conditions (rows, columns, diagonals)
bool checkWin(char board[3][3])
{
    // Check rows and columns
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return true;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return true;
    }
    // Check main diagonal
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return true;
    // Check anti-diagonal
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return true;

    return false;
}

int main()
{
    // Initialize board with position numbers
    char board[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}};
    char symbol;
    cout << BOLD GREEN << "------WELCOME TO THE ULTIMATE SHOWDOWN OF TWO UNEMPLOYED SYMBOLS-----" << RESET << endl;
    Sleep(1400);
    cout << BOLD RED << "\t\tTHE " << STRIKE << "DEADLY" << RESET BOLD RED << " GAME OF TIC";
    Sleep(900);
    cout << "-TAC";
    Sleep(900);
    cout << "-TOE" << RESET << endl
         << endl;
    Sleep(900);

    // Validate player symbol input
    cout << "Choose Your Symbol(X O) : ";
    cin >> symbol;
    while (symbol != 'X' && symbol != 'O' && symbol != 'x' && symbol != 'o')
    {
        cout << endl
             << "Brother you are playing (O X) not " << symbol << endl;
        cout << "Choose Your Symbol(X O) : ";
        cin >> symbol;
    }
    symbol = toupper(symbol);

    drawBoard(board);
    bool a; // Flag to track if game is won

    // Game loop: continue until 9 moves or win condition
    while (i < 9)
    {
        playerTurn(&board[0][0], symbol);
        drawBoard(board);
        if (a = checkWin(board)) // Check for winner after each move
            break;
        // Alternate between X and O
        symbol = (symbol == 'X') ? 'O' : 'X';
        i++;
    }

    // Display game result
    if (a)
    {
        system("cls");
        Sleep(700);
        cout << RED << "**********************" << BOLD MAGENTA "************************" << RESET << endl;
        if (symbol == 'X' || symbol == 'x')
            cout << GREEN << "Winner is Player with " << BOLD RED << symbol << BOLD GREEN << " !!" << RESET << endl;
        else if (symbol == 'O' || symbol == 'o')
            cout << GREEN << "Winner is Player with " << BOLD BLUE << symbol << BOLD GREEN << " !!" << RESET << endl;

        cout << RED << "************************" << BOLD MAGENTA "**********************" << RESET << endl;
        Sleep(900);
    }
    else
    {
        cout << RED << "**********************" << BOLD MAGENTA "************************" << RESET << endl;
        cout << YELLOW << "It is a Draw" << RESET;
        cout << RED << "************************" << BOLD MAGENTA "**********************" << RESET << endl;
    }
    getch();
}
