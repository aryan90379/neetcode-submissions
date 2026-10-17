class Solution {
   private:
    queue<pair<int, int>> q;

   public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] == 0) q.push({row, col});
            }
        }

        int step = 0;
        while (!q.empty()) {
            int sz = q.size();
            step++;

            for (int i = 0; i < sz; i++) {
                auto [row, col] = q.front();
                q.pop();

                int dr[] = {-1, 1, 0, 0};
                int dc[] = {0, 0, -1, 1};
                for (int k = 0; k < 4; k++) {
                    int newrow = row + dr[k];
                    int newcol = col + dc[k];

                    if (newrow < rows && newrow >= 0 && newcol >= 0 && newcol < cols &&
                        !visited[newrow][newcol] && grid[newrow][newcol] == INT_MAX)
                        {
                            grid[newrow][newcol]=step;
                            q.push({newrow,newcol});
                        }
                        
                }
            }
        }
    }
};
