class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s=0, e=nums.size();
        while(s<=e){  
            int mid = (s + e)/2;
            if(mid>=nums.size())
                return -1;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>target)
                e=mid-1;
            else
                s=mid+1;
        }
        return -1;
        
    }
};