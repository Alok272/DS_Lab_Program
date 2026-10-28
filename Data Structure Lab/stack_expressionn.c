
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

int priority(char x) {
    if (x == '^') return 3;
    if (x == '*' || x == '/') return 2;
    if (x == '+' || x == '-') return 1;
    return 0;
}

int main() {
    char infix[100], x;
    int i;

    printf("Enter infix expression: ");
    scanf("%99s", infix);

    printf("Postfix expression: ");

    for (i = 0; infix[i] != '\0'; i++) {
        if (isalnum(infix[i]))
            printf("%c", infix[i]);

        else if (infix[i] == '(')
            push(infix[i]);

        else if (infix[i] == ')') {
            while (top != -1 && stack[top] != '(')
                printf("%c", pop());
            if (top != -1) pop();
        }

        else {
            while (top != -1 && stack[top] != '(' &&
                   priority(stack[top]) >= priority(infix[i]))
                printf("%c", pop());
            push(infix[i]);
        }
    }

    while (top != -1)
        printf("%c", pop());

    printf("\nAlok Pandey 2501920100076\n");

    return 0;
}
