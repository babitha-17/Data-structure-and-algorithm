#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
void append(int data)
{
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}
void createcycle(int pos){
    struct node *temp=head;
    struct node *cyclenode=NULL;
    int count=1;
    while(temp->next!=NULL){
        if(count==pos){
            cyclenode=temp;
        }
        temp=temp->next;
        count++;
    }
    if(cyclenode!=NULL){
        temp->next=cyclenode;
    }
}
int detectcycle(){
    struct node *slow=head;
    struct node *fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return 1;
        }
    }
    return 0;
}
void display()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
int main()
{
    int n, data,choice,pos;
    printf("enter number of nodes: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        printf("enter data for node %d: ",i);
        scanf("%d", &data);
        append(data);
    }
    printf("do u want to create a cycle? (1=yes, 0=no): ");
    scanf("%d",&choice);
    if(choice==1){
        printf("enter position to connect last node (1 to %d): ",n);
        scanf("%d",&pos);
        createcycle(pos);
    }
    if(detectcycle()){
        printf("cycle detected in the linked list\n");
    }else{
        printf("no cycle detected in the linked list\n");
    }
    return 0;
}
