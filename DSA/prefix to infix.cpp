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
    return '(' + op1 + op + op2 + ')';
}

string convert(string exp)
{
    for (int i = exp.length() - 1; i >= 0; i--)
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
    string prefix;
    cout << "Enter prefix expression : ";
    getline(cin, prefix);
    cout << "Infix : " << convert(prefix);
    return 0;
}

