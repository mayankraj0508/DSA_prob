class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int i = 0;
        int j = nums.size()-1;
        int ans = 0;
         int mindiff = INT_MAX;
        for(int i =0; i<nums.size(); i++){
            int j = 0;
            int k = nums.size()-1;
            int val = nums[j]+nums[k];
           
            while(j<k){
                int sum = nums[j]+nums[k];
                int val = nums[j]+nums[k];
                if(j!=i && k!=i){
                    int diff= abs(target-(sum+nums[i]));
                    if(diff<mindiff){
                        mindiff = diff;
                        ans = val+nums[i];
                       
                    }
                    if(nums[i]+val<target){
                        j++;
                    }
                    else{
                        k--;
                    }
                    
                }
                else{
                    if(j==i){
                        j++;;
                    }
                    if(k==i){
                        k--;
                    }

                }
            }
        }
        return ans;
    }
};