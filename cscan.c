#include<stdio.h>
void sort(int *number,int first,int last)
{
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(number[i]<=number[pivot]&&i<last)
            i++;
         while(number[j]>number[pivot])
            j--;
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }

      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      sort(number,first,j-1);
      sort(number,j+1,last);

   }
}
int abs(int a,int b)
{
	if(a>b)
	return a-b;
	else
	return b-a;
}
void cscanAlg(int *que,int n,int head)
{
	int total=0;
	int i,j;
	int arr[n];
	for(i=0;i<n;i++)
	{
		arr[i]=que[i];
	}
	sort(arr,0,n-1);
	int pos;
	for(i=0;i<n;i++)
	{
		if(arr[i]>head)
		{
			pos=i;
			break;
		}
	}
	printf("%d -> ",head);
	for(i=pos;i<n;i++)
	{
		printf("%d -> ",arr[i]);
		total+=abs(head,arr[i]);
		head=arr[i];
	}
	total+=abs(199,head);
	printf("199->....0 -> ");
	head=0;
	for(i=0;i<pos;i++)
	{
		printf("%d -> ",arr[i]);
		total+=abs(head,arr[i]);
		head=arr[i];
	}
	
	
	printf("\ntotal cylinder movements=%d",total);
}

int main()
{
	printf("The limits are 0-200");
	printf("\nEnter the number of elements to be scheduled ");
	int n;
	scanf("%d",&n);
	printf("Enter the elements\n");
	int que[n];
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&que[i]);
	}
	printf("Enter the initial head position ");
	int head;
	scanf("%d",&head);
	printf("\n\n\t\tC-SCAN\n");
	cscanAlg(que,n,head);
}
