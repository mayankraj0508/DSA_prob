class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
        vector<int>ans;
        int n  = arr.size();
        unordered_map<int,int>m;
        for(int i =0; i<n; i++){
            m[arr[i]]++;
        }
        int freq = n/3;
        for(auto x:m){
            if(x.second>freq){
                ans.push_back(x.first);
            }
        }
        return ans;
        
        
    }
};