#include<stdio.h>  
#include<stdlib.h>  
#include<malloc.h>  
#include<string.h>  

struct node{
   int data;
   struct node *lchild;
   struct node *rchild;
}*root=NULL;

typedef struct node Node;

void insert(){
	Node *t;
	t = (Node *)malloc(sizeof(Node));
	printf("Enter data : ");
	scanf("%d", &t->data);
	t->lchild = NULL;
	t->rchild = NULL;

	 if(root == NULL) 
      root=t;
	 else{
	  Node *pre,*cur;
	  cur = root;
	  while(1){
	   if(t->data < cur->data) 
        { 
          pre = cur;
          cur = cur->lchild;
          if(cur == NULL) 
            {
              pre->lchild = t;
              break;
            }
          }
	   else if(t->data > cur->data){ 
            pre = cur;
            cur = cur->rchild;
            if(cur==NULL){
              pre->rchild = t;
              break;
            }
          }
	   else{ 
        printf("Invalid Input.");
        exit(0);
      }
    }
	}
}

void search(){ 
  int key;
  int f=0;
  int nc=0;
  printf("Enter key to search : ");
  scanf("%d", &key);
      Node *cur = root;
      while(cur != NULL){ 
        nc++;
        if(cur->data == key){
          f = 1;
          break;
        }
        if(key < cur->data)  
            cur = cur->lchild; 
      else if(key > cur->data) 
            cur = cur->rchild;
       
      }
      if(f)
        printf(" Key Found. Number of comprisons %d", nc);
      else 
        printf("Key Not Found.");
     }
    void inorder(Node *r){
      if(r != NULL){
        inorder(r->lchild);
        printf("<--> %d",r->data);
        inorder(r->rchild);  
       }
     }
    
    void preorder(Node *r){
      if(r != NULL){
      printf("<--> %d",r->data);
      preorder(r->lchild);
      preorder(r->rchild);
       }
     }
   
    void postorder(Node *r){
      if(r != NULL){
        preorder(r->lchild);
        preorder(r->rchild);
        printf("<-->%d",r->data); 
       }
     }
    
    Node* insuc(Node *r){
     Node *q = NULL;
     while(r->lchild != NULL){
      q = r; 
      r = r->lchild;
     }
     if(r->rchild != NULL) 
      q->lchild = r->rchild;
     else 
      q->lchild = NULL;

    return(r);
    }
    
void delete(){
      printf("Enter key to delete : ");
      int d;
      scanf("%d", &d);
      Node *cur = root;
      int f = 0;
      Node *pr = NULL;
      while(cur != NULL){
        if(cur->data == d)
          {
            f = 1;
            break;
          }
          if(d < cur->data) 
            {
              pr = cur; 
              cur = cur->lchild;
            } 
          else if(d > cur->data)
            {
              pr = cur; 
              cur = cur->rchild;
            }
       }
       if(f==0)  
        printf("Key not found.");
       else{
        Node *t = cur;
         if(t->lchild == NULL && t->rchild == NULL){
          if(pr->lchild == t) 
            pr->lchild = NULL;
          if(pr->rchild==t) 
            pr->rchild = NULL; 
	       }
       else if(t->lchild == NULL){
             if(pr->lchild == t) 
                pr->lchild = t->rchild;
             if(pr->rchild == t) 
              pr->rchild = t->rchild;
             }             
       else if(t->rchild == NULL){
             if(pr->lchild == t) 
              pr->lchild = t->lchild;
             if(pr->rchild == t) 
              pr->rchild = t->lchild;
             }
        else{
         Node *in = t->rchild;
          if(in->lchild == NULL) 
            {
              t->data = in->data;
              t->rchild = in->rchild;
            }
          else{
            in = insuc(t->rchild);
            t->data = in->data;
          }
       }

    }
}

int main(){
  int op;
  do{
    printf("\nMenu\n1.Insert\n2.Preorder\n3.Postorder\n4.Inorder\n5.Delete\n6.Search\n7.Exit\nEnter the option : ");
    scanf("%d", &op);
    switch(op){

      case 1 : insert();
               break;
      case 2 : preorder(root);
               break;
	    case 3 : postorder(root);
               break;
	    case 4 : inorder(root);
               break;
	    case 5 : delete();
               break;
	    case 6 : search();
               break;
      case 7 : break;
      default : printf("\nTry again.");
      }
     }
   while(op!=7);
return 0;
  }
