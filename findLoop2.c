#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node
{
  int ele;
  struct Node *next;
  int flag;
};

struct Node *hptr=NULL,*tptr;

void createList(int data)
{
    struct Node *nptr;    
    nptr=(struct Node *)malloc(sizeof(struct Node));    
    nptr->ele=data;
    nptr->flag=0;
    if(hptr==NULL)
       hptr=tptr=nptr;
    else
       tptr->next=nptr;
    tptr=nptr;
    nptr->next=NULL;
}

void display()
{
  struct Node *t;
  for(t=hptr;t!=NULL;t=t->next)
    printf(" %d ",t->ele);
}


int findLoop2(struct Node* h)
{
    while (h != NULL) {
        if (h->flag == 1)
            return 1;
 
        // If we are seeing the node for
        // the first time, mark its flag as 1
        h->flag = 1;
 
        h = h->next;
    }
 
    return 0;
}

int main()
{
    createList(10);
	createList(20);
	createList(30);
	createList(40);
	createList(50);
      display();
	hptr->next->next->next->next->next = hptr->next->next;
	printf("\n");
    printf(" %d ",findLoop2(hptr));
   return 0;
}
