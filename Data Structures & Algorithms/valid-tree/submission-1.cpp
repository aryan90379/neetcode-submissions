class Solution {
   private:
    int n;
    vector<vector<int>> adj;
    vector<bool> visited;

    bool dfs(int i, int prev) {
        visited[i] = true;
        for (auto& node : adj[i]) {
            if (node == prev)
                continue;
            else if (visited[node])
                return false;

            if (!dfs(node, i)) return false;
        }

        return true;
    }

   public:
    bool validTree(int _n, vector<vector<int>>& edges) {
        this->n = _n;
        adj = vector<vector<int>>(n);

        visited = vector<bool>(n);
        for (auto& it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

if(!dfs(0,-1)) return false;

        for(int i =0;i<n;i++)
        {
            if(visited[i] == false) return false;
        }

        return true;

        
    }
};
