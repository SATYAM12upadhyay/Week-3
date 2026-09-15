#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char ch)
{
    top++;
    stack[top] = ch;
}

char pop()
{
    char ch = stack[top];
    top--;
    return ch;
}

int priority(char ch)
{
    if(ch == '+' || ch == '-')
        return 1;

    if(ch == '*' || ch == '/')
        return 2;

    if(ch == '^')
        return 3;

    return 0;
}

int main()
{
    char infix[100], postfix[100];
    int i = 0, j = 0;
    char ch;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    while(infix[i] != '\0')
    {
        ch = infix[i];

        if(isalnum(ch))
        {
            postfix[j] = ch;
            j++;
        }
        else if(ch == '(')
        {
            push(ch);
        }
        else if(ch == ')')
        {
            while(top != -1 && stack[top] != '(')
            {
                postfix[j] = pop();
                j++;
            }

            pop();
        }
        else
        {
            while(top != -1 && priority(stack[top]) >= priority(ch))
            {
                postfix[j] = pop();
                j++;
            }

            push(ch);
        }

        i++;
    }

    while(top != -1)
    {
        postfix[j] = pop();
        j++;
    }

    postfix[j] = '\0';

    printf("Postfix expression: %s", postfix);

    return 0;
}