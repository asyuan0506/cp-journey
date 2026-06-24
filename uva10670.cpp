#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct agency
{
	string name;
	int a, b;
	int cost = 0;
};

bool cmp(agency a, agency b)
{
	if (a.cost == b.cost)
		return a.name < b.name;
	return a.cost < b.cost;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int Case = 0;
	while (n--)
	{
		int N, M, L;
		cin >> N >> M >> L;
		vector<agency> agencies(L);
		for (int i = 0; i < L; i++)
		{
			string name = "";
			char buf;
			while (cin >> buf && buf != ':')
				name += buf;
			agencies[i].name = name;
			cin >> agencies[i].a >> buf >> agencies[i].b;
			int tmp_N = N;
			while (tmp_N != M)
			{
				if (agencies[i].a > agencies[i].b / (tmp_N - tmp_N / 2) && tmp_N / 2 >= M)
				{
					tmp_N /= 2;
					agencies[i].cost += agencies[i].b;
				}
				else
				{
					tmp_N--;
					agencies[i].cost += agencies[i].a;
				}
			}
		}
		sort(agencies.begin(), agencies.end(), cmp);
		cout << "Case " << ++Case << "\n";
		for (agency i : agencies)
			cout << i.name << " " << i.cost << "\n";
	}	

	return 0;
}
