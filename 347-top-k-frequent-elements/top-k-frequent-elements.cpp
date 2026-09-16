class Solution {
public:
    #define pp pair<int,int>
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pp,vector<pp>,greater<pp>>pq;
        unordered_map<int,int>m;
        for(int i = 0; i<nums.size(); i++){
            m[nums[i]]++;
        }
        for(auto x : m){
            pq.push({x.second,x.first});
        }
        while(pq.size()>k){
            pq.pop();
        }
        vector<int>ans;;
        while(pq.size()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans ;
    }
};