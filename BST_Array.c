#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100  // Maximum size of the BST array

int bst[MAX_SIZE];  // Array to hold the BST
int size = 0;       // Number of elements in the BST

// Function to initialize the BST array
void initializeBST() {
    for (int i = 0; i < MAX_SIZE; i++) {
        bst[i] = -1;  // Initialize all elements to -1 (indicating empty)
    }
}

// Function to insert a node in the BST
void insert(int data) {
    if (size >= MAX_SIZE) {
        printf("Tree is full. Cannot insert more elements.\n");
        return;
    }
    
    int index = 0;  // Start at the root
    while (index < MAX_SIZE) {
        if (bst[index] == -1) {
            bst[index] = data;  // Found an empty spot
            size++;
            return;
        }
        
        if (data < bst[index]) {
            index = 2 * index + 1;  // Move to left child
        } else {
            index = 2 * index + 2;  // Move to right child
        }
    }
    
    printf("Failed to insert %d. The tree is full.\n", data);
}

// Function to search for a node in the BST
int search(int data) {
    int index = 0;
    
    while (index < MAX_SIZE && bst[index] != -1) {
        if (bst[index] == data) {
            return index;  // Data found
        }
        
        if (data < bst[index]) {
            index = 2 * index + 1;  // Move to left child
        } else {
            index = 2 * index + 2;  // Move to right child
        }
    }
    
    return -1;  // Data not found
}

// Function to find the minimum value node (for deletion)
int findMinIndex(int index) {
    while (2 * index + 1 < MAX_SIZE && bst[2 * index + 1] != -1) {
        index = 2 * index + 1;
    }
    return index;  // Return index of the minimum value
}

// Function to delete a node from the BST
void deleteNode(int data) {
    int index = search(data);
    
    if (index == -1) {
        printf("Data %d not found in the tree.\n", data);
        return;
    }
    
    // Case 1: Node to be deleted is a leaf node
    if (2 * index + 1 >= MAX_SIZE || bst[2 * index + 1] == -1) {
        bst[index] = -1;  // Simply remove the node
    }
    // Case 2: Node to be deleted has one child
    else if (2 * index + 1 < MAX_SIZE && bst[2 * index + 1] != -1 && 
             (2 * index + 2 >= MAX_SIZE || bst[2 * index + 2] == -1)) {
        bst[index] = bst[2 * index + 1];  // Replace with left child
    }
    else if (2 * index + 2 < MAX_SIZE && bst[2 * index + 2] != -1 &&
             (2 * index + 1 >= MAX_SIZE || bst[2 * index + 1] == -1)) {
        bst[index] = bst[2 * index + 2];  // Replace with right child
    }
    // Case 3: Node to be deleted has two children
    else {
        int minIndex = findMinIndex(2 * index + 2);  // Get the minimum value from right subtree
        bst[index] = bst[minIndex];  // Replace with the minimum value
        bst[minIndex] = -1;  // Remove the minimum node
    }
    
    printf("Data %d deleted from the tree (if it was present).\n", data);
}

// Function for inorder traversal of the BST
void inorderTraversal(int index) {
    if (index >= MAX_SIZE || bst[index] == -1) {
        return;
    }
    inorderTraversal(2 * index + 1);  // Left subtree
    printf("%d ", bst[index]);        // Visit the root
    inorderTraversal(2 * index + 2);  // Right subtree
}

int main() {
    initializeBST();

    int choice, data;
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
                insert(data);
                break;
            case 2:
                printf("Enter data to search: ");
                scanf("%d", &data);
                int result = search(data);
                if (result != -1) {
                    printf("Data %d found at index %d\n", data, result);
                } else {
                    printf("Data %d not found in the tree.\n", data);
                }
                break;
            case 3:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                deleteNode(data);
                break;
            case 4:
                printf("Inorder Traversal of the tree: ");
                inorderTraversal(0);  // Start from root
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
