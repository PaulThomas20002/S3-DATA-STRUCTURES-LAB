#include <stdio.h>
#include <math.h>
#define SIZE 10

int HT[SIZE]={0};

int hash(int data){
    int sum=0;
    while(data != 0){
        sum += pow(data%10,2);
        data/=10;
    }
return sum%SIZE;
}

int insert(int item){
    int index=hash(item);
    if( HT[index]==0 ){
        HT[index]=item;
        return 1;
    }
    //linear probing 
    int new_index=(index+1)%SIZE;
    while(new_index!=index){
        if(HT[new_index]==0){
            HT[new_index]=item;
            return 1;
        }
    new_index=(new_index+1)%SIZE;
    }
return 0;
}

int del(int item){
    int index=hash(item);
    if(HT[index]==item){
        HT[index]=0;
        return 1;
    }
    //linear probing
    int new_index=(index+1)%SIZE;
    while(new_index!=index){
        if(HT[new_index]==item){
            HT[new_index]=0;
            return 1;
         }
    new_index=(new_index+1)%SIZE;
    }
    return 0;
}

void display(){
    printf("\n***HASH TABLE***\n\n");
    for(int i=0;i<SIZE;i++){
        printf("\t%d : ",i);
        if(HT[i] !=0)
            printf("%d",HT[i]);
        printf("\n");
        }
        printf("\n***HASH TABLE***\n\n");
}

int main(){
    int d, value;
    do{
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\nchoose any Option : ");
        scanf("%d",&d);
        switch(d){
            case 1 : printf("Enter the key : ");
                     scanf("%d",&value);
                     if( insert(value)==0 )
                        printf("\nTable Full\n");
                     break;
            case 2 : printf("Enter the key : ");
                     scanf("%d",&value);
                     if( del(value)==0 )
                        printf("\nElement not found\n");
                     break;
            case 3 : display();
                     break;
            default :printf("\nTRY AGAIN!\n");
                     break;
            
        }
}while(d!=4);
return 0;
    
}
