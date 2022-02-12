#include <stdio.h>
#include <stdlib.h>

struct node{
	int info;
	struct node *prev, *next;
};
struct node *start;
int count=0;
void Displayf(){
	struct node *temp;
	if(start == NULL)
		printf("List is Empty...");
	else{
		temp = start;
		while(temp != NULL){
			printf("\n%d" ,temp->info);
			temp = temp->next;
		}
	}
}


void Displayr(){
	struct node *temp;
	temp = start;
	if(start == NULL)
		printf("\nList is Empty");
    else{
        while(temp->next != NULL){
        	
        	temp = temp->next;
        	}
       
		while(temp != NULL){ 	
			printf("\n%d", temp->info);
        	temp = temp->prev;
        	}


    	}
}

void InsertAtStart(){
	struct node *temp;
	int data;
	temp = (struct node *)malloc(sizeof(struct node));
	count++;

	printf("Enter the data : ");
	scanf("%d", &data);
	temp->info = data;
	temp->prev = NULL;
	temp->next = start;
	if(start != NULL)
		start->prev = temp;
	start = temp;
}

void InsertAtEnd(){
	struct node *temp, *trav;
	int data;
	temp = (struct node *)malloc(sizeof(struct node));
	count++;
	temp->next = NULL;
	temp->prev = NULL;
	printf("Enter the data : ");
	scanf("%d", &data);
	temp->info = data;
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
	int data, pos, i = 1;
    struct node *temp, *newnode;
    newnode = malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->prev = NULL;
    
   	printf("\nEnter position : ");
    scanf("%d", &pos);
    printf("\nEnter number to be inserted: ");
    scanf("%d", &data);
    newnode->info = data;
    temp = start;
    
    if (start == NULL) {
        start = newnode;
        newnode->prev = NULL;
        newnode->next = NULL;
        count++;
    }
    else if (pos == 1) {
        newnode->next = start;
        newnode->next->prev = newnode;
        newnode->prev = NULL;
        start = newnode;
        count++;
    }
    else if(pos == count+1){
            printf("\nSorry No newnode created.\nUse Insert At End Function.");free(newnode);}
    else if (count < pos){
            printf("\nSorry No newnode created.\nOnly %d elements are entered", count);free(newnode);}
    
    else if(pos > 1){
        while (i < pos - 1) {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
     	newnode->next->prev = newnode;
     	temp->next = newnode;
        newnode->prev = temp;
        count++;
    	}
    else
    	printf("\n No node created");
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
		count--;
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
		count--;
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
		count--;
	}
}
int main(){

	int main, sub;
	do{
		menu:
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
					 	case 4 : printf("Moving to next Menu");
					 			 goto menu;
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
					 	case 4 : printf("Moving to next Menu");
					 			 goto menu;
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
							case 3 : printf("Moving to next Menu");
									 goto menu;
							default : printf("\nTry again...\n");
							}
					}while(sub != 3);

			case 4 : printf("Aborting....");
					 break;
		    default : printf("\nTry again");
		    }
	}while(main != 4);

return 0;
}
