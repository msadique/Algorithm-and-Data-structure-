/*Program for Quick sort*/
#include<stdio.h>
#include<conio.h>
int partition(int a[],int l,int r);
void quicksort(int a[],int l,int r)
{
  int p;
  if(l<r)
  {
    p=partition(a,l,r);
    quicksort(a,l,p-1);
    quicksort(a,p+1,r);
  }
}


int partition(int a[],int l,int r)
{
  int i,j,t,x;
  i=l;
  j=r;
  x=a[l];
  while(i<j)
  {
       while(a[i]<=x&&i<=r)
	    i++;
       while(a[j]>x)
	    j--;
       if(i<j)
       {
	 t=a[i];
	 a[i]=a[j];
	 a[j]=t;
       }
  }
  t=a[j];
  a[j]=a[l];
  a[l]=t;
  return j;
}


void main()
{
  int a[100],n,i;
  clrscr();
  printf("Enter the no of elements to be sorted = ");
  scanf("%d",&n);
  for(i=0;i<=n-1;i++)
  {
     printf("Enter element a[%d]=",i);
     scanf("%d",&a[i]);
  }
  quicksort(a,0,n-1);
  printf("The sorted array is  :-");
  for(i=0;i<=n-1;i++)
     printf(" %d ",a[i]);
  getch();
}