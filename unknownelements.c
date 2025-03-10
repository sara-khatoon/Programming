//to find the unknown elements
#include<stdio.h>
//#include<conio.h>
//# define ROWS 3
//# define COLS 3
//# define UE -1
int main()
{ int arr[3][3];
int UE=0;
  int i,j,k=0;
  //clrscr();
  printf("Enter elements for a 2D Array\n");
  for(i=0;i<3;i++)
{ for(j=0;j<3;j++)
  { printf("Element[%d][%d]:",i,j);
    scanf("%d",&arr[i][j]);
  }
}
    printf("\n The 2D array is:\n");
  for(i=0;i<3;i++)
{  for(j=0;j<3;j++)
  { if(arr[i][j]==UE)
    {printf("  ue ");
    }else{
    printf(" %d, ",arr[i][j]);
    }
  }
    printf("\n");
}
// applying the equationp
 for(i=0;i<3;i++)
  { for(j=0;j<3;j++)
{ if(arr[i][j] == UE && arr[j][i] != UE){
  arr[i][j]= -arr[j][i];
} else if(arr[i][j] != UE && arr[j][i] == UE){
  arr[j][i]= -arr[i][j];
}
  if(arr[i][j] == UE){
   for(k=0;k<3;k++){
   if(arr[i][k] != UE && arr[k][j] != UE){
   arr[i][j] = arr[i][k] + arr[k][j];
   break;
}
} }} }
   printf("\nArray after evaluating unknown elements:\n");
   for(i=0;i<3;i++)
   { for(j=0;j<3;j++)
   { printf(" %d, ",arr[i][j]);
   }
   printf(" \n ");
   }
   //getch();
   return 0;
}