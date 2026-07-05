/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// helper function
void inorder(struct TreeNode* root, int *result , int *index) {

    if(root == NULL){
        return ;
    }

    inorder(root->left,result,index);

    result[*index] = root->val;
    (*index)++;

    inorder(root->right,result,index);
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* inorderTraversal(struct TreeNode* root, int* returnSize){

    int *result = (int *)malloc(100 * sizeof(int));
    int index = 0;

    inorder(root,result,&index);
    
    *returnSize = index;
    
    return result;
}