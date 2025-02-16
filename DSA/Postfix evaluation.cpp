#include <iostream>
#include <string.h>
#include <cmath>
#define MAX 100

using namespace std;

// Stack implementation without class
float a[MAX];
int top = -1;

void push(float item)
{
   
        a[++top] = item;
}

float pop()
{

        return a[top--];
}

float process(float op1, float op2, char op)
{
    switch (op)
    {
        case '^': return pow(op1, op2);
        case '/': return op1 / op2;
        case '*': return op1 * op2;
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        default: return 0;
    }
}

float operate(char op)
{
    float op1 = pop();
    float op2 = pop();
    return process(op2, op1, op);
}

float evaluate(string exp)
{
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
            push(num);
        }
        else
        {
            push(operate(exp[i]));
        }
    }
    return pop();
}

int main()
{
    string postfix;
    cout << "Enter postfix expression: ";
    getline(cin, postfix);
    cout << "Answer: " << evaluate(postfix);
    return 0;
}

