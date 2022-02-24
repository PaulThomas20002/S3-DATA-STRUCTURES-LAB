#include<stdio.h>
#include<stdlib.h>
struct node {
int size;
struct node *link;
};
struct node *readData();
void allocate(struct node **, struct node **);
void printList(struct node *);
int main(){
struct node *block, *process, *temp, *prev, *bestprev, *besttemp, *head;
block = process = NULL;
int bsize, psize, size;
printf("Enter no. of blocks: ");
scanf("%d", &bsize);
for(int i = 0; i < bsize; i++){
head = readData();
allocate(&block, &head);
}
printf("Enter no. of process: ");
scanf("%d", &psize);
if(psize > bsize){
printf("Allocation not possible\n");
return 0;
}
for(int i = 0; i < psize; i++){
printf("Enter the Size: ");
scanf("%d", &size);
int dif = 1000;
prev = bestprev = besttemp = NULL;
temp = block;
while(temp!=NULL){
if(dif > temp->size - size && temp->size - size >= 0){
bestprev = prev;
besttemp = temp;
dif = temp->size - size;
}
prev = temp;
temp = temp->link;
}
if(besttemp == block)
block = block->link;
else if(besttemp == NULL){
printf("Couldnt Allocate %d\n\n", size);
continue;
}
else
bestprev->link = besttemp->link;

printf("%d Allocated to %d block\n\n", size, besttemp->size);
allocate(&process, &besttemp);
}
printf("Block List: ");
printList(block);
printf("Process List: ");
printList(process);
return 0;
}
struct node *readData(){
struct node *new;
new = (struct node*)malloc(sizeof(struct node));
printf("Enter the Size: ");
scanf("%d", &new->size);
new->link = NULL;
return new;
}
void allocate(struct node **start, struct node **head){
struct node *new = *head;
new->link = NULL;
if(*start == NULL)
*start = new;
else{
struct node *temp = *start;
while(temp->link!=NULL)
temp = temp->link;
temp->link = new;
}
}
void printList(struct node *start){
struct node *temp = start;
while(temp!=NULL){
printf("%d ", temp->size);
temp = temp->link;
}
printf("\n");
}

