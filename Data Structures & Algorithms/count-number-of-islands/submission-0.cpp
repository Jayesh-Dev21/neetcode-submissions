class Solution {
private:
    int directions[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
public:
    int numIslands(vector<vector<char>>& grid) {
        int R = grid.size(), C = grid[0].size();
        int islands{0};
        for(int r{0}; r<R; r++){
            for(int c{0}; c<C; c++){
                if(grid[r][c] == '1'){
                    bfs(grid, r, c);
                    islands++;
                }
            }
        }
        return islands;
    }
    void bfs(vector<vector<char>>& g, int r, int c){
        queue<pair<int,int>>q;
        g[r][c] = '0';
        q.push({r,c});
        while(!q.empty()){
            auto [row, col] = q.front(); q.pop();
            for(int i{0}; i<4; i++){
                int _r = row + directions[i][0];
                int _c = col + directions[i][1];
                if(_r>=0 && _c >= 0 && _r < g.size() && _c < g[0].size() && g[_r][_c] == '1'){
                    q.push({_r,_c});
                    g[_r][_c] = '0';
                }
            }
        }
    }
};
