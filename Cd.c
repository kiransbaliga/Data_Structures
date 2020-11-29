#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
} * ptr, *del;
struct node *front = NULL;
struct node *last = NULL;

void display()
{
    if (front == NULL)
        printf("Underflow \n");
    else
    {
        printf("The list is \n");
        ptr = front;
        do
        {
            printf("%d \t", ptr->data);
            ptr = ptr->next;
        } while (ptr != front);
    }
    printf("\n\n");
}

void Insert_at_front(int x)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node *));
    temp->data = x;
    if (front == NULL)
    {
        front = temp;
        front->next = front->prev = front;
        last = front;
    }
    else
    {
        last->next = temp;
        temp->prev = last;
        temp->next = front;
        front->prev = temp;
        front = temp;
    }
    display();
}

void Insert_at_end(int x)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node *));
    temp->data = x;
    if (front == NULL)
    {
        front = temp;
        front->next = front->prev = front;
        last = front;
    }
    else
    {
        last->next = temp;
        temp->prev = last;
        temp->next = front;
        front->prev = temp;
        last = temp;
    }
    display();
}

void Delete_from_front()
{
    if (front == NULL)
        printf("Underflow \n");
    else if (front == last)
    {
        del = front;
        front = NULL;
        last = NULL;
        printf("Deleted element is %d \n", del->data);
        free(del);
    }
    else
    {
        del = front;
        last->next = front->next;
        front->next->prev = front->prev;
        front = front->next;
        printf("Deleted element is %d \n", del->data);
        free(del);
    }
    display();
}

void Delete_from_end()
{
    if (front == NULL)
        printf("Underflow \n");
    else if (front == last)
    {
        del = front;
        front = NULL;
        last = NULL;
        printf("Deleted element is %d \n", del->data);
        free(del);
    }
    else
    { 
        del = last;
        last->prev->next = front;
        front->prev = last->prev;
        last = last->prev;
        printf("Deleted element is %d \n", del->data);
        free(del);
    }
    display();
}

void main()
{
    int x, ans;
    do
    {
        printf("Enter your choice \n1- Insert at front \n2- Insert at end \n3- Delete at front \n4- Delete at end \n5- Display \n0- Exit \t");
        scanf("%d", &ans);
        switch (ans)
        {
        case 1:
            printf("Enter the element ");
            scanf("%d", &x);
            Insert_at_front(x);
            break;
        case 2:
            printf("Enter the element ");
            scanf("%d", &x);
            Insert_at_end(x);
            break;
        case 3:
            Delete_from_front();
            break;
        case 4:
            Delete_from_end();
            break;
        case 5:
            display();
            break;
        }
    } while (ans != 0);
}