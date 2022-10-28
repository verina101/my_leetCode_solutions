class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        dp[0] = nums[0];  
        // dp[1] = max(dp[0],nums[1]);
        for(int i=1;i<nums.size();i++){
           dp[i] = max(dp[i-1],nums[i]+ (i-2>=0 ? dp[i-2]:0));
            
        }
        return dp[nums.size()-1];
    }
};