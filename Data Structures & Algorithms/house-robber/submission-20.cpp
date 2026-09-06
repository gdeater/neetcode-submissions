class Solution {
    map<int,int> mp;
public:
    int rob(vector<int>& nums) {
        return dfs(nums,nums.size() - 1);
    }
    int dfs(vector<int>& nums, int i){
        if (i == 0){
            return nums[0];
        }
        if (i == 1){
            return max(nums[1],nums[0]);
        }
        if (mp.count(i)){
            return mp[i];
        }
        mp[i] = max(dfs(nums,i - 1), dfs(nums,i - 2) + nums[i]);
        return mp[i];
    }
};
