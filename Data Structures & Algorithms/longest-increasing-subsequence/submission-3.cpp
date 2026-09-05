class Solution {
public:
    int bin(vector<int> res, int n){
        int l,r;
        l = 0;
        r = res.size();
        while (l <= r){
            int m = (l + r) / 2;
            if (res[m] == n){
                return m;
            }
            else if (res[m] > n){
                r = m - 1;
            }
            else{
                l = m + 1;
            }
        }
        return l;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for(int i : nums){
            if (res.size() == 0 || res[res.size() - 1] < i){
                res.push_back(i);
            }
            else{
                int idx = bin(res,i);
                res[idx] = i;
            }
        }
        return res.size();
    }
};
