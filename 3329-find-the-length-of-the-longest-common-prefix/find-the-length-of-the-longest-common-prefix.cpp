class Solution {
public:
    int size(int x){
        int count = 0;
        while(x>0){
            x = x/10;
            count++;
        }
        return count;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int>s;
        for(int i=0; i<arr1.size(); i++){
            s.insert(arr1[i]);
            int x = arr1[i];
            while(x>0){
                x = x/10;
                if(x!=0){
                    s.insert(x);
                }
                else{
                    break;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i<arr2.size(); i++){
            if(s.find(arr2[i])!=s.end()){
                ans = max(ans,size(arr2[i]));
            }
            else{
                int x = arr2[i];
                while(x>0){
                    if(s.find(x)!=s.end()){
                        ans = max(ans,size(x));
                        break;
                    }
                    x = x/10;

                }

            }
        }
        return ans;

        
    }
};