#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	cin >> N;
	while (N--)
	{
		vector<int> v(46, -1);
		for (int i = 0; i < 9; i++)
		{
			if (i % 2 == 1)
				continue;
			int idx = (1 + i) * i / 2;
			for (int j = 0; j <= i; j++)
			{
				if (j % 2 == 1)
					continue;
				cin >> v[idx + j];
			}
		}	
		for (int i = 0; i <= 6; i++)
		{
			if (i % 2 == 1)
				continue;
			int idx = (1 + i) * i / 2;
			for (int j = 0; j <= i; j++)
			{
				if (j % 2 == 1)
					continue;
				int cur_idx = idx + j;
				int right_elements = (i - j);
				int left_idx = cur_idx + right_elements + (i + 3) + j;
				int right_idx = left_idx + 2;
				int middle =  (v[cur_idx] - v[left_idx] - v[right_idx]) / 2;
				int top_left_idx = cur_idx + right_elements + 1 + j;
				int top_right_idx = top_left_idx + 1;
				v[left_idx + 1] = middle;
				v[top_left_idx] = v[left_idx] + middle;
				v[top_right_idx] = v[right_idx] + middle; 
			}
		}	
		for (int i = 0; i < 9; i++)
		{
			int idx = (1 + i) * i / 2;
			for (int j = 0; j <= i; j++)
			{
				cout << v[idx + j];
				if (j != i)
					cout << " ";
			}
			cout << "\n";
		}
	} 
	
	return 0;
}
