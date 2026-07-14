class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int shoursec = (startTime[0]*10+startTime[1])*3600;
        int sminsec = (startTime[3]*10+startTime[4])*60;
        int ssec = (startTime[6]*10+startTime[7]);
        int ehoursec = (endTime[0]*10+endTime[1])*3600;
        int eminsec = (endTime[3]*10+endTime[4])*60;
        int esec = (endTime[6]*10+endTime[7]);
        return abs((shoursec+sminsec+ssec)-(ehoursec+eminsec+esec));
    }
};