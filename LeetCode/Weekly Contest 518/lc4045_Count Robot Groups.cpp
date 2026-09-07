class Solution {
public:
    struct group 
    {
        int pos;
        int speed;
    };
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        const int n = position.size();
        vector<group> groups;
        groups.push_back({ position[0], speed[0] });
        int idx = 0;
        for (int i = 1; i < n; i++) // Combine robots distance smaller than variable "distance"
        {
            if (position[i] - groups[idx].pos <= distance)
            {
                groups[idx] = { position[i], speed[i] };
            }
            else
            {
                groups.push_back({ position[i], speed[i] });
                idx++;
            }
        }
        int cnt = groups.size();
        for (int i = idx; i > 0; i--)
        {
            int right_speed = groups[i].speed;
            for (int j = i - 1; j >= 0; j--)
            {
                if (groups[j].speed > right_speed)
                {
                    cnt--;
                    i = j;
                }
                else
                    break;
            }
        }
        return cnt;
    }
};