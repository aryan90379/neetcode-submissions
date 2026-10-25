class Solution {

    vector<bool> visited;
    vector<vector<int>> adj;

    void dfs(int i)
    {
        visited[i] = true;

        for(auto& node: adj[i])
        {
            if(!visited[node])
            {
                dfs(node);
            }
        }
    }

public:
    int countComponents(int n, vector<vector<int>>& edges) {
        visited = vector<bool>(n,false);
        int count = 0;

        adj = vector<vector<int>>(n);

        for(auto& it : edges)
        {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }


        for(int i =0;i<n;i++)
        {
            if(!visited[i])
            {
                count++;
                dfs(i);
            }

        }

        return count;
    }
};
