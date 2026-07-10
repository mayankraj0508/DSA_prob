class Solution {
public:
    int minimumSum(int n, int k) {
        int cnt  = 1;
    
        int num  = 1;
        int sum = 1;
    
        while(num<k/2 && cnt<n){
            num++;
            sum = sum + num;
            cnt++;
        }
        if(cnt==n)
        return sum ;
        int cnt2 = 0;
        cout<<num;
        if(k%2!=0){
             while(cnt2<=k/2-1){
            num++;
            cnt2++;
        }
        }
        else{
        while(cnt2<k/2-1){
            num++;
            cnt2++;
        }
    }
        while(cnt<n){
            num++;
            sum   = sum + num;
            cnt++;
        }
        return sum ;
        
    }
};