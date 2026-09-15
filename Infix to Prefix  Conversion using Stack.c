#include <stdio.h>
#include <string.h>
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
    char infix[100], prefix[100];
    char temp[100];
    int i, j = 0, n;
    char ch;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    n = strlen(infix);

    for(i = n - 1; i >= 0; i--)
    {
        if(isalnum(infix[i]))
        {
            prefix[j] = infix[i];
            j++;
        }
        else if(infix[i] == ')')
        {
            push(infix[i]);
        }
        else if(infix[i] == '(')
        {
            while(top != -1 && stack[top] != ')')
            {
                prefix[j] = pop();
                j++;
            }

            pop();
        }
        else
        {
            while(top != -1 && stack[top] != ')' &&
                  priority(stack[top]) > priority(infix[i]))
            {
                prefix[j] = pop();
                j++;
            }

            push(infix[i]);
        }
    }

    while(top != -1)
    {
        prefix[j] = pop();
        j++;
    }

    prefix[j] = '\0';

    n = strlen(prefix);

    for(i = 0; i < n / 2; i++)
    {
        ch = prefix[i];
        prefix[i] = prefix[n - 1 - i];
        prefix[n - 1 - i] = ch;
    }

    printf("Prefix expression: %s", prefix);

    return 0;
}