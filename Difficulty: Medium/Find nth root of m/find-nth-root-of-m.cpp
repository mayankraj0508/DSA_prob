class Solution {
  public:
  int m;
     int find(long long  mid,int n){
         long long  ans   = 1;
          for(int i= 0;i<n; i++){
              ans  = ans*mid;
          }
          return ans;
     }
    int nthRoot(int n, int m) {
        // Code here
        if(n==1){
            return m;
        }
        if(m==1){
            return 1;
        }
        if(m==0){
            return 0;
        }
        this->m = m;
        int lo = 1;
        int hi = m/2;
        int ans  = -1;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            long long p = find(mid,n);
            if(p>m){
                hi = mid-1;
            }
            else if(p==m){
                ans  = mid;
                break;
            }
            else{
                lo = mid+1;
            }
        }
        return ans ;
        
    }
};