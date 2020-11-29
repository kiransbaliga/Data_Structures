#include <stdio.h>
#include <process.h>
#include <string.h>
#include <stdlib.h>
struct stud
{
    int name;
    struct stud *next;
};

struct stud *first = NULL;
struct stud *last = NULL;
void push(int nm)
{
    struct stud *link = (struct stud *)malloc(sizeof(struct stud));
    link->name = nm;
    link->next = NULL;
    if (first == NULL)
    {
        first = last = link;
    }
    last->next = link;
    last = link;
}
void pop()
{
    if (first == NULL)
    {
        printf("ERROR EMPTY QUEUE");
    }
    else
    {
        struct stud *temp = first;
        printf("%d is popped\n", temp->name);
        first = first->next;
        if (first == NULL)
            last = NULL;
    }
}
void display()
{
    struct stud *temp = first;
    printf("[");
    while (temp != NULL)
    {
        printf(" %d ", temp->name);
        temp = temp->next;
    }
    printf("]\n");
}
void main()
{
    int opt;
    int nm;
    while (1 == 1)
    {
        printf("1.Enter to queue \n2.Delete from queue\n3.Display the queue\n4.Exit\nChoose ur option:");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            printf("Enter the name to be pushed:");
            scanf("%d", &nm);
            push(nm);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;

        case 4:
            exit(0);
        }
    }
}