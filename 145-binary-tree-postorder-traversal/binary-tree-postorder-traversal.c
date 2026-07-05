/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//helper function
void postorder(struct TreeNode* root, int* result, int* index){
    if(root == NULL){
        return;
    }

    postorder(root->left,result,index);
    postorder(root->right,result,index);

    result[*index] = root->val;
    (*index)++;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(100*sizeof(int));
    int index = 0;

    postorder(root,result,&index);

    *returnSize = index;
    return result;
}