/*given linked list and k value return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end(list is 1-indexed)

example:
input =5
1 2 3 4 5
2
1 4 3 2 5

explanation:
1->2->3->4->5
k=2 
so from beginning second value is '2' and from ending second value is 4. so swap both elements.


ex:
input =10
10 20 30 40 50 60 70 80 90 100
3
output =
10 20 80 40 50 60 70 30 90 100
k=3
so from beginning third value is '30' and from ending third value is 80. so swap both elements.*/



#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
  int rno;
  struct node *link;
};
struct node* root=NULL;
void append(int);
void display();

void change(int idx)
{
   struct node* slow=root;
    struct node* fast=root;
    while(idx>1)
    {
        fast=fast->link;
        idx--;
    }
    struct node* curr=fast;
    while(fast->link!=NULL)
    {
        slow=slow->link;
        fast=fast->link;
    }
    int temp=curr->rno;
    curr->rno=slow->rno;
    slow->rno=temp;
    
}

void display()
{
    struct node* temp=root;
    while(temp!=NULL)
    {
        printf("%d ",temp->rno);
        temp=temp->link;
    }
}

int main()
{
  int n;
  scanf("%d",&n);
  while(n!=0)
  {
      //int roll,char ch[],int marks
     int roll;
     scanf("%d",&roll);
      append(roll);
      n--;
  }
  int tochange;
  scanf("%d",&tochange);
  change(tochange);
  display();
    return 0;
}
void append(int roll)
{
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    if(root==NULL)
    {
        temp->rno=roll;
        temp->link=NULL;
        root=temp;
    }
    else
    {
        struct node* p=root;
        while(p->link!=NULL)
        {
            p=p->link;
        }
        temp->rno=roll;
        temp->link=NULL;
        p->link=temp;
    }
}
