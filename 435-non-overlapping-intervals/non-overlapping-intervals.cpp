class Solution {
public:
    static bool cmp(vector<int>&a, vector<int>&b){
        return a[0]<b[0];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        //count no of overlapping intervals first
        int start  = intervals[0][0];
        int end   =  intervals[0][1];
        int count  = 0;
        for(int i =1; i<intervals.size(); i++){
            int s = intervals[i][0];
            int e = intervals[i][1];
            //case 1 when thisb interval lies completelyb within myb interval 
            if(s>=start && e<=end){
                count++;
                end   = e;
                start  = s;
            }
            //case 2 when half of this interval lies within my interval

            else if(s>=start && s<end && e>=end){
                count++;
                //end  = min(e,end);
            }
            else{
                start  = s;
                end  = e;
            }


        }
        cout<<count ;
        return count;
         
        
    }
};