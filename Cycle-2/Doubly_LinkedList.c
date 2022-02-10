#include<stdio.h>
#include<stdlib.h>
#include<string.h>

 struct Student
  {
    int RNo;
    char Name[20];
    int m1,m2,m3;
    int t;
    struct Student *prev;
    struct Student *next;
  };

 struct Student *ptr,*head,*temp;

 void Display()
  {
    ptr=head;
    while(ptr!=NULL)
     {
       printf("Roll No=%d\n",ptr->RNo);
       printf("Name   =%s\n",ptr->Name);
       printf("Mark 1 =%d\n",ptr->m1);
       printf("Mark 2 =%d\n",ptr->m2);
       printf("Mark 3 =%d\n",ptr->m3);
       printf("Total  =%d\n",ptr->t);
       ptr=ptr->next;
     }
  }

 void Insert()
  {
    int flag=0;
    int Rno;
    char Na[20];
    int ma1,ma2,ma3;
    int to;
    ptr=(struct Student*)malloc(sizeof(struct Student));
    printf("Enter the Roll no\n");
    scanf("%d",&Rno);
    printf("Enter the Name\n");
    scanf("%s",Na);
    printf("Enter Mark 1\n");
    scanf("%d",&ma1);
    printf("Enter Mark 2\n");
    scanf("%d",&ma2);
    printf("Enter Mark 3\n");
    scanf("%d",&ma3);
    to=ma1+ma2+ma3;
    ptr->RNo=Rno;
    strcpy(ptr->Name,Na); 
    ptr->m1=ma1;
    ptr->m2=ma2;
    ptr->m3=ma3;
    ptr->t=to;
    if(head==NULL)
     {
       ptr->next=NULL;
       ptr->prev=NULL;
       head=ptr;
     }
    else
     {
      temp=head;
      while(temp!=NULL)
       {
        if(ptr->t>temp->t)
         {
          if(temp==head)
           {
             head=ptr;
           }
          ptr->next=temp->next;
          temp->prev=ptr;
          ptr->next=temp;
          flag=1;
          break; 
         }
        else
         temp=temp->next;
       } 
      if(flag==0)
       {
         temp=head;
         while(temp->next!=NULL)
          temp=temp->next; 
         temp->next=ptr;
         ptr->prev=temp;
         ptr->next=NULL;
       }
    }
  }

 void Del()
  {
     int Ro;
    printf("Enter the Roll no\n");
    scanf("%d",&Ro);
    temp=head;  
    while(temp->RNo!=Ro)  
     temp=temp->next;  
    if(temp==NULL)  
     printf("Underflow\n");  
    else if(temp->next==NULL)  
     temp->prev->next=NULL;
    else  
    {  
      ptr=temp;
      temp->next->prev=temp->prev;
      temp->prev->next=temp->next; 
      free(ptr);  
    }    
  }
 
 int main()
  {
    int op;
    char ch;
    do
     {
       printf("Enter the option\n");
       printf("1.Enter Student Details\n");
       printf("2.Delete Student Details\n");
       printf("3.Display\n");
       scanf("%d",&op);
       if(op==1)
        Insert();
       else if(op==2)
        Del();
       else
        Display();
       printf("Do you wish to continue (Y/y)");
       scanf("%s",&ch);
      }while(ch=='y' || ch=='Y');
    return 0;
  }
