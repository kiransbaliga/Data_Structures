#include<stdio.h>
#include<process.h>
int stack[10],top=0,n;
void push()
{
    int item;
    printf("enter item to be pushed!:");
    scanf("%d",&item);
    if(top==9)
    printf("Oops StackOverflow!!!");
    else
    {
        top++;
        stack[top]=item;

    }
}
void pop()
{
    if (top==-1)
    {
        printf("ERROR STACK is EMPTY");
    }
    else{
        printf("%d is popped!!\n",stack[top]);
        top--;
    }
}
void disp()
{   
    printf("stack now is:\n");
    for(int i=0;i<=top;i++)
    {
        printf("%d \t",stack[i]);
    }
}
void main()
{
    int item,j,ch;
    printf("enter size of stack(n<10):");
    scanf("%d",&n);

    printf("enter intial elements:");
    for(int i=0;i<n;i++)
    {
        scanf("%i",&stack[i]);
        
    }
    top=n-1;
    disp();
    while(1==1)
    {
        printf("\n1.push\n2.pop\n3.Exit\nEnter ur option num:");
        scanf("%d",&j);
        switch (j)
        {
        case 1:
            push();
            disp();
            break;
        case 2:
            pop();
            disp();
            break;
        case 3:exit(0);
        default:
            printf("invalid!");
            break;
        }
        
    }
}