//Menu driven program for linear and binary search
#include <stdio.h>
#include<stdlib.h>
void linear(int a[10], int n){
    int loc=-1, item;
    printf("Enter the item to search : ");
    scanf("%d", &item);
    for(int i=0; i<n; i++){
        if(a[i]==item){
            loc=i;
            break;
        }
    }
    if(loc!=-1)
        printf("element found in %d\n", loc+1);
    else
        printf("Element not found ...\n");
}
void binary(int a[10], int n){
    int temp,i, j, item, first, last, mid, loc=-1;  
    printf("The sorted array is...\n");
    for(i=0;i<n-1;i++){
        for(j=0; j<n-i-1; j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    for(i=0; i<n;i++){
        printf("%d", a[i]);
    }
    printf("Enter the item to search : ");
    scanf("%d", &item);
    
    first=0;
    last=n-1;
    while(first<=last){
        int mid=(first+last)/2;
        if(item==a[mid]){
            loc=mid;
        }
        if(item<a[mid]){
            last=mid-1;
        }
        else{
            first=mid+1;
        }
    }
    if(loc==-1){
        printf("Not found\n");
    }
    else
    printf("Element found at %d\n", loc+1);
}

int main(){
    int c ,n,a[10],i;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    printf("Enter the array elements...");
    for(i=0; i<n; i++)
        scanf("%d", &a[i]);
    
    
    
    do{
        printf("\n1. Linear Search\n2. Binary search\n3.exit\n");
        scanf("%d", &c);
        
        switch(c){
            case 1 : linear(a, n);
                     break;
                     
            case 2 : binary(a, n);
                     break;
                     
            case 3 : exit(0);
            
            default : printf("Try again..\n");
                     break;
        }
    }while(c!=3);
    return 0;
    
}
