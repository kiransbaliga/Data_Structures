#include <stdio.h>

int front = -1, rear = -1, dq[10], size;

void pop()
{
    int item;
    if (front == -1)
    {
        printf("Queue Overflow !\n");
    }
    else
    {
        printf("From where do you want to pop the elem (1: Front / 2: Rear):\n");
        scanf("%d", &item);
        if (item == 1)
        {
            printf("elem %d is popped from the queue ! \n", dq[front]);
            if (front == rear)
            {
                front = -1;
                rear = -1;
            }
            else
            {
                front++;
                if (front == size)
                    front = 0;
            }
        }
        else if (item == 2)
        {
            printf("elem %d is popped from the queue ! \n", dq[rear]);

            if (front == rear)
            {
                front = -1;
                rear = -1;
            }
            else
            {
                rear--;
                if (rear == -1)
                    rear = size - 1;
            }
        }
        else
        {
            printf("Invalid!\n");
        }
    }
}
void push()
{
    int ele;
    int i, item;
    if (rear == front - 1 || front == 0 && rear == size - 1)
    {
        printf("Queue OverFlow !\n");
    }
    else
    {
        printf("Enter the Value:\n");
        scanf("%d", &ele);
        printf("Where do you want to push the elem (1: Front / 2: Rear):\n");
        scanf("%d", &item);
        if (item == 1)
        {
            if (front == -1)
            {
                front = 0;
                rear = 0;
            }
            else if (front == 0)
                front = size - 1;
            else
                front--;
            dq[front] = ele;
        }
        else if (item == 2)
        {
            if (rear == -1)
            {
                front = 0;
                rear = 0;
            }
            else if (rear == size - 1)
                rear = 0;
            else
                rear++;
            dq[rear] = ele;
        }
        else
        {
            printf("Invalid!\n");
        }
    }
}

void display()
{
    printf("The Queue is :\n");
    int i;
    if (front == -1)
        printf("EMPTY\n");
    else
    {
        if (front > rear)
        {
            for (i = front; i < size; i++)
                printf("%d\t", dq[i]);
            for (i = 0; i <= rear; i++)
                printf("%d\t", dq[i]);
        }
        else
            for (i = front; i <= rear; i++)
                printf("%d\t", dq[i]);
        printf("\n");
    }
}

int main()
{
    int n, i, item = 0;
    printf("Enter the size:");
    scanf("%d", &size);
    while (item != 4)
    {
        printf("1.push\n2.pop\n3.display\n4.exit\n");
        scanf("%i", &item);
        switch (item)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            break;
        default:
            printf("Invalid\n");
        }
    }

    return 0;
}