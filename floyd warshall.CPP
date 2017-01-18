#include<conio.h>
#include<string.h>
#include<math.h>
#include<stdio.h>
#include<graphics.h>
int wm[10][10],am[10][10];
//int p[10][10],sw[10][10];
void warshall();
char *combine(char s1[20],char s2[20]);
/***********************/
void main()
{
    clrscr();
    warshall();
    getch();
}
/***********************/

void warshall()
{
   int i,k,j,n,choice;
   char filename[100],ch='k',path[15][15][15],*comb;
   int data[20][20];
   FILE *P;

   //printf("Enter the no of nodes");
  // scanf("%d",&n);
   for(i=0;i<15;i++)
   for(j=0;j<15;j++)
   path[i][j][0]='/0';

   printf("\n\n\t 1. FILE");
   printf("\n\n\t 2. USER");
   printf("\n\n\t Enter your choice ");
   fflush(stdin);
   scanf("%d",&choice);
   if(choice==1)
   {
	for(i=0;i<15;i++)
	for(j=0;j<15;j++)
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
	wm[i][j]=data[i][j];
	}
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	{
	    if(wm[i][j]==0)
	    {am[i][j]=0;wm[i][j]=3200;}
	    if(wm[i][j]>0)
	    {am[i][j]=1;sprintf(path[i][j],"%d-%d",i+1,j+1);}

	}

	getch();
    }
   clrscr();
 if(choice==2)
 {
   printf("Enter the no of nodes");
   scanf("%d",&n);

   printf("\n Enter adjacency matrix :-");
   for(i=0;i<n;i++)
   for(j=0;j<n;j++)
   {
       printf("\n AM[%d][%d] = ",i+1,j+1);
       scanf("%d",&am[i][j]);
    }
    printf("\n Enter weight matrix :-");
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    {
	printf("\n WM[%d][%d] = ",i+1,j+1);
	scanf("%d",&wm[i][j]);
	if(wm[i][j]==0)
	wm[i][j]=3200;
	else
	sprintf(path[i][j],"%d-%d",i+1,j+1);

    }
  }
    for(k=0;k<n;k++)
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    {
	 am[i][j]=am[i][j]||am[i][k]&&am[k][j];
	 if(wm[i][j]>(wm[i][k]+wm[k][j]))
	 {
	     wm[i][j]=wm[i][k]+wm[k][j];
	     comb=combine(path[i][k],path[k][j]);
	     strcpy(path[i][j],comb);
	}

    }
    printf("\n");
   for(i=0;i<n;i++)
{   for(j=0;j<n;j++)
   {
       printf(" %d ",am[i][j]);
    }
    printf("\n");
 }
    printf("\n sortest weight matrix :-");
    printf("\n");
    for(i=0;i<n;i++)
   { for(j=0;j<n;j++)
    {
	if(wm[i][j]!=3200)
	printf(" %d ",wm[i][j]);
	else
	printf(" - ");
    }
    printf("\n");
   }
   printf("\n\n\t PATH MATRIX\n");
    for(i=0;i<n;i++)
   { for(j=0;j<n;j++)
    {   printf(" [ %s ] ",path[i][j]);

    }
    printf("\n\n");
   }
 }
char *combine(char s1[20],char s2[20])
{
int i,k;
char s3[100];
for(i=0,k=0;s1[i]!=NULL;i++,k++)
s3[k]=s1[i];
for(i=0,k=k-1;s2[i]!=NULL;i++,k++)
s3[k]=s2[i];
s3[k]=NULL;
return s3;

}