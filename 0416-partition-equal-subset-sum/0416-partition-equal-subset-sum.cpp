class Solution {
public:
    bool canPartition(vector<int>& nums) {
        long long total = 0;
        for(auto &n : nums){
            total+=n;
        }

        if(total % 2 !=0)return false;
        total/=2;
        set<int>st;
        st.insert(0);
        for(auto &x : nums){
            set<int>innerSet;
            for(auto &s : st){
                innerSet.insert(s);
                if(x+s<= total )
                    innerSet.insert(x + s);
                
                if(x+s == total)return true;
            }
            st = innerSet;
        }
        return false;
        
    }
};