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
    newNode->next=NULL;
        if(head==NULL)
        {
            head=newNode;
        }
        else
        {
            struct node *temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newNode;
        }
    }
void del()
{
    if(head==NULL)
    {
        printf("List is empty");
        return;
    }
    struct node *temp=head;
    struct node *prev=NULL;
    while(temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    free(temp);
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
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&data);
        if(data>0)
        {
            append(data);
        }
    }
    del();
    printf("The data in the nodes are:");
    display();
}
