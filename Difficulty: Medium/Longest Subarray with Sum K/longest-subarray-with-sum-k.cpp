class Solution {
  public:
    int longestSubarray(vector<int>&nums, int k) {
        // code here
        unordered_map<int,int>m;
        int n = nums.size();
        vector<int>prefix(n+1);
        prefix[0] = 0;
        for(int i = 1; i<n+1; i++){
            prefix[i] = nums[i-1]+prefix[i-1];
        }
        for(int i = n; i>=0; i--){
            if(m.find(prefix[i])==m.end()){
                m[prefix[i]] = i;
            }
        }
       

        int ans  = 0;
        for(int i = 1; i<nums.size(); i++){
            int x = prefix[i-1];
            int required = x+k;
            if(m.find(required)!=m.end()){
                ans  = max(ans,m[required]-i+1);
            }
            
        }
          return ans ;
        
     
    }
};