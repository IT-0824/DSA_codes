#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
};
struct node* head;

void create(int n,struct node *&temp)
{
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=n;
    temp->next=NULL;
    

}

void insertail(int num){
    struct node*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
     newnode->data=num;
     newnode->next=NULL;
    //create(num,newnode);
    struct node*ptr=head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
        }
        ptr->next=newnode;
}

void insertbegin(int num){
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    // create(num,newnode);
   newnode->data=num;
  
    newnode->next=head;
    head=newnode;
}

void insertpos(int num,int key){
    struct node*ptr=head;
    struct node*newnode;
    create(num,newnode);
    while(ptr!=NULL){
        if(key==ptr->data)
        {
         newnode->next=ptr->next;
         ptr->next=newnode;
         break;
        }
        ptr=ptr->next;
    }
}

void delhead()
{
    struct node *ptr=head;
    head=head->next;
    free(ptr);
}

void deltail()
{
    struct node *ptr=head;
    while(ptr->next->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=NULL;
}

void delpos(int key)
{
   struct node*ptr=head;
   while(ptr!=NULL){
       if(ptr->next->data==key)
       {
           struct node*p=ptr->next;
           ptr->next=ptr->next->next;
           free(p);
       }
       ptr=ptr->next;
   }
}

void display()
{
    
    struct node *p=head;
    while(p!=NULL){
        printf("%d -> ",p->data);
        p=p->next;
    }
    printf(" NULL \n");

}
int main()
{
    struct node *N;
   N=(struct node*)malloc(sizeof(struct node));
    
    create(1,N);
    head=N;
  insertail(2);
  insertail(3);
  insertbegin(4);
  insertpos(6,1);
   display();
   delhead();
   display();
   deltail();
   display();
   delpos(2);
   display();
   return 0;
}