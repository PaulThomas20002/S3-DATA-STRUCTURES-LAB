#include<stdio.h>

int q[20], top = -1, front = -1, rear = -1, a[20][20], vis[20], stack[20];
int delete();
void add(int item);
void bfs(int s,int n);

void main(){
    int n,i,s,ch,j;
    char c;
    printf("Enter the number vertices : ");
    scanf("%d", &n);
    for(i = 1;i <= n;i++){
        for(j = 1;j <= n;j++){
            printf("Enter 1 if %d has a node with %d else 0 ",i,j);
            scanf("%d", &a[i][j]);
        }
    }
    printf("The Adjacency Matrix\n");
    for(i = 1;i <= n;i++){
        for(j = 1;j <= n;j++){
            printf(" %d ",a[i][j]);
        }
    printf("\n");
    }

    do{
        for(i = 1;i <= n;i++)
            vis[i] = 0;

        printf("\nMenu\n1.B.F.S\n0 to Exit\nEnter the option : ");
        scanf("%d",&ch);
        printf("Enter the source vertex :");
        scanf("%d",&s);

        switch(ch){
        case 1 : bfs(s,n);
                 break;
        case 0 : printf("Exiting.");
                 break;
        }
    }while(ch!=0);
}

void bfs(int s,int n){
    int p,i;
    add(s);
    vis[s] = 1;
    p = delete();
    if(p != 0)
        printf(" %d",p);
    while(p != 0){
        for(i = 1;i <= n;i++)
            if((a[p][i] != 0) && (vis[i] == 0)){
                add(i);
                vis[i] = 1;
            }
        p = delete();
        if(p != 0)
            printf(" %d ",p);
    }
    for(i = 1;i <= n;i++)
        if(vis[i] == 0)
            bfs(i,n);
}


void add(int item){
    if(rear == 19)
        printf("Queue full.");
    else{
        if(rear == -1){
            q[++rear] = item;
            front++;
        }
        else
            q[++rear] = item;
    }
}

int delete(){
    int k;
    if((front > rear) || (front == -1))
        return(0);
    else{
        k = q[front++];
        return(k);
    }
}
