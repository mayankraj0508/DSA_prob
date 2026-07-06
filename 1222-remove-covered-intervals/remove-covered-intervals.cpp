class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        return a[0]<b[0];
          
    }
    int removeCoveredIntervals(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end(),cmp);
        int start = nums[0][0];
        int end  = nums[0][1];
        int count  = 1;
        // count++;
        bool flag  = true;
        for(int i=1; i<nums.size(); i++){
            int s = nums[i][0];
            int e = nums[i][1];
            if(s==start && e>=end){
                end = max(end,e);
                continue;

            }
           else  if(s>=start && e<=end){
                flag  = false;
                continue;
            }
            else {
               count++;
               start  = s;
               end  = e;
               flag  = true;
            }

        }
      
        return count;
    }
};