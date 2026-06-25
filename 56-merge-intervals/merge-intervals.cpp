class Solution {
public:
#define pp pair<int,int>
    static bool cmp(vector<int>&a, vector<int>&b){
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
         sort(intervals.begin(),intervals.end(),cmp);
         vector<vector<int>>ans;
         int n  = intervals.size();
         int start  = intervals[0][0];
         int end   = intervals[0][1];
         for(int i =1; i<n; i++){
            int s = intervals[i][0];
            int e = intervals[i][1];
            //case 1 this completely lie within my interval
            if(s>=start && e<=end){
                continue;
            }
            //case 2 when only start lie within the onyerval 
            else if(s>=start && s<=end && e>=end){
                end = max(end,e);
            }
            //case 2 when this interval is completely out of my interval 
            else{
                ans.push_back({start,end});
                start  = s;
                end  = e;

            }
         }
         ans.push_back({start,end});
        
         return ans;

        
    }
};