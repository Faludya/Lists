#ifndef CODE_SKELETON_TREES_TREE_H
#define CODE_SKELETON_TREES_TREE_H

struct bst_node {
    struct bst_node* left;
    struct bst_node* right;
    int data;
};

void insert_node(struct bst_node** root, int new_element_value);
void preorder(struct bst_node* root);
void postorder(struct bst_node* root);
void inorder(struct bst_node* root);
int search_node(struct bst_node* root, int searched_value);
int FindMin(struct bst_node* root);
int pop_node(struct bst_node* root, int searched_value);


#endif
