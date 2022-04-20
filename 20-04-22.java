/*



1) Given single linked list of digits, and given k value.

add k value to linked list 

note: 0<k<9 (k value is single digit number only)

ex:
input =1 2 3
1
output =1 2 4

input =1 0 0
5
output =1 0 5

input = 9 9 9 9 
1
output =1 0 0 0 0

input =1 2 9 9
1
output =1 3 0 0



*/



#include <stdio.h>
#include <stdlib.h>
 
struct Node
{
    int data;
    struct Node* next;
};
 
void push(struct Node** head, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}
void printList( struct Node* head)
{
    while (head)
    {
        printf("%d ",head->data);
        head = head->next;
    }
}
int add(struct Node *head, int digit)
{
    if (head == NULL) {
        return digit;
    }
    int carry = add(head->next, digit);
 
    if (carry == 0) {
        return 0;
    }
    int sum = head->data + carry;
 
    head->data = sum % 10;  
    return sum/10;
}
 
void addDigit(struct Node** head, int digit)
{
    int carry = add(*head, digit);
 
    if (carry) {
        push(head, carry);
    }
}
 
int main()
{ 
    int n;
    scanf("%d",&n);
    int arr[n];
   for(int i=0;i<n;i++)
   scanf("%d",&arr[i]);
    struct Node* head = NULL;
    for (int i=n-1;i>=0;i--) {
        push(&head, arr[i]);
    }
 
    int digit;
    scanf("%d",&digit);
    addDigit(&head, digit);
    printList(head);
    return 0;
}
