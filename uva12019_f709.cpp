#include <bits/stdc++.h>

using namespace std;

const int DAY[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const string WEEKDAY[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

int main()
{
    vector<vector<int>> everyday(12);
    for (int i = 0; i < 12; i++)
        everyday[i].resize(DAY[i]);
    
    everyday[0][0] = 5; // 1/10 is Monday -> 1/1 is Saturday
    int next_weekday = everyday[0][0];
    for (int i = 0; i < 12; i++)
        for (int j = 0; j < DAY[i]; j++)
        {   
            everyday[i][j] = next_weekday;
            next_weekday = (next_weekday + 1) % 7;
        }
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int M, D;
        cin >> M >> D;
        cout << WEEKDAY[everyday[M-1][D-1]] << "\n";
    }
    

    return 0;
}