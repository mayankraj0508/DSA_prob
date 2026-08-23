class Solution {
public:
    int reverse(int x) {
        if(x<=INT_MIN||x>=INT_MAX) return 0;
        long long  ans  = 0;
        long long  l = abs(x);
        int p = 1;
        while(l>=1){
            
            long long  a = l/10;
            long long  rem  = l%10;
            ans  =(long long) ans*p + rem;
            if(ans>=INT_MAX || ans<=INT_MIN) return 0;
            l = a;
            if(p==1)
            p = p*10;

        }
       if(x<0){
       return (-1)*ans ;
       }
       return ans ;
        
    }
};