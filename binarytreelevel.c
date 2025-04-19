#include<stdio.h>
int level =1;
void findlevel(int size){
    int i=1;
    while(i<=size){
        int left = 2*i;
        int right = 2*i+1;
        if(right<=size){
            i=right;
        } else{
            i=left;
        }    
        level++;
    }
}
int main(){
    int size=9;
    char arr[9]={'A','B','C','D','E','F','G','H','I'};
    findlevel(size);
    printf("Level of the binary tree is %d\n",level);
    return 0;

}