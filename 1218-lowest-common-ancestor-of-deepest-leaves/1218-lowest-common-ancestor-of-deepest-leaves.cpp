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
// map<int,TreeNode*> mp;
TreeNode* ans;
int maxi=INT_MIN;
int dfs(TreeNode* n,int d){
    if(n==NULL){
        return d-1;
    }
    int l=dfs(n->left,d+1);
    int r=dfs(n->right,d+1);
    if(l==r&&l>=maxi) {
        maxi=l;
       ans=n;
    }
    return max(l,r);
}
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        dfs(root,0);
        return ans;
    }
};