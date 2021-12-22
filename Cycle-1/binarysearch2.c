/*
algorithm for binary search
step 1: start
step 2: accept a value in max as the number of elements of the array
step 3: accept max elements into the array ar
step 4: accept the value to be searched in the variable item
step 5 : store the postion of the first element of the list in first in first anf that of the last in the last
step 6 : repeat steps 7 to 11 while(first<=last)
step 7 : find the middle position using the formula (first+last)/2 and store it in mid
step 8 : compare the search value in item with the elements at the mid of the list
step 9 : if the mid element contains the search value in the item then stop search, display the position and go to step 12
step 10 : if the value is smaller than the mid element'THEN set last = mid-1
step 11 : if the search value is larger than the mid element    THEN    set first = mid+1
*/
#include<stdio.h>
int main(){
    int ar[25], max,first, last, mid, i, item , loc=-1;
    printf("How many elements : ");
    scanf("%d" , &max);
    printf("Enter the array elements in ascending order ");
    for(i=0; i<max; i++)   
        scanf("%d", &ar[i]);
    printf("Enter the item to search : ");
    scanf("%d", &item);
    first=0;
    last=max-1;
    while(first<=last){
        mid=(first+last)/2;
        if(item==ar[mid]){
            loc=mid;
            break;
        }
        if(item<ar[mid])
            last=mid-1;
        else
            first=mid+1;
    }    
    if (loc==-1)
        printf("The item is not found in the array");
    else
        printf("The item found at %d position", loc+1);
    
    return 0;
}
