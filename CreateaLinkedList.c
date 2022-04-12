/*

Write a C Program to Create a Linked List of Students.

Where Each Student Node Should consists of Rno,Name, Marks.

Create a Linked List of 5 Students. 

Display the Student Data like the following 

Rno Name Marks.

input =
101 Mike 100
99 Scott 98
98 Tom 97
95 Sara 94
102 Zim 91

output =
101 Mike 100
99 Scott 98
98 Tom 97
95 Sara 94
102 Zim 91

*/



#include<stdio.h>
struct student{
    int rollno;
    char name[100];
    int marks;
    struct student *next;
};
void createLinkedList(int n);
void display();
struct student *stnode;
int main(){
    createLinkedList(5);
    display();
}
void createLinkedList(int n){
    struct student *fnnode,*tmp;
    stnode=(struct student *)malloc(sizeof(struct student));
    if(stnode==NULL)
        return;
    else {
        int roll,m;
        char n[100];
        scanf("%d %s %d" ,&roll,n,&m);
        stnode->rollno=roll;
        strcpy(stnode->name,n);
        stnode->marks=m;
        stnode->next=NULL;
        tmp=stnode;
        for(int i=2;i<=5;i++){
            fnnode=(struct student *) malloc(sizeof(struct student));
            if(fnnode==NULL)
                return ;
            else{
                scanf("%d %s %d ",&roll,n,&m);
                fnnode->rollno=roll;
                strcpy(fnnode->name,n);
                fnnode->marks=m;
                fnnode->next=NULL;
                tmp->next=fnnode;
                tmp=fnnode;
            }
        }
        
    }
}
void display(){
    struct student *i;
    if(stnode==NULL)
        return ;
    for(i=stnode;i!=NULL;i=i->next){
        printf("%d %s %d\n",i->rollno,i->name,i->marks);
    }
}
















