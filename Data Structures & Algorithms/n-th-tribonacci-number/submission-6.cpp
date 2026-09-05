class Solution {
    unordered_map<int,int> mp;
public:
    int tribonacci(int n) {
        return dfs(n);
    }
    int dfs(int n){
        if (n == 0){
            return 0;
        }
        if (n <= 2){
            return 1;
        }
        if (mp.count(n)){
            return mp[n];
        }
        mp[n] = dfs(n - 1) + dfs(n - 2) + dfs(n - 3);
        return mp[n];
    }
};