class Solution {
    
public:
    set<string>words;
    queue<string>q;
    set<string>vis;
    map<string,int>level;
    int ans=1;
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) { 
        
        
        for(auto& w : wordList)
            words.insert(w);
        
        if(!words.count(endWord))return 0;
        
        q.push(beginWord);        
        vis.insert(beginWord);
        level[beginWord]=1;
        
        while(!q.empty()){
            string word = q.front();
            q.pop();
            if(word == endWord)return level[endWord];
            
            for(int i=0;i<word.size();i++){
                for(char c = 'a';c<='z';c++){
                    string new_word = word;
                    new_word[i]=c;
                    if(words.count(new_word) && !vis.count(new_word)){
                        q.push(new_word);
                        level[new_word]=level[word]+1;
                        vis.insert(new_word);
                    }
                }
            }
        }
        return 0;
        
        
        
        
    }
};