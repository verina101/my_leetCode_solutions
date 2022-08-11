/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return is_BST(root,LLONG_MAX,LLONG_MIN);
        
    }
    bool is_BST(TreeNode* root, long long max_parent,long long min_parent){
        if(root == NULL)return true;
        if(!is_BST(root->left,root->val,min_parent))return false;;
        if(!is_BST(root->right,max_parent,root->val))return false;
        
        if(root->val <= min_parent || root->val >= max_parent)return false;
        return true;
    }
};