#include <stdio.h>
#include <stdlib.h>

struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

typedef struct TreeNode TreeNode;

int sumGrandChildren(TreeNode* root) {
    int result = 0;

    TreeNode* children[2] = {
        root->left,
        root->right
    };

    if (children[0] != NULL) {
        if (children[0]->left != NULL)  result += children[0]->left->val;
        if (children[0]->right != NULL) result += children[0]->right->val;
    }

    if (children[1] != NULL) {
        if (children[1]->left != NULL)  result += children[1]->left->val;
        if (children[1]->right != NULL) result += children[1]->right->val;
    }


    printf("RoC (%d): %d\n", root->val, result);
    return result;
}

int sumEvenGrandparents(TreeNode* root) {

    int result = 0;

    if(root->val%2 == 0) {
        result += sumGrandChildren(root);
    }

    if (root->left != NULL) result += sumEvenGrandparents(root->left);
    if (root->right != NULL) result += sumEvenGrandparents(root->right);

    printf("current %d -> result: %d\n", root->val, result);
    return result;
}


void createTreeNode(TreeNode** root, int val){
    *root = malloc(sizeof(TreeNode));
    (*root)->left = NULL;
    (*root)->right = NULL;
    (*root)->val = val;
}
int main() {
    //[6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
    TreeNode* root;
    createTreeNode(&root, 6);
    createTreeNode(&(root->left), 7);
    createTreeNode(&(root->right), 8);

    createTreeNode(&(root->left->left), 2);
    createTreeNode(&(root->left->right), 7);

    createTreeNode(&(root->right->left), 1);
    createTreeNode(&(root->right->right), 3);

    createTreeNode(&(root->left->left->left), 9);
    root->left->left->right = NULL;

    createTreeNode(&(root->left->right->left), 1);
    createTreeNode(&(root->left->right->right), 4);

    root->right->left->left = NULL;
    root->right->left->right = NULL;

    root->right->right->left = NULL;
    createTreeNode(&(root->right->right->right), 5);
    printf("%d\n", sumEvenGrandparents(root));
    return 0;
}
