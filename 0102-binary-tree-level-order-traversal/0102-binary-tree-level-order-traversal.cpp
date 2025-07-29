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
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        while(!q.empty()){
        //    vector<TreeNode*> p;
           vector<int> arr;
           int sz=q.size();
           for(int i=0;i<sz;i++){
            
                TreeNode* t=q.front();
                q.pop();
                // cout<<t->val;
                arr.push_back(t->val);
                if(t->left){
                    q.push(t->left);

                }
                if(t->right) {
                     q.push(t->right);
                }
           }  
        //    node=p;
           ans.push_back(arr);
        }
        return ans;

    }
};