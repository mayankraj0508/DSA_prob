class Solution {
public:
    bool isPalindrome(int x) {
        int y = 0;
        long long  r = 0;
        int n = x;
        while(n>0){
            int rem  = n%10;
            n = n/10;
            r = r*10 + rem;
           
        }
        if(r==x) return true;
        return false;
    }
};