#include<stdio.h>
#include<stdlib.h>

 struct Node
  {
    int exp;
    int val;
    struct Node *link;
  };
  
 struct Node *top1=NULL,*top2=NULL,*top3=NULL,*ptr,*temp;

 void Push1()
  {
    ptr=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter the Exponent\n");
    scanf("%d",&ptr->exp);
    printf("Enter the Value\n");
    scanf("%d",&ptr->val);
    ptr->link=NULL;
    if(top1==NULL)
     top1=ptr;
    else
     {
      ptr->link=top1;
      top1=ptr;
     }
  }
  
 void Push2()
  {
    ptr=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter the Exponent\n");
    scanf("%d",&ptr->exp);
    printf("Enter the Value\n");
    scanf("%d",&ptr->val);
    ptr->link=NULL;
    if(top2==NULL)
     top2=ptr;
    else
     {
      ptr->link=top2;
      top2=ptr;
     }
  }  

 void Add()
  {
    while(top1!=NULL&&top2!=NULL)
    {
     if(top1->exp==top2->exp)
      { 
        temp=(struct Node*)malloc(sizeof(struct Node));
        temp->val=top1->val+top2->val;
        temp->exp=top2->exp;
        temp->link=top3;
        top3=temp;
        top1=top1->link;
        top2=top2->link;
      }
     else if(top1->exp<top2->exp)
      {
        temp=(struct Node*)malloc(sizeof(struct Node));
        temp=top1;
        temp->link=top3;
        top3=temp;
        top1=top1->link;
      }
    else if(top1->exp>top2->exp)
     {
       temp=(struct Node*)malloc(sizeof(struct Node));
       temp=top2;
       temp->link=top3;
       top3=temp;
       top2=top2->link;
     }
   }
  if(top1!=NULL)
   {
     while(top1!=NULL)
      {
       temp=(struct Node*)malloc(sizeof(struct Node));
       temp->val=top1->val;
       temp->exp=top1->exp;
       temp->link=top3;
       top3=temp;
       top1=top1->link;
      }
   }
  else if(top2!=NULL)
   {
    while(top2!=NULL)
     {
      temp=(struct Node*)malloc(sizeof(struct Node));
      temp->val=top2->val;
      temp->exp=top2->exp;
      temp->link=top3;
      top3=temp;
      top2=top2->link;
     }
   }
  } 
 
 void Display()
  {
    printf("Polynomial Expression=");
    while(top3!=NULL)
     {
       printf("%dX^%d + ",top3->val,top3->exp);
       top3=top3->link;
     }
  }
 
 int main()
  {
    char op;
    struct Node *top1=NULL,*top2=NULL,*top3=NULL;
    printf("Enter the First Polynomial\n");
    do
     {
       Push1();
       printf("Do you wish to continue Press (Y/y)\n");
       scanf("%s",&op);
     }while(op=='Y' || op=='y');
    printf("Enter the Second Polynomial\n");
    do
     {
       Push2();
       printf("Do you wish to continue Press (Y/y)\n");
       scanf("%s",&op);
     }while(op=='Y' || op=='y');
    Add();
    Display();
    printf("\n");
    return 0;
  }
   
