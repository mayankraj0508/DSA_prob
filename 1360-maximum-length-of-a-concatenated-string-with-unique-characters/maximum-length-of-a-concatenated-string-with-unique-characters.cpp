class Solution {
public:

    bool valid(string &s){
        vector<int> freq(26,0);

        for(char ch : s){

            if(freq[ch-'a'] > 0){
                return false;
            }

            freq[ch-'a']++;
        }

        return true;
    }

    void f(int i, vector<string>& arr, string ans, int &mx){

        if(!valid(ans)){
            return;
        }

        mx = max(mx, (int)ans.size());

        if(i == arr.size()){
            return;
        }

        // take
        f(i+1, arr, ans + arr[i], mx);

        // not take
        f(i+1, arr, ans, mx);
    }

    int maxLength(vector<string>& arr) {

        int mx = 0;

        f(0, arr, "", mx);

        return mx;
    }
};