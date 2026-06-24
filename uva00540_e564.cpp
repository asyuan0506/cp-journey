#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

int find_team_idx(vector<pair<int, queue<int>>> &my_queue, int team_id)
{
    for (int i = 0; i < my_queue.size(); i++)
    {
        if (team_id == my_queue[i].first)
            return i;
    }
    return -1;
}

int main()
{
    int team;
    int cnt = 0;
    while (cin >> team)
    {
        if (team == 0)
            return 0;
        cout << "Scenario #" << ++cnt << endl;

        unordered_map<int, int> id_team;
        vector<bool> team_in_queue(team, false);
        vector<pair<int, queue<int>>> my_queue; // first: team_id, second: queue

        while (team--)
        {
            int members;
            cin >> members;
            while (members--)
            {
                int id;
                cin >> id;
                id_team[id] = team;
            }
        }
        string op;
        while (cin >> op)
        {
            if (op == "STOP")
                break;
            else if (op == "DEQUEUE")
            {
                cout << my_queue[0].second.front() << endl;
                my_queue[0].second.pop();
                if (my_queue[0].second.empty())
                {
                    team_in_queue[my_queue[0].first] = false;
                    my_queue.erase(my_queue.begin());
                }
            }
            else if (op == "ENQUEUE")
            {
                int x;
                cin >> x; // ID
                int x_team = id_team[x];
                if (team_in_queue[x_team])
                {
                    int idx = find_team_idx(my_queue, x_team);
                    my_queue[idx].second.push(x);
                }
                else
                {
                    queue<int> tmp;
                    tmp.push(x);
                    my_queue.push_back(make_pair(x_team, tmp));
                    team_in_queue[x_team] = true;
                }
            }
        }
        cout << endl;
    }
    return 0;
}