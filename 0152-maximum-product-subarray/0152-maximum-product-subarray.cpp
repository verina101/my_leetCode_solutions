class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx =INT_MIN, curMax = 1,curMin = 1;
        for(auto &x :nums)
            mx = max(mx,x);
        
        for(auto &x : nums){
            int prevMax = curMax*x;
            curMax = max({x,x*curMax,x*curMin});
            curMin = min({x,prevMax,x*curMin});
            mx = max(mx,curMax);

        }
        return mx;
    }
};