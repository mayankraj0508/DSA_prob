class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_map<int,int>m;
        for(int i= 0; i<nums.size(); i++){
            m[nums[i]]++;
           
        }
        for(auto x : m){
            if(x.second>=3){
                return false;
            }
        }
        return true;
        
    }
};