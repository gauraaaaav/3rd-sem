#include<iostream>
#include<string.h>
#define max 100
using namespace std;

char a[max],result[100];
int top=-1;

void push(char n)
{

	a[++top]=n;
}

char pop()
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

void reverse(char infic[])
{
	int len=strlen(infic);
	for(int i=0;i<len/2;i++)
	{
		swap(infic[i],infic[len-i-1]);
	}
	
	for(int i=0;i<len;i++)
	{
		if(infic[i]=='(')
		infic[i]=')';
		else if(infic[i]==')')
		infic[i]='(';
	}
}

void convert(char infic[],char result[])
{
	int i,j=0,len=strlen(infic);
	reverse(infic);
	char ch;
	
	for(i=0;i<len;i++)
	{
		ch=infic[i];
		
		if(isalnum(ch))
		{
			result[j++]=ch;
		}
		else if (ch == '(') {
            push(ch);
        } 
		else if (ch == ')') {
            while (top >= 0 && a[top]!= '(') {
                result[j++] = pop();
            }
            pop();
        }
		else 
		{
			while(top>=0&&assoc(a[top])>=assoc(ch))
			{
				result[j++]=pop();
			}
			push(ch);
		}
	}

	
	while (top >= 0) 
	{
        result[j++] = pop();
    }
	int leng=strlen(result);
	for(int i=0;i<leng/2;i++)
	{
		swap(result[i],result[len-i-1]);
	}
		result[j]='\0';
}

int main()
{
	char infic[100];
	
	cout<<"Enter infix expression:";
	cin>>infic;
	
	convert(infic,result);
	cout<<"Prefix:"<<result;
	
	
}
