#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<stdio.h>
#include<graphics.h>

int warshall(int am[10][10],int n);
/***********************/
void kruskal();
void main()
{
clrscr();
kruskal();
getch();
}
void kruskal()
{   int i,j,k,l,m,n,p,ne,t,temp[10][10],tree[10][10],gptr[10][10],X[100][4];
   char filename[100],ch='k',choice,*st;
   int data[20][20];
   FILE *P;
   //printf("Enter the no of nodes");
  // scanf("%d",&n);
   printf("\n\n\t 1. FILE");
   printf("\n\n\t 2. USER");
   printf("\n\n\t Enter your choice ");
   fflush(stdin);
   scanf("%d",&choice);
   if(choice==1)
   {
	for(i=0;i<20;i++)
	for(j=0;j<20;j++)
	data[i][j]=0;
	printf("Enter the the file name");
	scanf("%s",filename);
	P=fopen(filename,"r+");
	i=0;j=0;k=0;
	while(ch!=EOF)
	{
	ch=getc(P);
	if(ch>=48&&ch<58)
	{    st[k]=ch;
	     //data[i][j]=data[i][j]+((ch-48)*pow(10,k));
	     k++;
	     if(n<j)
	     n=j;
	 }
	if(ch==' ')
	{st[k]=NULL;data[i][j]=atoi(st);j++;k=0;}
	if(ch=='\n')
	{st[k]=NULL;data[i][j]=atoi(st);i++;j=0;k=0;}
	printf("%c",ch);
	if(n<j)
	n=j;
	}

	n=n+1;
	for(i=0;i<n;i++)
	{for(j=0;j<n;j++)
       {gptr[i][j]=data[i][j];
       //	printf(" %d ",data[i][j]);
	}

	}
	getch();
    }
   clrscr();


 if(choice==2)
 { printf("Enter the no of nodes");
   scanf("%d",&n);
   printf("\n Enter weight of  matrix :-");
   for(i=0;i<n;i++)
   for(j=0;j<n;j++)
   {
       printf("\n W[%d][%d] = ",i+1,j+1);
       scanf("%d",&gptr[i][j]);
    }
 }
    k=0;
    for(i=0;i<n-1;i++)
    for(j=i+1;j<n;j++)
    if(gptr[i][j]>0)
    {
	X[k][0]=i;
	X[k][1]=j;
	X[k][2]=gptr[i][j];
	X[k][3]=0;
	k=k+1;
    }
    ne=k;
    if(ne<n-2)
    printf("no spanning tree possible in the graph");
    /*************sort************************/
    for(i=0;i<ne;i++)
    for(j=i+1;j<ne;j++)
    if(X[i][2]>X[j][2])
    {
	t=X[i][0];X[i][0]=X[j][0];X[j][0]=t;
	t=X[i][1];X[i][1]=X[j][1];X[j][1]=t;
	t=X[i][2];X[i][2]=X[j][2];X[j][2]=t;
	t=X[i][3];X[i][3]=X[j][3];X[j][3]=t;
    }
    printf("\n");for(p=0;p<ne;p++){printf("\n V[%d] - V[%d]   = %d ",X[p][0],X[p][1],X[p][2]); }getch();

    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    tree[i][j]=0;
    k=0;l=0;
    while(k<n-1)
    {
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	temp[i][j]=tree[i][j];
	i=X[l][0];j=X[l][1];
	temp[i][j]=1;temp[j][i]=1;
	for(p=1;p<n;p++)
	for(m=0;m<p;m++)
	temp[p][m]=0;
	if( warshall(temp,n)!=1)
	{
	    tree[i][j]=1;tree[j][i]=1;
	    k=k+1;
	    X[l][3]=1;
	}
	l=l+1;
    }
     printf(" \n\n\t KRUSKAL\n\n");
     for(i=0;i<n;i++)
     {
	for(j=0;j<n;j++)
	if(tree[i][j]==1)
	printf("  %d  ",gptr[i][j]);
	else
	printf("  -  ");
	printf("\n\n");
     }
     for(i=0;i<ne;i++)
     { if(X[i][3]==1)
     printf("V[%d] - V[%d]  =  %d \n",X[i][0]+1,X[i][1]+1,X[i][2]);
     }

}



int warshall(int am[10][10],int n)
{
   int i,k,j,l,m,p;
   int cm[10][10];
   for(i=0;i<n;i++)for(j=0;j<n;j++)cm[i][j]=am[i][j];

    for(k=0;k<n;k++)
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    {
      am[i][j]=am[i][j]||am[i][k]&&am[k][j];

    }
    for(p=0;p<n;p++)
    if(am[p][p]==1)
    return 1;

    for(l=0;l<n-1;l++)
    for(m=l+1;m<n;m++)
   { for(i=0;i<n;i++)for(j=0;j<n;j++)am[i][j]=cm[i][j];
    if(am[l][m]>0)
    {
    am[m][l]=am[l][m];
    am[l][m]=0;

    for(k=0;k<n;k++)
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    {
	 if(i==j&&am[i][j]>0&&(am[i][j]||am[i][k]&&am[k][j])>0)
	 am[i][j]++;
	 else
	 am[i][j]=am[i][j]||am[i][k]&&am[k][j];

    }

    for(p=0;p<n;p++)
    if(am[p][p]==1)
    return 1;
    }
     }
    return 0;
 }
