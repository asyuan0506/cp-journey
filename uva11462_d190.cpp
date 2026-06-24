#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
       	cin.tie(0);
	int N;
	while (cin >> N && N != 0)
	{
		vector<int> bucket(100, 0);
		for (int i = 0; i < N; i++)
		{
			int age;
			cin >> age;
			if (age >= 1 && age < 100)
			{
				bucket[age]++;
			}
		}
		bool first = true;
		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < bucket[i]; j++)
			{
				if (!first)
					cout << " ";
				cout << i;
				first = false;
			}
		}
		cout << "\n";
	}

       	return 0;
}