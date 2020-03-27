#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node **item;
int *k;

void insert(int b,int a,int i)
{
	struct node *new;
	new=(struct node *)malloc(sizeof(struct node));
	new->data=i;
	new->next=NULL;
	if(item[a]==NULL)
		item[b]=new;
	else
	{
		item[b]=new;
		new->next=item[a];
	}	
}

void unbounded_Knapsack(int W,int n,int *w,int *v)
{
	int x,i,c;
	for(x=1;x<=W;x++)
	{
		k[x]=0;
		for(i=0;i<n;i++)
		{
			if(w[i]<=x)
			{
				c=1;
				if(k[x]<k[x-w[i]]+v[i])
				{
					k[x]=k[x-w[i]]+v[i];
					c=c*0;
				}
				if(c==0)
					insert(x,x-w[i],i+1);
			}
		}
//		printf("for W=%d\t,V=%d\n",x,k[x]);
	}
//	printf("\n");
	//return k[W];
}

int main()
{
	int n,*w,i,*v,W;
	printf("ENTER THE NUMBER OF ITEMS :\n");
	scanf("%d",&n);
	w=(int *)malloc(n*sizeof(int));
	printf("ENTER THE WEIGHTS :\n");
	for(i=0;i<n;i++)
		scanf("%d",&w[i]);
	v=(int *)malloc(n*sizeof(int));
	printf("ENTER THE VALUES :\n");
	for(i=0;i<n;i++)
		scanf("%d",&v[i]);
	printf("ENTER THE REQUIRED WEIGHT :\t");
	scanf("%d",&W);
	item=(struct node **)malloc((W+1)*sizeof(struct node*));
	for(i=0;i<=W;i++)
		item[i]=NULL;
	k=(int *)malloc((W+1)*sizeof(int));
	k[0]=0;	
	//printf("ENTER THE REQUIRED VALUES :\t");
	//scanf("%d",&V);
	unbounded_Knapsack(W,n,w,v);
	printf("required value=%d\n",k[W]);
	while(item[W]!=NULL)
	{
		printf("%d\t",item[W]->data);
		item[W]=item[W]->next;
	}
	printf("\n");
}
