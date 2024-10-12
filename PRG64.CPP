//program to illustrate pass by reference method
#include<iostream.h>
#include<conio.h>
  void swap(int &a,int &b)
  {int temp=a;
  a=b;
  b=temp;
  }int main()
  {clrscr();
  int x=5;
  int y=10;
  cout<<"Before Swapping:";
  cout<<x<<y;
  swap(x,y);
  cout<<"After swapping:";
  cout<<x<<y;
  getch();
  return 0;
  }