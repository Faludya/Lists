#include <stdio.h>
#include <malloc.h>
#include "tree.h"

void insert_node(struct bst_node** root, int new_value) //checked
{
    while (*root != NULL) {
        if (new_value > (*root)->data)
            root = &(*root)->right;
        else
            root = &(*root)->left;
    }
    *root = malloc(sizeof * *root);
    (*root)->data = new_value;
    (*root)->left = NULL;
    (*root)->right = NULL;

}

void preorder(struct bst_node* root) // root - left - right
{
    if (root == NULL){
        printf("\nThe BST is empty");
        return;
    }
    printf("%d,", root->data);
    if (root->left) preorder(root->left);
    if (root->right) preorder(root->right);

}

void postorder(struct bst_node* root) // left - root - right
{
    if (root == NULL) {
        printf("\nThe BST is empty");
        return;
    }

    if (root->left)  preorder(root->left);
    printf("%d,", root->data);
    if (root->right) preorder(root->right);
}


void inorder(struct bst_node* root)
{
    if (root == NULL) {
        printf("\nThe BST is empty");
        return;
    }

    if (root->left) preorder(root->left);
    if (root->right) preorder(root->right);
    printf("%d,", root->data);
}

int search_node(struct bst_node* root, int searched_value)
{
    struct bst_node* current = root;

    while (current != NULL) {
        if (searched_value == current->data) {
            return 1;
        }
        else
            if (searched_value > current->data) {
                current = current->right;
            }
            else
                current = current->left;
    }
    return 0;
}

int FindMin(struct bst_node* root)
{
    if (root == NULL) {
        return printf("The tree is empty");
    }

    if (root->left != NULL) {
        return FindMin(root->left); // left tree is smaller
    }
    return root->data;
}

int pop_node(struct bst_node* root, int searched_value)
{

    if (root == NULL) {
        return 0;
    }

    if (searched_value < root->data) { // data is in the left subtree.
        root->left = pop_node(root->left, searched_value);
    }
    else if (searched_value > root->data) { // data is in the right subtree.
        root->right = pop_node(root->right, searched_value);
    }
    else {
        // case 1: no children
        if (root->left == NULL && root->right == NULL) {
            free(root); // wipe out the memory, in C, use free function
            root = NULL;
        }
        // case 2: one child (right)
        else if (root->left == NULL) {
            struct bst_node* aux = root; // save current node as a backup
            root = root->right;
            free(aux);

        }
        // case 3: one child (left)
        else if (root->right == NULL) {
            struct bst_node* aux = root; // save current node as a backup
            root = root->left;
            free(aux);
        }
        // case 4: two children
        else {
            struct bst_node* aux = FindMin(root->right); // find minimum value of right subtree
            root->data = aux->data; // duplicate the node
            root->right = pop_node(root->right, aux->data); // delete the duplicate node
            free(aux);
        }
    }
    return root; // parent node can update reference
}
