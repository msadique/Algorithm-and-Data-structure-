#include<conio.h>
#include<math.h>
#include<stdio.h>
#include<graphics.h>
//int wm[10][10],am[10][10];
//int p[10][10],sw[10][10];
int warshall(int am[10][10],int n);
/***********************/
void prims();
void main()
{
clrscr();
prims();
getch();
}
void prims()
{   int i,j,k,l,m,n,p,ne,t,tree[10][10],gptr[10][10];
   int S[100],min,x,y,choice;
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
	gptr[i][j]=data[i][j];
	}
	getch();
    }
   clrscr();
   if(choice==2)
 {
   printf("Enter the no of nodes");
   scanf("%d",&n);

   printf("\n Enter weight of  matrix :-");

   for(i=0;i<n;i++)
   for(j=0;j<n;j++)
   {

       printf("\n W[%d][%d] = ",i+1,j+1);
       scanf("%d",&gptr[i][j]);
    }
 }
   clrscr();
   printf(" \n\n\t PRIMS \n\n");
   for(i=0;i<n;i++)
   for(j=0;j<n;j++)
   if(gptr[i][j]==0)
   gptr[i][j]=3200;

    for(i=0;i<n;i++)
    S[i]=0;

    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    tree[i][j]=0;

    S[0]=1;ne=0;

    while(ne<n)
    {   x=-1;y=-1;
	min=3200;
	for(i=0;i<n;i++)
	{
	    if(S[i]==1)
	    {
		for(j=0;j<n;j++)
		if(S[j]==0)
		{
		    if(min>gptr[i][j])
		    {  // printf(" %d ",gptr[i][j]);
			min=gptr[i][j];
			x=i;y=j;
		    }
		}

	}}
	tree[x][y]=1;
	printf("V[%d] - V[%d]  =  %d \n",x+1,y+1,gptr[x][y]);
	//printf("\n{ %d %d }",x,y);
      //	tree[y][x]=1;
	S[y]=1;


	ne=ne+1;
    }
    if(ne<n-2)
    printf("no spanning tree possible in the graph");
    /*************sort************************/

     printf("\n\n\tPRIMS MATRIX \n\n");
     for(i=0;i<n;i++)
     {
	for(j=0;j<n;j++)
	if(tree[i][j]==1)
	printf("  %d  ",gptr[i][j]);
	else
	printf("  -  ");
	printf("\n\n");
     }

}

