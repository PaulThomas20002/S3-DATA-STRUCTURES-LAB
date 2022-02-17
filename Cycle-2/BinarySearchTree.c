#include <stdio.h>
#include <stdlib.h>

struct node{
int data;
struct node *lchild,*rchild;
};

struct node *root = NULL, *head, *ptr, *parent;

void insert();
void traversal();
void inorder(struct node*);
void preorder(struct node*);
void postorder(struct node*);

void main(){
int ch;
do{
    printf("\nMenu\n1. Insertion\n2. Traversal\n3. Exit\nEnter the choice: ");
    scanf("%d",&ch);
    switch(ch){
        case 1: insert();
                break;
        case 2: traversal();
                break;
        default: break;
        }
    }while(ch!=3);
}

void traversal(){
int ch;
do{
    printf("\nMenu\n1. inorder\n2. preorder\n3. postorder\n4. Exit\nEnter the choice: ");
    scanf("%d",&ch);

    switch(ch){
    case 1: inorder(root);
            break;
    case 2: preorder(root);
            break;
    case 3: postorder(root);
            break;
    default: break;
        }
    }while(ch!=4);
}

void insert(){
    head = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d",&head->data);
    head->lchild = head->rchild = NULL;
    if(root==NULL)
        root=head;
    else{
        ptr=root;
        int flag=0;
        while(ptr!=NULL&&flag==0){
            if(ptr->data < head-> data){
                parent=ptr;
                ptr=ptr->rchild;
                }
            else if(ptr->data > head-> data){
                    parent=ptr;
                    ptr=ptr->lchild;
                    }
            else
                flag=1;
                }
            if(flag==1)
                printf("Data already exists");
            else{
                if(parent->data < head->data)
                    parent->rchild=head;
            else
                parent->lchild=head;
        }
    }
}

void inorder(struct node *ptr){
    if(root==NULL)
        printf("Tree is empty");
    else{
        if(ptr!=NULL){
        inorder(ptr->lchild);
        printf("%d\t",ptr->data);
        inorder(ptr->rchild);
        }
    }   
}

void preorder(struct node *ptr){
    if(root==NULL)
        printf("Tree is empty");
    else{
        if(ptr!=NULL){
            printf("%d\t",ptr->data);
            preorder(ptr->lchild);
            preorder(ptr->rchild);
        }
    }
}

void postorder(struct node *ptr){
    if(root==NULL)
        printf("Tree is empty");
    else{
        if(ptr!=NULL){
            postorder(ptr->lchild);
            postorder(ptr->rchild);
            printf("%d\t",ptr->data);
        }
    }
}
