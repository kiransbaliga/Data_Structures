#include<stdio.h>
#include<process.h>

int cq[10],front=-1,rear=-1,size;

void push(){
    int num;
    if(rear==size-1&&front==0||front==rear+1)
    {
        printf("Queue Overflow !\n");
    }
    else
    {
        printf("Enter the elem to push:\n");
        scanf("%d",&num);
        if(front==-1)
        {front=rear=0;}
        else{
        rear++;
        if(rear==size)
        rear=0;}
        cq[rear]=num;
    }
    
}

void pop(){
    if(front==-1)
    {printf("empty queue!\n");
    }
    else
    {
        printf("elem %d is popped from the queue!\n",cq[front]);
        front++;
        if(front==size)
        front=0;
        if(rear==front)
        {
            rear=-1;
            front=-1;
        }
    }
}

void display(){
    int i;
    if(front>rear)
    {for(i=front;i<size;i++)
     printf("%d\t",cq[i]);
     for(i=0;i<=rear;i++)
     printf("%d\t",cq[i]);}
    else
    for(i=front;i<=rear;i++)
    printf("%d\t",cq[i]);
    printf("\n");
}

int main(){
     int n,i,item=0;
    printf("Enter the size of Queue\n");
    scanf("%i",&n);
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
        default:printf("Invalid!\n");                     
    }
    }
   
    return 0;
}