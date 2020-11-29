#include<stdio.h>

struct elem{
   int val,prio;
}queue[10];

int rear=-1,front=-1,size;

void pop(){
    if(rear==front)
    {
        printf("empty que! \n");
    }
    else
    {
        printf(" %d is popped from the queue !\n",queue[front]);
        front++;
    }
    
}

void push(){
   struct elem ele;
   int i;
   if(rear==size-1)
   {
      printf("Queue OverFlow !\n");
   }
   else
   {  
   printf("Enter the Value and prio of new elem:\n");
   scanf("%d%d",&ele.val,&ele.prio);
   if(rear==-1)
   {
      queue[0].prio=ele.prio;
   queue[0].val=ele.val; 
   rear=0;
   front=0;
   }
   else
   {
         
   for(i=rear;queue[i].prio<ele.prio&&i>=0;i--)
   {
      queue[i+1]=queue[i];
   }
   queue[i+1].prio=ele.prio;
   queue[i+1].val=ele.val;
   rear++;
   }
   }
}

void display(){
    printf("The Queue is :\n");
    if(front==rear)
    printf("EMPTY\n");
    else{
    for(int i=front;i<=rear;i++)
    {
        printf("%i\t",queue[i].val);
    }
    printf("\n");
    for(int i=front;i<=rear;i++)
    {
        printf("%i\t",queue[i].prio);
    }
    printf("\n");
    }
}

int main()
{
    int n,i,item=0;
    printf("Enter the size:\n");
    scanf("%d",&size);
    while(item!=4)
    {    
    printf("1.push\n2.pop\n3.display\n4.exit\n");
    scanf("%i",&item);
    switch(item)
    {
        case 1:push();
               break;
        case 2:pop();
               break;
        case 3:display();
               break;
        case 4:break;      
        default:printf("Invalid !\n");                     
    }
    }
   
    return 0;
}