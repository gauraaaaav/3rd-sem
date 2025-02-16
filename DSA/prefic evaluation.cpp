#include<iostream>
#include<string>
#include<math.h>
#include<cctype>
#define MAX 100

using namespace std;

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
    return process(op1, op2, op);
}

float evaluate(string exp)
{
    for (int i = exp.length() - 1; i >= 0; i--)
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
            push(operate(exp[i]));
    }
    return pop();
}

int main()
{
    string prefix;
    cout << "Enter prefix expression : ";
    getline(cin, prefix);
    cout << "Answer : " << evaluate(prefix);
    return 0;
}

