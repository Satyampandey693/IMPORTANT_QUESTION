/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
 TreeNode*  find(TreeNode* root, TreeNode* p, TreeNode* q){
    if(root==NULL||root==p||root==q){
        return root;
    }
     TreeNode* lf=find(root->left,p,q);
     TreeNode* rt=find(root->right,p,q);
     if(lf==NULL) return rt;
     else if(rt==NULL) return lf;
     return root;
 }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return find(root,p,q);
    }
};