//
// Created by Eric Li on 2021/9/9.
//



#include <stdlib.h>
#include <stdio.h>

//  Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void inorder(struct TreeNode *root, int *res, int *i) {
    if (!root) {
        return;
    }
    inorder(root->left, res, i);
    res[(*i)++] = root->val;
    inorder(root->right, res, i);
}

int *inorderTraversal(struct TreeNode *root, int *returnSize) {
//    TODO why 101 ?
    int *res = malloc(sizeof(int) * 101);
    *returnSize = 0;
    inorder(root, res, returnSize);
    return res;
}

int main() {
//    TODO 
    printf("Hello World!\n");
    return 0;
}
