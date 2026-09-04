class Solution {
public:
    void back(int n,int i, int k, vector<vector<int>>& res, vector<int>& sub){
        if (sub.size() == k){
            res.push_back(sub);
            return;
        }
        for(int j = i;j <= n;j++){
            sub.push_back(j);
            back(n,j + 1,k,res,sub);
            sub.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        res.clear();
        vector<int> sub;
        back(n,1,k,res,sub);
        return res;
    }
};