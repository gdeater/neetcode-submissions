class Solution {
public:
    unordered_map<int,int> mp;
    int coinChange(vector<int>& coins, int amount) {
        int lo = dfs(coins,amount);
        return (lo >= 1e9) ? -1 : lo;
    }
    int dfs(vector<int>& coins,int amount){
        if (amount == 0){
            return 0;
        }
        if (mp.count(amount)){
            return mp[amount];
        }
        int res = 1e9;
        for(int coin : coins){
            if (amount >= coin){
                res = min(res, 1 + dfs(coins,amount - coin));
            }
        }
        mp[amount] = res;
        return mp[amount];
    }
};
