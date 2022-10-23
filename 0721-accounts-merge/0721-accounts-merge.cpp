class Solution {
public:
    unordered_map<string, vector<string>>adj;
    vector<vector<string>> ans;
    unordered_set<string>vis;
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        for(auto &acc:accounts){
            for(int i=1;i<acc.size()-1;i++){
                adj[acc[i]].push_back(acc[i+1]);
                adj[acc[i+1]].push_back(acc[i]);
            }
        }
        
        for(auto& acc: accounts){
            if(!vis.count(acc[1])){
                ans.push_back({acc[0]});
                dfs(acc[1]);
                sort(ans.back().begin()+1, ans.back().end());
            }
        }
        return ans;
    }
    
    void dfs(string& email){
        vis.insert(email);
        ans.back().push_back(email);
        for(auto& e : adj[email]){
            if(!vis.count(e)){
                dfs(e);
            }
        }
    }
};