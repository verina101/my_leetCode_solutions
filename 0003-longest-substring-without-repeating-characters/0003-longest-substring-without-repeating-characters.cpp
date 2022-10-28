class Solution {
public:
    map<char,bool>mp;
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)return 0;
        int start=0,end=0,ans=0;
        for(int i=0;i<s.size();i++){
            if(!mp[s[i]]){
                mp[s[i]]=1;
                end=i;
            }else{
                ans = max(ans,i-start);
                while(s[start]!=s[i]){
                    mp[s[start]]=0;
                    start++;
                }
                start++;
                mp[s[i]]=1;
            }
        }
        ans=max(ans,end-start+1);
        return ans;
    }
};