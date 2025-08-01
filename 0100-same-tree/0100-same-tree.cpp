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
bool mx(TreeNode* p,TreeNode* q){

    if(p==NULL&&q==NULL) return true;
    if(p==NULL&&q!=NULL) return false;
    else if (p!=NULL&&q==NULL) return false;
    if(p->val!=q->val) return false;
    bool lft=mx(p->left,q->left);
   bool rt=mx(p->right,q->right);
    return lft&rt;
}
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return mx(p,q);
    }
};