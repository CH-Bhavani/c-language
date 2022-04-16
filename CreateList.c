#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct Node
{
  char name[20];
  struct Node *next;
};

struct Node *hptr=NULL,*tptr;

void createList(char *s)
{
    struct Node *nptr;    
    nptr=(struct Node *)malloc(sizeof(struct Node));    
    strcpy(nptr->name,s);
    
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
    printf("%s\n",t->name);
}

void displayFromEnd(struct Node *ptr)
{
  struct Node *t;
  if(!ptr)
    return;
  displayFromEnd(ptr->next);
  printf("%s\n",ptr->name);
}

void reverseIterative()
{
  struct Node *current, *prev, *next;
  current = hptr;
  prev=NULL;
  while(current != NULL)
  {
    next = current->next;
    current->next=prev;
    prev=current;
    current = next;
  }
  hptr = prev;
}

void main()
{
  int i;
  createList("ravi");
  createList("ajay");
  createList("subbu");
  createList("indira");
  display();
  printf("\n");
  displayFromEnd(hptr);
}