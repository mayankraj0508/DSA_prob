class Solution {
public:
    int findunion(vector<int>& parent, int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = findunion(parent, parent[x]);
    }
    void unions(vector<int>& parent, vector<int>& size, int a, int b) {
        a = findunion(parent, a);
        b = findunion(parent, b);
        if (a == b)
            return;
        if (size[a] <= size[b]) {
            size[a] = size[a] + size[b];
            parent[a] = b;
        } else {
            size[b] = size[b] + size[a];
            parent[b] = a;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<int> parent(accounts.size());
        for (int i = 0; i < accounts.size(); i++) {
            parent[i] = i;
        }
        vector<int> size(accounts.size(), 1);
        unordered_map<string, int> m;
        for (int i = 0; i < accounts.size(); i++) {
            for (int j = 0; j < accounts[i].size(); j++) {
                if (j != 0 && m.find(accounts[i][j]) == m.end()) {
                    m[accounts[i][j]] = i;
                } else {
                    if (j != 0) {
                        unions(parent, size, i, m[accounts[i][j]]);
                    }
                }
            }
        }
        vector<vector<string>> ans(accounts.size());
        for (auto x : m) {
            int a = findunion(parent, x.second);
            if (ans[a].size() == 0) {
                if (accounts[a][0] != " ")
                    ans[a].push_back(accounts[a][0]);
            }
            if (x.first != " ") {
                ans[a].push_back(x.first);
            }
        }
        for (auto& v : ans) {
            if (v.size() > 1)
                sort(v.begin() + 1, v.end());
        }

        vector<vector<string>> res;
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i].size() != 0) {
                res.push_back(ans[i]);
            }
        }
       
        return res;
    }
};