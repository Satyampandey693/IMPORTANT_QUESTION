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
#define ll long long
bool valid(TreeNode* root,ll l,ll r){
    if(root==NULL) return true;
    if(root->val<=l||root->val>=r) return false;
   bool lf= valid(root->left,l,root->val);
    bool rf=valid(root->right,root->val,r);
    return lf&&rf;
}
    bool isValidBST(TreeNode* root) {
       ll l=1ll*INT_MIN-1;
       ll r=1ll*INT_MAX+1;
      return  valid(root,l,r); 

    }
};