#include <stdio.h> 
#include <stdlib.h> 
struct Node 
{ 
    int data; 
    struct Node *left; 
    struct Node *right; 
}; 
struct Node *createNode(int value) 
{ 
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); 
    newNode->data = value; 
    newNode->left = NULL; 
    newNode->right = NULL; 
    return newNode; 
} 
struct Node *insert(struct Node *root, int value) 
{ 
    if (root == NULL) 
        return createNode(value); 
    if (value < root->data) 
        root->left = insert(root->left, value); 
    else if (value > root->data) 
        root->right = insert(root->right, value); 
    else 
        printf("%d already exists in tree\n", value); 
    return root; 
} 
struct Node *search(struct Node *root, int value) 
{ 
    if (root == NULL || root->data == value) 
        return root; 
    if (value < root->data) 
        return search(root->left, value); 
    return search(root->right, value); 
} 
struct Node *findMin(struct Node *root) 
{ 
    while (root->left != NULL) 
        root = root->left; 
    return root; 
} 
struct Node *deleteNode(struct Node *root, int value) 
{ 
    struct Node *temp; 
    if (root == NULL) 
    { 
        printf("%d not found in tree\n", value); 
        return NULL; 
    } 
    if (value < root->data) 
    { 
        root->left = deleteNode(root->left, value); 
    } 
    else if (value > root->data) 
    { 
        root->right = deleteNode(root->right, value); 
    } 
    else 
    { 
        if (root->left == NULL) 
        { 
            temp = root->right; 
            free(root); 
            return temp; 
        } 
        if (root->right == NULL) 
        { 
            temp = root->left; 
            free(root); 
            return temp; 
        } 
        temp = findMin(root->right); 
        root->data = temp->data; 
        root->right = deleteNode(root->right, temp->data); 
    } 
    return root; 
} 
  
void inorder(struct Node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%d ", root->data); 
        inorder(root->right); 
    } 
} 
  
void preorder(struct Node *root) 
{ 
    if (root != NULL) 
    { 
        printf("%d ", root->data); 
        preorder(root->left); 
        preorder(root->right); 
    } 
} 
  
void postorder(struct Node *root) 
{ 
    if (root != NULL) 
    { 
        postorder(root->left); 
        postorder(root->right); 
        printf("%d ", root->data); 
    } 
} 
  
int main() 
{ 
    struct Node *root = NULL; 
    int choice, value; 
    while (1) 
    { 
        printf("\n1. Insert\n2. Delete\n3. Search\n4. Inorder\n5. Preorder\n"); 
        printf("6. Postorder\n7. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
        switch (choice) 
        { 
            case 1: 
                printf("Enter value: "); 
                scanf("%d", &value); 
                root = insert(root, value); 
                break; 
            case 2: 
                printf("Enter value to delete: "); 
                scanf("%d", &value); 
                root = deleteNode(root, value); 
                break; 
            case 3: 
                printf("Enter value to search: "); 
                scanf("%d", &value); 
                if (search(root, value) != NULL) 
                    printf("%d found in tree\n", value); 
                else 
                    printf("%d not found in tree\n", value); 
                break; 
            case 4: 
                printf("Inorder: "); 
                inorder(root); 
                printf("\n"); 
                break; 
            case 5: 
                printf("Preorder: "); 
                preorder(root); 
                printf("\n"); 
                break; 
            case 6: 
                printf("Postorder: "); 
                postorder(root); 
                printf("\n"); 
                break; 
            case 7: 
                return 0; 
            default: 
                printf("Invalid choice\n"); 
        } 
    } 
} 