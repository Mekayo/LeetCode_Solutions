class DSU {
    vector<int> rank, parent;

public:
    DSU(int n) {
        rank.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findparent(int i) {
        return i == parent[i] ? i : parent[i] = findparent(parent[i]);
    }

    void unionbyrank(int x, int y) {

        int x_parent = findparent(x);
        int y_parent = findparent(y);

        if (x_parent == y_parent)
            return;

        if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else {
            parent[y_parent] = x_parent;
            rank[x_parent] += 1;
        }
        return;
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();

        DSU dsu(n);

        unordered_map<string, int> emailToIndex;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if (emailToIndex.find(mail) == emailToIndex.end()) {
                    emailToIndex[mail] = i;
                } else {
                    dsu.unionbyrank(i, emailToIndex[mail]);
                }
            }
        }
        vector<string> merging[n];
        for (auto it : emailToIndex) {
            string mail = it.first;
            int node = dsu.findparent(it.second);
            merging[node].push_back(mail);
        }
        vector<vector<string>> ans;

        for (int i = 0; i < n; i++) {
            if (merging[i].size() == 0)
                continue;
            sort(merging[i].begin(), merging[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto it : merging[i]) {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};