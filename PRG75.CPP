#include<iostream.h>
#include<conio.h>
class A
{public:
int x;
A()
{x=10;
}};
class B
{public:
int y;
B()
{y=15;
}};
class C:public A,public B
{public:
void sum()
{cout<<"sum="<<x+y;
}};
class D:public C
{public:
D()
{cout<<"square="<<x*x;
}};
class E:public C
{public:
E()
{cout<<"cube="<<y*y*y;
}};
int main()
{ clrscr();
C ob;
ob.sum();
getch();
return 0;
}