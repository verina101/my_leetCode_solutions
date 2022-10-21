class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        vector<int>indegree(numCourses);
        queue<int>q;
        
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        
        for(int i=0;i<numCourses;i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)
                q.push(i);
        }
        
        vector<int>topologicalSort;
        
        while(!q.empty()){
            int course = q.front();
            q.pop();
            topologicalSort.push_back(course);
            
            for(auto req : adj[course]){
                if(--indegree[req] == 0)
                    q.push(req);
            }
        }
        
        if(topologicalSort.size()==numCourses)
            return true;
        else
            return false;
    }
};