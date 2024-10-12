//program to illustrate friend class
#include<iostream.h>
#include<conio.h>
class rectangle;
class square
{ friend class rectengle;
int side;
public:
square(int s)
{side=s;
}};
class rectangle
{ friend class square;
int length;
int breadth;
public:
int getarea()
{return length * breadth;
}
void shape(square a)
{length = a.side;
breadth=a.side;
}};
int main()
{clrscr();
square sq(5);
rectangle rect;
rect.shape(sq);
cout<<rect.getarea();
getch();
return 0;
}