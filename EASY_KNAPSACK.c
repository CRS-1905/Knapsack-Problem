#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *s;

void insert(int x)
{
	struct node *new,*a;
	new=(struct node *)malloc(sizeof(struct node));
	new->data=x;
	new->next=NULL;
	if(s==NULL)
		s=new;
	else
	{
		a=s;
		s=new;
		new->next=a;
	}
}

void easy_napsack(int n,int W,int *w)
{
	int i;
	while(W>0)
	{
		for(i=0;i<n;i++)
		{
			if(W<w[i])
				break;
		}
		insert(i);
		W=W-w[i-1];
		if(w[0]>W)
			W=W-w[0];
	}
}
int main()
{
	int n,*w,i,*v,W;
	struct node *a;
	printf("ENTER THE NUMBER OF ITEMS :\t");
	scanf("%d",&n);
	w=(int *)malloc(n*sizeof(int));
	printf("ENTER THE WEIGHTS OF %d ITEMS IN SUPER SEQUENCE ORDER\t",n);
	for(i=0;i<n;i++)
		scanf("%d",&w[i]);
	printf("ENTER THE CAPACITY :\t");
	scanf("%d",&W);
	s=NULL;
	easy_napsack(n,W,w);
	printf("the items in the knapsack are given by :\t");
	a=s;
	while(a!=NULL)
	{
		printf("%d\t",a->data);
		a=a->next;
	}
	printf("\n");
}
