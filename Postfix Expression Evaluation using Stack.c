#include <stdio.h>
#include <ctype.h>

int stack[100];
int top = -1;

void push(int value)
{
    top++;
    stack[top] = value;
}

int pop()
{
    int value = stack[top];
    top--;
    return value;
}

int main()
{
    char postfix[100];
    int i, a, b, result;

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    for(i = 0; postfix[i] != '\0'; i++)
    {
        if(isdigit(postfix[i]))
        {
            push(postfix[i] - '0');
        }
        else
        {
            b = pop();
            a = pop();

            if(postfix[i] == '+')
                result = a + b;
            else if(postfix[i] == '-')
                result = a - b;
            else if(postfix[i] == '*')
                result = a * b;
            else if(postfix[i] == '/')
                result = a / b;

            push(result);
        }
    }

    result = pop();

    printf("Result = %d", result);

    return 0;
}