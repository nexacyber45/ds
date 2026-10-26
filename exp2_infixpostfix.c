#include <stdio.h> 
#include <ctype.h> 
 
char stack[100]; 
int top = -1; 
 
void push(char x) { 
    stack[++top] = x; 
} 
 
char pop() { 
    return stack[top--]; 
} 
 
int precedence(char x) { 
    if (x == '%' || x == '*' || x == '/') 
        return 2; 
    if (x == '+' || x == '-') 
        return 1; 
    return 0; 
} 
 
int main() { 
    char infix[100], postfix[100]; 
    int i, k = 0; 
    char ch; 
 
    scanf("%s", infix); 
 
    for (i = 0; infix[i] != '\0'; i++) { 
        ch = infix[i]; 
 
        if (isalnum(ch)) { 
            postfix[k++] = ch; 
        } 
        else if (ch == '(') { 
            push(ch); 
        } 
        else if (ch == ')') { 
            while (top != -1 && stack[top] != '(') 
                postfix[k++] = pop(); 
 
            if (top != -1) 
                pop();          /* discard '(' */ 
        } 
        else { 
            while (top != -1 && 
                   stack[top] != '(' && 
                   precedence(stack[top]) >= precedence(ch)) 
                postfix[k++] = pop(); 
 
} 
} 
push(ch); 
while (top != -1) 
postfix[k++] = pop(); 
postfix[k] = '\0'; 
printf("Postfix = %s\n", postfix); 
return 0; 
} 
