class Solution {
public:
    bool isNStraightHand(vector<int>& nums, int groupSize) {
        int N = nums.size();
         if(N%(groupSize)!=0){
            return false;
        }
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i =0; i<nums.size(); i++){
            pq.push(nums[i]);
        }
        while(pq.size()){
            int size = 0;
            int last = -1;
            vector<int>temp;
            while(size<groupSize && pq.size()){
                if(last==-1){
                    last = pq.top();
                    pq.pop();
                    size++;
                }
                else{
                    int diff = pq.top()-last;
                    if(diff==0){
                        temp.push_back(pq.top());
                        pq.pop();
                    }
                    else if(diff!=1){
                        return false;
                    }
                    else{
                        last = pq.top();
                        pq.pop();
                        size++;
                    }
                }
            }
            if(size!=groupSize){
                return false;
            }
            for(int i=0; i<temp.size(); i++){
                pq.push(temp[i]);
            }
        }
        return true;
        
    }
};