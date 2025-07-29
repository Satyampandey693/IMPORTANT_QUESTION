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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL) return {};
        vector<TreeNode*> node;
        node.push_back(root);
        vector<vector<int>> ans;
        while(node.size()>0){
           vector<TreeNode*> p;
           vector<int> arr;
           for(int i=0;i<node.size();i++){
            
                TreeNode* t=node[i];
                // cout<<t->val;
                arr.push_back(t->val);
                if(t->left){
                    p.push_back(t->left);

                }
                if(t->right) {
                     p.push_back(t->right);
                }
           }  
           node=p;
           ans.push_back(arr);
        }
        return ans;

    }
};