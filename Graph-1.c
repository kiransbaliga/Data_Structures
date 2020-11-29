#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    int visit;
    struct link *adj;
} * node;

struct link
{
    int data;
    struct link *next;
};

struct node graph[12];

void init(int ind)
{
    graph[ind].val = ind + 1;
    graph[ind].visit = 0;
}

struct link *createneighbour(int i)
{
    struct link *newcon;
    newcon = (struct link *)malloc(sizeof(struct link));
    newcon->data = i;
    newcon->next = NULL;
}



void depthfirst(int ind)
{
    if (graph[ind].visit == 0)
    {
        printf("%d -> ", graph[ind].val);
        graph[ind].visit = 1;
        struct link *n;
        n = graph[ind].adj;
        while (n != NULL)
        {
            depthfirst(n->data);
            n = n->next;
        }
    }
}
void breadthfirst(int ind)
{
    int queue[12], front, back, size;
    struct link *k;
    queue[0] = ind;
    back = size = 1;
    front = 0;
    graph[0].visit = 0;
    while (size > 0)
    {
        printf("%d -> ", graph[queue[front]].val);
        k = graph[front].adj;
        front++;
        if (front == 12)
            front = 0;
        size--;
        while (k != NULL)
        {
            if (graph[k->data].visit == 1)
            {
                graph[k->data].visit = 0;
                queue[back] = k->data;
                back++;
                size++;
                if (back == 12)
                    back = 0;
            }
            k = k->next;
        }
    }
}

int main()
{
    int i = 0;
    for (i = 0; i < 12; i++)
    {
        init(i);
    }
    graph[0].adj = createneighbour(1);
    graph[0].adj->next = createneighbour(3);
    graph[1].adj = createneighbour(0);
    graph[1].adj->next = createneighbour(2);
    graph[1].adj->next->next = createneighbour(3);
    graph[1].adj->next->next->next = createneighbour(5);
    graph[2].adj = createneighbour(1);
    graph[2].adj->next = createneighbour(5);
    graph[3].adj = createneighbour(0);
    graph[3].adj->next = createneighbour(1);
    graph[3].adj->next->next = createneighbour(4);
    graph[3].adj->next->next->next = createneighbour(6);
    graph[4].adj = createneighbour(3);
    graph[4].adj->next = createneighbour(6);
    graph[5].adj = createneighbour(1);
    graph[5].adj->next = createneighbour(2);
    graph[5].adj->next->next = createneighbour(7);
    graph[5].adj->next->next->next = createneighbour(8);
    graph[6].adj = createneighbour(3);
    graph[6].adj->next = createneighbour(4);
    graph[6].adj->next->next = createneighbour(9);
    graph[6].adj->next->next->next = createneighbour(10);
    graph[7].adj = createneighbour(5);
    graph[7].adj->next = createneighbour(8);
    graph[10].adj = createneighbour(6);
    graph[10].adj->next = createneighbour(9);
    graph[8].adj = createneighbour(5);
    graph[8].adj->next = createneighbour(7);
    graph[8].adj->next->next = createneighbour(9);
    graph[8].adj->next->next->next = createneighbour(11);
    graph[11].adj = createneighbour(8);
    graph[11].adj->next = createneighbour(9);
    graph[9].adj = createneighbour(6);
    graph[9].adj->next = createneighbour(8);
    graph[9].adj->next->next = createneighbour(10);
    graph[9].adj->next->next->next = createneighbour(11);
    printf("Depth first Search...");
    depthfirst(0);
    printf("\nBreadth first Search...");
    breadthfirst(0);
}