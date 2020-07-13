#include<stdio.h>
int abs(int a,int b)
{
	if(a>b)
	return a-b;
	else
	return b-a;
}
int min(int a,int b)
{
	if(a<b)return a;
	else return b;
}
void sstf(int *que,int n,int head)
{
	int total=0;
	int i,j;
	int arr[n];
	for(i=0;i<n;i++)
	{
		arr[i]=que[i];
	}
	for(i=0;i<n;i++)
	{
		int minimum=201;
		int pos=1000;
		for(j=0;j<n;j++)
		{
			if(arr[j]!=-1)
			{
				if(minimum!=min(minimum,abs(head,arr[j])))
				{
					minimum=min(minimum,abs(head,arr[j]));
					pos=j;
				}
			}
		}
		
		
		printf("%d -> ",head);
		total+=abs(head,arr[pos]);
		head=arr[pos];
		arr[pos]=-1;
	}
	printf("%d",head);
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
	printf("\n\n\t\tSSTF\n");
	sstf(que,n,head);
}
