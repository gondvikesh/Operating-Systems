#include<stdio.h>
int main()
{
	int n;
	printf("No of frames ");
	scanf("%d",&n);
	int i;
	int frame[n];
	for(i=0;i<n;i++)
		frame[i]=-1;
	int len;
	printf("length of reference string ");
	scanf("%d",&len);
	int ref[len];
	printf("Enter the page string\n");
	for(i=0;i<len;i++)
	{
		scanf("%d",&ref[i]);
	}
	int p=0;
	int count=0;
	for(i=0;i<len;i++)
	{
		int flag=0;
		int j;
		for(j=0;j<n;j++)
		{
			if(frame[j]==ref[i])
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			printf("hit\t\t->");
				int k;
				for(k=j;k>0;k--)
				{
					frame[k]=frame[k-1];
				}
		}
		else
		{
			printf("page fault\t->");
				int k;
				for(k=n-1;k>0;k--)
				{
					frame[k]=frame[k-1];
				}
		}
		frame[0]=ref[i];
		
		for(j=0;j<n;j++)
		{
			if(frame[j]!=-1)
				printf("%d ",frame[j]);
		}
		printf("\n");
	}
}
