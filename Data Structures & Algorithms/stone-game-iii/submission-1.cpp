#include<bits/stdc++.h>
class Solution {
public:
    int n;
    int t[50001];
    int solve(vector<int>& stones, int index) {
        if (index >= n) return 0;
        if (t[index] != -1) return t[index];
        int result = stones[index] - solve(stones, index + 1);
        if (index + 1 < n) result = max(result, stones[index] + stones[index+1] - solve(stones, index + 2));
        if (index + 2 < n) result = max(result,stones[index] + stones[index+1] + stones[index+2] - solve(stones, index + 3));

        return t[index] = result;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        memset(t, -1, sizeof(t));
        n = stoneValue.size();
        int result = solve(stoneValue, 0);
        if (result > 0) return "Alice";
        else if (result < 0) return "Bob";
        return "Tie";
    }
};