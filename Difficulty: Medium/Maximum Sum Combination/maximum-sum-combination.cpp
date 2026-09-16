class Solution {
	public:
	#define sp pair<int, int>
	#define pp pair<int,pair<int,int>>
	vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
	    priority_queue<pp>pq;
	    vector<int>ans;
	    sort(a.begin(),a.end());
	    sort(b.begin(),b.end());
	    pq.push({a[a.size()-1]+b[b.size()-1],{a.size()-1,b.size()-1}});
	    set<sp>visited;
	    visited.insert({a.size()-1,b.size()-1});
	    while(ans.size()<k){
	       
	        int val  = pq.top().first;
	        int idx1 = pq.top().second.first;
	        int idx2  = pq.top().second.second;
	         pq.pop();
	        ans.push_back(val);
	        if(idx1-1>=0 && visited.find({idx1-1,idx2})==visited.end()){
	            pq.push({a[idx1-1]+b[idx2],{idx1-1,idx2}});
	            visited.insert({idx1-1,idx2});
	            
	        } 
	        if(idx2-1>=0 && visited.find({idx1,idx2-1})==visited.end()){
	            pq.push({a[idx1]+b[idx2-1],{idx1,idx2-1}});
	            visited.insert({idx1,idx2-1});
	        } 
	        
	    }
	    return ans ;
	    
	    
	    
	    
	    
	    
	}
	
};
