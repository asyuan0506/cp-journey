class Solution
{
public:
    vector<int> countTasks(vector<int> &tasks, vector<int> &shifts)
    {
        const int n = tasks.size();
        vector<long long> pre(n + 1, 0); // 1-indexed
        for (int i = 1; i <= n; i++)
        {
            pre[i] = pre[i - 1] + tasks[i - 1]; // exclusive
        }

        const int sn = shifts.size();
        long long t = 0;
        for (int i = 0; i < sn; i++)
        {
            int shift = shifts[i];
            t += shift;
            if (t >= pre[n])
            { // Finish all jobs
                shifts[i] = 0;
                t = 0;
                continue;
            }
            int idx = upper_bound(pre.begin(), pre.end(), t) - pre.begin();
            shifts[i] = n - idx + 1;
        }

        return shifts;
    }
};