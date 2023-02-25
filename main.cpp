#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <cstdlib>  // exit

using std::cout;
using std::cin;


char board[10]
{   'N',
    '~', '~', '~',
    '~', '~', '~',
    '~', '~', '~' 
};


void print_board()
{
    cout <<   " 1 2 3 : " << board[1] << " " << board[2] << " " << board[3] << " "
         << "\n 4 5 6 : " << board[4] << " " << board[5] << " " << board[6] << " "
         << "\n 7 8 9 : " << board[7] << " " << board[8] << " " << board[9] << " "
         << "\n";
}


void turn(char player)
{
    int move_index {}; // Defaults to 0

    // Handle input until move_index ∈ [1, 9]
    while ( (move_index < 1) || (move_index > 9) )
    {
        print_board();
        cout << player << " move: ";
        if ( !(cin >> move_index) )
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        
        else if ( board[move_index] != '~' )
        {
            cout << "Move is taken, try again.\n";
            continue;
        }
    }

    board[move_index] = player;
    cout << "---------------\n";
}


int wins[8][3]
{
    // Horizontal
    { 1, 2, 3 },
    { 4, 5, 6 },
    { 7, 8, 9 },
    // Vertical
    { 1, 4, 7 },
    { 2, 5, 8 },
    { 3, 6, 9 },
    // Diagonal
    { 1, 5, 9 },
    { 3, 5, 7 },
};


char win_check()
{
    char winner { 'N' };

    for (int i = 0; i < 8; i++) {
        std::set<char> potential_win {};
        potential_win.insert(board[wins[i][0]]);
        potential_win.insert(board[wins[i][1]]);
        potential_win.insert(board[wins[i][2]]);
        
        if (potential_win.size() == 1 && *(potential_win.begin()) != '~')
        {
            winner = *(potential_win.begin());
        }
    }

    return winner;
}


void end_game(char winner)
{
    if (winner != 'N')
    {
        print_board();
        cout << winner << " is the winner!\n";
        exit(0);
    }
}


int main()
{
    char winner { 'N' };
    turn('X');
    turn('O');
    turn('X');
    turn('O');
    turn('X');
    winner = win_check();
    end_game(winner);
    turn('O');
    winner = win_check();
    end_game(winner);
    turn('X');
    winner = win_check();
    end_game(winner);
    turn('O');
    winner = win_check();
    end_game(winner);
    turn('X');
    winner = win_check();
    end_game(winner);
}
