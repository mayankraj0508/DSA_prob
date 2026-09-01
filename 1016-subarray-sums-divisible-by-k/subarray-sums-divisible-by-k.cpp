class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int prefix = 0;
        unordered_map<int,int>m;
        m[0] = 1;
        int ans  = 0;
        for(int i = 0; i<nums.size(); i++){
            prefix = prefix+nums[i];
            int rem  = prefix%k;
            if(rem<0) rem  = rem+k;
            if(m.find(rem)!=m.end()){
                ans  = ans + m[rem];

            }
            m[rem]++;
 
        }
        return ans ;

        
    }
};