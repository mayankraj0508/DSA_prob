class Solution {
  public:
    long subarrayXor(vector<int> &nums, int k) {
        // code here
        unordered_map<int,int>m;
        m[0] = 1;
        int x = 0;
        int count  = 0;
        for(int i = 0;i<nums.size(); i++){
            x = x xor nums[i];
            int y = x xor k;
            if(m.find(y)!=m.end()){
                int freq = m[y];
                count = count+freq;
            }
           m[x]++;
            
        }
        return count ;
        
    }
};