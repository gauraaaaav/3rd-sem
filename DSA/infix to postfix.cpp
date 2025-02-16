#include<iostream>
#include<string.h>
#define max 100
using namespace std;
char a[max],result[max];
int top=-1;

void push(char n)
{
	a[++top]=n;
}

int pop()
{
	return a[top--];
}


int assoc(char op)
{
	if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
   
}


int convert(char infic[]) {
    int i, j = 0, len = strlen(infic);
  
    char ch;

    for (i = 0; i < len; i++) {
        ch = infic[i];
        if(isspace(ch))
			continue;

        if (isalnum(ch)) {
            result[j++] = ch; 
        } else if (ch == '(') {
            push(ch); 
        } else if (ch == ')') {
           
            while (top >= 0 && a[top]!='(') {
                result[j++] = pop();
            }
            pop();
        } else
        {
            while (top >= 0 && assoc(a[top]) > assoc(ch) ){
                result[j++] = pop();
            }
            push(ch);
        }
    
    
    }

    while (top >= 0) {
        result[j++] = pop();
    }
    result[j] = '\0'; 
}


int main()
{
	char infic[100];
	
	cout<<"Enter infix expression:";
	cin>>infic;
	
	convert(infic);
	cout<<"Postfix:"<<result;
	
	
}
