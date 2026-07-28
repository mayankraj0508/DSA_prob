class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0;
        int first =0;
        int tank  = 0;
        bool flag  = true;
        int f = INT_MIN;
        for(int i = 0; i<gas.size(); i++){
            int find  = gas[i]-cost[i];
            sum  =  sum + find;
            tank  =  tank + find;
            if(tank<0){
                tank = 0;
                first = i+1;
            }
       
            
            
        }
        if(sum>=0){
            return first;
        }
        return -1;

        
    }
};