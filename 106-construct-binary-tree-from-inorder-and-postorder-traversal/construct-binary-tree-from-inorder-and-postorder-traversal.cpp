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

    TreeNode* build(vector<int>& inorder,
                    vector<int>& postorder,
                    int &idx,
                    int l,
                    int r) {

        if(l > r)
            return NULL;

        int rootVal = postorder[idx--];

        TreeNode* root = new TreeNode(rootVal);

        int pos = l;

        while(inorder[pos] != rootVal)
            pos++;

        root->right = build(inorder,postorder,idx,pos+1,r);
        root->left = build(inorder,postorder,idx,l,pos-1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder,
                        vector<int>& postorder) {

        int idx = postorder.size()-1;

        return build(inorder,postorder,
                     idx,0,inorder.size()-1);
    }
};