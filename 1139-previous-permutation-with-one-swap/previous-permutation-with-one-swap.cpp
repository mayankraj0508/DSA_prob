class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int idx = -1;
        int n = arr.size();
        for(int i = n-2; i>=0; i--){
            if(arr[i]>arr[i+1]){
                 idx = i;
                 break;
            }
        }
        if(idx==-1) return arr;
        int idx2 = -1;
        int mn  =INT_MIN;
        for(int j = n-1; j>idx; j--){
            if(arr[j]<arr[idx]){
               if(arr[j]>=mn){
                mn = arr[j];
                idx2 = j;
               }
        
        }
        }
         swap(arr[idx],arr[idx2]);
        return arr;

        
    }
};