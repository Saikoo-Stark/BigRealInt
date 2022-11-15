#include <iostream>
#include <algorithm>
using namespace std;
class Board {
    char board[3][3];
public:
    Board() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                board[i][j] = '.';
            }
        }
    }

    void showBoard()
    {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if(j == 0)
                    cout << '|';
                cout << board[i][j] << '|';
            }
            cout << endl;
        }
    }

    int isWinner()
    {
        for (int i = 0; i < 3; ++i) {
            if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
            {
                if(board[i][0] == 'X')
                    return 2;
                else if(board[i][0] == 'O')
                    return -2;
            }
            if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
            {
                if(board[0][i] == 'X')
                    return 2;
                else if(board[0][i] == 'O')
                    return -2;
            }
        }
        if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
        {
            if(board[0][0] == 'X')
                return 2;
            else if(board[0][0] == 'O')
                return -2;
        }
        if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
        {
            if(board[0][2] == 'X')
                return 2;
            else if(board[0][2] == 'O')
                return -2;
        }

        bool tie = true;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if(board[i][j] == '.')
                    tie = false;
            }
        }
        if(tie) return 0;

        return 1;
    }
    friend class Player;
};
class Player{
protected:
    char ch;
public:
    Player(char ch): ch(ch){}
    void play(Board& b, int x, int y)
    {
        b.board[x][y] = ch;
    }
    int minimax(Board& b, int depth, bool isMax, bool first = true)
    {
        int result = b.isWinner();
        if(result != 1 || depth == 0)
            return result;

        if(isMax)
        {
            int maxScore = INT_MIN, finalI, finalJ;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    if(b.board[i][j] == '.')
                    {
                        b.board[i][j] = 'X';
                        int score = minimax(b, depth - 1, false, false);
                        b.board[i][j] = '.';
                        if(score > maxScore)
                        {
                            maxScore = score;
                            finalI = i, finalJ = j;
                        }
                    }
                }
            }
            if(first) {
                b.board[finalI][finalJ] = 'O';
            }
            return maxScore;
        }
        else
        {
            int minScore = INT_MAX, finalI, finalJ;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    if(b.board[i][j] == '.')
                    {
                        b.board[i][j] = 'O';
                        int score = minimax(b, depth - 1, true, false);
                        b.board[i][j] = '.';
                        if(score < minScore)
                        {
                            minScore = score;
                            finalI = i, finalJ = j;
                        }
                    }
                }
            }
            if(first)
            {
                b.board[finalI][finalJ] = 'O';
            }
            return minScore;
        }
    }
};

int main()
{
    Board b;
    Player p('X');
    bool foundWinner = false;
    while (!foundWinner)
    {
        int x, y;
        cin >> x >> y;
        p.play(b, x, y);
        int result = p.minimax(b, 100, false);
        b.showBoard();
        foundWinner = b.isWinner() != 1;
    }
    int result = b.isWinner();
    if(result == 0)
        cout << "Tie" << endl;
    else
    {
        if(result == 2)
            cout << "You won" << endl;
        else
            cout << "Computer Has won" << endl;
    }
    return 0;
}
