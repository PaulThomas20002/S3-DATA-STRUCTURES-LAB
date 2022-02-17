/* To insert elements to LinkedList and delete an entered value completely from the LinkedList*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next; 

};
struct node *start;
int count = 0; 
void display(){
	struct node *temp = start;
	temp = start;
	if(start == NULL)
			printf("\nList is empty\n");
	else{
		while(temp != NULL){
			printf("\nData = %d in %u with next %u", temp->data, temp, temp->next);
			temp = temp->next;
			}
		}
}

void insert(){

	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	count++;
	int item;
	printf("Enter the data : ");
	scanf("%d", &item);
	temp->data = item;
	temp->next = NULL;
	temp->next = start;
	start = temp;
	printf("%d", count);
}

void delx(int x){
	struct node *ptr, *temp=start;
	
	
	if(start == NULL)
			printf("\nList is empty\n");
	else{
	//for(int i = 1; i <= count; i++){
		while(temp != NULL){
		    if(temp->data==x){
		        start=temp->next;
		        free(temp);count--;break;
		        }
			else if(temp->next->data == x){
				ptr = temp;
				temp = temp->next;
				ptr->next = temp->next;
				free(temp);count--;break;
			    }
			else
			printf("\nNo change\n");
			
		temp = temp->next;
		}
	}
}
//}

int main(){
	int d, x;
	do{
	printf("\n1.Insert\n2.DelX\n3.Display\n4.Exit\n");
	scanf("%d", &d);
	switch(d){
			case 1 : insert();break;
			case 2 : 
					 printf("\nEnter the key : ");
					 scanf("%d", &x);
					 delx(x);break;
			case 3 : display(); break;
			case 4 : printf("Aborting....");exit(0);
			default : printf("Try again");
		}
	}while(d != 4);
}
