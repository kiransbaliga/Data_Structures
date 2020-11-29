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
    struct poly *t=s;
    while(t!=NULL)
    {
         if(t!=s&&t->con >=0)
         printf("+");
         
         if(t->exp!=0)
         printf("%dx^%d ",t->con,t->exp );
          else
         {
             printf("%d ",t->con);
         }
         
         t=t->next;
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
  { if(sel==1)
    start1=n;
      else if(sel==2) 
     start2=n;
     else if(sel==3)
     startres=n;
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
     else if(sel==3)
     startres=n;
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



void sum()
{
    struct poly *tp=start1,*tq=start2;
    while(tp!=NULL && tq!=NULL)
    {
        if(tp->exp > tq->exp)
        {
            enter(startres,tp->con,tp->exp,3);
            tp=tp->next;
        }
        else if(tp->exp<tq->exp){
            enter(startres,tq->con,tq->exp,3);
            tq=tq->next;
        }
        else{
            if(tp->con+tq->con!=0)
            enter(startres,tq->con+tp->con,tq->exp,3);
            tq=tq->next;
            tp=tp->next;
        }
    }
    while(tp!=NULL)
    {
        enter(startres,tp->con,tp->exp,3);
            tp=tp->next;
    }
    while(tq!=NULL)
    {
         enter(startres,tq->con,tq->exp,3);
            tq=tq->next;
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
    printf("Enter second polynomial\n");
    for(i=0;i<n2;i++)
    {
        printf("Coeff and Power: ");
        scanf("%d%d",&value,&power);
        enter(start2,value,power,2);
    }
    sum();
    printf("SUM OF:");
    display(start1);
    printf(" and ");
    display(start2);
    printf("\n is :");
    display(startres);

}
