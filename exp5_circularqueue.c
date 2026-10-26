#include <stdio.h> 
#define MAX 5 
int dq[MAX]; 
int front = -1, rear = -1; 
void insertFront(int item) 
{ 
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) 
    { 
        printf("Deque Overflow\n"); 
        return; 
    } 
    if (front == -1) 
    { 
        front = rear = 0; 
    } 
    else if (front == 0) 
    { 
        front = MAX - 1; 
    } 
    else 
    { 
        front--; 
    } 
    dq[front] = item; 
} 
  
void insertRear(int item) 
{ 
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) 
    { 
        printf("Deque Overflow\n"); 
        return; 
    } 
    if (front == -1) 
    { 
        front = rear = 0; 
    } 
    else if (rear == MAX - 1) 
    { 
        rear = 0; 
    } 
    else 
    { 
        rear++; 
    } 
    dq[rear] = item; 
} 
  
void deleteFront() 
{ 
    if (front == -1) 
    { 
        printf("Deque Underflow\n"); 
        return; 
    } 
    printf("Deleted Element %d\n", dq[front]); 
    if (front == rear) 
    { 
        front = rear = -1; 
    } 
    else if (front == MAX - 1) 
    { 
        front = 0; 
    } 
    else 
    { 
        front++; 
    } 
} 
  
void deleteRear() 
{ 
    if (front == -1) 
    { 
        printf("Deque Underflow\n"); 
        return; 
    } 
    printf("Deleted Element %d\n", dq[rear]); 
    if (front == rear) 
    { 
        front = rear = -1; 
    } 
    else if (rear == 0) 
    { 
        rear = MAX - 1; 
    } 
    else 
    { 
        rear--; 
    } 
} 
  
void display() 
{ 
    int i; 
    if (front == -1) 
    { 
        printf("Deque is Empty\n"); 
        return; 
    } 
    i = front; 
    printf("Deque Elements: "); 
    while (1) 
    { 
        printf("%d ", dq[i]); 
        if (i == rear) 
            break; 
        i = (i + 1) % MAX; 
    } 
    printf("\n"); 
} 
  
int main() 
{ 
    int choice, item; 
    while (1) 
    { 
        printf("\nCIRCULAR DEQUE\n"); 
        printf("1. Insert Front\n"); 
        printf("2. Insert Rear\n"); 
        printf("3. Delete Front\n"); 
        printf("4. Delete Rear\n"); 
        printf("5. Display\n"); 
        printf("6. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
        switch (choice) 
        { 
            case 1: 
                printf("Enter element: "); 
                scanf("%d", &item); 
                insertFront(item); 
                break; 
            case 2: 
                printf("Enter element: "); 
                scanf("%d", &item); 
                insertRear(item); 
                break; 
            case 3: 
                deleteFront(); 
                break; 
            case 4: 
                deleteRear(); 
                break; 
            case 5: 
                display(); 
                break; 
            case 6: 
                return 0; 
            default: 
                printf("Invalid choice\n"); 
        } 
    } 
} 