#include<conio.h>
#include<stdio.h>
#include<math.h>
void heapmax();
void heapsort();
int heap(int i);
void display(int M);
void enter();
int TA[18000],max=0;
void main()
{
     int a,n,i;
     clrscr();
     for(i=1;i<18000;i++)
     TA[i]=-3200;
     printf("Enter no of elements");
     scanf("%d",&n);
     clrscr();
     i=1;
     while(i<=n)
     {
	enter();
	display(max);
	i++;
     }
     clrscr();
     for(i=0;i<max;i++)
     printf(" %d ", TA[i]);
     getch();
     heapsort();
     printf("\n\n\t Sorted array  :- ");
     for(i=0;i<max;i++)
     printf(" %d ", TA[i]);
     getch();
}
void enter()
{
int i ,d;
gotoxy(1,1);
printf("Enter no");
scanf("%d",&d);
TA[max]=d;
max++;
}
void display(int M)
{
    clrscr();
    int Y=3,N=M,no=0;
    int i=0,j,k,z;
    long X,inc=0;
    no=log(N)/log(2);
    for(j=0;j<=no;j++)
    {
	inc=252000/pow(2,j+1);
	X=4000;
	for(k=0;k<pow(2,j);k++)
	{
	    X=X+inc;
	    if(k>0&&k<pow(2,j))
	    X=X+inc;
	    gotoxy(X/3200,Y);
	    if(TA[i]!=-3200)
	    printf("%d",TA[i]);
	    i++;
	    if(i>N)
	    break;
	}

	Y=Y+(12-no);
   }

}
int heap(int i)
{  int l,r,largest,t;
   l=(2*i)+1;
   r=(2*i)+2;
   if(l<max&&TA[l]>TA[i])
   largest=l;
   else
   largest=i;
   if(r<max&&TA[r]>TA[largest])
   largest=r;
   if(largest!=i)
   {
       t=TA[largest];
       TA[largest]=TA[i];
       TA[i]=t;
       heap(largest);
    }
    else
    return 0;
    return 0;
}
void heapmax()
{
   for (int i=(max/2)-1;i>=0;i--)
   {
       heap(i);

   }
}
void heapsort()
{
    int L,t;
    L=max;
    heapmax();
    display(max);
    getch();
    while(max>0)
    {
	t=TA[max-1];
	TA[max-1]=TA[0];
	TA[0]=t;
	max=max-1;
	heapmax();
	display(L);
	getch();
    }
    max=L;
    display(L);
    getch();
}

