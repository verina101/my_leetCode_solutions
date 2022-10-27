class Solution {
public:
    int solve(int n, vector<int>& ans){
        if(n==0)
            return 1;
        else if(n<0)
            return 0;
        else if(ans[n])
            return ans[n];
        else{
            ans[n] = solve(n-1,ans) + solve(n-2,ans);
            return ans[n];
        }
        
    }
    int climbStairs(int n) {
        vector<int> ans(n+1);
        return solve(n, ans);
        
    }
};