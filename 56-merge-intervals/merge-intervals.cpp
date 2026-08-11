class Solution {
public:
#define pp pair<int,int>
    static bool cmp(vector<int>&a, vector<int>&b){
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& nums) {

        sort(nums.begin(),nums.end(),cmp);
        int start  = nums[0][0];
        int end  = nums[0][1];
        int m = nums.size();
        int n =nums[0].size();
        vector<vector<int>>ans;
        for(int i = 1; i<nums.size(); i++){
            int s = nums[i][0];
            int e= nums[i][1];
            //this new interval lies completely inside the givenp intevral 
            if(s>=start && e<=end){
                start  = min(s,start);
                end  =   max(e,end);
            }
            else if(s>=start && e>=end && s<=end){
                 end  = max(e,end);
            }
            else{
                ans.push_back({start,end});
                start  = s;
                end  = e;
            }

        }
        ans.push_back({start,end});
        return ans ;

  

        
    }
};