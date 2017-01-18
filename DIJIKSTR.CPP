#include<conio.h>
#include<math.h>
#include<stdio.h>
#include<graphics.h>

int warshall(int am[10][10],int n);
/***********************/
void dijikstra();
void main()
{
clrscr();
dijikstra();
getch();
}
void dijikstra()
{  int i,j,k,l,m,n=0,p,ne,t,set[10],len[10],path[10],gptr[10][10];//={{0,0,0,0,0},{0,0,1,6,0,0},{0,1,0,2,3,5},{0,6,2,0,4,2},{0,0,3,4,0,2},{0,0,5,2,2,0}};
   int S,min,x,y,flag,D,Path[20],choice;
   char filename[100],ch='k';
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
	{
	     data[i][j]=data[i][j]+((ch-48)*pow(10,k));
	     k++;
	     if(n<j)
	     n=j;
	 }
	if(ch==' ')
	{j++;k=0;}
	if(ch=='\n')
	{i++;j=0;k=0;}
	printf("%c",ch);
	if(n<j)
	n=j;
	}

	n=n+1;
	for(i=0;i<n;i++)
	{for(j=0;j<n;j++)
	gptr[i+1][j+1]=data[i][j];
	}
	getch();
    }
   clrscr();
   printf("\n\n\tEnter the Source");
   scanf("%d",&S);
   printf("\n\n\tEnter the destination");
   scanf("%d",&D);
   if(choice==2)
   {
	printf("\n Enter weight of  matrix :-");
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	{
		printf("\n W[%d][%d] = ",i,j);
		scanf("%d",&gptr[i][j]);
	}
   }
   printf("\n");

   for(i=1;i<=n;i++)
   {for(j=1;j<=n;j++)
      printf(" %d ",gptr[i][j]);
      printf("\n");
    }
    for(i=1;i<=n;i++)
    set[i]=0;

    for(i=1;i<=n;i++)
    {
	if(gptr[S][i]==0)
	{
	    len[i]=3200;
	    path[i]=0;
	}
	else
	{
	    len[i]=gptr[S][i];
	    path[i]=S;
	}
     }
     set[S]=1;
     len[S]=0;
     flag=0;
     j=-1;
   while(!flag)
   {
       for(i=1;i<=n;i++)
       if(j!=S&&set[i]==0)
       {j=i;break;}

       set[j]=1;
       for(i=1;i<=n;i++)
       {
	   if(gptr[i][j]!=0)
	   {
	       if((len[j]+gptr[i][j])<len[i])
	       {
		   len[i]=len[j]+gptr[i][j];
		   path[i]=j;
	       }
	   }
       }
       flag=1;
       for(i=1;i<=n;i++)
       if(set[i]==0)
       {flag=0;break;}

   }
      printf(" \n\nLength :-");
      for(i=1;i<=n;i++)
      printf(" %d ",len[i]);
      printf(" \n\nPATH :-");
      for(i=1;i<=n;i++)
      printf(" %d ",path[i]);
      x=D;k=1;
      Path[k]=x;
      while(1)
     {
	if(x==S)
	break;
	k++;
	Path[k]=path[x];
	x=path[x];
     }
	printf("\n\n\n\tPATH :-");
	for(i=k;i>0;i--)
	printf(" %d ",Path[i]);
	printf("\n\tLENGTH :- %d",len[D]);



}

