class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int>ans;
        if(n==1){
            ans.push_back(0);
            return ans;
        } 
        if(n==2){
            ans.push_back(0);
            ans.push_back(1);
            return ans;
        } 
        
        vector<vector<int>> adj(n);
        for(auto e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int>in_degree(n);
        queue<int>q;
        int nodes_left = n;
        for(int i=0;i<n;i++){
            in_degree[i]=adj[i].size();
            if(in_degree[i]== 1)
                q.push(i);
        }

        while(nodes_left > 2){
            int sz = q.size();
            nodes_left-=sz;
            for(int i=0;i<sz;i++){
                int node = q.front();
                q.pop();
                for(auto n : adj[node]){
                    if(--in_degree[n] == 1)
                        q.push(n);
                }
            }
        }
        
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};