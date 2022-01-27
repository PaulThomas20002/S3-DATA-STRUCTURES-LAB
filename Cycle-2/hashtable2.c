/*Implementation of HashTable*/

#include <stdio.h>
void main()
{ 
int n, key, i , j, index, HT[40];
printf("Enter the size of Hashtable: ");
scanf("%d", &n);
for(i = 0; i < n; i++)
  HT[i] = -1;
for(i = 0; i < n; i++)
  { 
    printf("Enter the value: ");
  scanf("%d", &key);
  for(j = 0; j < n; j++)
  {
    index = (key + j) % n;
    if(HT[index] == -1)
    {
    if(j!=0)
      printf("Collision occurred for value %d\n",key);
    HT[index] = key;
    break;
    }
}
}
printf("Hashtable: \n");
for(i = 0; i < n; i++)
  printf(" value @ %d = %d \n",i, HT[i]);
}
