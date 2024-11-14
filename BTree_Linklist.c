#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};



struct node* create() {
    int x;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("\nEnter data (-1 for no child): ");
    scanf("%d", &x);


    if (x == -1) {
        return NULL;
    }

    newnode->data = x;
    
    printf("\nEnter left child of %d: ", x);
    newnode->left = create();
    
    printf("\nEnter right child of %d: ", x);
    newnode->right = create();

    return newnode;
}


void PreOrder(struct node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data); 
    PreOrder(root->left);
    PreOrder(root->right);
}


void InOrder(struct node *root) {
    if (root == NULL) {
        return;
    }
    InOrder(root->left);
    printf("%d ", root->data); 
    InOrder(root->right);
}


void PostOrder(struct node *root) {
    if (root == NULL) {
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%d ", root->data); 
}

int main() {
    struct node *root = NULL; 

    root = create(); 

    printf("\nPreOrder Traversal: ");
    PreOrder(root); 

    printf("\nInOrder Traversal: ");
    InOrder(root); 

    printf("\nPostOrder Traversal: ");
    PostOrder(root); 

    return 0;
}
