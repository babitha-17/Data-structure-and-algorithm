#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
void append(int data)
{
    struct node *newNode=malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=head;
        head=newNode;
    }
    
void display()
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
int main()
{
    int n,data;
    printf("Enter number of node:");
    scanf("%d",&n);//5
    for(int i=0;i<n;i++)
    {
        scanf("%d",&data);
        if(data>0)
        {
            append(data);
        }
    }
    printf("The data in the nodes are:");
    display();
}
