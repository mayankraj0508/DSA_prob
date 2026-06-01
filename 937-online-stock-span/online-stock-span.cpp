class StockSpanner {
public:
    vector<int>pge;
    vector<int>nums;
    StockSpanner() {

        
    }
    
    int next(int price) {
        if(nums.size()==0){
            pge.push_back(-1);
            nums.push_back(price);
        }
        else{
            if(price<nums[nums.size()-1]){
                pge.push_back(nums.size()-1);
                nums.push_back(price);
            }
            else{
                int x = pge[nums.size()-1];
                while(x!=-1 && nums[x]<=price){
                    x = pge[x];
                }
                pge.push_back(x);
                nums.push_back(price);
            }
        }
        int left = nums.size()-1-pge[nums.size()-1];
        return left;

    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */