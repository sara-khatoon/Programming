#include <stdio.h>
#include <stdlib.h>

//Structure of a node in the binary tree
struct node {
    char data;
    struct node *left, *right;
};

struct node *root = NULL;//Pointer to the root node of the tree

//Function to create new node
struct node* createNode(char data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

//inserts a new node with the given data into the tree 
void insert(char data) {
    struct node **current = &root; //Pointer to pointer to the root node
    while (*current) {
        if (data < (*current)->data)
            current = &(*current)->left;
        else
            current = &(*current)->right;
    }
    *current = createNode(data);
}
//Performs preorder traversal of a tree
void preOrder(struct node *root) {
    if (root) {
        printf("%c ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
//Performs inorder traversal of a tree
void inOrder(struct node *root) {
    if (root) {
        inOrder(root->left);
        printf("%c ", root->data);
        inOrder(root->right);
    }
}
//Performs postorder traversal of a tree
void postOrder(struct node *root) {
    if (root) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%c ", root->data);
    }
}
//Calls the respective traversal function based on the type
void traverse(int type) {
    switch (type) {
        case 1: printf("Preorder: "); preOrder(root); break;
        case 2: printf("Inorder: "); inOrder(root); break;
        case 3: printf("Postorder: "); postOrder(root); break;
    }
    printf("\n");
}
//Function to find the maximum level of the binary tree
int maxDepth(struct node* node) {
    if (node == NULL)
        return 0;
    else {
        int leftDepth = maxDepth(node->left);
        int rightDepth = maxDepth(node->right);

        if (leftDepth > rightDepth)
            return(leftDepth + 1);
        else return(rightDepth + 1);
    }
}

int main() {
    char values[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'K'};
    for (int i = 0; i < 10; i++)
        insert(values[i]);

    traverse(1);
    traverse(2);
    traverse(3);

    int height = maxDepth(root);
    printf("The maximum level (height) of the tree is: %d\n", height);

    return 0;
}