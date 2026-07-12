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

    unordered_map<int,int> mp;


    TreeNode* build(vector<int>& preorder,
                    int &index,
                    int left,
                    int right)
    {

        if(left > right)
            return NULL;


        int rootVal = preorder[index++];

        TreeNode* root = new TreeNode(rootVal);


        int mid = mp[rootVal];


        root->left =
            build(preorder,
                  index,
                  left,
                  mid-1);


        root->right =
            build(preorder,
                  index,
                  mid+1,
                  right);


        return root;
    }


    TreeNode* buildTree(vector<int>& preorder,
                        vector<int>& inorder)
    {

        for(int i=0;i<inorder.size();i++)
            mp[inorder[i]]=i;

        int index=0;

        return build(preorder,
                     index,
                     0,
                     inorder.size()-1);
    }
};