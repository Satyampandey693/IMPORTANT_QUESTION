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
class FindElements {
public:
TreeNode* root;
// vector<int> elem;
// map<int,int> mp;
// vector<bool> v;
// unordered_set<int> v;
bitset<1048576> b1; 
void traverse(TreeNode* root,int val){
    if(root==NULL) return ;
   
        traverse(root->left,val*2+1);
        traverse(root->right,val*2+2);
        // if(val<=1e6)
        // v.insert(val);
        b1.set(val);

   
}
    FindElements(TreeNode* root) {
        // v.resize(1e6+1,false);
        root=root;
        traverse(root,0);

    }
    
    bool find(int target) {
        return b1[target];
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */