    #include <bits/stdc++.h>

    using namespace std;

    string s;
    int l;
    vector<bool> image;

    void Build(int x, int width)
    {
        l++;
        if (s[l] == 'p')
        {
            int base = width / 4;
            for (int i = 0; i < 4; i++)
                Build(x + i * base, base);
        }
        else if (s[l] == 'f')
        {
            for (int i = 0; i < width; i++)
                image[x + i] = true;
        }
    }

    int main()
    {
        int T;
        cin >> T;
        while (T--)
        {
            cin >> s;
            image.assign(1024, false);
            l = -1;
            Build(0, 1024);
            cin >> s;
            l = -1;
            Build(0, 1024);
            int ans = 0;
            for (int i = 0; i < 1024; i++)
                ans += image[i];
            cout << "There are " << ans << " black pixels.\n";
        }

        return 0;
    }