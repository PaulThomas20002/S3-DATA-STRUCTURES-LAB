#include<stdio.h>
#include<stdlib.h>
#define size 10
struct Queue
{
  int e;
  int p;
}Q[size];
int front=-1,rear=-1;
void Insert()
{
  int t1=0,t2=0,x,y;
  if(rear==size-1)
    printf("Queue Overflow!!!");
  else if(front==-1)
  {
    front=0;
    printf("Enter the element and it's priority to be inserted: ");
    scanf("%d %d",&x,&y);
    rear++;
    Q[rear].e=x;
    Q[rear].p=y;
  }
  else
  {
    printf("Enter the element and it's priority to be inserted: ");
    scanf("%d %d",&x,&y);
    rear++;
    Q[rear].e=x;
    Q[rear].p=y;
  }
  for(int i=0;i<=rear-1;i++)
  {
    for(int j=0;j<=rear-i-1;j++)
    {
      if(Q[j].p>Q[j+1].p)
      {
        t1=Q[j].e;
        t2=Q[j].p;
        Q[j].e=Q[j+1].e;
        Q[j].p=Q[j+1].p;
        Q[j+1].e=t1;
        Q[j+1].p=t2;
      }
    }
  }
}
void Delete()
{
  if(front==rear+1)
    printf("Queue Underflow!!!");
  else
  {
    printf("The deleted element: %d and it's priority: %d\n",Q[front].e,Q[front].p);
    front++;
  }
}
void Display()
{
  for(int i=front;i<=rear;i++)
  {
    printf("%d %d\n",Q[i].e,Q[i].p);
  }
}
void main()
{
  int ch;
  do
  {
    printf("\nMENU\n1.INSERT\n2.DELETE\n3.DISPLAY\n4.EXIT");
    printf("\nEnter the choice: ");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:Insert();
             break;
      case 2:Delete();
             break;
      case 3:Display();
             break;
      case 4:exit(0);
    break;
      default:printf("Invalid choice");
     break;
    }
  }while(ch<4);
}
