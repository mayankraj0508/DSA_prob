class Solution {
public:
    int trailingZeroes(int n) {
    int ans  = 0;
    while(n>0){
        int q = n/5;
        ans  =  ans + q;
        n  = n/5;

    }
    return ans ;
    }
};