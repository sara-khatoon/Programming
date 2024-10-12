//program to  illustrate pass by pointer method.
#include<iostream.h>
#include<conio.h>
   void swap(int *a,int *b)
{  int temp =*a;
   *a=*b;
   *b=temp;
}
   int main()
{  clrscr();
   int x=5,y=10;
   cout<<"Before swapping:";
   cout<<x<<y;
   swap(&x,&y);
   cout<<"After swapping:";
   cout<<x<<y;
   getch();
   return 0;
}