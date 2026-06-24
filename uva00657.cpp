#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool image_out_of_range(int r, int c, int &h, int &w)
{
    return r < 0 || c < 0 || r >= h || c >= w;
}

void same_X(int r, int c, vector<vector<char>> &image, int &h, int &w)
{
    if (image_out_of_range(r, c, h, w) || image[r][c] != 'X')
        return;
    image[r][c] = '*';
    same_X(r - 1, c, image, h, w);
    same_X(r + 1, c, image, h, w);
    same_X(r, c - 1, image, h, w);
    same_X(r, c + 1, image, h, w);
}

void same_dice(int r, int c, vector<vector<char>> &image, int &h, int &w, int &cnt)
{
    if (image_out_of_range(r, c, h, w) || image[r][c] == '.')
        return;
    if (image[r][c] == 'X')
    {
        cnt++;
        same_X(r, c, image, h, w);
    }
    image[r][c] = '.';
    same_dice(r - 1, c, image, h, w, cnt);
    same_dice(r + 1, c, image, h, w, cnt);
    same_dice(r, c - 1, image, h, w, cnt);
    same_dice(r, c + 1, image, h, w, cnt);
}

int main()
{
    int w, h;
    int cnt = 0;
    while (cin >> w >> h)
    {
        if (w == 0 && h == 0)
            return 0;
        cout << "Throw " << ++cnt << endl;

        vector<vector<char>> image(h, vector<char>(w));
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                cin >> image[i][j];

        vector<int> dots;
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (image[i][j] == '*' || image[i][j] == 'X')
                {
                    int cnt = 0;
                    same_dice(i, j, image, h, w, cnt);
                    dots.push_back(cnt);
                }
            }
        }
        sort(dots.begin(), dots.end());
        for (int i = 0; i < dots.size(); i++)
        {
            if (i != 0)
                cout << " ";
            cout << dots[i];
        }
        cout << "\n\n";
    }

    return 0;
}