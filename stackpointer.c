#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *next;
} * head, *ptr, *del;

void display()
{
  if (head == NULL)
    printf("Underflow \n");
  else
  {
    printf("The list is \n");
    ptr = head;
    while (ptr != NULL)
    {
      printf("%d \t", ptr->data);
      ptr = ptr->next;
    }
    printf("\n\n");
  }
}

void insatfr(int x)
{
  struct node *new = (struct node *)malloc(sizeof(struct node *));
  if (new == NULL)
    printf("Failed to allocate memory \n");
  else
  {
    new->data = x;
    new->next = head;
    head = new;
  }
  display();
}

void insatend(int x)
{
  struct node *new = (struct node *)malloc(sizeof(struct node *));
  if (new == NULL)
    printf("Failed to allocate memory \n");
  else
  {
    new->data = x;
    new->next = NULL;
    ptr = head;
    while (ptr->next != NULL)
      ptr = ptr->next;
    ptr->next = new;
  }
  display();
}

void insatpos(int x, int pos)
{
  struct node *new = (struct node *)malloc(sizeof(struct node *));
  if (new == NULL)
    printf("Failed to allocate memory \n");
  else
  {
    new->data = x;                          
    new->next = NULL;                       
    ptr = head;
    for (int i = 0; i < pos - 1; i++)
      ptr = ptr->next;
    new->next = ptr->next;
    ptr->next = new;
  }
  display();
}

void delatfr()
{
  if (head == NULL)
    printf("Underflow \n");
  else
  {
    del = head;
    head = head->next;
    printf("Deleted element is %d \n", del->data);
    free(del);
  }
  display();
}

void delatend()
{
  struct node *last;
  if (head == NULL)
    printf("Underflow \n");
  else
  {
    del = head;
    while (del->next != NULL)
    {
      last = del;
      del = del->next;
    }
    if (del == head)
      head = NULL;
    else
      last->next = NULL;
    printf("Deleted element is %d \n", del->data);
    free(del);
  }
  display();
}

void delatpos(int pos)
{
  struct node *inter;
  if (head == NULL)
    printf("Underflow \n");
  else
  {
    inter = del = head;
    for (int i = 0; i < pos; i++)
    {
      inter = del;
      del = del->next;
    }
    inter->next = del->next;
    del->next = NULL;
    printf("Deleted element is %d \n", del->data);
    free(del);
  }
  display();
}

void main()
{
  int x, y, pos;
  do
  {
    printf("Enter your choice \n1- Insert at front \n2- Insert at end  \n3- Insert at a position \n4- Delete at front \n5- Delete at end \n6- Delete at a position \n7- Display \n0- Exit \t");
    scanf("%d", &y);
    switch (y)
    {
    case 1:
      printf("Enter the element ");
      scanf("%d", &x);
      insatfr(x);
      break;
    case 2:
      printf("Enter the element ");
      scanf("%d", &x);
      insatend(x);
      break;
    case 3:
      printf("Enter the element and position ");
      scanf("%d%d", &x, &pos);
      insatpos(x, pos);
      break;
    case 4:
      delatfr();
      break;
    case 5:
      delatend();
      break;
    case 6:
      printf("Enter the position ");
      scanf("%d", &pos);
      delatpos(pos);
      break;
    case 7:
      display();
      break;
    }
  } while (y != 0);
}