#include<stdio.h>
void merge(int a[],int,int,int);
void merse_sort(int a[],int,int);
void merge_sort(int a[],int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		merge_sort(a,low,mid);
		merge_sort(a,mid+1,high);
		merge(a,low,mid,high);
	}
}
void merge(int a[],int low,int mid,int high)
{
	int i,j,k;
	i=low;
	j=mid+1;
	k=low;
	int b[20];
	while(i<=mid && j<=high)
	{
	 if(a[i]<=a[j])
	 {
	 	b[k]=a[i];
	 	i++;
	 	k++;
	 }
	 else
	 {
	 	b[k]=a[j];
	 	j++;
	 	k++;
	 }
	 
	}
	if(i>mid)
	{
		while(j<=high)
		{
			b[k]=a[j];
			j++;
			k++;
		}
	}
	if(j>high)
	{
		while(i<=mid)
		{
			b[k]=a[i];
			i++;
			k++;
		}
	}
	for(k=low;k<=high;k++)
	{
		a[k]=b[k];
	}
}
int main()
{
		int n;
	printf("enter size");
	scanf("%d",&n);
	int a[n];
	printf("enter elements:");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	merge_sort(a,0,n-1);
	for(int i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
}
