#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node* next;
    struct node *ptr;
};

struct node *insertbeg(struct node *head, int info ){
    struct node *new;
    new = (struct node*)malloc(sizeof(struct node));
    new->data = info;
    new->next = head;
    head = new;
    return head;
}
struct node *insertend(struct node *head, int info ){
    struct node *new;
    new = (struct node*)malloc(sizeof(struct node));
    new->data = info;
    new->next = NULL;
    if (head == NULL) {
        head = new;
        return head;
    }
    struct node *ptr = head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = new;
    return head;
}
int main(){
    
    printf("Enter the number of nodes: ");
    int n;  
    scanf("%d", &n);
    struct node *head = NULL;
    for (int i = 0; i < n; i++){
        int info;
        printf("Enter the data for node %d: ", i + 1);
        scanf("%d", &info);
        head = insertbeg(head, info);
    }
    printf("The linked list is: ");
    struct node *ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    // Free the allocated memory
    ptr = head;
    return 0;
}