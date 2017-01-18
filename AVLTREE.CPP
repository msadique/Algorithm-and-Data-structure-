#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<graphics.h>
struct node
{
int d,h;
struct node *l;
struct node *r;
};

void display();
int preorder(struct node *ptr,int k);
int com_height(struct node *ptr);
struct node *rot_l_t_l(struct node *pptr);
struct node * rot_r_t_r(struct node *pptr);
struct node * rot_r_t_l(struct node *pptr);
struct node * rot_l_t_r(struct node *pptr);
struct node *insert(struct node *root,struct node *nptr);
int max=0,TA[100];

void main()
{
struct node *root,*nptr;
int i,I;
for(i=0;i<100;i++)
TA[i]=-3200;
root=NULL;
root->l=NULL;
root->r=NULL;
char c='n';
clrscr();
while(1)
{
nptr=(struct node *)malloc(sizeof(struct node));
gotoxy(1,1);
printf("Enter data :-");
scanf("%d",&nptr->d);
for(i=0;i<100;i++)
TA[i]=-3200;
nptr->l=NULL;
nptr->r=NULL;
root=insert(root,nptr);
preorder(root,0);
display();
gotoxy(30,46);
printf("\npress ' N' for exit");
fflush(stdin);
scanf("%c",&c);
if(c=='n'||c=='N')
break;

}

}
struct node *insert(struct node *root,struct node *nptr)
{
    struct node *ptr,*lptr,*rptr;
    int hr,hl,bf;
    ptr=root;

    if(ptr==NULL)
    {
	ptr=nptr;

	ptr->h=1;

    }
    else if(nptr->d<ptr->d)
    {
	lptr =ptr->l;
	rptr =ptr->r;
	ptr->l=insert(lptr,nptr);

	if(lptr==NULL)
	hl=0;
	else
	{
	     hr=com_height(rptr);

	     hl=com_height(lptr);
	     bf=hl-hr;
	     if(bf==2)
	     {
		if(nptr->d<lptr->d)
		ptr=rot_l_t_l(ptr);
		else
		ptr=rot_l_t_r(ptr);


	      }
	  }
    }
    else if(nptr->d>ptr->d)
    {
	lptr =ptr->l;
	rptr=ptr->r;
	ptr->r=insert(rptr,nptr);

	if(rptr==NULL)
	hr=0;
	else
	{
	     hr=com_height(rptr);
	     hl=com_height(lptr);
	     //printf(" (%d %d) ",hl,hr);
	     bf=hl-hr;
	     if(bf==-2)
	     {
	       if(nptr->d>rptr->d)
	       ptr=rot_r_t_r(ptr);
	       else
	       ptr=rot_r_t_l(ptr);



	      }
	  }
    }
    else
    printf("\nNptr data is already exist in the tree");
    ptr->h=com_height(ptr);
return ptr;
}
int com_height(struct node *ptr)
{
    struct node *lptr,*rptr;
    int h,hl,hr;
    if(ptr==NULL)
    {
	h=0;
	return h;
    }
    else
    {
	lptr=ptr->l;
	rptr=ptr->r;
	hl=com_height(lptr);
	hr=com_height(rptr);
	if(hl<=hr)
	     h=1+hr;
	else
	     h=1+hl;

	return(h);
      }

}

struct node *rot_l_t_l(struct node *pptr)
{
     struct node *aptr;
     aptr=pptr->l;
     pptr->l=aptr->r;
     aptr->r=pptr;
     return aptr;
}

struct node * rot_r_t_r(struct node *pptr)
{
     struct node *aptr;
     aptr=pptr->r;
     pptr->r=aptr->l;
     aptr->l=pptr;
     return aptr;
}

struct node * rot_r_t_l(struct node *pptr)
{
     pptr->r=rot_l_t_l(pptr->r);
     pptr=rot_r_t_r(pptr);
     return pptr;
}
struct node * rot_l_t_r(struct node *pptr)
{
     pptr->l=rot_r_t_r(pptr->l);
     pptr=rot_l_t_l(pptr);
     return pptr;
}
void display()
{
    clrscr();
    int Y=2,N=max+1,no=0;
    int i=0,j,k,z,postree[1000][2];
    long X,inc=0;
    no=log(N)/log(2);
    printf("\n\n");

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
	    postree[i][0]=-1;

	    if(TA[i]!=-3200)
	    {
	     printf("%d",TA[i]);
	     postree[i][0]=X/400;
	     postree[i][1]=Y*10+Y;

	     }
	    i++;
	    if(i>N)
	    break;
	}

	Y=Y+(10-no);
   }
/*   for(i=0;i<=max/2;i++)
   {
   if((postree[(2*i)+1][0])!=-1)
   line(postree[i][0],postree[i][1],postree[(2*i)+1][0],postree[(2*i)+1][1]);
   if((postree[(2*i)+2][0])!=-1)
   line(postree[i][0],postree[i][1],postree[(2*i)+2][0],postree[(2*i)+2][1]);
   }    */


}
int preorder(struct node *ptr,int k)
{       if(ptr!=NULL)
	{
	if(k>max)
	max=k;
	TA[k]=ptr->d;
      //	printf(" %d  .%d.",ptr->d,ptr->h);
	preorder(ptr->l,(2*k)+1);
	preorder(ptr->r,(2*k)+2);
	}
	else
	return 0;
	return 0;
}



