#include <stdio.h>
struct poly
{
    int con;
    int exp;
}a[100],temp;

int main()
{
    int i,n,m,valx,y,j;
    printf("Enter the number of terms in first polynomial\n");
    scanf("%i",&m);
    printf("Enter coeff and exp of first polynomial\n");
    for(i=0;i<m;i++)
    {
        scanf("%i %i",&a[i].con,&a[i].exp);
    }
     for(int i=1;i<m;i++)
    {
        for(int j=0;j<m-i;j++)
        {
            if(a[j].exp<a[j+1].exp)
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    printf("Enter the number of terms in second polynomial\n");
    scanf("%i",&n);
    printf("Enter coeff and exp  of second polynomial\n");
    for(i=m;i<m+n;i++)
    {
        scanf("%i %i",&a[i].con,&a[i].exp);
    }
    for(int i=1;i<n;i++)
    {
        for(int j=m;j<m+n-i;j++)
        {
            if(a[j].exp<a[j+1].exp)
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    valx=0;
    y=m;
    i=m+n;
    while(valx<m && y<m+n)
    {
        if(a[valx].exp==a[y].exp)
        {
            if(a[valx].con+a[y].con!=0)
            {
                a[i].con=a[valx].con+a[y].con;
                a[i].exp=a[valx].exp;
                ++i;
            }
            ++valx,++y;

        }
        else if(a[valx].exp>a[y].exp)
        {
            a[i].con=a[valx].con;
            a[i].exp=a[valx].exp;
            ++valx,++i;
        }
        else
        {
            a[i].con=a[y].con;
            a[i].exp=a[y].exp;
            ++i,++y;
        }
    }
    while(valx<m)
    {
        a[i].con=a[valx].con;
        a[i].exp=a[valx].exp;
        ++valx,++i;
    }
    while(y<m+n)
    {
        a[i].con=a[y].con;
        a[i].exp=a[y].exp;
        ++i,++y;
    }
    for(int j=0;j<i;j++)
    {
        if(j==0)
        {
            printf("\n First polynomial:\n");
            printf(" %ix^%i",a[j].con,a[j].exp);
            continue;
        }
        if(j==m)
        {
            printf("\n second polynomial:\n");
            printf(" %ix^%i",a[j].con,a[j].exp);
            continue;
        }
        if(j==m+n)
        {
            printf("\n Sum of polynomial:\n");
            printf(" %ix^%i",a[j].con,a[j].exp);
            continue;
        }
	if(a[j].con>0)
	{
		printf(" +%ix^%i",a[j].con,a[j].exp);	
	}
	else if(a[j].con<0)
	{
		printf(" %ix^%i",a[j].con,a[j].exp);
	}
    }
    return 0;
}