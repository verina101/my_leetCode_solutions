class Solution {
public:
    string longestPalindrome(string s) {
        int sz = s.size();
        vector<vector<bool>>dp(sz,vector<bool>(sz,0));
        for(int i=0;i<sz;i++)
            dp[i][i]=1;
        int longestLength=1,longestStart = 0;
        
        for(int end = 1 ;end < sz ; end++){
            for(int start = end -1 ; start>=0 ; start--){
                if(s[start]==s[end]){
                    if(start+1 == end || dp[start+1][end-1]){
                        dp[start][end]=1;
                        if(end - start +1 > longestLength){
                            longestLength = end - start +1;
                            longestStart = start;
                        }
                    }
                }
            }
        }
        return s.substr(longestStart, longestLength);
    }
};