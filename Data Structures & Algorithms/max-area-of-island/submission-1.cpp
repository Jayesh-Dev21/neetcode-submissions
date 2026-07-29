class Solution {
private:
    int directions[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    int t = sizeof(directions) / sizeof(directions[0]);
    [[nondiscard]] int bfs(vector<vector<int>> &g, int r, int c){
        g[r][c] = 0;
        queue <pair<int,int>> q;
        int T{1};
        q.push({r,c});
        while(!q.empty()){
            auto [row, col] = q.front();
            q.pop();
            for(int i{0}; i<t; i++){
                int _r = row + directions[i][0];
                int _c = col + directions[i][1];
                if(_r >= 0 && _r < g.size() && _c >= 0 && _c < g[0].size() && g[_r][_c] == 1){
                    g[_r][_c] = 0;
                    q.push({_r,_c});
                    T++;
                }
            }
        }
        return T;
    }
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int R = grid.size(), C = grid[0].size();
        int MaxA{0};
        for(int r{0}; r<R; r++){
            for(int c{0}; c<C; c++){
                if(grid[r][c] == 1){
                    MaxA = max(MaxA, bfs(grid,r,c));
                }
            }
        }
        return MaxA;
    }
};