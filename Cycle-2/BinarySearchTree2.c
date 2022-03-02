 #include<stdio.h>  

#include<stdlib.h>  
#include<malloc.h>  
#include<string.h>  
struct node
{
   int data;
   struct node *lchild;
   struct node *rchild;
}*root=NULL;
typedef struct node Node;
void insert()
{
	Node *t;
	t=(Node *)malloc(sizeof(Node));
	printf("Enter data....");
	scanf("%d",&t->data);
	t->lchild=NULL;
	t->rchild=NULL;

	 if(root==NULL) root=t;
	 else
	 {
	  Node *pre,*cur;
	  cur=root;
	  while(1)
	  {
	   if(t->data<cur->data) { pre=cur;cur=cur->lchild;if(cur==NULL) {pre->lchild=t;break;}}
	   else if(t->data>cur->data){ pre=cur;cur=cur->rchild;if(cur==NULL) {pre->rchild=t;break;}}
	  else { printf("Invalid Input");exit(0);}
           }
	 }
    }

    void search()
     { int key;
       int f=0;
      int nc=0;
      printf("Enter key to serach...");
      scanf("%d",&key);
      Node *cur=root;
      
      while(cur!=NULL)
      { nc++;
	if(cur->data==key) {f=1;break;}
        
      if(key<cur->data)  cur=cur->lchild; 
      else if(key>cur->data) cur=cur->rchild;
       
      }
       if(f)printf("Keyfound!!! number of comaprisons %d",nc);else printf("key Not found...");
     }
    void inorder(Node *r)
    {

     if(r!=NULL)
       {

         inorder(r->lchild);
         printf("<--> %d",r->data);
         inorder(r->rchild);  
       }
     }
     void preorder(Node *r)
    {

     if(r!=NULL) 
       {
         
         printf("<--> %d",r->data);
         preorder(r->lchild);
         preorder(r->rchild);
       }
     }
   void postorder(Node *r)
    {

     if(r!=NULL)
       {

         preorder(r->lchild);
         preorder(r->rchild);
         printf("<-->%d",r->data);
           
       }
     }
    Node* insuc(Node *r)
    {
     Node *q=NULL;
     while(r->lchild!=NULL)
     {
     q=r; r=r->lchild;
     }
     if(r->rchild!=NULL) q->lchild=r->rchild;else q->lchild=NULL;
     return(r);
    }
     void delete()
      {
      printf("Enter key to delete...");
      int d;
      scanf("%d",&d);
      Node *cur=root;
      int f=0;
      Node *pr=NULL;
      while(cur!=NULL)
      { 
	  if(cur->data==d) {f=1;break;}
        
      if(d<cur->data) {pr=cur; cur=cur->lchild;} 
      else if(d>cur->data){pr=cur; cur=cur->rchild;}
       
      }
      if(f==0)  printf("key not found..!!!");
      else
       {
       Node *t=cur;// node to be deleted...
	//leaf nodes....
         if(t->lchild==NULL&&t->rchild==NULL)
          {
            if(pr->lchild==t) pr->lchild=NULL;
            if(pr->rchild==t) pr->rchild=NULL; 
	       }
         else if(t->lchild==NULL) // only right child exist	       
             {
             if(pr->lchild==t) pr->lchild=t->rchild;
             if(pr->rchild==t) pr->rchild=t->rchild;
             }
             
         else if(t->rchild==NULL) // only left child exist	       
             {
             if(pr->lchild==t) pr->lchild=t->lchild;
             if(pr->rchild==t) pr->rchild=t->lchild;
             }
        else //both left and right child
          {
         Node *in=t->rchild;
          if(in->lchild==NULL) {t->data=in->data;t->rchild=in->rchild;}
          else {in=insuc(t->rchild);t->data=in->data;}

           }

          }//end of found else
        }// end of delete fn

    
    main()
    {int op;
     do
    {
    printf("\n.menu\n1.insert\n2.preorder\n3.postorder\n4.inorder\n5.delete\n6.search\n7.exit\nenter option\n");
    scanf("%d",&op);
     switch(op)
     {
            case 1:insert();break;
            case 2:preorder(root);break;
	    case 3:postorder(root);break;
	    case 4:inorder(root);break;
	    case 5:delete();break;
	    case 6:search();break;
      }
     }
   while(op!=7);
  }

