#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100  // Define maximum size for the tree array

int tree[MAX_SIZE];  // Array to hold the binary tree
int size = 0;        // To keep track of the number of elements in the tree

// Function to initialize the tree with -1 to indicate empty slots
void initializeTree() {
    for (int i = 0; i < MAX_SIZE; i++) {
        tree[i] = -1;
    }
}

// Function to insert a node into the tree array
void insert(int data) {
    if (size >= MAX_SIZE) {
        printf("Tree is full. Cannot insert more elements.\n");
        return;
    }
    tree[size] = data;  // Insert at the next available position
    size++;
}

// Function to search for an element in the binary tree array
int search(int data) {
    for (int i = 0; i < size; i++) {
        if (tree[i] == data) {
            return i;  // Return index if data is found
        }
    }
    return -1;  // Return -1 if data is not found
}

// Function to display the binary tree
void displayTree() {
    printf("Binary Tree (Array Representation):\n");
    for (int i = 0; i < size; i++) {
        if (tree[i] != -1)
            printf("%d ", tree[i]);
        else
            printf("- ");
    }
    printf("\n");
}

int main() {
    initializeTree();

    int choice, data, result;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Display\n");
        printf("4. Exit\n");
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
                result = search(data);
                if (result != -1) {
                    printf("Data found at index %d\n", result);
                } else {
                    printf("Data not found in the tree\n");
                }
                break;
            case 3:
                displayTree();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
