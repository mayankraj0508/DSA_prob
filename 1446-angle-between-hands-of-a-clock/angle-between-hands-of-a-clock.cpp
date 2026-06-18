class Solution {
public:
    double angleClock(int hour, int minutes) {
        int x = minutes*6;
        double f = minutes/60.0;
        double y = f*5;
        if(hour<6){
            hour = hour+12;
        }
        double ans  = x -(hour-12)*30 -y*6;
         ans = min(ans,360-ans);
         return abs(ans);
        // ans =  min(ans,360-ans);
        // return abs(ans);
        
    }
};