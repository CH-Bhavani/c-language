/*Given a Linked List which contains names write a function to 
print from n elements 
*/
//sol-1 non-recursion

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



//sol-2 recursion


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    char arr[100];
    struct node* link;
};
struct node* root=NULL;
void createNode(char arr[])
{
 struct node* temp;
 temp=(struct node*)malloc(sizeof(struct node));
 strcpy(temp->arr,arr);
 temp->link=NULL;
 if(root==NULL)
 {
     root=temp;
 }
 else
 {
     struct node* p=root;
     while(p->link!=NULL)
     {
         p=p->link;
     }
     p->link=temp;
 }
}

void displayFrom(int n,int count,struct node* temp)
{
    if(temp==NULL)
    return;
    
    if(count>=n)
    printf("%s\n",temp->arr);
    displayFrom(n,count+1,temp->link);
}

int main()
{
    int n;
    scanf("%d",&n);
    while(n!=0)
    {
        char arr[50];
        scanf("%s",arr);
        createNode(arr);
        n--;
    }
    scanf("%d",&n);
    struct node* temp=root;
    displayFrom(n,1,temp);
   return 0; 
}
