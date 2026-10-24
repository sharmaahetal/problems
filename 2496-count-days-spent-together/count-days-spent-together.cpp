class Solution {
public:
    int covertTOdays(string date){
        int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 , 31};

        int month = stoi(date.substr(0,2));
        int day = stoi(date.substr(3,2));

        int total = 0;

        for(int i=0; i< month-1; i++){
            total += days[i];
        }
        total += day;
        return total;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int start = max(covertTOdays(arriveAlice), covertTOdays(arriveBob));
        int end = min(covertTOdays(leaveAlice), covertTOdays(leaveBob));

        if(end < start){
            return 0;
        }
        return end - start + 1;
    }
};