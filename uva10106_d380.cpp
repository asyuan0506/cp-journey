#include <bits/stdc++.h>

using namespace std;

int arr1[505], arr2[255];

void product(int &lenX, int &lenY)
{
    for (int i = lenX - 1; i >= 0; i--)
    {
        for (int j = lenY - 1; j >= 0; j--)
        {
            arr1[i + j] += arr1[i] * arr2[j];
        }
        int carry = 0;
        for (int j = i; j < lenX + lenY; j++)
        {
            arr1[j] += carry;
            carry = arr1[j] / 10;
            arr1[j] %= 10;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string X, Y;
    while (cin >> X >> Y)
    {
        if (X == "0" || Y == "0")
        {
            cout << "0\n";
            continue;
        }
        memset(arr1, 0, sizeof(arr1));
        memset(arr2, 0, sizeof(arr2));
        int lenX = X.size();
        int lenY = Y.size();
        for (int i = 0; i < lenX; i++)
        {
            arr1[i] = X[lenX - 1 - i] - '0';
        }
        for (int i = 0; i < lenY; i++)
        {
            arr2[i] = Y[lenY - 1 - i] - '0';
        }

        int idx = 0;
        arr2[idx]--;
        while (arr2[idx] < 0)
        {
            arr2[idx] += 10;
            arr2[++idx]--;
        }
        product(lenX, lenY);
        bool flag = false;
        for (int i = lenX + lenY; i >= 0; i--)
        {
            if (arr1[i] != 0)
            {
                flag = true;
            }
            if (flag)
                cout << arr1[i];
        }
        cout << "\n";
    }

    return 0;
}