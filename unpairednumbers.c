#include<stdio.h>
int main(){

    int arr[10]={1,2,3,4,2,6,4,8,3,10};
    int brr[10];
    int i,j,paired;
    for(i=0;i<10;i++){
        
        for(j=0;j<10;j++){
            brr[i]=arr[i];
            if(arr[i]==brr[j]){
                paired=brr[j];
            }
            else{
                brr[j]=arr[i];
                    }        }
        //printf("%d   ",brr[j]);
    
    //printf("\n");
    }
    for(int i=0;i<10;i++){
        printf("%d ",brr[i]);
        }
    
    return 0;

    }