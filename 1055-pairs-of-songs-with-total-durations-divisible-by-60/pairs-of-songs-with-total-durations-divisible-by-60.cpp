class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {

        vector<int> freq(60,0);

        int count = 0;

        for(int t : time){

            int r = t % 60;

            int need = (60 - r) % 60;

            count += freq[need];

            freq[r]++;
        }

        return count;
    }
};