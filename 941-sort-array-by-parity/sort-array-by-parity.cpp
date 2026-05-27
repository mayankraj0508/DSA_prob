class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& arr) {
        int i =0;
         int j = arr.size()-1;
         while(i<=j){
            if(arr[i]%2!=0 && arr[j]%2==0){
                swap(arr[i],arr[j]);
                i++;
                j--;

            }
            else if(arr[i]%2==0 && arr[j]%2==0){
                i++;
            }
             else if(arr[i]%2!=0 && arr[j]%2!=0){
                j--;
            }
            else{
                i++;
            }


         }
         return arr;
        
    }
};