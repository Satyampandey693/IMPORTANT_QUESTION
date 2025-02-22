class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        int i = 0, n = traversal.size();
        map<int, TreeNode*> mp;  // Stores the latest node at each depth

        while (i < n) {
            int depth = 0;
            while (i < n && traversal[i] == '-') {  // Count dashes (depth)
                depth++;
                i++;
            }

            string valStr;
            while (i < n && isdigit(traversal[i])) {  // Extract number
                valStr.push_back(traversal[i]);
                i++;
            }

            int val = stoi(valStr);  // Convert extracted number
            TreeNode* newNode = new TreeNode(val);

            if (depth == 0) {  // Root node
                mp[0] = newNode;
            } else {
                TreeNode* parent = mp[depth - 1];  // Get parent node
                if (!parent->left) {
                    parent->left = newNode;
                } else {
                    parent->right = newNode;
                }
            }
            mp[depth] = newNode;  // Update latest node at this depth
        }

        return mp[0];  // Return root node
    }
};
