class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int an = 0;
        int ans = 0;
        for(int i =0; i<gain.size(); i++){
           an  = an + gain[i];
           ans  = max(ans,an);
        }
        return ans;
        
    }
};