class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {

        unordered_map<int,int> freq;
        unordered_map<int,int> first;
        unordered_map<int,int> last;

        int degree = 0;

        for(int i=0; i<nums.size(); i++){

            if(first.find(nums[i]) == first.end()){
                first[nums[i]] = i;
            }

            last[nums[i]] = i;

            freq[nums[i]]++;

            degree = max(degree, freq[nums[i]]);
        }

        int ans = INT_MAX;

        for(auto x : freq){

            if(x.second == degree){

                ans = min(ans,
                          last[x.first] - first[x.first] + 1);
            }
        }

        return ans;
    }
};