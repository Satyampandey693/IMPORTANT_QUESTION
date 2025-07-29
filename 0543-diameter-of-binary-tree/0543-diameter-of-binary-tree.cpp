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
int ans;
int mx(TreeNode* root){
    if(root==NULL) return 0;
    int lft=mx(root->left);
    int rt=mx(root->right);
    ans=max(ans,lft+rt);
    return 1+max(lft,rt);
}
    int diameterOfBinaryTree(TreeNode* root) {
        mx(root);
        return ans; 
           }
};