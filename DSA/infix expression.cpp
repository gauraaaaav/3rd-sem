#include <iostream>
#include <string.h>
#include <math.h>
#define MAX 100
using namespace std;

struct Stack
{
    float arr[MAX];
    int top;
};

void push(Stack &s, float item)
{
        s.arr[++s.top] = item;
}


float pop(Stack &s)
{
        return s.arr[s.top--];
    
}

int precedence(char c)
{
    switch (c)
    {
    case '^':
        return 3;
    case '/':
    case '*':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}

float process(float op1, float op2, char op)
{
    switch (op)
    {
    case '^':
        return pow(op1, op2);
    case '/':
        return op1 / op2;
    case '*':
        return op1 * op2;
    case '+':
        return op1 + op2;
    case '-':
        return op1 - op2;
    default:
        return 0;
    }
}

float operate(Stack &operand, Stack &sign)
{
    char op = pop(sign);
    float op1 = pop(operand);
    float op2 = pop(operand);
    return process(op2, op1, op);
}

float evaluate(string exp)
{
    Stack sign, operand;
    sign.top = -1;
    operand.top = -1;

    for (int i = 0; i < exp.length(); i++)
    {
        if (isspace(exp[i]))
            continue;

        if (isdigit(exp[i]))
        {
            float num = 0;
            while (isdigit(exp[i]))
            {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            i--;
            push(operand, num);
        }
        else if (exp[i] == '(')
        {
            push(sign, exp[i]);
        }
        else if (exp[i] == ')')
        {
            while (sign.top != -1 && sign.arr[sign.top] != '(')
            {
                push(operand, operate(operand, sign));
            }
            pop(sign);
        }
        else
        {
            while (sign.top != -1 && precedence(exp[i]) <= precedence(sign.arr[sign.top]))
            {
                push(operand, operate(operand, sign));
            }
            push(sign, exp[i]);
        }
    }

    while (sign.top != -1)
    {
        push(operand, operate(operand, sign));
    }

    return pop(operand);
}

int main()
{
    string infix;
    cout << "Enter infix expression : ";
    getline(cin, infix);
    cout << "Answer : " << evaluate(infix);
    return 0;
}

