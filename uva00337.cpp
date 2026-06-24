/*
    UVa 337 - Simulating a 10x10 Screen
    Straightforward simulation problem
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define SCREEN_WIDTH 10
#define SCREEN_HEIGHT 10

vector<vector<char>> screen(SCREEN_HEIGHT, vector<char>(SCREEN_WIDTH));

void clear_screen()
{
    for (int i = 0; i < SCREEN_HEIGHT; i++)
    {
        for (int j = 0; j < SCREEN_WIDTH; j++)
        {
            screen[i][j] = ' ';
        }
    }
}

bool cursor_out_of_bound(int next_row, int next_col)
{
    if (next_row < 0 || next_row >= SCREEN_HEIGHT || next_col < 0 || next_col >= SCREEN_WIDTH)
        return true;
    return false;
}

void write(int row, int col, char c, bool overwrite)
{
    if (overwrite)
    {
        screen[row][col] = c;
        return;
    }
    else // Insert mode
    {
        for (int j = SCREEN_WIDTH - 1; j > col; j--)
        {
            screen[row][j] = screen[row][j - 1];
        }
        screen[row][col] = c;
        return;
    }
}

int main()
{
    int N;
    int case_cnt = 0;
    while (cin >> N)
    {
        if (N == 0)
            return 0;

        cout << "Case " << ++case_cnt << endl;
        cout << "+----------+" << endl;
        clear_screen();
        int cur_row = 0, cur_col = 0;
        bool overwrite = true; // Overwrite: true, Insert: false

        while (N--)
        {
            cin >> ws;  // When using cin >> N and use getline it will need this line of code to solve the problem.
            string line;
            getline(cin, line);
            for (int i = 0; i < line.size(); i++)
            {
                char c = line[i];
                if (c == '^')
                {
                    char control = line[++i];
                    switch (control)
                    {
                    case 'b':
                        cur_col = 0;
                        break;
                    case 'c':
                        clear_screen();
                        break;
                    case 'd':
                        if (!cursor_out_of_bound(cur_row + 1, cur_col))
                            cur_row++;
                        break;
                    case 'e':
                        for (int v = cur_col; v <= 9; v++)
                            screen[cur_row][v] = ' ';
                        break;
                    case 'h':
                        cur_row = 0;
                        cur_col = 0;
                        break;
                    case 'i':
                        overwrite = false;
                        break;
                    case 'l':
                        if (!cursor_out_of_bound(cur_row, cur_col - 1))
                            cur_col--;
                        break;
                    case 'o':
                        overwrite = true;
                        break;
                    case 'r':
                        if (!cursor_out_of_bound(cur_row, cur_col + 1))
                            cur_col++;
                        break;
                    case 'u':
                        if (!cursor_out_of_bound(cur_row - 1, cur_col))
                            cur_row--;
                        break;
                    case '^':
                        write(cur_row, cur_col, '^', overwrite);
                        break;
                    default:                     // case: ^##
                        int row = line[i] - '0'; // only 0 ~ 9
                        int col = line[++i] - '0';
                        if (!cursor_out_of_bound(row, col)) // If smaller screen size need it but not in this case
                        {
                            cur_row = row;
                            cur_col = col;
                        }
                        break;
                    }
                }
                else
                {
                    write(cur_row, cur_col, c, overwrite);
                    if (!cursor_out_of_bound(cur_row, cur_col + 1)) // Don't change row
                        cur_col++;
                }
            }
        }

        for (int i = 0; i < 10; i++)
        {
            cout << "|";
            for (int j = 0; j < 10; j++)
            {
                cout << screen[i][j];
            }
            cout << "|" << endl;
        }
        cout << "+----------+" << endl;
    }

    return 0;
}