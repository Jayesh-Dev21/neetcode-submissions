#define INF INT_MAX

class Solution {
public:
    vector<vector<int>> const dirs = {{-1, 0},{1, 0},{0, -1},{0, 1}};

    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int row = grid.size();
        int col = grid[0].size();
        for(int i{0}; i<row; i++) for(int j{0}; j<col; j++) if(grid[i][j]==0) q.push({i,j});

        while(!q.empty()){
            auto [m,n] = q.front();
            q.pop();

            for(int i{0}; i<4; i++){
                int r = m + dirs[i][0];
                int c = n + dirs[i][1];
            
                if(r<0 || r>=row || c<0 || c>=col || grid[r][c] != INF) continue;
                grid[r][c] = grid[m][n] + 1;
                q.push({r,c});
            }
        }
        return;
    }
};
