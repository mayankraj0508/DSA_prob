class Solution {
public:
    int candy(vector<int>& rating) {
        //most ptimal approach-- slope approach 
        int sum  = 1;
        int i =1;
        while(i<rating.size()){
            if(rating[i]==rating[i-1]){
                sum++;
                i++;
                continue;
            }
            int peak = 1;
            while(i<rating.size() && rating[i]>rating[i-1]){
                peak++;
                sum  = sum + peak;
                i++;
            }
            int down  = 1;
            while(i<rating.size() && rating[i]<rating[i-1]){
                sum  = sum +down;
                down++;
                i++;
            }
            if(down>peak){
                sum   = sum + down-peak;
            }
        }
        return sum ;

     }
};