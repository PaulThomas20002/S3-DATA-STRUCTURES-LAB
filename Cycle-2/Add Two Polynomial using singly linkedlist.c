#include <stdio.h>
#include <stdlib.h>

struct node
{
	int coef;
	int exp;
	struct node *link;
	
};


struct node *insert(struct node *head, int co, int ex ){

	struct node *temp = NULL;
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	newnode->coef = co;
	newnode->exp = ex;
	newnode->link = NULL;

	if(head == NULL || ex > head->exp){

		newnode->link = head;
		head = newnode;
		//printf("\n%u = newnode ", newnode);
		}
	else {

		temp = head;
		//printf("\n%u temp ", temp);
		while (temp->link != NULL && temp->link->exp >= ex){
			temp = temp->link;
		}
		//printf("\n%u = temp", temp);
		
		newnode->link = temp->link;
		//printf("\n%unewnodelink", newnode->link);
		
		temp->link = newnode;
		//printf("\n%unewtemplink", temp->link);
		//printf("\n1.%d\n2.%d\n3.%u --%u", newnode->coef, newnode->exp, newnode->link, newnode);
	}
	
	return head;
}

struct node* create(struct node *head){
	 int exp, coef, i , n;
	 printf("\nEnter the number of terms : ");
	 scanf("%d", &n);

	 for(i = 0; i<n; i++){
	 	printf("\nEnter the coefficient of the term : ");
	 	scanf("%d", &coef);

	 	printf("Enter the exponent of the term : ");
	 	scanf("%d", &exp);

	 	head = insert(head, coef, exp);
	 }
	 return head;
}


void print(struct node *head){
	struct node *temp = head;
	if(head == NULL)
		printf("No Polynomial\n");
	else{
		while(temp != NULL){
			printf("(%dx^%d)", temp->coef, temp->exp);
			temp = temp->link;
			if(temp != NULL)
				printf("+");
			else
				printf("\n");
			}
		}
}

void addpoly(struct node *head1, struct node *head2){

	struct node *ptr1 = head1;
	struct node *ptr2 = head2;
	struct node *head3 = NULL;
	while(ptr1 != NULL && ptr2 != NULL){

		if (ptr1->exp == ptr2->exp){
			head3 = insert(head3, ptr1->coef+ptr2->coef, ptr1->exp);
			ptr1 = ptr1->link;
			ptr2 = ptr2->link;
		}
		else if(ptr1->exp > ptr2->exp){
			head3 = insert(head1, ptr1->coef, ptr1->exp);
			ptr1 = ptr1->link;
		}
		else if(ptr1->exp < ptr2->exp){
			head3 = insert(head3, ptr2->coef, ptr2->exp);
			ptr2 = ptr2->link;
		}
	}
	while(ptr1 != NULL){
		head3 = insert(head3, ptr1->coef, ptr1->exp);
		ptr1 = ptr1->link;
	}
	while(ptr2 != NULL){
		head3 = insert(head3, ptr2->coef, ptr2->exp);
		ptr2 = ptr2->link;
	}
	printf("\nAdded Polynomial is : ");
	print(head3);
}

int main(){
	struct node *head1 = NULL;
	struct node *head2 = NULL;
	printf("The first Polynomial \n");
	head1 = create(head1);
	printf("\nFirst Polynomial :");
	print(head1);
	printf("\nThe second Polynomial \n");
	head2 = create(head2);
	printf("\nSecond Polynomial : ");
	print(head2);
	addpoly(head1, head2);
	return 0;
}
