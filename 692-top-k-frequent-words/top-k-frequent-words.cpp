class Solution {
public:
    #define pp pair<int,string>
    class comp {
        public:
        bool operator()(pair<int,string>&a, pair<int,string>&b){
            if(a.first==b.first){
                return a.second>b.second;

            }
        
                return a.first<b.first;
            

        }

    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pp,vector<pp>,comp>pq;
        unordered_map<string,int>m;
        for(int i=0; i<words.size(); i++){
            m[words[i]]++;
        }    
        for(auto x:m){
            pq.push({x.second,x.first});

        }    
        vector<string>ans;
    
        int p = k;
        while(p-- && pq.size()){
            ans.push_back(pq.top().second);
            pq.pop();
            
        }
        return ans;
    
        
  
    }
};