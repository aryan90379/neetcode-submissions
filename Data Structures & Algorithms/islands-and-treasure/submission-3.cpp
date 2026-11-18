class Solution {
   public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int rows = grid.size();
        int cols = grid[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        int step = 0;
        while (!q.empty()) {
            step++;

            int sz = q.size();

            for (int i = 0; i < sz; i++) {
                auto [row, col] = q.front();
                q.pop();
                int dr[] = {-1, 1, 0, 0};
                int dc[] = {0, 0, -1, 1};

                for (int k = 0; k < 4; k++) {
                    int adjrow = row + dr[k];
                    int adjcol = col + dc[k];

                    if (adjrow < 0 || adjrow >= rows || adjcol < 0 || adjcol >= cols) continue;

                    if (grid[adjrow][adjcol] > step) {
                        grid[adjrow][adjcol] = step;
                        q.push({adjrow, adjcol});
                    }
                }
            }
        }
    }
};
