
#include<stdio.h>
int t1[30][3],t2[30][3],tr1[30][3],tr2[30][3],e[30][3];
int sparsematrix(int d[10][10],int u[30][3],int v,int w)
{ 
	int k,l,t,n;
	u[0][0]= v;
	u[0][1]=w;
	t=0; n=1;
	for (k=0; k<v; k++)
	{
		for (l=0; l<w; l++)
		if(d[k][l]!=0)
		{
			u[n][0]=k;
			u[n][1]=l;
			u[n][2]=d[k][l];
			t++;
			n++;
	       }
	}
	u[0][2]=t;
	for(int i=0;i<=u[0][2];i++)
	{
		for(int j=0;j<3;j++)
		{
			printf("%i\t",u[i][j]);
		}
	printf("\n");
	}
}
int transpose(int sp[30][3],int trans[30][3])
{
	int i,j,k=1;
	trans[0][0] = sp[0][1];
	trans[0][1] = sp[0][0];
	trans[0][2] = sp[0][2];
	for (i=0; i<sp[0][1]; i++)
	for (j=1; j<=sp[0][2]; j++)
	if (sp[j][1]==i)
	{
		trans[k][0] = sp[j][1];
		trans[k][1] = sp[j][0];
		trans[k][2] = sp[j][2];
		k++;
	}
	for(int i=0;i<=trans[0][2];i++)
	{
		for(int j=0;j<3;j++)
		{
			printf("%i\t",trans[i][j]);
		}
		printf("\n");
	}
}
void add(int g[30][3],int h[30][3],int e[30][3])
{
	int i,j,k,m,r1,r2;
	i=j=k=1;
	r1=g[0][2];
	r2=h[0][2];
	if(g[0][0]==h[0][0]&&g[0][1]==h[0][1])
	{
		e[0][0]=g[0][0];
		e[0][1]=g[0][1];
		while(i<=r1 && j<=r2)
		{
			if(g[i][0]==h[j][0])
			{
				if(g[i][1]==h[j][1])
				{
					if(g[i][2] + h[j][2]!=0)
					{
						e[k][0]=g[i][0];
						e[k][1]=g[i][1];
						e[k][2]=g[i][2] + h[j][2];
						k++;
					}
					i++; j++;
				}	
				else  if (g[i][1]<h[j][1])
				{
					e[k][0]=g[i][0];
					e[k][1]=g[i][1];
					e[k][2]=g[i][2];
					i++;k++;
				}
				else if (g[i][1]>h[j][1])
				{
					e[k][0]=h[j][0];
					e[k][1]=h[j][1];
					e[k][2]=h[j][2];
					j++;k++;
				}
			}
			else if(g[i][0]<h[j][0])
			{
				e[k][0]=g[i][0];
				e[k][1]=g[i][1];
				e[k][2]=g[i][2];
				i++;k++;
			}
			else if(g[i][0]>h[j][0])
			{
				e[k][0]=h[j][0];
				e[k][1]=h[j][1];
				e[k][2]=h[j][2];
				j++;k++;
			}
		}
		if(i<=r1)
		{
			for(m=i; m<=r1; m++)
			{	
				e[k][0]=g[m][0];
				e[k][1]=g[m][1];
				e[k][2]=g[m][2];
				k++;
			}
		}
		if(j<=r2)
		{
			for(m=j; m<=r2; m++)
			{
				e[k][0]=h[m][0];
				e[k][1]=h[m][1];
				e[k][2]=h[m][2];
				k++;
			}
		}
		e[0][2]=k-1;
	}
	else
	{
		printf("\n Cannot add these matrices\n");
	}
	for(int x=0;x<=e[0][2];x++)
	{
		for(int y=0;y<3;y++)
		{
			printf("%i\t",e[x][y]);		
		}
		printf("\n");	
	}
}

int main()
{

	int a[10][10],b[10][10],m,n,p,q;
	//first matrix
	printf("Enter the order of first matrix:\n");
	printf("Rows:");
	scanf("%i",&m);
	printf("Columns:");
	scanf("%i",&n);
	printf("\nEnter the elements of first matrix:\n");
	for(int i=0;i<m;i++)
	for(int j=0;j<n;j++)
	{
		scanf("%i",&a[i][j]);
	}
	//second matrix
	printf("\nEnter the order of second matrix:\n");
	printf("Rows:");
	scanf("%i",&p);
	printf("Columns:");
	scanf("%i",&q);
	printf("\nEnter the elements of second matrix:\n");
	for(int i=0;i<p;i++)
	for(int j=0;j<q;j++)
	{
		scanf("%i",&b[i][j]);
	}
	//display first and second matrix
	//first matrix
	printf("First matrix:\n");
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%i\t",a[i][j]);
	}
	printf("\n");
	}
	printf("Second matrix:\n");
	for(int i=0;i<p;i++)
	{
		for(int j=0;j<q;j++)
		{
			printf("%i\t",b[i][j]);
		}
	printf("\n");
	}
	printf("Tupple form of first matrix\n");
	sparsematrix(a,t1,m,n);
	printf("Tupple form of second matrix\n");
	sparsematrix(b,t2,p,q);
	printf("Transpose of first matrix in tupple form\n");
	transpose(t1,tr1);
	printf("Transpose of second matrix in tupple form\n");
	transpose(t2,tr2);
	printf("Sum of matrices in tuple form\n");
	add(t1,t2,e);
}
