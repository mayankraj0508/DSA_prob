class Solution {
public:
    #define pp pair<int,char>
    int leastInterval(vector<char>& nums, int n) {
        unordered_map<char,int>m;
        for(int i =0; i<nums.size(); i++){
            m[nums[i]]++;
        }
        priority_queue<pp>pq;
        for(auto x:m){
            pq.push({x.second,x.first});
        }
        int time = 0;
        int prev_time = 0;
        while(pq.size()){
            prev_time = time;
            vector<pp>temp;
            while(time-prev_time<
            n+1){
                if(pq.size()==0 && temp.size()==0){
                    return time;
                }
                if(pq.size()==0){
                    time++;
                }
                else{
                auto x   = pq.top();
                int freq = x.first;
                pq.pop();
                freq--;
                if(freq>0){
                    temp.push_back({freq,x.second});
                }
                time++;
                }

            }
            for(int i=0; i<temp.size(); i++){
                pq.push(temp[i]);
            }
        }
    
        return time;

        
              
    }
};