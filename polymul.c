
#include<stdio.h>
#include<stdlib.h>
struct poly
{
    int con;
    int exp;
    struct poly *next;
} node;

struct poly *start1=NULL,*start2=NULL,*startres=NULL;

void display(struct poly *s)
{
    struct poly *temp=s;
    while(temp!=NULL)
    {
        if(temp->con!=0)
        {
         if(temp!=s&&temp->con >=0)
         printf("+");
         if(temp->exp!=0)
         printf("%dx^%d ",temp->con,temp->exp );
         else
         {
             printf("%d ",temp->con);
         }
        }
         temp=temp->next;
    }
}
void enter(struct poly *s,int val,int pow,int sel)
{
    struct poly *n;
    n=(struct poly*)malloc(sizeof(struct poly));
    n->con=val;
    n->exp=pow;
    n->next=NULL;
  if(s==NULL)
  {
      if(sel==1)
    start1=n;
      else 
     start2=n;
  }
  else
  {
      struct poly *tp=s;
      if(tp->exp<pow)
      {
          n->next=tp;
      if(sel==1)
    start1=n;
      else if(sel==2)
     start2=n;
       }
      else if(tp->exp==pow)
      {
          tp->con+=val;
          free(n);
      }
      else{
      while(tp->next!=NULL)
      {
          if(tp->next->exp>pow)
          {tp=tp->next;}
          else if(tp->next->exp==pow)
          {
              tp->con+=val;
          free(n);
          break;
          }
          else
          {
              n->next=tp->next;
              tp->next=n;
              break;
          }
      }
      if(tp->next==NULL){
      n->next=tp->next;
      tp->next=n;}
      }
  }
  
}




void insert(int val,int exp)
{
   struct poly *n,*s=startres;
    n=(struct poly*)malloc(sizeof(struct poly));
    n->con=val;
    n->exp=exp;
    n->next=NULL;
  if(s==NULL)
  {
      startres=n; 
  }
  else
  {
      struct poly *tp=s;
      if(tp->exp<exp)
      {n->next=startres;
     startres=n;
       }
      else if(tp->exp==exp)
      {
          tp->con+=val;
          free(n);
      }
      while(tp->next!=NULL)
      {if(tp->next->exp>exp)
          {tp=tp->next;}
          else if(tp->next->exp==exp)
          {
              tp->next->con+=val;
          free(n);
          break;
          }
          else
          {
              n->next=tp->next;
              tp->next=n;
              break;
          }
      }
      if(tp->next==NULL){
      n->next=tp->next;
      tp->next=n;}
    
  }
  
}

void multiply()
{
    struct poly *tp=start1,*tq=start2;
    while(tp!=NULL )
    {tq=start2;
        while(tq!=NULL)
        {
            insert(tp->con*tq->con,tp->exp+tq->exp);
            tq=tq->next;
        }
        tp=tp->next;
    }
}


int main(){
    int n1,n2,i,value,power;
    printf("Enter the no of terms in first polynomial\n");
    scanf("%i",&n1);
    printf("Enter  first polynomial\n");
    for(i=0;i<n1;i++)
    {
        printf("Coeff and power: ");
        scanf("%d%d",&value,&power);
        enter(start1,value,power,1);
    }
    printf("Enter the no of terms in second polynomial\n");
    scanf("%i",&n2);
    printf("Enter the coeff of second polynomial\n");
    for(i=0;i<n2;i++)
    {
        printf("Coeff and Power: ");
        scanf("%d%d",&value,&power);
        enter(start2,value,power,2);
    }
    multiply();
    printf("Product of: ");
    display(start1);
    printf(" and ");
    display(start2);
    printf("\n is :");
    display(startres);

}
