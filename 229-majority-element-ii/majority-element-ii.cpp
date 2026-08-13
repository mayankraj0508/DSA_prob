class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        long long  candidate1 = LLONG_MIN;
        long long  candidate2  = LLONG_MIN;
        int freq1 = 0;
        int freq2 = 0;
        for(int i = 0; i<nums.size(); i++){
           if(freq1==0 && nums[i]!=candidate2){
               candidate1 = nums[i];
               freq1 = 1;
           }
           else if(freq2==0 && nums[i]!=candidate1){
            candidate2  = nums[i];
            freq2 = 1;
           }
           else if(nums[i]==candidate1){
              freq1++;
           }
           else if(nums[i]==candidate2){
            freq2++;
           }
           else {
               freq1--;
               freq2--;
              

           }
            
        }
        vector<int>ans;
           int count1 = 0;
        int count2 = 0;
       
        for (int x : nums) {
            if (x == candidate1)
                count1++;
            else if (x == candidate2)
                count2++;
        }
        int n = nums.size();
        if(count1>n/3){
            ans.push_back(candidate1);
        }
        if(count2>n/3){
            ans.push_back(candidate2);
        }
        return ans ;
        
    }
};