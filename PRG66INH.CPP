//program to illustrate single inheritence
#include<iostream.h>
#include<conio.h>
class A
{int a,b;
public:
int mul()
{cout<<"Enter the value of a and b:";
cin>>a>>b;
int c=a*b;
return c;
}};
class B:public A
{public:
void display()
{int result = mul();
cout<<"Multiplication of a and b is:"<<result;
}};
int main()
{clrscr();
B b;
b.display();
getch();
return 0;
}
}