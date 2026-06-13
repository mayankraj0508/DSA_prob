class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freq1(256, 0);
        int unique = 0;
        for (int i = 0; i < t.size(); i++) {
            if (freq1[t[i]] == 0) {
                unique++;
            }
            freq1[t[i]]++;
        }
        vector<int> freq2(256, 0);
        int i = 0;
        int j = 0;
        int count = 0;
        int firstidx = -1;
        int secondidx = -1;
        int ans = INT_MAX;
        while (j < s.size()) {
            freq2[s[j]]++;
            if (freq1[s[j]] == freq2[s[j]] && freq1[s[j]] != 0) {
                count++;
            }
            while (count == unique && i < s.size()) {
                if (j - i + 1 < ans) {
                    ans = j - i + 1;
                    firstidx = i;
                    secondidx = j;
                }
                ans = min(ans, j - i + 1);
                freq2[s[i]]--;
                if (freq1[s[i]] != 0 && freq2[s[i]] < freq1[s[i]]) {
                    count--;
                }
                i++;
            }
            j++;
        }
        if (firstidx == -1) {
            return "";
        }
        string p = s.substr(firstidx, ans);
        return p;
    }
};