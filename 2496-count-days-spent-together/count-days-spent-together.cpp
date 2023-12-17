class Solution {
public:
    vector<int>daysInMonth = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
                             // Jan,Feb,Mar,Apr,May,Jun,Jul,Aug,Sep,Oct,Nov,Dec
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {

        int AliceAriveMonth = stoi(arriveAlice.substr(0, 2));
        int AliceAriveDay = stoi(arriveAlice.substr(3, 2));
        int AliceLeaveMonth = stoi(leaveAlice.substr(0, 2));
        int AliceLeaveDay = stoi(leaveAlice.substr(3, 2));

        int BobAriveMonth = stoi(arriveBob.substr(0, 2));
        int BobAriveDay = stoi(arriveBob.substr(3, 2));
        int BobLeaveMonth = stoi(leaveBob.substr(0, 2));
        int BobLeaveDay = stoi(leaveBob.substr(3, 2));

        int AliceAriveAbsoluteDay = 0;
        for (int m = 1; m < AliceAriveMonth; m++)
            AliceAriveAbsoluteDay += daysInMonth[m];
        AliceAriveAbsoluteDay += AliceAriveDay;

        int BobAriveAbsoluteDay = 0;
        for (int m = 1; m < BobAriveMonth; m++)
            BobAriveAbsoluteDay += daysInMonth[m];
        BobAriveAbsoluteDay += BobAriveDay;

        int AliceLeaveAbsoluteDay = 0;
        for (int m = 1; m < AliceLeaveMonth; m++)
            AliceLeaveAbsoluteDay += daysInMonth[m];
        AliceLeaveAbsoluteDay += AliceLeaveDay;

        int BobLeaveAbsoluteDay = 0;
        for (int m = 1; m < BobLeaveMonth; m++)
            BobLeaveAbsoluteDay += daysInMonth[m];
        BobLeaveAbsoluteDay += BobLeaveDay;

        return max(0, min(AliceLeaveAbsoluteDay, BobLeaveAbsoluteDay) - max(AliceAriveAbsoluteDay, BobAriveAbsoluteDay) + 1);
    }
};