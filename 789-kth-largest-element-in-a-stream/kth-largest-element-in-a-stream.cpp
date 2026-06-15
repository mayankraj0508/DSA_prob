class KthLargest {
public:
    int K;
    priority_queue<int,vector<int>,greater<int>>pq;
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(int i =0; i<nums.size(); i++){
            if(pq.size()<k){
                pq.push(nums[i]);
            }
            else{
                if(nums[i]>pq.top()){
                    pq.push(nums[i]);
                    pq.pop();
                }
            }
        }
        
    }
    
    int add(int val) {
        if(pq.size()<K){
            pq.push(val);
            return pq.top();
        }
        else{
            if(val>pq.top()){
                pq.push(val);
                pq.pop();
                return pq.top();
            }
            return pq.top();
        }
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */