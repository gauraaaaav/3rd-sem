#include<iostream>
#include<string.h>
#include<cctype>
#define MAX 100

using namespace std;

string stack[MAX];
int top = -1;


void push(string item)
{
        stack[++top] = item;
}

string pop()
{
        return stack[top--];
}

bool isOperator(char c)
{
    return (c == '^' || c == '/' || c == '*' || c == '+' || c == '-');
}

string newString(char op)
{
    string op1 = pop();
    string op2 = pop();
    return '(' + op2 + op + op1 + ')';
}

string convert(string exp)
{
    for (int i = 0; i < exp.length(); i++)
    {
        if (isspace(exp[i]))
            continue;
        if (isalnum(exp[i]))
            push(string(1, exp[i]));
        else if (isOperator(exp[i]))
            push(newString(exp[i]));
        else
        {
            cout << "Invalid input" << endl;
            return "";
        }
    }
    return pop();
}

int main()
{
    string postfix;
    cout << "Enter postfix expression : ";
    getline(cin, postfix);
    cout << "Infix : " << convert(postfix);
    return 0;
}
