#include <bits/stdc++.h>

using namespace std;

/*  Recursive backtracking approach (TLE)
bool available(int r, int c, vector<vector<bool>> &board, int &M, int &N)
{
    int translation_r[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int translation_c[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
    for (int i = 0; i < 8; i++)
    {
        int pos_r = r + translation_r[i];
        int pos_c = c + translation_c[i];
        if (pos_r < 0 || pos_c < 0 || pos_r >= M || pos_c >= N)
            continue;
        if (board[pos_r][pos_c])
            return false;
    }
    return true;
}

int place_knight(int pos, vector<vector<bool>> &board, int cnt, int &M, int &N)
{
    int r = pos / N;
    int c = pos % N;
    if (r >= M)
        return cnt;

    int knight_cnt;
    if (available(r, c, board, M, N))
    {
        board[r][c] = true;
        knight_cnt = place_knight(pos + 1, board, cnt + 1, M, N);
    }
    board[r][c] = false;
    knight_cnt = max(knight_cnt, place_knight(pos + 1, board, cnt, M, N));
    return knight_cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int M, N;
    while (cin >> M >> N)
    {
        if (M == 0 && N == 0)
            break;
        vector<vector<bool>> board(M, vector<bool>(N, false));
        cout << place_knight(0, board, 0, M, N);

        cout << " knights may be placed on a " << M << " row " << N << " column board." << "\n";
    }

    return 0;
}
*/

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int M, N;
    while (cin >> M >> N)
    {
        if (M == 0 && N == 0)
            break;

        int knights;
        if (M == 1 || N == 1)
            knights = max(M, N);
        // else if (M == 2 || N == 2)
        // {
        //     knights = 4 * (max(M, N) / 4);
        //     int tmp = max(M, N) % 4;
        //     if (tmp == 1)
        //         knights += 2;
        //     else if (tmp == 2 || tmp == 3)
        //         knights += 4;
        // }
        // else
        //     knights = N * (M / 2) + (M % 2) * ((N / 2) + (N % 2));
        else if (M == 2 || N == 2)
        {
            knights = 4 * (max(M, N) / 4);
            knights += 2 * min(max(M, N) % 4, 2);
        }
        else
            knights = M * N / 2 + (M * N % 2);

        cout << knights << " knights may be placed on a " << M << " row " << N << " column board." << "\n";
    }

    return 0;
}