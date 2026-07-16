class Solution {
public:
    int minOperations(string s1, string s2) {
        const int n = s1.length();
        int op = 0;
        for (int i = 0; i < n; i++) {   // Change 1 to 0 first
            if (s1[i] == '1' && s2[i] == '0') // Look for the next one first
            {
                bool substituted = false;
                if (i < n - 1 && s1[i + 1] == '1' && s2[i + 1] == '0')
                {
                    s1[i] = '0'; s1[i + 1] = '0';
                    op++;    
                    substituted = true;
                }
                else if (i == 0 && i < n - 1)
                {
                    if (s1[i + 1] == '1')
                    {
                        s1[i] = '0'; s1[i + 1] = '0';
                        op++;    
                        substituted = true;
                    }
                    else
                    {
                        s1[i] = '0';
                        op += 2;
                        substituted = true;
                    }
                }
                else if (i > 0)
                {
                    if (s1[i - 1] == '0')
                    {
                        s1[i] = '0';
                        op += 2; // s1[i - 1] change to 1 and change both to 0
                    }
                    else
                    {
                        s1[i - 1] = '0';
                        s1[i] = '0';
                        op++;
                    }
                    substituted = true;
                }
                if (!substituted)
                    return -1;
            }
        }      
        for (int i = 0; i < n; i++) // change 0 to 1
        {
            if (s1[i] != s2[i])
            {
                if (s1[i] == '1')
                    return -888;
                op++; 
            }
        }
        return op;
    }
};