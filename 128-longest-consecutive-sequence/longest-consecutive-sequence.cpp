class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<long long >s;
        for(int i = 0; i<nums.size(); i++){
            s.insert(nums[i]);
        }
        int i = 0;
        int ans  = 0;
         
      for (long long  x : s) {
    if (s.find(x - 1) != s.end())
        continue;

    int len = 1;
    while (s.find(x + 1) != s.end()) {
        x++;
        len++;
    }

    ans = max(ans, len);
}
        return ans ;
        
    }
};