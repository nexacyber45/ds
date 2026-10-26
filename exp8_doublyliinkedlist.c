#include <stdio.h> 
#include <stdlib.h> 
struct Node 
{ 
    int data; 
    struct Node *prev; 
    struct Node *next; 
}; 
struct Node *head = NULL; 
struct Node *createNode(int value) 
{ 
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); 
    newNode->data = value; 
    newNode->prev = NULL; 
    newNode->next = NULL; 
    return newNode; 
} 
  
void insertBegin(int value) 
{ 
    struct Node *newNode = createNode(value); 
    newNode->next = head; 
    if (head != NULL) 
        head->prev = newNode; 
    head = newNode; 
    printf("%d inserted at beginning\n", value); 
} 
  
void insertEnd(int value) 
{ 
    struct Node *newNode = createNode(value); 
    struct Node *temp; 
    if (head == NULL) 
    { 
        head = newNode; 
    } 
    else 
    { 
        temp = head; 
        while (temp->next != NULL) 
            temp = temp->next; 
        temp->next = newNode; 
        newNode->prev = temp; 
    } 
    printf("%d inserted at end\n", value); 
} 
  
void insertPosition(int value, int pos) 
{ 
    struct Node *newNode, *temp; 
    int i; 
    if (pos < 1) 
    { 
        printf("Invalid position\n"); 
        return; 
    } 
    if (pos == 1) 
    { 
        insertBegin(value); 
        return; 
    } 
    temp = head; 
    for (i = 1; i < pos - 1 && temp != NULL; i++) 
        temp = temp->next; 
    if (temp == NULL) 
    { 
        printf("Invalid position\n"); 
        return; 
    } 
    newNode = createNode(value); 
    newNode->next = temp->next; 
    newNode->prev = temp; 
    if (temp->next != NULL) 
        temp->next->prev = newNode; 
    temp->next = newNode; 
    printf("%d inserted at position %d\n", value, pos); 
} 
  
void deleteBegin() 
{ 
    struct Node *temp; 
    if (head == NULL) 
    { 
        printf("List is empty\n"); 
        return; 
    } 
    temp = head; 
    head = head->next; 
    if (head != NULL) 
        head->prev = NULL; 
    printf("%d deleted from beginning\n", temp->data); 
    free(temp); 
} 
  
void deleteEnd() 
{ 
    struct Node *temp; 
    if (head == NULL) 
    { 
        printf("List is empty\n"); 
        return; 
    } 
    temp = head; 
    while (temp->next != NULL) 
        temp = temp->next; 
    if (temp->prev != NULL) 
        temp->prev->next = NULL; 
    else 
        head = NULL; 
    printf("%d deleted from end\n", temp->data); 
    free(temp); 
} 
  
void deletePosition(int pos) 
{ 
    struct Node *temp = head; 
    int i; 
    if (head == NULL) 
    { 
        printf("List is empty\n"); 
        return; 
    } 
    if (pos < 1) 
    { 
        printf("Invalid position\n"); 
        return; 
    } 
    for (i = 1; i < pos && temp != NULL; i++) 
        temp = temp->next; 
    if (temp == NULL) 
    { 
        printf("Invalid position\n"); 
        return; 
    } 
    if (temp->prev != NULL) 
        temp->prev->next = temp->next; 
    else 
        head = temp->next; 
    if (temp->next != NULL) 
        temp->next->prev = temp->prev; 
    printf("%d deleted from position %d\n", temp->data, pos); 
    free(temp); 
} 
  
void deleteValue(int value) 
{ 
    struct Node *temp = head; 
    while (temp != NULL && temp->data != value) 
        temp = temp->next; 
    if (temp == NULL) 
    { 
        printf("%d not found in list\n", value); 
        return; 
    } 
    if (temp->prev != NULL) 
        temp->prev->next = temp->next; 
    else 
        head = temp->next; 
    if (temp->next != NULL) 
        temp->next->prev = temp->prev; 
    printf("%d deleted from list\n", value); 
    free(temp); 
} 
  
void displayForward() 
{ 
    struct Node *temp = head; 
    if (head == NULL) 
    { 
        printf("List is empty\n"); 
        return; 
    } 
    printf("Forward: "); 
    while (temp != NULL) 
    { 
        printf("%d ", temp->data); 
        temp = temp->next; 
    } 
    printf("\n"); 
} 
  
void displayBackward() 
{ 
    struct Node *temp = head; 
    if (head == NULL) 
    { 
        printf("List is empty\n"); 
        return; 
    } 
    while (temp->next != NULL) 
        temp = temp->next; 
    printf("Backward: "); 
    while (temp != NULL) 
    { 
        printf("%d ", temp->data); 
        temp = temp->prev; 
    } 
    printf("\n"); 
} 
  
int main() 
{ 
    int choice, value, pos; 
    while (1) 
    { 
        printf("\n1. Insert at beginning\n2. Insert at end\n3. Insert at position\n"); 
        printf("4. Delete from beginning\n5. Delete from end\n6. Delete from position\n"); 
        printf("7. Delete a value\n8. Display forward\n9. Display backward\n10. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
        switch (choice) 
        { 
            case 1: 
                printf("Enter value: "); 
                scanf("%d", &value); 
                insertBegin(value); 
                break; 
            case 2: 
                printf("Enter value: "); 
                scanf("%d", &value); 
                insertEnd(value); 
                break; 
            case 3: 
                printf("Enter value and position: "); 
                scanf("%d %d", &value, &pos); 
                insertPosition(value, pos); 
                break; 
            case 4: 
                deleteBegin(); 
                break; 
            case 5: 
                deleteEnd(); 
                break; 
            case 6: 
                printf("Enter position: "); 
                scanf("%d", &pos); 
                deletePosition(pos); 
                break; 
            case 7: 
                printf("Enter value to delete: "); 
                scanf("%d", &value); 
                deleteValue(value); 
                break; 
            case 8: 
                displayForward(); 
                break; 
            case 9: 
                displayBackward(); 
                break; 
            case 10: 
                return 0; 
            default: 
                printf("Invalid choice\n"); 
        } 
    } 
} 