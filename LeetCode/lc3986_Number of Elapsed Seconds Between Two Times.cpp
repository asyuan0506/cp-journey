class Solution {
public:
    static int time(string times)
    {
        return (((times[0] - '0') * 10 + (times[1] - '0')) * 60 * 60) + (((times[3] - '0') * 10 + (times[4] - '0')) * 60) + ((times[6] - '0') * 10 + times[7] - '0');
    }
    int secondsBetweenTimes(string startTime, string endTime) {
        return time(endTime) - time(startTime);
    }
};