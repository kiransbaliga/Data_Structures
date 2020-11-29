#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
  char data;
  struct node *next;
  struct node *prev;
} * ptr, *f1, *f2;
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

void insert(char ch)
{
  struct node *temp = (struct node *)malloc(sizeof(struct node *));
  temp->data = ch;
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
}

void check(int l)
{
  int c = 0;
  f1 = front;
  f2 = last;
  for (int j = 0; j < l / 2; j++)
  {
    if (f1->data != f2->data)
    {
      c++;
      break;
    }
    f1 = f1->next;
    f2 = f2->prev;
  }
  if (c == 0)
    printf("The string is palindrome \n");
  else
    printf("The string is not palindrome \n");
}

void main()
{
  char s[100];
  int l;
  printf("Enter the string:");
  gets(s);
  for (int i = 0; i < strlen(s); i++)
    insert(s[i]);
  l = strlen(s);
  check(l);
}