class Solution {
public:
    int finals = 0;
    long long f( int prev, int curr){
        if(curr>finals){
            return INT_MAX;
        }
        if(curr==finals){
            return 0;
        }
        if(curr==1){
           return 2+ f(curr,curr+1);
        }
        else{
            return min(1+f(prev,curr+prev),2+f(curr,curr+curr));
        }
    }
    int minSteps(int n) {
        finals = n;
         return f(0,1);
    }
};