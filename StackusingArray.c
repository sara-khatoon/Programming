//program to implement stack using array
#include<stdio.h>
#include<conio.h>
int main()
{ int stack[10];
  int popstack[10];
  int top=-1;
  int pop=-1;
  int i,a,popvalue;
  int item;
  float free;
  clrscr();
  do{
  printf("Enter your choice:\n");
  scanf("%d",&a);
  switch(a){
  case 1:
  if(top>=10)
  printf("Stack is full\n");
  else{
  top=top+1;
  printf("Item to be pushed in the stack:\n");
  scanf("%d",&item);
  stack[top]=item;
  }
  break;
  case 2:
  if(top<1)
  printf("Stack is empty\n");
  else{
  popvalue=stack[top];
  top--;
  pop++;
  popstack[pop]=popvalue;
  }
  break;
  case 3:
  if(top<0)
  printf("Stack is empty\n");
  else
  if(top>=10)
  printf("Stack is full\n");
  else{
  for(i=pop;i>0;i--)
  {printf("popped values are %d\n",popstack[i]);
  }
  printf("The element at top is %d\n",stack[top]);
  free=((10-top)/10 )* 100;
  printf("percentage of free stack is %d\n",free);
  }
  break;
  case 4:
  printf("Exit\n");
  return 0;
  default:printf("invalid\n");
}  }while(1);
  getch();
  return 0;
}
