class Solution {
public:
    void bfs(int x, int y, vector<vector<char>>& grid){
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] != '1'){
            return;
        }
        grid[x][y] = '0';
        bfs(x + 1,y,grid);
        bfs(x - 1,y,grid);
        bfs(x,y + 1,grid);
        bfs(x,y - 1,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        for (int i = 0;i < grid.size();i++){
            for(int j = 0;j < grid[0].size();j++){
                if (grid[i][j] == '1'){
                    bfs(i,j,grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
