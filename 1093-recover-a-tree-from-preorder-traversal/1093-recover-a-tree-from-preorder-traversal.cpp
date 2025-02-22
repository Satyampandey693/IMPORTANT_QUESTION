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
    TreeNode* recoverFromPreorder(string traversal) {
          int i=0;
           string p;
           int n=traversal.size();
         while(i<n&&traversal[i]!='-'){
                    p.push_back(traversal[i]);
                    i++;
                }
                // cout<<i<<endl;
                 int q;
                if(p!="")
                q=stoi(p);
               
        TreeNode* root=new TreeNode(q);
        map<int,TreeNode*> mp;
        mp[0]=root;
      
        int d=0;
        while(i<n){
            int c=0;
            while(i<n&&traversal[i]=='-'){ c++;i++;}
            // cout<<i<<endl;
            TreeNode* node=mp[c-1];
            TreeNode* nd;
            if(node->left==NULL){
                string p;
                while(i<n&&traversal[i]!='-'){
                    p.push_back(traversal[i]);
                    i++;
                }
                 int q;
                if(p!="")
               q=stoi(p);
                nd=new TreeNode(q);
                node->left=nd;

            }
            else{
                    string p;
                while(i<n&&traversal[i]!='-'){
                    p.push_back(traversal[i]);
                    i++;
                }
                 int q;
                if(p!="")
               q=stoi(p);
                nd=new TreeNode(q);
                node->right=nd;
            }
            mp[c]=nd;
            
        }
        return root;

    }
};