//
// Created by Eric Li on 2021/9/9.
//



#include <stdlib.h>

//  Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *inorderTraversal(struct TreeNode *root, int *returnSize) {
    int* res = malloc(sizeof(int) * 101);
    
}