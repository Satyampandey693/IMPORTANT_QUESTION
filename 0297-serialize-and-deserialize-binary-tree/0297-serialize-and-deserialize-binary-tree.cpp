/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "";
        string p;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* n=q.front();
            q.pop();

           
            // if(n->left){
            //     q.push(n->left);
            // }
            // else p.append("#,");
            // if(n->right){
            //       q.push(n->right);
            // }
            // else p.append("#,");
            if(n){
                q.push(n->left);
                q.push(n->right);
                 p+=to_string(n->val)+",";
            }
            else p+="#,";
        }
        return p;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* n=q.front();
            q.pop();
             getline(s,str,',');
             if(str!="#"){
                TreeNode* p=new TreeNode(stoi(str));;
                n->left=p;
                q.push(p);
             }
             else n->left=NULL;
               getline(s,str,',');
             if(str!="#"){
                TreeNode* p=new TreeNode(stoi(str));;
                n->right=p;
                q.push(p);
             }
             else n->right=NULL;
        }
        // return NULL;
        return root;

    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));