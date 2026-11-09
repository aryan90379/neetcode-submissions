class Solution {
   private:
    vector<int> par;

   public:
    int find_par(int p) {
        p = par[p];
        while (p != par[p]) {
            p = par[par[p]];
            p = par[p];
        }
        return p;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1) return false;
        par = vector<int>(n+1);
        iota(par.begin(),par.end(),0);

        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int par_u = find_par(u);
            int par_v = find_par(v);
            if (par_u == par_v) return false;
            par[par_u] = par_v;
        }
        return true;
    }
};
