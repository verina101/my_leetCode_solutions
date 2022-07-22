class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>vec;
        for(auto num : nums){
            vec.push_back(num * num);
        }
        sort(vec.begin(),vec.end());
        return vec;
    }
};