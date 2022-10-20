/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*>mp;
    
    Node* cloneGraph(Node* node) {
        if(node == NULL)
            return NULL;
        else if(node->neighbors.empty()){
            Node* clone = new Node(node->val);
            return clone;
        }
        return dfs(node);   
    }
    
    Node* dfs (Node* node){
        Node* clone = new Node(node->val);
        vector<Node*> clone_neighbors;
        mp[node] = clone;
        
        for(auto it : node->neighbors){
            if(mp.find(it)!=mp.end()){
                clone_neighbors.push_back(mp[it]);
            }
            else
                clone_neighbors.push_back(dfs(it));
        }
        clone->neighbors = clone_neighbors;
        return clone;
    }
};