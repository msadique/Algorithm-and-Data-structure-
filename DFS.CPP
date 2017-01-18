#include<conio.h>
#include<stdio.h>
#include<graphics.h>
//int wm[10][10],am[10][10];
//int p[10][10],sw[10][10];
int warshall(int am[10][10],int n);
/***********************/
void kruskal();
void main()
{ clrscr();
kruskal();
getch();
}
void kruskal()
{  int i,j,k,l,m,n,p,u=0,t,tree[100],gptr[10][10];//={{0,1,1,0,0,0,0,1},{1,0,0,1,1,0,0,0},{1,0,0,1,0,1,0,0},{0,1,0,0,0,0,1,0},{0,1,1,0,0,0,1,1},{0,0,1,0,0,0,1,0},{0,0,0,1,1,1,0,0},{1,0,0,1,0,0,0,0}};;
   int S[100],stack[100],min,x,y;
   printf("Enter the no of nodes");
   scanf("%d",&n);
   printf("\n Enter weight of  matrix :-");
   for(i=0;i<n;i++)
   for(j=0;j<n;j++)
   {
       printf("\n W[%d][%d] = ",i+1,j+1);
       scanf("%d",&gptr[i][j]);
    }
   printf("\n");
   for(i=0;i<n;i++)
   {for(j=0;j<n;j++)
     { if(gptr[i][j]>0)
      gptr[i][j]=1;

      printf(" %d ",gptr[i][j]);  }
      printf("\n");
    }

    for(i=0;i<n;i++)
    S[i]=0;
    k=-1;j=-1;

    k++;stack[k]=u;

    while(k!=-1)
    {   printf("\n");
	for(i=0;i<=k;i++)
	printf(" %d ",stack[i]+1);

	u=stack[k];k--;
	if(S[u]==0)
	{
	    S[u]=1;
	    j++;tree[j]=u;

	    for(i=n-1;i>=0;i--)
	    {
		if(gptr[u][i]>0)
		{k++;stack[k]=i;}
	    }

	}
    }
    printf("\n\n\t DFS :-");
    for(i=0;i<=j;i++)
    printf(" V[%d] ",tree[i]+1);


}

