class Solution {
    map<vector<int>, int> mp;
public:
    int uniquePaths(int m, int n) {
        return dfs(0,0,m,n);
    }
    int dfs(int i, int j, int x,int y){
        if (i == (x - 1) && j == (y - 1)){
            return 1;
        }
        if (i >= x || j >= y){
            return 0;
        }
        if (mp.count({i,j})){
            return mp[{i,j}];
        }
        mp[{i,j}] = dfs(i + 1,j,x,y) + dfs(i,j + 1,x,y);
        return mp[{i,j}];
    }
};
