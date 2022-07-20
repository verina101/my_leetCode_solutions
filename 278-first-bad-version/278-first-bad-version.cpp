// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long s=1, e=n,loc=-1;
        while(s<=e){  
            long long mid = (s + e)/2;
            if(!isBadVersion(mid)){
                s=mid+1;
            } 
            else {
                loc=mid;
                e=mid -1;
            }
        }
        return loc;
    }
};