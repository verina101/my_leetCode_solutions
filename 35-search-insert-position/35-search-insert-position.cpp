class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s=0, e=nums.size()-1, loc=-1;
        while(s<=e){  
            int mid = (s + e)/2;
            if(nums[mid]==target){
                loc=mid;
                return loc;
            }
            else if(nums[mid]>target){
                e=mid-1; 
                loc=mid;
            }
            else
                s=mid+1;
        }
        return loc == -1 ? nums.size() : loc;
    }
};