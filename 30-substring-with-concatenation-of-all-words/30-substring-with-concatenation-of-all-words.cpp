class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
    int wordSize = words[0].size();
    int subStringSize = wordSize * words.size();
    string word;
    vector<int>ans;
    int cnt=0;
        
    map<string,int>mp;
    map<string,int>freq;
    map<string,bool>valid;
    
    if(s.size()<subStringSize)
        return ans;   
    
    for(int i=0;i<words.size();i++){
        mp[words[i]]++;
        valid[words[i]]=true;
    }
    
    freq=mp;
    
    int start=0;
    for(int i=0;i<=s.size() - subStringSize;i++){
        cnt=0;start=i;
        mp=freq;
        for(int j=start;j<i+subStringSize;j+=wordSize){
            word = s.substr(j,wordSize);
            if(valid[word]){
                mp[word]--;
                if(mp[word]==0)cnt+=freq[word];
            }
            if(cnt==words.size())ans.push_back(start);
        }
    
    }
        
    return ans;
    }
};
