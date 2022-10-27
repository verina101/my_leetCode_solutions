class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int>dp(nums.size());
        dp[0]=nums[0];
        int ans = dp[0];
        
        for(int i=1;i<nums.size();i++){
            dp[i] = nums[i] + (dp[i-1]> 0 ? dp[i-1] : 0 );
            ans = max(dp[i],ans);
        }
        return ans;
    }
   
};