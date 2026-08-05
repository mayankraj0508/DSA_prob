class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        unordered_map<int,long long> mp;

        long long prefix = 0;
        long long ans = LLONG_MIN;

        for(int i=0;i<nums.size();i++){

            prefix += nums[i];

            if(mp.count(nums[i]-k))
                ans = max(ans, prefix - mp[nums[i]-k]);

            if(mp.count(nums[i]+k))
                ans = max(ans, prefix - mp[nums[i]+k]);

            if(!mp.count(nums[i]))
                mp[nums[i]] = prefix - nums[i];
            else
                mp[nums[i]] = min(mp[nums[i]], prefix - nums[i]);
        }

        return ans==LLONG_MIN ? 0 : ans;
    }
};