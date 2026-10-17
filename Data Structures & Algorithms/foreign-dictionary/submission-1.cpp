class Solution {
   public:
    bool dfs(int node, vector<int>& visited, vector<vector<int>>& adj,
             stack<int>& st, vector<int>& pathVisited) {
        visited[node] = 1;
        pathVisited[node] = 1;
        for (auto& it : adj[node]) {
            if (pathVisited[it]) {
                return false;
            }
            if (!visited[it]) {
                if (!dfs(it, visited, adj, st,pathVisited)) {
                    return false;
                }
            }
        }
        pathVisited[node] = 0;
        st.push(node);
        return true;
    }
    vector<int> topoSort(int V, vector<vector<int>>& adj, vector<bool>& exists) {
        vector<int> visited(V, 0);
        vector<int> pathVisited(V, 0);

        stack<int> st;
        for (int i = 0; i < V; i++) {
            if (!visited[i] && exists[i]) {
                if (
                    !dfs(i, visited, adj, st,pathVisited))
                    return {};
            }
        }

        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }

    string foreignDictionary(vector<string>& words) {
        vector<bool> exists(26, false);

        for (auto& word : words) {
            for (char c : word) {
                exists[c - 'a'] = true;
            }
        }

        vector<vector<int>> adj(26);
        for (int i = 0; i < words.size() - 1; i++) {
            string s1 = words[i];
            string s2 = words[i + 1];
            int len = min(s1.size(), s2.size());

            bool found = false;
            for (int k = 0; k < len; k++) {
                if (s1[k] != s2[k]) {
                    adj[s1[k] - 'a'].push_back(s2[k] - 'a');
                    found = true;
                    break;
                }
            }

            // invalid prefix case, it can never be true entie dictionary is invalid bro
            if (!found && s1.size() > s2.size()) {
                return "";
            }
        }

        vector<int> topo = topoSort(26, adj, exists);

        string ans = "";
        for (auto& it : topo) {
            ans += char(it + 'a');
        }
        return ans;
    }
};
