/*Given a Linked List which contains names write a function to 
print the middle element 
*/

#include<stdio.h>
#include<string.h>

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
       hptr=nptr;
    else
       tptr->next=nptr;
    tptr=nptr;
    nptr->next=NULL;
}

void middleNode()
{
  struct Node *sp = hptr;   // slow pointer
  struct Node *fp = hptr;   // fast pointer

  if (hptr != NULL)
  {
    while (fp != NULL && fp->next != NULL)
    {
      fp = fp->next->next;
      sp = sp->next;
    }
    printf("Middle element is %s\n", sp->name);
  }  
}

void main(int argc, char * argv[])
{
  int i = 1;
  for(; i < argc; i++)
    createList(argv[i]);

  middleNode();
}