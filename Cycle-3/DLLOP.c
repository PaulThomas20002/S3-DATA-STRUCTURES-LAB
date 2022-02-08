#include <stdio.h>
#include <stdlib.h>

struct node{
	int info;
	struct node *prev, *next;
};
struct node *start;

void Displayf(){
	struct node *temp;
	if(start == NULL)
		printf("List is Empty...");
	else{
		temp = start;
		while(temp != NULL){
			printf("\nData = %d", temp->info);
			temp = temp->next;
		}
	}
}

void Displayr(){    //error here try to correct it
	struct node *temp;
	temp = start;
	if(start == NULL)
		printf("\nList is Empty");
    else{
        while(temp != NULL) //try temp->next here instead of temp
        	temp = temp->next;
  
		while(temp != NULL){
			printf("\nData = %d", temp->info);
			temp = temp->prev;
        	}

    	}
}

void InsertAtStart(){
	struct node *temp;
	int data;
	temp = (struct node *)malloc(sizeof(struct node));
	printf("Enter the data : ");
	scanf("%d", &data);
	temp->info = data;
	temp->prev = NULL;
	temp->next = start;
	start = temp;
}

void InsertAtEnd(){
	struct node *temp, *trav;
	int data;
	temp = (struct node *)malloc(sizeof(struct node));
	printf("Enter the data : ");
	scanf("%d", &data);
	temp->info = data;
	temp->next = NULL;
	temp->prev = NULL;
	trav = start;
	if(trav == NULL){
		start = temp;
	}
	else{
		while(trav->next != NULL)
			trav = trav->next;
		temp->prev = trav;
		trav->next = temp;
	}
}

void InsertAtPos(){
	struct node *temp, *newnode;
	int data, pos, i=1;
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode->next = NULL;
	newnode->prev = NULL;
	printf("\nEnter the Position : ");
	scanf("%d", &pos);
	if(start == NULL){
		start = newnode;
		newnode->prev = NULL;
		newnode->next = NULL;
	}
	else if(pos == 1)
			InsertAtStart();
	else{
			printf("Enter the data : ");
			scanf("%d", &data);
			newnode->info = data;
			temp = start;
			while(i<pos - 1){
				temp = temp->next;
				i++;
			}
			newnode->next = temp->next;
			newnode->prev = temp;
			temp->next = newnode;
			temp->next->prev = newnode;
	}
}

void DelAtStart(){

	struct node *temp;
	if(start == NULL)
			printf("\nList is empty");
	else{
		temp = start;
		start = start->next;
		start->prev = NULL;
		free(temp);
	}
}

void DelAtEnd(){
	struct node *temp;
	if(start == NULL)
		printf("\nList is empty ");
	temp = start;
	while(temp != NULL){
		temp = temp->next;
	if(start->next == NULL)
		start = NULL;
	else{
		temp->prev->next = NULL;
		free(temp);
		}
	}
}
void DelAtPos(){
 	struct node *temp, *position;
 	int pos, i=1;
 	temp = start;
 	if(start == NULL)
			printf("\nList is empty");
	else{
		printf("Enter the position : ");
		scanf("%d", &pos);
		if(pos == 1){
			DelAtStart();
			}
		while(i < pos - 1 ){
			temp = temp->next;
			i++;
		}
		position = temp->next;
		if(position->next != NULL)
			position->next->prev = temp;
		temp->next = position->next;
		free(position);
	}
}
int main(){

	int main, sub;
	do{
		printf("\nMenu\n1.Insertion\n2.Deletion\n3.Traversal\n4.Exit\n");
		scanf("%d", &main);
		switch(main){
			case 1 : do{
				     printf("\nSub-menu\n1.Insertion At Start\n2.Insertion At End\n3.Insertion At any Position\n4.Next Sub-Menu\n");
					 scanf("%d", &sub);
					 switch(sub){
					 	case 1 : InsertAtStart();
					 			 break;
					 	case 2 : InsertAtEnd();
					 			 break;
					 	case 3 : InsertAtPos();
					 			 break;
					 	case 4 : printf("Moving to next Sub-Menu");
					 			 break;
					 	default : printf("\nTry again...\n");
					 			 
					  }
					 }while( sub != 4);
		    case 2 : do{
		    			printf("\nSub-menu\n1.Deletion At Start\n2.Deletion At End\n3.Deletion At any Position\n4.Next Sub-Menu\n");
					 scanf("%d", &sub);
					 switch(sub){
					 	case 1 : DelAtStart();
					 			 break;
					 	case 2 : DelAtEnd();
					 			 break;
					 	case 3 : DelAtPos();
					 			 break;
					 	case 4 : printf("Moving to next Sub-Menu");
					 			 break;
					 	default : printf("\nTry again...\n");
					 	}
					 }while(sub != 4);
			case 3 : do{
						printf("\nSub-Menu\n1.Forward Display\n2.Reverse Display\n3.Exit\n");
						scanf("%d", &sub);
						switch(sub){
							case 1 : Displayf();
									 break;
							case 2 : Displayr();
									 break;
							case 3 : printf("Moving to next Sub-Menu");
									 break;
							default : printf("\nTry again...\n");
							}
					}while(sub != 3);
		    default : printf("\nTry again");
		    }
	}while(main != 4);

return 0;
}
