class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        if(a.size()>b.size()) return kthElement(b,a,k);
        int lo = 0;
        if(k>b.size()){
            lo = k-b.size();
        }
        int x = a.size();
       int hi = min(k,x);
       int left = k;
       while(lo<=hi){
           int mid  = lo+(hi-lo)/2;
           int x = left-mid;
           int l1 = (mid-1>=0 && mid-1<a.size())?a[mid-1] :INT_MIN;
           int r1 = (mid>=0  && mid<a.size()) ? a[mid]:INT_MAX;;;
           int l2 = (x-1>=0 && x-1<b.size())? b[x-1]:INT_MIN;
           int r2  = (x>=0 && x<b.size()) ? b[x]:INT_MAX;;
           if(l1<=r2 && l2<=r1){
               return max(l1,l2);
               
           }
           else if(l1>r2){
               hi  = mid-1;
           }
           else{
               lo = mid+1;
           }
           
           
       }
        return -1;
    }
};