class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i = 0;
        int j = 1;
        int k = nums.size()-1;
        vector<vector<int>>ans;
        while(i<nums.size()){
            
            int j  = i+1;
            int k = nums.size()-1;
            while(j<k){
                int val  = nums[i]+nums[j]+nums[k];
                if(val==0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    int a = nums[j];
                    while(j<=k && nums[j]==a){
                        j++;
                    }
                    int b = nums[k];
                    while(k>j && nums[k]==b){
                        k--;
                    }


                }
                else if(val<0){
                    j++;
                
                }
                else{
                    k--;
                }
            }
            int v= nums[i];
            while(i<nums.size() && nums[i]==v){
                i++;
            }


        }
        return ans ;
        
    }
};