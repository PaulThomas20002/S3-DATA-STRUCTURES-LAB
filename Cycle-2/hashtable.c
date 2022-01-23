#include <stdio.h>
#include <math.h>
#define HASH_TABLE_SIZE 10
int hash_table[HASH_TABLE_SIZE]={0};
int hash(int data){
    int sum=0;
    while(data!=0){
        sum+=pow(data%10,2);
        data/=10;
        }
return sum%HASH_TABLE_SIZE;
    
}
int insert_ht(int ele){
    int index=hash(ele);
    if( hash_table[index]==0 ){
        hash_table[index]=ele;
        return 1;
        }
        //linear probing 
        int new_index=(index+1)%HASH_TABLE_SIZE;
while(new_index!=index){
    if(hash_table[new_index]==0){
        hash_table[new_index]=ele;
        return 1;
        }
        new_index=(new_index+1)%HASH_TABLE_SIZE;
        }
        return 0;
    
}
int delete_ht(int ele){
    int index=hash(ele);
if(hash_table[index]==ele){
    hash_table[index]=0;
    return 1;
    }
    //linear probing
    
    int new_index=(index+1)%HASH_TABLE_SIZE;
 while(new_index!=index){
     if(hash_table[new_index]==ele){
         hash_table[new_index]=0;
         return 1;
         }
         new_index=(new_index+1)%HASH_TABLE_SIZE;
         }
         return 0;}
void display_ht(){
    printf("\n***HASH TABLE***\n\n");
    for(int i=0;i<HASH_TABLE_SIZE;i++){
        printf("\t%d : ",i);
        if(hash_table[i] !=0)
        printf("%d",hash_table[i]);
        printf("\n");
        }
        printf("\n***HASH TABLE***\n\n");}
int main(){
    int option;
    int value;
    do{
        printf("1.insert\n2.delete\n3.display\n4.exit\nchoose any option : ");
        scanf("%d",&option);
        switch(option){
            case 1:
            printf("Enter the key : ");
            scanf("%d",&value);
            if( insert_ht(value)==0 )
            printf("\nTable Full\n");
            break;
            case 2:
            printf("Enter the key : ");
            scanf("%d",&value);
            if( delete_ht(value)==0 )
            printf("\nElement not found\n");
            break;
            case 3:
            display_ht();
            break;
            default:
            printf("\nEnter a valid option\n");
            }
}while(option!=4);
return 0;
    
}
