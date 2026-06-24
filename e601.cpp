/*
    e601
    Better code: https://yuihuang.com/zj-e601/

*/

#include <iostream>

using namespace std;

int board[8][8];

bool out(int row, int col)
{
    if (row < 0 || row >= 8 || col < 0 || col >= 8)
        return true;
    return false;
}

bool check_legal(int cur_row, int cur_col, int move_row, int move_col)
{
    int dif_row = move_row - cur_row;
    int dif_col = move_col - cur_col;
    if (dif_row != 0 && dif_col != 0)
        return false; // Move diagnoally
    if (board[move_row][move_col] == 1 || board[move_row][move_col] == 2)
        return false; // Stand or Move to king/queen pos

    int add_or_minus;
    if (dif_row != 0 && dif_row > 0)
        add_or_minus = 1;
    else if (dif_row != 0 && dif_row < 0)
        add_or_minus = -1;
    else if (dif_col != 0 && dif_col > 0)
        add_or_minus = 1;
    else if (dif_col != 0 && dif_col < 0)
        add_or_minus = -1;
    while (cur_row != move_row || cur_col != move_col)
    {
        if (cur_row == move_row)
            cur_col += add_or_minus;
        else
            cur_row += add_or_minus;
        if (board[cur_row][cur_col] == 1 || board[cur_row][cur_col] == 2)
            return false; // Pass king/queen pos
    }
    return true;
}

bool check_allow(int king_row, int king_col, int queen_row, int queen_col, int move_row, int move_col)
{
    // Only consider legal region
    int king_row_dif = move_row - king_row;
    int king_col_dif = move_col - king_col;
    if (abs(king_row_dif) > 1)
        return true;
    if (abs(king_col_dif) > 1)
        return true;
    if (abs(king_row_dif) == 1 && abs(king_col_dif) == 1) // diagonal to king
        return true;
    int queen_row_dif = move_row - queen_row;
    int queen_col_dif = move_col - queen_col;
    if (queen_row_dif != 0 && queen_col_dif != 0)
        return true; // diagonal to queen;
    return false;
}

int main()
{
    int king, queen, queen_move;
    while (cin >> king >> queen >> queen_move)
    {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                board[i][j] = 0;
            }
        }

        int king_row = king / 8;
        int king_col = king % 8;
        board[king_row][king_col] = 1; // 1 for king

        int queen_row = queen / 8;
        int queen_col = queen % 8;
        if (board[queen_row][queen_col] == 1)
        {
            cout << "Illegal state" << endl;
            continue;
        }
        board[queen / 8][queen % 8] = 2; // 2 for queen

        int queen_move_row = queen_move / 8;
        int queen_move_col = queen_move % 8;
        if (!check_legal(queen_row, queen_col, queen_move_row, queen_move_col))
        {
            cout << "Illegal move" << endl;
            continue;
        }
        if (!check_allow(king_row, king_col, queen_row, queen_col, queen_move_row, queen_move_col))
        {
            cout << "Move not allowed" << endl;
            continue;
        }
        // Move queen
        board[queen_row][queen_col] = 0;
        board[queen_move_row][queen_move_col] = 2;
        // Check king legal, allow to move
        bool stop = true;
        for (int i = -1; i <= 1; i++)
        {
            if (!out(king_row + i, king_col) &&
                check_legal(king_row, king_col, king_row + i, king_col) &&
                check_allow(king_row, king_col, queen_move_row, queen_move_col, king_row + i, king_col))
            {
                cout << "Continue" << endl;
                stop = false;
                break;
            }
            if (!out(king_row, king_col + i) &&
                check_legal(king_row, king_col, king_row, king_col + i) &&
                check_allow(king_row, king_col, queen_move_row, queen_move_col, king_row, king_col + i))
            {
                cout << "Continue" << endl;
                stop = false;
                break;
            }
        }
        if (stop)
            cout << "Stop" << endl;
    }

    return 0;
}