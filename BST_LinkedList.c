#include <stdio.h>
#include <stdlib.h>

// Define a structure for nodes in the Binary Search Tree
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the Binary Search Tree
Node* insert(Node *root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    
    return root;
}

// Function to search for a node in the Binary Search Tree
Node* search(Node *root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    
    if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// Function to find the minimum value node in a tree (used in deletion)
Node* findMin(Node *root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a node from the Binary Search Tree
Node* deleteNode(Node *root, int data) {
    if (root == NULL) {
        return root;
    }
    
    // Traverse to the node to be deleted
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        // Node to be deleted found
        if (root->left == NULL) {
            Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        
        // Node with two children
        Node *temp = findMin(root->right);  // Find the inorder successor
        root->data = temp->data;            // Replace data with successor's data
        root->right = deleteNode(root->right, temp->data);  // Delete the inorder successor
    }
    return root;
}

// Function for inorder traversal of the Binary Search Tree
void inorderTraversal(Node *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    Node *root = NULL;
    int choice, data;
    Node *result;
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Inorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("Enter data to search: ");
                scanf("%d", &data);
                result = search(root, data);
                if (result != NULL) {
                    printf("Data %d found in the tree.\n", data);
                } else {
                    printf("Data %d not found in the tree.\n", data);
                }
                break;
            case 3:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                printf("Data %d deleted from the tree (if it was present).\n", data);
                break;
            case 4:
                printf("Inorder Traversal of the tree: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
