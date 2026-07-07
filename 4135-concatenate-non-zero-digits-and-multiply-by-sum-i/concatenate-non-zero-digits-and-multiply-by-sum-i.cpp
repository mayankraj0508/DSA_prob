class Solution {
public:
    long long power(int a, int b){
        if(b==0){
            return 1;
        }
        if(b==1){
            return a;
        }
        long long half = power(a,b/2);
        if(b%2==0){
            return half*half;
        }
        else
        return half*half*a;
    }
    long long f(int n){
        int x = 0;
        int sum  = 0;
        int number = 0;
        while(n>0){
            int rem = n%10;
            n = n/10;
            if(rem==0){
                continue;
            }
            else{
                sum  = sum + rem;
                number = rem*power(10,x)+ number;
                x++;
            }
    }
    return sum*(long long)number;
    }
    long long sumAndMultiply(int n) {
        return f(n);
        
    }
};