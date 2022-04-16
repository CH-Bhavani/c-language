/*Given a Linked List which contains names write a function to 
print from n elements 
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

// Print all the elements from the number specified (N)
void printFromNElements(int num)
{
  struct Node *t;
  int count = 1;
  for(t = hptr; t != NULL; t = t->next)
  {
    if(count >= num)
      printf("%s\n",t->name);
    count++;
  }
}

void main()
{
  int num;
  createList("ravi");
  createList("ajay");
  createList("subbu");
  createList("indira");
  createList("Bharath");
  createList("Sudhir");
  createList("Satyam");

  printf("Enter number to print last n elements\n");
  scanf("%d", &num);
  if(num > 0)
  {
    printf("\n\n");
    printFromNElements(num);
  }
}