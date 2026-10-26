#include <stdio.h> 
#define MAX 20 
int adj[MAX][MAX]; 
int visited[MAX]; 
int n; 
  
void resetVisited() 
{ 
    int i; 
    for (i = 0; i < n; i++) 
        visited[i] = 0; 
} 
  
void dfs(int v) 
{ 
    int i; 
    visited[v] = 1; 
    printf("%d ", v); 
    for (i = 0; i < n; i++) 
    { 
        if (adj[v][i] == 1 && visited[i] == 0) 
            dfs(i); 
    } 
} 
  
void bfs(int start) 
{ 
    int queue[MAX]; 
    int front = 0, rear = 0; 
    int v, i; 
    visited[start] = 1; 
    queue[rear++] = start; 
    while (front < rear) 
    { 
        v = queue[front++]; 
        printf("%d ", v); 
        for (i = 0; i < n; i++) 
        { 
            if (adj[v][i] == 1 && visited[i] == 0) 
            { 
                visited[i] = 1; 
                queue[rear++] = i; 
            } 
        } 
    } 
} 
  
int main() 
{ 
    int i, j, choice, start; 
    printf("Enter number of vertices: "); 
    scanf("%d", &n); 
    printf("Enter adjacency matrix:\n"); 
    for (i = 0; i < n; i++) 
        for (j = 0; j < n; j++) 
            scanf("%d", &adj[i][j]); 
    while (1) 
    { 
        printf("\n1. Depth First Search\n2. Breadth First Search\n3. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
        switch (choice) 
        { 
            case 1: 
                printf("Enter starting vertex: "); 
                scanf("%d", &start); 
                resetVisited(); 
                printf("DFS traversal: "); 
                dfs(start); 
                printf("\n"); 
                break; 
            case 2: 
                printf("Enter starting vertex: "); 
                scanf("%d", &start); 
                resetVisited(); 
                printf("BFS traversal: "); 
                bfs(start); 
                printf("\n"); 
                break; 
            case 3: 
                return 0; 
            default: 
                printf("Invalid choice\n"); 
        } 
    } 
}
