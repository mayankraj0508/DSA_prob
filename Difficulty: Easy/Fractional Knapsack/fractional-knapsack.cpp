class Solution {
  public:
    #define pp pair<int,int>
    static bool cmp(pp &a, pp&b){
         return (double)a.first/a.second>(double)b.first/b.second;      
    }
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = wt.size();
        vector<pp>nums(n);
        
        for(int i = 0; i<n; i++){
            nums[i] = {val[i],wt[i]};
        }
        sort(nums.begin(),nums.end(),cmp);
        //for(int i = 0; i<nums.size(); i++) cout<<nums[i].first<<" "<<nums[i].second<<" ";
        double ans  = 0;
        int wgt = 0;
        for(int i = 0; i<nums.size(); i++){
            wgt = wgt+nums[i].second;
            if(wgt<=capacity){
                ans  = ans + nums[i].first;
                
            }
            else{
                wgt  = wgt-nums[i].second;
                int rem  = capacity-wgt;
                double k = (double)nums[i].first/nums[i].second;
                ans  = ans + (double)(rem)*k;
                return ans;
            }
            
            
        }
        return ans ;
        
    }
};
