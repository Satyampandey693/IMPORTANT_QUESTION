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
int ans=INT_MIN;
int mx(TreeNode* root){
    if(root==NULL) return 0;
    int lft=max(0,mx(root->left));
    int rt=max(0,mx(root->right));
    ans=max(ans,root->val+lft+rt);
    return root->val+max(lft,rt);
}
    int maxPathSum(TreeNode* root) {
        mx(root);
        return ans;
    }
};