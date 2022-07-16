#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node NODE;
NODE *start=NULL;

void Create_Empty_List();
void Insert_at_begining();
void Traverse();


void Create_Empty_List(NODE *start)
{
start = NULL;
}

void Insert_at_begining(int item)
{
  NODE *temp;
  temp =(NODE *)  malloc (sizeof(NODE));
  temp->data=item;
  if (start==NULL)
    temp->next=NULL;
  else
    temp->next=start;
    start=temp;
}

void Travarse(NODE *start)
{
 NODE *current;
 current=start;
 while(current!=NULL)
 {
   printf(" item-> %d\n",current->data)  ;
   current=current->next;
 }
}

void main()
{
    int item,choice;
    char ch;
    Create_Empty_List(start);
    do{
    printf("1.Insert at the begining \n");
    printf("2.Traverse list :::\n");
    printf("Enter your choice : \n");\
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        printf("Enter the item inside list \n");
        scanf("%d",&item);
        Insert_at_begining(item);
        break;
    case 2:
        printf("Traverse the list \n");
        Travarse(start);
        break;
    
    default:
        exit(0);
        break;
    }
}
while(choice!=2);

}