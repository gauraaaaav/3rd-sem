//24:gauss integration
#include<stdio.h>
#include<math.h>
#define F(x) (exp(x))
int main(){
float w1,w2,x1,x2,integration;
w1=1;
w2=1;
x1=-1/(sqrt(3));
x2=1/(sqrt(3));
integration=w1F(x1)+w2F(x2);
printf("Integration using gauss two point formula:%f",integration);
return 0;
}
