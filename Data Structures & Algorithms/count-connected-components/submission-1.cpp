class Solution {
   public:
    vector<bool> visited;
    vector<vector<int>> adj;
    void bfs(int node) {
        visited[node] = true;
        for (auto& it : adj[node]) {
            if (!visited[it]) {
                bfs(it);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        visited = vector<bool>(n, false);

        adj = vector<vector<int>>(n);
        int count =0;

        for (auto& it : edges) {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;
                bfs(i);
            }
        }

        return count;
    }
};
