class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>prefix(n+1);
        prefix[1] = nums[0];
        for(int i = 1; i<=n; i++){
            prefix[i] = prefix[i-1]+nums[i-1];
        }
         for(int i = 0; i<prefix.size(); i++) cout<<prefix[i]<<" ";
        unordered_map<int,int>m;
       int ans  = 0;
    
        for(int i = n; i>=1 ; i--){
             m[prefix[i]]++;
            int y = prefix[i-1];
            int x = k+y;
            if(m.find(x)!=m.end()){
                ans  = ans + m[x];
            }
            

        }
        return ans ;

         
        

        
    }
};