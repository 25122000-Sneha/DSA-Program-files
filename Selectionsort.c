#include <stdio.h>
main()
{
	int n,i,k,loc,min,temp,N,a[100];
	printf("Enter no. of elements:");
	scanf("%d",&n);
	printf("Enter the numbers:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Sorted list in order:");
	for(i=0;i<n;i++)
	{
		min=a[i];
		loc=i;
		for(k=i+1;k<n;k++)
		{
			if(min>a[k])
			{
				min=a[k];
				loc=k;
			}
		}
		if(loc!=i)
		{
			temp=a[i];
			a[i]=a[loc];
			a[loc]=temp;
		}
	}
	for(i=0;i<n;i++)
	{
		printf("\n%d",a[i]);
	}
}

