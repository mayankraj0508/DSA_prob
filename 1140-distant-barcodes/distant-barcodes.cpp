class Solution {
public:
    #define pp pair<int,int>
    vector<int> rearrangeBarcodes(vector<int>& nums) {
        unordered_map<int,int>m;
        for(int i = 0; i<nums.size(); i++){
            m[nums[i]]++;
            
        }
        priority_queue<pp>pq;
        for(auto x: m){
            pq.push({x.second,x.first});
        }
        int idx = 0;
        while(pq.size()>1){
            int freq1 = pq.top().first;
            int num1 = pq.top().second;
            pq.pop();
            int freq2 = pq.top().first;
            int num2 = pq.top().second;
            pq.pop();
            nums[idx] = num1;
            idx++;
            nums[idx] = num2;
            idx++;
            freq1--;
            freq2--;
            if(freq1){
                pq.push({freq1,num1});
            }
            if(freq2){
                pq.push({freq2,num2});
            }

        }
        if(pq.size()==1){
            nums[idx] = pq.top().second;
            pq.pop();
        }
        return nums;

        
    }
};