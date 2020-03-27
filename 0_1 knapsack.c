#include<stdio.h>
#include<stdlib.h>

int c[100][100][100],n,W,*v,*w,**k;

void knapsack()
{
	int j,i,p;
	for(j=1;j<=W;j++)
	{
		for(i=1;i<=n;i++)
		{
			k[i][j]=k[i-1][j];
			for(p=0;p<=c[i-1][j][0];p++)
				c[i][j][p]=c[i-1][j][p];
			if(w[i-1]<=j)
			{
				if(k[i][j]<k[i-1][j-w[i-1]]+v[i-1])
				{
					k[i][j]=k[i-1][j-w[i-1]]+v[i-1];
					for(p=1;p<=c[i-1][j-w[i-1]][0];p++)
						c[i][j][p]=c[i-1][j-w[i-1]][p];
					c[i][j][p]=i;
					c[i][j][0]=c[i-1][j-w[i-1]][0]+1;
				}
			}
		}
	}
}


int main()
{
	int i,j;
	printf("ENTER THE CAPACITY :\t");
	scanf("%d",&W);
	printf("ENTER THE NUMBER OF ITEMS :\t");
	scanf("%d",&n);
	v=(int *)malloc(n*sizeof(int));
	w=(int *)malloc(n*sizeof(int));
	printf("enter the weight :\n");
	for(i=0;i<n;i++)
		scanf("%d",&w[i]);
	printf("enter the values:\n");
	for(i=0;i<n;i++)
		scanf("%d",&v[i]);
	k=(int **)malloc((n+1)*sizeof(int *));
	for(i=0;i<=n;i++)
		k[i]=(int *)malloc((W+1)*sizeof(int));
	for(i=0;i<=n;i++)
		k[i][0]=0;
	for(j=0;j<=W;j++)
		k[0][j]=0;
	knapsack();
	printf("the required value is :%d\n",k[n][W]);
	printf("the items in the bag is given by :\n");
	for(i=1;i<=c[n][W][0];i++)
		printf("%d\t",c[n][W][i]);
	printf("\n");
}

