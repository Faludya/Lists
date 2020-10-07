#include <stdio.h>
#include <stdlib.h>
#include "tree.h"


int main()
{
    struct bst_node* root;
    root = NULL;
    insert_node(&root, 12);
    insert_node(&root, 5);
    insert_node(&root, 18);
    printf("Preorder: ");  preorder(root); printf("\n");
    printf("Postorder: ");  postorder(root); printf("\n");
    printf("Inorder: ");  inorder(root); printf("\n");

    if (search_node(root, 5) == 1)
        printf("The value was found \n");
    else
        printf("The value was not found\n");

    return 0;
}
